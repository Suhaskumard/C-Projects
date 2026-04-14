# Process Scheduling Visualizer

## Overview
This C program implements two CPU scheduling algorithms:
- **FCFS (First Come First Serve)**
- **Round Robin (RR)**

## Features
- Interactive input for number of processes, burst times, arrival times, and time quantum (for RR)
- Calculates and displays **Waiting Time (WT)** and **Turnaround Time (TAT)** for each process
- Console-based visualization of scheduling results

## How to Compile and Run
```bash
gcc process_scheduler.c -o process_scheduler
./process_scheduler
```

## Sample Input/Output
```
Enter number of processes: 3
Enter burst time for P1: 24
Enter arrival time for P1: 0
Enter burst time for P2: 3
Enter arrival time for P2: 0
Enter burst time for P3: 3
Enter arrival time for P3: 0

1. FCFS
2. Round Robin
Choose: 1

--- FCFS Scheduling ---
PID    WT      TAT
P1     0       24
P2     24      27
P3     27      30
```

## Algorithms Implemented
### FCFS
- Non-preemptive scheduling
- Processes execute in order of arrival

### Round Robin
- Preemptive scheduling with time quantum
- Fair CPU time sharing among processes

## Future Enhancements (Potential)
- Gantt chart visualization
- Additional algorithms (SJF, Priority)
- Average waiting/turnaround time calculation

