#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Account {
    int accNo;
    int pin;
    char name[50];
    float balance;
};

struct Account acc[MAX];
int count = 0;

// Remove newline from fgets
void trim_newline(char *str) {
    str[strcspn(str, "\n")] = 0;
}

// Clear input buffer
void clear_input() {
    while (getchar() != '\n');
}

// Validate account number
int is_valid_accno(int accno) {
    return accno > 0;
}

// Validate amount
int is_valid_amount(float amount) {
    return amount > 0;
}

// Check if account exists
int account_exists(int accno) {
    for (int i = 0; i < count; i++) {
        if (acc[i].accNo == accno) {
            return 1;
        }
    }
    return 0;
}

// Find account with PIN
int find_account(int accno, int pin) {
    for (int i = 0; i < count; i++) {
        if (acc[i].accNo == accno && acc[i].pin == pin) {
            return i;
        }
    }
    return -1;
}

// Safe name input
void get_valid_name(char *name) {
    clear_input();
    printf("Enter Name: ");
    fgets(name, 50, stdin);
    trim_newline(name);
}

// Create Account
void createAccount() {
    if (count >= MAX) {
        printf("\n❌ Maximum accounts reached!\n");
        return;
    }

    int accno, pin;

    do {
        printf("\nEnter Account Number: ");
        scanf("%d", &accno);

        if (!is_valid_accno(accno)) {
            printf("❌ Must be positive!\n");
        } else if (account_exists(accno)) {
            printf("❌ Account already exists!\n");
        }
    } while (!is_valid_accno(accno) || account_exists(accno));

    get_valid_name(acc[count].name);

    printf("Enter 4-digit PIN: ");
    scanf("%d", &pin);

    acc[count].accNo = accno;
    acc[count].pin = pin;
    acc[count].balance = 0;

    count++;

    printf("✅ Account Created!\n");
}

// Deposit
void deposit() {
    int accno, pin, idx;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accno);

    printf("Enter PIN: ");
    scanf("%d", &pin);

    idx = find_account(accno, pin);

    if (idx == -1) {
        printf("❌ Invalid Account or PIN!\n");
        return;
    }

    do {
        printf("Enter Amount: ");
        scanf("%f", &amount);

        if (!is_valid_amount(amount)) {
            printf("❌ Invalid amount!\n");
        }

    } while (!is_valid_amount(amount));

    acc[idx].balance += amount;

    printf("✅ Deposited! Balance: %.2f\n", acc[idx].balance);
}

// Withdraw
void withdraw() {
    int accno, pin, idx;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accno);

    printf("Enter PIN: ");
    scanf("%d", &pin);

    idx = find_account(accno, pin);

    if (idx == -1) {
        printf("❌ Invalid Account or PIN!\n");
        return;
    }

    do {
        printf("Enter Amount: ");
        scanf("%f", &amount);

        if (!is_valid_amount(amount)) {
            printf("❌ Invalid amount!\n");
        } else if (amount > acc[idx].balance) {
            printf("❌ Insufficient balance!\n");
        }

    } while (!is_valid_amount(amount) || amount > acc[idx].balance);

    acc[idx].balance -= amount;

    printf("✅ Withdrawn! Balance: %.2f\n", acc[idx].balance);
}

// Check Balance
void checkBalance() {
    int accno, pin, idx;

    printf("\nEnter Account Number: ");
    scanf("%d", &accno);

    printf("Enter PIN: ");
    scanf("%d", &pin);

    idx = find_account(accno, pin);

    if (idx == -1) {
        printf("❌ Invalid Account or PIN!\n");
        return;
    }

    printf("\n👤 Name: %s", acc[idx].name);
    printf("\n💰 Balance: %.2f\n", acc[idx].balance);
}

// Display all accounts
void displayAll() {
    if (count == 0) {
        printf("\nNo accounts found.\n");
        return;
    }

    printf("\n--- All Accounts ---\n");

    for (int i = 0; i < count; i++) {
        printf("\nAccount No: %d", acc[i].accNo);
        printf("\nName: %s", acc[i].name);
        printf("\nBalance: %.2f\n", acc[i].balance);

        if (i < count - 1)
            printf("----------------------\n");
    }
}

// Main
int main() {
    int choice;

    printf("🔐 Welcome to Secure Banking System\n");

    while (1) {
        printf("\n\n===== MENU =====");
        printf("\n1. Create Account");
        printf("\n2. Deposit");
        printf("\n3. Withdraw");
        printf("\n4. Check Balance");
        printf("\n5. Display All");
        printf("\n6. Exit");
        printf("\nEnter choice: ");

        if (scanf("%d", &choice) != 1) {
            clear_input();
            printf("❌ Invalid input!\n");
            continue;
        }

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: displayAll(); break;
            case 6: printf("👋 Goodbye!\n"); return 0;
            default: printf("❌ Invalid choice!\n");
        }
    }
}