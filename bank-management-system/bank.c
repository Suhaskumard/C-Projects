#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Trim trailing newline from fgets
void trim_newline(char *str) {
    str[strcspn(str, "\n")] = 0;
}

// Validate account number (positive integer)
int is_valid_accno(int accno) {
    return accno > 0;
}

// Validate amount (positive float)
int is_valid_amount(float amount) {
    return amount > 0;
}

// Check if account exists and PIN matches
int find_account(int accno, int pin, struct Account *account) {
    for (int i = 0; i < 100; i++) {
        if (acc[i].accNo == accno && acc[i].pin == pin) {
            *account = acc[i];
            return i;
        }
    }
    return -1;
}

// Check if account number already exists
int account_exists(int accno) {
    for (int i = 0; i < 100; i++) {
        if (acc[i].accNo == accno) {
            return 1;
        }
    }
    return 0;
}

// Safe name input
void get_valid_name(char *name) {
    printf("Enter Name: ");
    fgets(name, 49, stdin);
    trim_newline(name);
}

struct Account {
    int accNo;
    int pin;
    char name[50];
    float balance;
};

struct Account acc[100];
int count = 0;

// Create Account
void createAccount() {
    if (count >= 100) {
        printf("\n❌ Maximum accounts reached (100)!\n");
        return;
    }

    int accno, pin;
    char name[50];

    do {
        printf("\nEnter Account Number: ");
        scanf("%d", &accno);
        if (!is_valid_accno(accno)) {
            printf("❌ Invalid account number (must be positive)!\n");
        } else if (account_exists(accno)) {
            printf("❌ Account number already exists!\n");
        }
    } while (!is_valid_accno(accno) || account_exists(accno));

    get_valid_name(name);  // Safe input

    printf("Enter 4-digit PIN: ");
    scanf("%d", &pin);

    acc[count].accNo = accno;
    strcpy(acc[count].name, name);
    acc[count].pin = pin;
    acc[count].balance = 0.0;  // Start with zero, deposit separately

    count++;
    printf("\n✅ Account Created Successfully!\n");
}

// Deposit Money
void deposit() {
    int accno, pin, idx;
    float amount;
    struct Account found_acc;

    printf("\nEnter Account Number: ");
    scanf("%d", &accno);

    printf("Enter PIN: ");
    scanf("%d", &pin);

    idx = find_account(accno, pin, &found_acc);
    if (idx == -1) {
        printf("❌ Invalid Account or PIN!\n");
        return;
    }

    do {
        printf("Enter Amount to Deposit: ");
        scanf("%f", &amount);
        if (!is_valid_amount(amount)) {
            printf("❌ Invalid amount (must be positive)!\n");
        }
    } while (!is_valid_amount(amount));

    acc[idx].balance += amount;
    printf("✅ Deposit Successful! New Balance: %.2f\n", acc[idx].balance);
}

// Withdraw Money
void withdraw() {
    int accno, pin, idx;
    float amount;
    struct Account found_acc;

    printf("\nEnter Account Number: ");
    scanf("%d", &accno);

    printf("Enter PIN: ");
    scanf("%d", &pin);

    idx = find_account(accno, pin, &found_acc);
    if (idx == -1) {
        printf("❌ Invalid Account or PIN!\n");
        return;
    }

    do {
        printf("Enter Amount to Withdraw: ");
        scanf("%f", &amount);
        if (!is_valid_amount(amount)) {
            printf("❌ Invalid amount (must be positive)!\n");
        } else if (amount > acc[idx].balance) {
            printf("❌ Insufficient Balance: %.2f\n", acc[idx].balance);
        }
    } while (!is_valid_amount(amount) || amount > acc[idx].balance);

    acc[idx].balance -= amount;
    printf("✅ Withdrawal Successful! Remaining Balance: %.2f\n", acc[idx].balance);
}

// Check Balance
void checkBalance() {
    int accno, pin, idx;
    struct Account found_acc;

    printf("\nEnter Account Number: ");
    scanf("%d", &accno);

    printf("Enter PIN: ");
    scanf("%d", &pin);

    idx = find_account(accno, pin, &found_acc);
    if (idx == -1) {
        printf("❌ Invalid Account or PIN!\n");
        return;
    }

    printf("\n👤 Name: %s", found_acc.name);
    printf("\n💰 Balance: %.2f\n", found_acc.balance);
}

// Display All Accounts (Admin view - no auth for simplicity, consider password later)
void displayAll() {
    printf("\n--- All Accounts ---\n");

    if (count == 0) {
        printf("No accounts found.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nAccount No: %d", acc[i].accNo);
        printf("\nName: %s", acc[i].name);
        printf("\nBalance: %.2f", acc[i].balance);
        printf("\n" + (i < count-1 ? "────────────" : ""));
    }
}

// Main Function
int main() {
    int choice;

    printf("🔐 Welcome to Secure Banking System!\n");

    while (1) {
        printf("\n\n===== BANKING SYSTEM =====");
        printf("\n1. Create Account");
        printf("\n2. Deposit");
        printf("\n3. Withdraw");
        printf("\n4. Check Balance");
        printf("\n5. Display All Accounts");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');  // Clear bad input
            printf("❌ Invalid input! Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: displayAll(); break;
            case 6: printf("\n👋 Thank you for using Banking System!\n"); return 0;
            default: printf("❌ Invalid Choice! Please select 1-6.\n");
        }
    }

    return 0;
}
