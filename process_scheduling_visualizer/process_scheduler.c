#include <stdio.h>

struct Process {
    int pid, bt, at, wt, tat;
};

// FCFS Scheduling
void fcfs(struct Process p[], int n) {
    int time = 0;

    printf("\n--- FCFS Scheduling ---\n");

    for(int i = 0; i < n; i++) {
        if(time < p[i].at)
            time = p[i].at;

        p[i].wt = time - p[i].at;
        time += p[i].bt;
        p[i].tat = p[i].wt + p[i].bt;
    }

    printf("PID\tWT\tTAT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\n", p[i].pid, p[i].wt, p[i].tat);
    }
}

// Round Robin Scheduling
void roundRobin(struct Process p[], int n, int quantum) {
    int time = 0, done;
    int rem[n];

    for(int i = 0; i < n; i++)
        rem[i] = p[i].bt;

    printf("\n--- Round Robin Scheduling ---\n");

    do {
        done = 1;
        for(int i = 0; i < n; i++) {
            if(rem[i] > 0) {
                done = 0;

                if(rem[i] > quantum) {
                    time += quantum;
                    rem[i] -= quantum;
                } else {
                    time += rem[i];
                    p[i].wt = time - p[i].bt;
                    rem[i] = 0;
                }
            }
        }
    } while(!done);

    printf("PID\tWT\tTAT\n");
    for(int i = 0; i < n; i++) {
        p[i].tat = p[i].wt + p[i].bt;
        printf("P%d\t%d\t%d\n", p[i].pid, p[i].wt, p[i].tat);
    }
}

int main() {
    int n, choice, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &p[i].bt);

        printf("Enter arrival time for P%d: ", i + 1);
        scanf("%d", &p[i].at);
    }

    printf("\n1. FCFS\n2. Round Robin\nChoose: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            fcfs(p, n);
            break;

        case 2:
            printf("Enter time quantum: ");
            scanf("%d", &quantum);
            roundRobin(p, n, quantum);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}

