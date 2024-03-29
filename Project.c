#include <stdio.h>
#include <string.h>

void printDivider(int lineNum);
void printTabs(int tab);
float sleepCheck(int n);
int customDays(int total);
void getUserData(int totalMods);
void sortModules(int modCount);
int printStudyPlan(int totalMods);

int temp2, days, moduleCount = 0, tabCount = 6; // global variables
float temp1[20],  totalHoursPerModule[20], allocatedHours[20], hoursCount = 0, hours;
char modules[15][30];

/* counter1 & counter2 are used to count iterations in loops
 * temp2 used to hold integer data temporarily
 * temp1[] is a float array used to hold float data temporarily
 * tHours[] is a float array used to hold total hours to cover the workload of each subject
 */

int main() {
    printDivider(1);

    printf("\n");
    printTabs(tabCount + 3);
    printf("WELCOME TO THE STUDY PLAN GENERATOR\n");

    printDivider(1);

    int totalMods; // holds the number of modules

    printf("\n\n ");
    printTabs(tabCount);
    printf("Enter the number of modules you wish to include  : ");

    scanf("%d", &totalMods);
    printDivider(0);

    // char modules[totalMods][30];    //array of strings use to record modules

    getUserData(totalMods); // calling the recorder function

    sortModules(totalMods); // calling the sortModules function

    printStudyPlan(totalMods);

    /*processing the study plan
    for(int i=0; i<modTotal; i++) {
        if(i<(modTotal/2)) {
            asH[i]=3;
        } else asH[i]=2;
    }

    int dayCount=0;
    printDivider(2);

    printf("\n%8s %d\t\t|","Day",++dayCount); //day 1

    for(int i=0; i<=modTotal; i++) {    //modtot =3
        if(i==modTotal) {
            i=0;
        }
    float toatalHoursPerDay = temp1[11];

        if(toatalHoursPerDay==timeCount) {
            printDivider(2);
            timeCount=0;
            printf("\n%8s %d\t\t|","Day",++dayCount);
        }

        if(modTotalHours[i]>1) {

            if(toatalHoursPerDay-timeCount<asH[i]) {
                if(modTotalHours[i]<asH[i]) {
                    goto label4;
                }

                printf("%15s   -   %.1fH\t|",modules[i],(toatalHoursPerDay-timeCount));
                timeCount=toatalHoursPerDay;
                modTotalHours[i]-=(toatalHoursPerDay-timeCount);

            } else {
                if(modTotalHours[i]>=3) {
                    printf("%15s   -   %.1fH\t|",modules[i],asH[i]);
                    timeCount+=asH[i];
                    modTotalHours[i]-=asH[i];
                } else {
    label4:
                    printf("%15s   -   %.1fH\t|",modules[i],modTotalHours[i]);
                    timeCount+=modTotalHours[i];
                    modTotalHours[i]=0;
                }
            }
        }

        if(modTotalHours[0]==0&&modTotalHours[1]==0&&modTotalHours[2]==0&&modTotalHours[3]==0||dayCount==days) {
            break;
        }
    }

    printDivider(2);*/

    return 0;
}

int printStudyPlan(int totalMods) {
    int index = 0;
    float toatalHoursPerDay = temp1[11];

    for (int i = 0; i < totalMods; i++) {
        if (i <= (totalMods / 2)) {
            allocatedHours[i] = 3;
        } else
            allocatedHours[i] = 2;
    }

    int day = 1;
label6:
    printf("\nDay %d\t", day);
label2:
    if ((toatalHoursPerDay - hoursCount) >= 2) {

        if ((toatalHoursPerDay - hoursCount) >= allocatedHours[index]) {

            if ((totalHoursPerModule[index] >= allocatedHours[index])) {

                hours = allocatedHours[index];
            } else {
label5:
                hours = totalHoursPerModule[index];
            }
            printf("%s : %.1f\t", modules[index], hours);

            moduleCount++;

            totalHoursPerModule[index] -= hours;

            hoursCount += hours;
label1:
            if (moduleCount == totalMods) {
                // reset

                moduleCount = 0;
                index = 0;
            } else {
                index++;
            }

            if (totalHoursPerModule[index] > 0) {
                goto label2;
            } else {
                if (index == 0) {
label4:
                    if (totalHoursPerModule[index] > 0) {
                        goto label2;
                    } else {
                        if (moduleCount == totalMods) {
                            //return 0;
                            goto label3;
                        } else {
                            moduleCount++;
                            index++;
                            goto label4;
                        }
                    }
                } else {
                    index++;
                    moduleCount++;

                    if (totalHoursPerModule[index] > 0) {
                        goto label2;
                    } else {
                        if (moduleCount == totalMods) {
                            moduleCount = 0;
                            index = 0;
                            goto label4;
                        }
                    }
                }
            }
        } else {
            goto label1;
        }
    } else {
        if ((toatalHoursPerDay - hoursCount) >= totalHoursPerModule[index]) {
            goto label5;
        } else {
            hoursCount = 0;
            day++;
            goto label6;
        }
    }
label3:
    return 0;
}

void printTabs(int tab) {
    for (int t = 0; t < tab; t++) {
        printf("\t");
    }
}

void printDivider(int lineNum) {
    int x;
    switch (lineNum) {
    case 1:
        printTabs(tabCount);
        for (x = 0; x < 41; x++) {
            printf("==");
        }
        break;

    case 2:
        printf("\n");
        for (x = 0; x < 8; x++) {
            printf("_________________________");
        }
        printf("\n");
        break;

    case 3:
        printf("\n");
        printTabs(tabCount);
        for (x = 0; x < 20; x++) {
            printf("**");
        }
        printf("~ALERT!~");
        for (x = 0; x < 20; x++) {
            printf("**");
        }
        break;

    case 4:
        printf("\n");
        printTabs(tabCount);
        for (x = 0; x < 18; x++) {
            printf("**");
        }
        printf("~INVALID ENTRY!~");
        for (x = 0; x < 18; x++) {
            printf("**");
        }
        break;

    case 5:
        printf("\n");
        printTabs(tabCount);
        for (x = 0; x < 41; x++) {
            printf("--");
        }
        break;

    default:
        printf("\n");
        printTabs(tabCount);
        for (x = 0; x < 41; x++) {
            printf("__");
        }
        printf("\n");
    }
}

float sleepCheck(int n) {
    if (temp1[n] > 6) {
        printDivider(3);

        printf("\n\n");
        printTabs(tabCount);
        printf("YOU SLEEP TOO MUCH! Do you wish to reduce sleeping time? [Y/N] : ");

        char c;
label3:
        scanf("%s", &c);

        switch (c) {
        case 'Y':
        case 'y':
            printf("\n");
            printTabs(tabCount);
            printf("Enter your new sleeping time (in hours)\t: ");

            scanf("%f", &temp1[n + 1]);

            temp1[15] = temp1[n + 1] * 60; // temp1[15] = new sleeping time in minutes

            temp1[n + 2] = temp1[n] - temp1[n + 1]; // extra time obtained from sleep

            sleepCheck(n + 1); // recursion
            break;

        case 'N':
        case 'n':
            break;

        default:
            printDivider(4);

            printf("\n\n");
            printTabs(tabCount);
            printf("Do you wish to reduce sleeping time? [Y/N] : ");

            goto label3;
        }
    }

    return temp1[n + 2];
}

int customDays(int total) {
    // total = total number of hours to complete the work in minutes

    printf("\n");
    printTabs(tabCount);
    printf("Enter your expected number of days to be completed your workload\t: ");

    scanf("%d", &days); // days = number of days user wanted

    return (total / days);
}

void getUserData(int totalMods) {
    for (int i = 0; i < totalMods; i++) {

        printf("\n\n ");
        printTabs(tabCount);
        printf("Enter subject name (**Do_not_use_any_spaces**)   : ");

        scanf("%s", modules[i]);

        printf("\n ");
        printTabs(tabCount);
        printf("> Enter the number of lecture recordings in %-23s: ", modules[i]);

        scanf("%f", &temp1[0]);

        printf("\n ");
        printTabs(tabCount);
        printf("> Enter the average length(in hours) of a recording in %-12s: ", modules[i]);

        scanf("%f", &temp1[1]);

        printf("\n ");
        printTabs(tabCount);
        printf("> Enter the total number of pages of lecture notes in %-13s: ", modules[i]);

        scanf("%f", &temp1[2]);

        printf("\n ");
        printTabs(tabCount);
        printf("> Enter the average time you need to study 10 pages(in minutes)    : ");

        scanf("%f", &temp1[3]);
        temp1[3] /= 600; // converted to hours

        totalHoursPerModule[i] = (temp1[0] * (temp1[1] + 1)) + (temp1[2] * temp1[3]); // added one hour extra

        temp1[4] += totalHoursPerModule[i]; // temp1[4] = sum of the total hours of all module

        printDivider(0);
    }
    printf("\n\n");
    printTabs(tabCount);
    printf("Enter the average number of hours , usually you study per day (in hours)\t: ");

    scanf("%f", &temp1[11]);
    

    printDivider(0);

    printf("\n\n");
    printTabs(tabCount);
    printf("Enter your average sleeping time per day (in hours)\t: ");

    scanf("%f", &temp1[10]);

    temp1[10] = sleepCheck(10); // calling sleep check function

    temp1[12] = temp1[4] / (temp1[11] + temp1[10]); // temp1[12] = estimated number of days

    temp2 = (int)temp1[12]; // integer casting

    printDivider(5);
    if (temp2 == temp1[12]) {
        printf("\n");
        printTabs(tabCount + 2);
        printf("ESTIMATED TIME DURATION TO COMPLETE YOUR WORKLOAD : %d DAYS", temp2);
    } else {
        printf("\n");
        printTabs(tabCount + 2);
        printf("ESTIMATED TIME DURATION TO COMPLETE YOUR WORKLOAD : %d DAYS", ++temp2);
    }

    days = temp2;
    printDivider(5);

    printf("\n\n");
    printTabs(tabCount);
    printf("Please wait...");

    system("PAUSE"); // hold the execution temporary until any key is pressed

    char check;
label1:
    printf("\n\n");
    printTabs(tabCount);
    printf("Do you need to customize the time duration(Y/N) :");

    scanf("%s", &check);

    switch (check) {
    case 'Y':
    case 'y':
label2:
        temp2 = customDays(temp1[4] * 60); // nH - new working time to reach the target

        if (temp2 < (18 * 60)) {
            // 6 hours - Allocated for essential daily chores
            printDivider(5);

            printf("\n");
            printTabs(tabCount + 3);
            printf("YOU HAVE TO WORK %d HOURS AND %d MINUTES PER DAY", temp2 / 60, temp2 % 60);

            printDivider(5);
            temp1[11] = temp2 / 60;
            goto label1;
        } else {
            printDivider(3);

            printf("\n\n");
            printTabs(tabCount);
            printf("***YOUR REQUEST EXCEEDS THE DAILY LIMIT. PLEASE TRY A HIGHER NUMBER OF DAYS***\n\n");

            goto label2;
        }
        break;

    case 'N':
    case 'n':
        printf("\n\n");
        printTabs(tabCount);
        printf("Your request is being processed. please wait...");

        system("PAUSE");

        printDivider(0);

        printf("\n");
        printTabs(tabCount + 3);
        printf("NOW YOU CAN FOLLOW THE STUDY PLAN BELOW");

        printDivider(0);
        break;

    default:
        printDivider(4);
        goto label1;
    }
}

void sortModules(int modCount) {
    for (int i = 1; i < modCount; i++) {
        for (int j = 0; j < modCount - 1; j++) {
            if (totalHoursPerModule[j] < totalHoursPerModule[j + 1]) {

                char c[20];
                int C;

                C = totalHoursPerModule[j];
                totalHoursPerModule[j] = totalHoursPerModule[j + 1];
                totalHoursPerModule[j + 1] = C;

                strcpy(c, modules[j]);
                strcpy(modules[j], modules[j + 1]);
                strcpy(modules[j + 1], c);
            }
        }
    }
}
