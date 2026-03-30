#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ================= CONFIG ================= */
#define ADMIN_USER "admin"
#define ADMIN_PASS "admin123"

/* ================= STRUCTURES ================= */
typedef struct Product {
    int id;
    char name[30];
    float price;
    int qty;
} Product;

typedef struct Sale {
    int billNo;
    char productName[30];
    int quantity;
    float total;
    char date[20];
} Sale;

/* ================= UTIL ================= */
void currentDate(char *buf) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    sprintf(buf, "%02d-%02d-%04d",
            tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
}

/* ================= AUTH ================= */
int adminLogin() {
    char u[20], p[20];
    printf("Username: ");
    scanf("%s", u);
    printf("Password: ");
    scanf("%s", p);

    return strcmp(u, ADMIN_USER) == 0 && strcmp(p, ADMIN_PASS) == 0;
}

/* ================= PRODUCT FUNCTIONS ================= */
void addProduct() {
    FILE *fp = fopen("products.dat", "ab");
    Product p;

    printf("Product ID: ");
    scanf("%d", &p.id);
    printf("Name: ");
    scanf("%s", p.name);
    printf("Price: ");
    scanf("%f", &p.price);
    printf("Quantity: ");
    scanf("%d", &p.qty);

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
    printf("✔ Product added successfully\n");
}

void viewProducts() {
    FILE *fp = fopen("products.dat", "rb");
    Product p;

    if (!fp) {
        printf("No products available\n");
        return;
    }

    printf("\nID  Name  Price  Qty\n");
    while (fread(&p, sizeof(p), 1, fp)) {
        printf("%d  %s  %.2f  %d\n",
               p.id, p.name, p.price, p.qty);
    }
    fclose(fp);
}

int findProduct(Product *p, int id, long *pos) {
    FILE *fp = fopen("products.dat", "rb");
    long index = 0;

    while (fread(p, sizeof(*p), 1, fp)) {
        if (p->id == id) {
            *pos = index;
            fclose(fp);
            return 1;
        }
        index++;
    }
    fclose(fp);
    return 0;
}

void updateProduct() {
    FILE *fp = fopen("products.dat", "rb+");
    Product p;
    int id;
    long pos;

    printf("Enter product ID to update: ");
    scanf("%d", &id);

    if (!findProduct(&p, id, &pos)) {
        printf("❌ Product not found\n");
        fclose(fp);
        return;
    }

    printf("New Price: ");
    scanf("%f", &p.price);
    printf("New Quantity: ");
    scanf("%d", &p.qty);

    fseek(fp, pos * sizeof(p), SEEK_SET);
    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);

    printf("✔ Product updated\n");
}

void deleteProduct() {
    FILE *fp = fopen("products.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    Product p;
    int id;

    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id != id)
            fwrite(&p, sizeof(p), 1, temp);
    }

    fclose(fp);
    fclose(temp);
    remove("products.dat");
    rename("temp.dat", "products.dat");

    printf("✔ Product deleted\n");
}

/* ================= BILLING ================= */
void createBill() {
    FILE *fp = fopen("products.dat", "rb+");
    FILE *fs = fopen("sales.dat", "ab");
    Product p;
    Sale s;
    int id, qty;
    float billTotal = 0;
    int billNo = rand() % 10000;

    currentDate(s.date);
    printf("Bill No: %d | Date: %s\n", billNo, s.date);

    while (1) {
        printf("\nEnter Product ID (0 to finish): ");
        scanf("%d", &id);
        if (id == 0) break;

        rewind(fp);
        while (fread(&p, sizeof(p), 1, fp)) {
            if (p.id == id) {
                printf("Enter Quantity: ");
                scanf("%d", &qty);

                if (qty > p.qty) {
                    printf("❌ Not enough stock\n");
                    break;
                }

                p.qty -= qty;
                fseek(fp, -sizeof(p), SEEK_CUR);
                fwrite(&p, sizeof(p), 1, fp);

                strcpy(s.productName, p.name);
                s.quantity = qty;
                s.total = qty * p.price;
                s.billNo = billNo;

                fwrite(&s, sizeof(s), 1, fs);

                billTotal += s.total;
                printf("Added: %s x%d = %.2f\n",
                       p.name, qty, s.total);
                break;
            }
        }
    }

    fclose(fp);
    fclose(fs);

    printf("\n🧾 TOTAL BILL AMOUNT: %.2f\n", billTotal);
}

/* ================= REPORTS ================= */
void totalRevenue() {
    FILE *fp = fopen("sales.dat", "rb");
    Sale s;
    float sum = 0;

    while (fp && fread(&s, sizeof(s), 1, fp))
        sum += s.total;

    if (fp) fclose(fp);
    printf("💰 Total Revenue: %.2f\n", sum);
}

/* ================= MENUS ================= */
void adminMenu() {
    int ch;
    while (1) {
        printf("\n--- ADMIN MENU ---\n");
        printf("1.Add Product\n2.View Products\n3.Update Product\n4.Delete Product\n5.Revenue Report\n6.Back\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: totalRevenue(); break;
            case 6: return;
        }
    }
}

void cashierMenu() {
    int ch;
    while (1) {
        printf("\n--- CASHIER MENU ---\n");
        printf("1.View Products\n2.Create Bill\n3.Back\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: viewProducts(); break;
            case 2: createBill(); break;
            case 3: return;
        }
    }
}

/* ================= MAIN ================= */
int main() {
    srand(time(NULL));
    int ch;

    while (1) {
        printf("\n=== SUPERMARKET MANAGEMENT SYSTEM ===\n");
        printf("1.Admin Login\n2.Cashier\n3.Exit\n");
        scanf("%d", &ch);

        if (ch == 1) {
            if (adminLogin())
                adminMenu();
            else
                printf("❌ Invalid login\n");
        } else if (ch == 2) {
            cashierMenu();
        } else {
            exit(0);
        }
    }
}