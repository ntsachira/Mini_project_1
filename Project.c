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
    printf("==================================================================");
    printf("\n\t\tWelcome to the study plan generator");
    printf("\n==================================================================");

    int modTotal;   //holds the number of modules

    printf("\n\nEnter the number of modules you wish to include\t: ");
    scanf("%d",&modTotal);

    char mods[modTotal][30];    //array of strings use to record modules

    recorder(&mods[0], modTotal); //calling the recorder function

    ranker(&tHours[0],&mods[0], modTotal); //calling the ranker function


    return 0;
}


void divider()
{
    printf("____________________________________________________________________\n");
}

float sleepCheck(int n)
{
    if(temp1[n]>6)
    {
        printf("\n*******************************ALERT!*******************************");
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
    printf(" \nEnter a new time duration you wish \t\t: ");
    scanf("%d",&new_days);

    //line();

    int nwHours = (total/new_days) ;
    return nwHours ;
}


void recorder(char *mods, int modTotal)
{
    for(counter1 = 0; counter1 < modTotal; counter1++)
    {
        printf("\n\nEnter subject name (**Do not use any spaces**)  : ");
        scanf("%s",mods);

        printf("\nEnter the number of lecture recordings in %-20s\t: ",mods);
        scanf("%f",&temp1[0]);

        printf("\nEnter the average length(in hours) of a recording in %-20s: ",mods);
        scanf("%f",&temp1[1]);

        printf("\nEnter the total number of pages of lecture notes in %-12s: ",mods);
        scanf("%f",&temp1[2]);

        printf("\nEnter the average time do you need to read 10 pages (in minutes)\t: ");
        scanf("%f",&temp1[3]);
        temp1[3]/=60;   //converted to hours

        tHours[counter1]= (temp1[0]*temp1[1])+(temp1[2]*temp1[3]) ;

        temp1[4]+= tHours[counter1]; //temp1[4] = sum of the total hours per module

        divider();
        mods+=30;
    }
    printf("\n\nEnter the average number of hours you free for study in a normal day (in hours)\t: ");
    scanf("%f",&temp1[11]);

    printf("\n\nEnter your average sleeping time per day (in hours)\t: ");
    scanf("%f",&temp1[10]);


    temp1[10] = sleepCheck(10);   //calling sleep check function



label:
    temp1[12]= temp1[4]/(temp1[11]+temp1[10]);      //temp1[12] = estimated number of days

    temp2 = (int)temp1[12]; //integer casting

    printf("\n\n-----------------------------------------------------------------");
    if(temp2 == temp1[12])
    {
        printf("\nEstimated time duration to complete you workload\t: %d Days",temp2);
    }
    else
    {
        printf("\nEstimated time duration to complete you workload\t: %d Days",++temp2);
    }
    printf("\n-----------------------------------------------------------------");

    printf("\n\nPlease wait...");

    system("PAUSE");    //hold the execution temporary until any key is pressed


    char check;
    printf("\nDo you need to change this estimate time duration(Y/N) :");
    scanf("%s",&check);

    //line();

    if(check == 'y'||check == 'Y')
    {
        temp2=(int)temp1[4]*60;

        int nH = prasent(temp2);
        if(nH< (24*60 -temp1[15]))
        {
            printf("you have to work %dhrs %dmin per day",nH/60,nH%60);

        }
        else
        {
            printf("you cannot reach this time duration \nplease Enter again");
            prasent(temp2);
        }
    }
    else
    {
        printf("You can follow you study plan now\n");
        printf("_________________________________\n");
    }

    /* char c;
     printf("\n\nDo you wish to allocate more time from your sleep to your studies? [Y/N]\t: ");
     scanf("%s",&c);

     if(c == 'y'||c == 'Y')
     {
         temp1[10] += sleepCheck(1);   //function call
         goto label;
     }*/
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


