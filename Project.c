#include <stdio.h>
#include <string.h>

int counter1,counter2,temp2,days,tabCount=6;    //global variables
float temp1[20], tHours[20],asH[20],timeCount=0;
/* counter1 & counter2 are used to count iterations in loops
 * temp2 used to hold integer data temporarily
 * temp1[] is a float array used to hold float data temporarily
 * tHours[] is a float array used to hold total hours to cover the workload of each subject
 */

int main() {
    divider(1);

    printf("\n");
    printTabs(tabCount+3);
    printf("WELCOME TO THE STUDY PLAN GENERATOR\n");

    divider(1);

    int modTotal;   //holds the number of modules

    printf("\n\n ");
    printTabs(tabCount);
    printf("Enter the number of modules you wish to include  : ");

    scanf("%d",&modTotal);
    divider(0);

    char mods[modTotal][30];    //array of strings use to record modules

    recorder(&mods[0], modTotal); //calling the recorder function

    ranker(&tHours[0],&mods[0], modTotal); //calling the ranker function


    //processing the study plan
    for(counter2=0; counter2<modTotal; counter2++) {
        if(counter2<(modTotal/2)) {
            asH[counter2]=2.5;
        } else asH[counter2]=1.5;
    }

    counter1=0;
    divider(2);

    printf("\n%8s %d\t\|","Day",++counter1);

    for(counter2=0; counter2<=modTotal; counter2++) {
        if(counter2==modTotal) {
            counter2=0;
        }

        if(temp1[11]==timeCount) {
            divider(2);
            timeCount=0;
            printf("\n%8s %d\t\|","Day",++counter1);
        }

        if(tHours[counter2]>1) {

            if(temp1[11]-timeCount<asH[counter2]) {   //day filler
                if(tHours[counter2]<asH[counter2]) {
                    goto label4;
                }

                printf("%15s   -   %.1fH\t|",mods[counter2],(temp1[11]-timeCount));
                timeCount=temp1[11];
                tHours[counter2]-=(temp1[11]-timeCount);

            } else {
                if(tHours[counter2]>=2.5) {
                    printf("%15s   -   %.1fH\t|",mods[counter2],asH[counter2]);
                    timeCount+=asH[counter2];
                    tHours[counter2]-=asH[counter2];
                } else {
label4:
                    printf("%15s   -   %.1fH\t|",mods[counter2],tHours[counter2]);
                    timeCount+=tHours[counter2];
                    tHours[counter2]=0;
                }
            }
        }

        if(tHours[0]==0&&tHours[1]==0&&tHours[2]==0&&tHours[3]==0||counter1==days) {
            break;
        }
    }

    divider(2);

    return 0;
}


void printTabs(int tab) {
    for(int t=0; t<tab; t++) {
        printf("\t");
    }
}


void divider(int lineNum) {
    int x;
    switch (lineNum) {
    case 1:
        printTabs(tabCount);
        for(x=0; x<41; x++) {
            printf("==");
        }
        break;

    case 2:
        printf("\n");
        for(x=0; x<8; x++) {
            printf("_________________________");
        }
        printf("\n");
        break;

    case 3:
        printf("\n");
        printTabs(tabCount);
        for(x=0; x<20; x++) {
            printf("**");
        }
        printf("~ALERT!~");
        for(x=0; x<20; x++) {
            printf("**");
        }
        break;

    case 4:
        printf("\n");
        printTabs(tabCount);
        for(x=0; x<18; x++) {
            printf("**");
        }
        printf("~INVALID ENTRY!~");
        for(x=0; x<18; x++) {
            printf("**");
        }
        break;

    case 5:
        printf("\n");
        printTabs(tabCount);
        for(x=0; x<41; x++) {
            printf("--");
        }
        break;

    default:
        printf("\n");
        printTabs(tabCount);
        for(x=0; x<41; x++) {
            printf("__");
        }
        printf("\n");
    }
}


float sleepCheck(int n) {
    if(temp1[n]>6) {
        divider(3);

        printf("\n\n");
        printTabs(tabCount);
        printf("YOU ARE SLEEPING TOO MUCH! Do you wish to reduce sleeping? [Y/N] : ");

        char c;
label3:
        scanf("%s",&c);

        switch (c) {
        case 'Y':
        case 'y':
            printf("\n");
            printTabs(tabCount);
            printf("Enter your new sleeping time (in hours)\t: ");

            scanf("%f",&temp1[n+1]);

            temp1[15]=temp1[n+1]*60;   //temp1[15] = new sleeping time in minutes

            temp1[n+2]=temp1[n]-temp1[n+1];   //extra time obtained from sleep

            sleepCheck(n+1);   //recursion
            break;

        case 'N':
        case 'n':
            break;

        default:
            divider(4);

            printf("\n\n");
            printTabs(tabCount);
            printf("Do you wish to reduce sleeping? [Y/N] : ");

            goto label3;
        }
    }

    return temp1[n+2];
}


int customDays(int total) { //total = total number of hours to complete the work in minutes

    printf("\n");
    printTabs(tabCount);
    printf("Enter your expected number of days to be completed your workload\t\t: ");

    scanf("%d",&days);  //days = number of days user wanted

    return (total/days) ;
}


void recorder(char *mods, int modTotal) {
    for(counter1 = 0; counter1 < modTotal; counter1++) {

        printf("\n\n ");
        printTabs(tabCount);
        printf("Enter subject name (**Do_not_use_any_spaces**)   : ");

        scanf("%s",mods);

        printf("\n ");
        printTabs(tabCount);
        printf("> Enter the number of lecture recordings in %-23s: ",mods);

        scanf("%f",&temp1[0]);

        printf("\n ");
        printTabs(tabCount);
        printf("> Enter the average length(in hours) of a recording in %-12s: ",mods);

        scanf("%f",&temp1[1]);

        printf("\n ");
        printTabs(tabCount);
        printf("> Enter the total number of pages of lecture notes in %-13s: ",mods);

        scanf("%f",&temp1[2]);

        printf("\n ");
        printTabs(tabCount);
        printf("> Enter the average time you need to study 10 pages(in minutes)    : ");

        scanf("%f",&temp1[3]);
        temp1[3]/=600;   //converted to hours

        tHours[counter1]= (temp1[0]*(temp1[1]+1))+(temp1[2]*temp1[3]) ;  //added one hour extra

        temp1[4]+= tHours[counter1]; //temp1[4] = sum of the total hours per module

        divider(0);
        mods+=30;
    }
    printf("\n\n");
    printTabs(tabCount);
    printf("Enter the average number of hours you free for study in a normal day (in hours)\t: ");

    scanf("%f",&temp1[11]);

    divider(0);

    printf("\n\n");
    printTabs(tabCount);
    printf("Enter your average sleeping time per day (in hours)\t: ");

    scanf("%f",&temp1[10]);

    temp1[10] = sleepCheck(10);   //calling sleep check function

    temp1[12]= temp1[4]/(temp1[11]+temp1[10]);      //temp1[12] = estimated number of days

    temp2 = (int)temp1[12]; //integer casting

    divider(5);
    if(temp2 == temp1[12]) {
        printf("\n");
        printTabs(tabCount+2);
        printf("ESTIMATED TIME DURATION TO COMPLETE YOUR WORKLOAD : %d DAYS",temp2);

    } else {
        printf("\n");
        printTabs(tabCount+2);
        printf("ESTIMATED TIME DURATION TO COMPLETE YOUR WORKLOAD : %d DAYS",++temp2);
    }

    days=temp2;
    divider(5);

    printf("\n\n");
    printTabs(tabCount);
    printf("Please wait...");

    system("PAUSE");    //hold the execution temporary until any key is pressed

    char check;
label1:
    printf("\n\n");
    printTabs(tabCount);
    printf("Do you need to customize the time duration(Y/N) :");

    scanf("%s",&check);

    switch (check) {
    case 'Y':
    case 'y':
label2:
        temp2 = customDays(temp1[4]*60);    //nH - new working time to reach the target

        if(temp2<(18*60)) { //6 hours - Allocated for essential daily chores
            divider(5);

            printf("\n");
            printTabs(tabCount+3);
            printf("YOU HAVE TO WORK %d HOURS AND %d MINUTES PER DAY",temp2/60,temp2%60);

            divider(5);
            temp1[11]=temp2/60;
            goto label1;

        } else {
            divider(3);

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

        divider(0);

        printf("\n");
        printTabs(tabCount+2);
        printf("NOW YOU CAN FOLLOW THE STUDY PLAN BELOW");

        divider(0);
        break;

    default:
        divider(4);
        goto label1;
    }
}


void ranker(float *ptr,char *mods, int modCount) {
    for(counter1 = 1; counter1 < modCount; counter1++) {
        for(counter2 = 1; counter2 < modCount; counter2++) {
            if(*ptr < *(ptr+1)) {
                int c;

                c = *ptr;
                *ptr = *(ptr+1);
                *(ptr+1) = c;

                c = *mods;
                *mods = *(mods+1);
                *(mods+1) = c;
            }
            ptr++;
            mods+=20;
        }
        ptr = ptr - (modCount-1);
        mods = mods - ((modCount-1)*20);
    }
}


