#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ================= CONFIG ================= */
#define ADMIN_USER "admin"

/* ================= STRUCTURES ================= */
typedef struct Bus {
    int busNo;
    char src[20], dest[20];
    float fare;
    int seats;
    struct Bus *next;
} Bus;

typedef struct Booking {
    int ticketID;
    int busNo;
    int seatNo;
    char name[30];
    char datetime[30];
    float paid;
    struct Booking *next;
} Booking;

/* ================= GLOBAL LISTS ================= */
Bus *busHead = NULL;
Booking *bookHead = NULL;

/* ================= UTILITIES ================= */
unsigned long hash(const char *s) {
    unsigned long h = 5381;
    int c;
    while ((c = *s++))
        h = ((h << 5) + h) + c;
    return h;
}

unsigned long ADMIN_HASH;   // computed at runtime

void now(char *buf) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    sprintf(buf, "%02d-%02d-%04d %02d:%02d",
            tm->tm_mday, tm->tm_mon + 1,
            tm->tm_year + 1900,
            tm->tm_hour, tm->tm_min);
}

int genTicketID() {
    return rand() % 90000 + 10000;
}

/* ================= FILE HANDLING ================= */
void loadData() {
    FILE *fb = fopen("buses.dat", "rb");
    FILE *ft = fopen("bookings.dat", "rb");
    Bus b;
    Booking k;

    while (fb && fread(&b, sizeof(b), 1, fb)) {
        Bus *n = malloc(sizeof(Bus));
        *n = b;
        n->next = busHead;
        busHead = n;
    }
    while (ft && fread(&k, sizeof(k), 1, ft)) {
        Booking *n = malloc(sizeof(Booking));
        *n = k;
        n->next = bookHead;
        bookHead = n;
    }
    if (fb) fclose(fb);
    if (ft) fclose(ft);
}

void saveData() {
    FILE *fb = fopen("buses.dat", "wb");
    FILE *ft = fopen("bookings.dat", "wb");

    for (Bus *b = busHead; b; b = b->next)
        fwrite(b, sizeof(Bus), 1, fb);

    for (Booking *k = bookHead; k; k = k->next)
        fwrite(k, sizeof(Booking), 1, ft);

    fclose(fb);
    fclose(ft);
}

/* ================= BUS FUNCTIONS ================= */
Bus* findBus(int no) {
    for (Bus *b = busHead; b; b = b->next)
        if (b->busNo == no) return b;
    return NULL;
}

void addBus() {
    Bus *b = malloc(sizeof(Bus));
    printf("Bus No: "); scanf("%d", &b->busNo);

    if (findBus(b->busNo)) {
        printf("❌ Bus already exists\n");
        free(b);
        return;
    }

    printf("Source: "); scanf("%s", b->src);
    printf("Destination: "); scanf("%s", b->dest);
    printf("Fare: "); scanf("%f", &b->fare);
    printf("Seats: "); scanf("%d", &b->seats);

    b->next = busHead;
    busHead = b;

    printf("✔ Bus added successfully\n");
}

void viewBuses() {
    if (!busHead) {
        printf("No buses available\n");
        return;
    }
    printf("\nBus | Route | Fare | Seats\n");
    for (Bus *b = busHead; b; b = b->next)
        printf("%d | %s-%s | %.2f | %d\n",
               b->busNo, b->src, b->dest, b->fare, b->seats);
}

/* ================= BOOKING FUNCTIONS ================= */
int seatTaken(int busNo, int seat) {
    for (Booking *k = bookHead; k; k = k->next)
        if (k->busNo == busNo && k->seatNo == seat)
            return 1;
    return 0;
}

void bookTicket() {
    int no;
    printf("Bus No: "); scanf("%d", &no);
    Bus *b = findBus(no);

    if (!b) {
        printf("❌ Bus not found\n");
        return;
    }

    Booking *k = malloc(sizeof(Booking));
    printf("Passenger Name: "); scanf("%s", k->name);
    printf("Seat (1-%d): ", b->seats);
    scanf("%d", &k->seatNo);

    if (k->seatNo < 1 || k->seatNo > b->seats || seatTaken(no, k->seatNo)) {
        printf("❌ Invalid or already booked seat\n");
        free(k);
        return;
    }

    k->ticketID = genTicketID();
    k->busNo = no;
    k->paid = b->fare;
    now(k->datetime);
    k->next = bookHead;
    bookHead = k;

    printf("\n🎫 Ticket Booked Successfully\n");
    printf("Ticket ID: %d\nName: %s\nBus: %d\nSeat: %d\nFare: %.2f\nDate: %s\n",
           k->ticketID, k->name, k->busNo, k->seatNo, k->paid, k->datetime);
}

void viewTicket() {
    int id;
    printf("Enter Ticket ID: ");
    scanf("%d", &id);

    for (Booking *k = bookHead; k; k = k->next) {
        if (k->ticketID == id) {
            printf("Ticket ID: %d | %s | Bus %d | Seat %d | %.2f | %s\n",
                   k->ticketID, k->name, k->busNo,
                   k->seatNo, k->paid, k->datetime);
            return;
        }
    }
    printf("❌ Ticket not found\n");
}

void cancelTicket() {
    int id;
    printf("Ticket ID: ");
    scanf("%d", &id);

    Booking **pp = &bookHead;
    while (*pp) {
        if ((*pp)->ticketID == id) {
            Booking *del = *pp;
            *pp = del->next;
            printf("✔ Ticket cancelled. Refund: %.2f\n", del->paid * 0.7);
            free(del);
            return;
        }
        pp = &(*pp)->next;
    }
    printf("❌ Ticket not found\n");
}

/* ================= REPORTS ================= */
void revenue() {
    float sum = 0;
    for (Booking *k = bookHead; k; k = k->next)
        sum += k->paid;
    printf("💰 Total Revenue: %.2f\n", sum);
}

void exportCSV() {
    FILE *f = fopen("bookings.csv", "w");
    fprintf(f, "TicketID,Name,Bus,Seat,Amount,DateTime\n");

    for (Booking *k = bookHead; k; k = k->next)
        fprintf(f, "%d,%s,%d,%d,%.2f,%s\n",
                k->ticketID, k->name, k->busNo,
                k->seatNo, k->paid, k->datetime);

    fclose(f);
    printf("📁 bookings.csv exported\n");
}

/* ================= AUTH ================= */
int adminLogin() {
    char u[20], p[20];
    printf("User: "); scanf("%s", u);
    printf("Pass: "); scanf("%s", p);

    return strcmp(u, ADMIN_USER) == 0 && hash(p) == ADMIN_HASH;
}

/* ================= MAIN ================= */
int main() {
    srand(time(NULL));
    ADMIN_HASH = hash("root");   // ✅ FIXED HERE

    loadData();
    int ch;

    while (1) {
        printf("\n=== BUS MANAGEMENT SYSTEM ===\n");
        printf("1.Admin Login  2.View Buses  3.Book  4.View Ticket\n");
        printf("5.Cancel  6.Revenue  7.Export CSV  8.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (adminLogin()) {
                    int a;
                    printf("Admin Menu: 1.Add Bus 2.View Buses\n");
                    scanf("%d", &a);
                    if (a == 1) addBus();
                    else viewBuses();
                } else {
                    printf("❌ Access denied\n");
                }
                break;
            case 2: viewBuses(); break;
            case 3: bookTicket(); break;
            case 4: viewTicket(); break;
            case 5: cancelTicket(); break;
            case 6: revenue(); break;
            case 7: exportCSV(); break;
            case 8:
                saveData();
                printf("✔ Data saved. Exiting...\n");
                exit(0);
        }
    }
}