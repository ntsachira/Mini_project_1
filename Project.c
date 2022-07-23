#include <stdio.h>
#include <string.h>

int counter1,counter2,temp2;    //global variables
float temp1[20], tHours[20];
/* counter1 & counter2 are used to count iterations in loops
 * temp2 used to hold integer data temporarily
 * temp1[] is a float array used to hold float data temporarily
 * tHours[] is a float array used to hold total hours to cover the workload of each subject
 */

int main()
{
    printf("=======================================================================================");
    printf("\n\t\t\tWelcome to the study plan generator");
    printf("\n=======================================================================================");

    int modTotal;   //holds the number of modules

    printf("\n\n Enter the number of modules you wish to include  : ");
    scanf("%d",&modTotal);
    divider();

    char mods[modTotal][30];    //array of strings use to record modules

    recorder(&mods[0], modTotal); //calling the recorder function

    ranker(&tHours[0],&mods[0], modTotal); //calling the ranker function


    return 0;
}


void divider()
{
    printf("\n_______________________________________________________________________________________\n");
}


float sleepCheck(int n)
{
    if(temp1[n]>6)
    {
        printf("\n*****************************************ALERT!*****************************************");
        printf("\n\nYOU ARE SLEEPING TOO MUCH! Do you wish to reduce sleeping? [Y/N] : ");
        char c;
        scanf("%s",&c);

        if(c == 'y'||c == 'Y')
        {
            printf("\nEnter your new sleeping time (in hours)\t: ");
            scanf("%f",&temp1[n+1]);

            temp1[15]=temp1[n+1]*60;   //temp1[15] = new sleeping time in minutes

            temp1[n+2]=temp1[n]-temp1[n+1];   //extra time obtained from sleep

            sleepCheck(n+1);   //recursion
        }
    }

    return temp1[n+2];
}


int prasent(int total)
{
    int new_days;

    printf("\nEnter your expected number of days to be completed your workload\t\t: ");
    scanf("%d",&new_days);

    int nwHours = (total/new_days) ;

    return nwHours ;
}


void recorder(char *mods, int modTotal)
{
    for(counter1 = 0; counter1 < modTotal; counter1++)
    {
        printf("\n\n Enter subject name (**Do not use any spaces**)   : ");
        scanf("%s",mods);

        printf("\n > Enter the number of lecture recordings in %-23s: ",mods);
        scanf("%f",&temp1[0]);

        printf("\n > Enter the average length(in hours) of a recording in %-12s: ",mods);
        scanf("%f",&temp1[1]);

        printf("\n > Enter the total number of pages of lecture notes in %-13s: ",mods);
        scanf("%f",&temp1[2]);

        printf("\n > Enter the average time you need to read 10 pages(in minutes)     : ");
        scanf("%f",&temp1[3]);
        temp1[3]/=60;   //converted to hours

        tHours[counter1]= (temp1[0]*temp1[1])+(temp1[2]*temp1[3]) ;

        temp1[4]+= tHours[counter1]; //temp1[4] = sum of the total hours per module

        divider();
        mods+=30;
    }
    printf("\n\nEnter the average number of hours you free for study in a normal day (in hours)\t: ");
    scanf("%f",&temp1[11]);

    divider();

    printf("\n\nEnter your average sleeping time per day (in hours)\t: ");
    scanf("%f",&temp1[10]);

    temp1[10] = sleepCheck(10);   //calling sleep check function

    temp1[12]= temp1[4]/(temp1[11]+temp1[10]);      //temp1[12] = estimated number of days

    temp2 = (int)temp1[12]; //integer casting

    printf("\n\n-----------------------------------------------------------------------------------------");
    if(temp2 == temp1[12])
    {
        printf("\n\t\tESTIMATED TIME DURATION TO COMPLETE YOUR WORKLOAD : %d DAYS",temp2);
    }
    else
    {
        printf("\n\t\tESTIMATED TIME DURATION TO COMPLETE YOUR WORKLOAD : %d DAYS",++temp2);
    }
    printf("\n-----------------------------------------------------------------------------------------");

    printf("\n\nPlease wait...");

    system("PAUSE");    //hold the execution temporary until any key is pressed

    char check;
    label1:
    printf("\n\nDo you need to customize the time duration(Y/N) :");
    scanf("%s",&check);

    if(check == 'y'||check == 'Y')
    {label2:
        temp2=(int)temp1[4]*60; //converting to minutes

        int nH = prasent(temp2);

        if(nH<(18*60))
        {
            printf("\n-----------------------------------------------------------------------------------------");
            printf("\n\t\t\tYOU HAVE TO WORK %d HOURS AND %d MINUTES PER DAY",nH/60,nH%60);
            printf("\n-----------------------------------------------------------------------------------------");
            goto label1;
        }
        else
        {
            printf("\n*****************************************ALERT!*****************************************\n");
            printf("\n***YOUR REQUEST EXCEEDS THE DAILY LIMIT. PLEASE TRY A HIGHER NUMBER OF DAYS***\n\n");
            goto label2;
        }

    }
    else
    {   printf("\n\nYour request is being processed. please wait...");
        system("PAUSE");
        divider();
        printf("\nNOW YOU CAN FOLLOW THE STUDY PLAN BELOW");
        divider();
    }
}


void ranker(float *ptr,char *mods, int modCount)
{
    for(counter1 = 1; counter1 < modCount; counter1++)
    {
        for(counter2 = 1; counter2 < modCount; counter2++)
        {
            if(*ptr < *(ptr+1))
            {
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


