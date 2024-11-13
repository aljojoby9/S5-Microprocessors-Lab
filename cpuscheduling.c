#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int ch;
    while (1) {
        printf("Enter your choice : 1)fcfs\t2)sjf\t3)priority\t4)round_robin\t5)exit : ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: {
                int p[30], bt[30], tat[30], wt[30], tot_tat = 0, tot_wt = 0, i, n;
                printf("Enter the number of processes : ");
                scanf("%d", &n);

                for (i = 0; i < n; i++) {
                    printf("Enter the burst time of process %d : ", i + 1);
                    scanf("%d", &bt[i]);
                    p[i] = i;
                }

                printf("\nFCFS Scheduling\n");
                for (i = 0; i < n; i++) {
                    tat[i] = (i == 0) ? bt[i] : tat[i - 1] + bt[i];
                    tot_tat += tat[i];
                }

                wt[0] = 0;
                for (i = 1; i < n; i++) {
                    wt[i] = wt[i - 1] + bt[i - 1];
                    tot_wt += wt[i];
                }

                printf("\nPROCESS\tBURST TIME\tTURNAROUND TIME\tWAITING TIME\n");
                for (i = 0; i < n; i++) {
                    printf("Process[%d]\t%d\t\t%d\t\t%d\n", p[i] + 1, bt[i], tat[i], wt[i]);
                }

                printf("\nTotal TAT = %d, Average TAT = %.2f\n", tot_tat, (float)tot_tat / n);
                printf("Total WT = %d, Average WT = %.2f\n", tot_wt, (float)tot_wt / n);
                break;
            }

            case 2: {
                int p[30], bt[30], tat[30], wt[30], tot_tat = 0, tot_wt = 0, i, n, j;
                printf("Enter the number of processes : ");
                scanf("%d", &n);

                for (i = 0; i < n; i++) {
                    printf("Enter the burst time of process %d : ", i + 1);
                    scanf("%d", &bt[i]);
                    p[i] = i;
                }

                for (i = 0; i < n; i++) {
                    for (j = i + 1; j < n; j++) {
                        if (bt[i] > bt[j]) {
                            swap(&bt[i], &bt[j]);
                            swap(&p[i], &p[j]);
                        }
                    }
                }

                printf("\nSJF Scheduling\n");
                for (i = 0; i < n; i++) {
                    tat[i] = (i == 0) ? bt[i] : tat[i - 1] + bt[i];
                    tot_tat += tat[i];
                }

                wt[0] = 0;
                for (i = 1; i < n; i++) {
                    wt[i] = wt[i - 1] + bt[i - 1];
                    tot_wt += wt[i];
                }

                printf("\nPROCESS\tBURST TIME\tTURNAROUND TIME\tWAITING TIME\n");
                for (i = 0; i < n; i++) {
                    printf("Process[%d]\t%d\t\t%d\t\t%d\n", p[i] + 1, bt[i], tat[i], wt[i]);
                }

                printf("\nTotal TAT = %d, Average TAT = %.2f\n", tot_tat, (float)tot_tat / n);
                printf("Total WT = %d, Average WT = %.2f\n", tot_wt, (float)tot_wt / n);
                break;
            }

            case 3: {
                int pr[30], p[30], bt[30], tat[30], wt[30], i, n, j, tot_tat = 0, tot_wt = 0;

                printf("Enter the number of processes : ");
                scanf("%d", &n);

                for (i = 0; i < n; i++) {
                    printf("Enter the burst time and priority of process %d : ", i + 1);
                    scanf("%d %d", &bt[i], &pr[i]);
                    p[i] = i;
                }

                for (i = 0; i < n; i++) {
                    for (j = i + 1; j < n; j++) {
                        if (pr[i] > pr[j]) {
                            swap(&pr[i], &pr[j]);
                            swap(&bt[i], &bt[j]);
                            swap(&p[i], &p[j]);
                        }
                    }
                }

                printf("\nPriority Scheduling\n");
                for (i = 0; i < n; i++) {
                    tat[i] = (i == 0) ? bt[i] : tat[i - 1] + bt[i];
                    tot_tat += tat[i];
                }

                wt[0] = 0;
                for (i = 1; i < n; i++) {
                    wt[i] = wt[i - 1] + bt[i - 1];
                    tot_wt += wt[i];
                }

                printf("\nPROCESS\tBURST TIME\tTAT\tWT\tPriority\n");
                for (i = 0; i < n; i++) {
                    printf("Process[%d]\t%d\t\t%d\t%d\t%d\n", p[i] + 1, bt[i], tat[i], wt[i], pr[i]);
                }

                printf("\nTotal TAT = %d, Average TAT = %.2f\n", tot_tat, (float)tot_tat / n);
                printf("Total WT = %d, Average WT = %.2f\n", tot_wt, (float)tot_wt / n);
                break;
            }

            case 4: {
                int limit, i, time_quantum, total = 0, x, counter = 0,temp2;
                int bt[100], temp[100], tat[100], wt[100];
                int gantt[100], gi = 0,id[100],l=0;
                int total_tat = 0, total_wt = 0;

                printf("Enter the number of processes: ");
                scanf("%d", &limit);
                x = limit;

                for (i = 0; i < limit; i++) {
                    printf("Enter the burst time of process %d: ", i + 1);
                    scanf("%d", &bt[i]);
                    temp[i] = bt[i];
                }

                printf("Enter the time quantum: ");
                scanf("%d", &time_quantum);

                while (x != 0) {
                    for (i = 0; i < limit; i++) {
                        if (temp[i] > 0) {
                            if (temp[i] <= time_quantum) {
                                total += temp[i];
                                temp[i] = 0;
                                id[l++]=temp[i];
                                counter = 1;
                                gantt[gi++] = i;
                            } else {
                                temp[i] -= time_quantum;
                                total += time_quantum;
                                id[l++]=time_quantum;
                                gantt[gi++] = i;
                            }
                            if (temp[i] == 0 && counter == 1) {
                                x--;
                                tat[i] = total;
                                wt[i] = tat[i] - bt[i];
                                total_tat += tat[i];
                                total_wt += wt[i];
                                counter = 0;
                            }
                        }
                    }
                }

                printf("\nPROCESS\tBURST TIME\tTAT\tWT\n");
                for (i = 0; i < limit; i++) {
                    printf("Process[%d]\t%d\t\t%d\t%d\n", i + 1, bt[i], tat[i], wt[i]);
                }

                printf("\nGantt Chart:\n-------------------------------------------------------------------------------------------\n");
                for (i = 0; i < gi; i++) {
                    printf("P[%d]\t", gantt[i] + 1);
                }printf("\n");
                for (i = 0; i <=l; i++) {
                    printf("%d", temp2);
                    temp2+=id[i];
                }
                printf("\n-------------------------------------------------------------------------------------------\n");

                printf("\nTotal TAT = %d, Average TAT = %.2f\n", total_tat, (float)total_tat / limit);
                printf("Total WT = %d, Average WT = %.2f\n", total_wt, (float)total_wt / limit);
                break;
            }

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Error: Invalid choice. Try again!\n");
                break;
        }
    }
    return 0;
}
