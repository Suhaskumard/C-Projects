#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float m1, m2, m3;
    float total, percentage;
    char grade;
};

// Calculate total, percentage, grade
void calculate(struct Student *s) {
    s->total = s->m1 + s->m2 + s->m3;
    s->percentage = s->total / 3;

    if (s->percentage >= 90) s->grade = 'A';
    else if (s->percentage >= 75) s->grade = 'B';
    else if (s->percentage >= 50) s->grade = 'C';
    else s->grade = 'F';
}

// Add Student
void addStudent() {
    FILE *fp = fopen("students.dat", "ab");
    if (fp == NULL) {
        printf("❌ File error!\n");
        return;
    }

    struct Student s;

    printf("\nEnter Roll: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);   // FIXED (allows full name)

    printf("Enter Marks (3 subjects): ");
    scanf("%f %f %f", &s.m1, &s.m2, &s.m3);

    calculate(&s);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("✅ Student added successfully!\n");
}

// Display All Students
void displayAll() {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("⚠️ No records found!\n");
        return;
    }

    struct Student s;

    printf("\n===== STUDENT LIST =====\n");

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("\nRoll: %d\nName: %s\nMarks: %.2f %.2f %.2f\n",
               s.roll, s.name, s.m1, s.m2, s.m3);
        printf("Total: %.2f\nPercentage: %.2f%%\nGrade: %c\n",
               s.total, s.percentage, s.grade);
        printf("--------------------------\n");
    }

    fclose(fp);
}

// Search Student
void searchStudent() {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("⚠️ No records found!\n");
        return;
    }

    struct Student s;
    int roll, found = 0;

    printf("Enter Roll to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("\n✅ Student Found\n");
            printf("Name: %s\nPercentage: %.2f%%\nGrade: %c\n",
                   s.name, s.percentage, s.grade);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("❌ Student not found\n");

    fclose(fp);
}

// Update Student
void updateStudent() {
    FILE *fp = fopen("students.dat", "rb+");
    if (fp == NULL) {
        printf("⚠️ No records found!\n");
        return;
    }

    struct Student s;
    int roll, found = 0;

    printf("Enter Roll to update: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("Enter new marks: ");
            scanf("%f %f %f", &s.m1, &s.m2, &s.m3);

            calculate(&s);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);

            printf("✅ Updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("❌ Student not found\n");

    fclose(fp);
}

// Delete Student
void deleteStudent() {
    FILE *fp = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL) {
        printf("❌ File error!\n");
        return;
    }

    struct Student s;
    int roll, found = 0;

    printf("Enter Roll to delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll != roll) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("🗑️ Deleted successfully!\n");
    else
        printf("❌ Student not found\n");
}

// MAIN
int main() {
    int choice;

    while (1) {
        printf("\n===== STUDENT RESULT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display All\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: 
                printf("👋 Exiting...\n");
                exit(0);
            default: 
                printf("❌ Invalid choice!\n");
        }
    }

    return 0;
}