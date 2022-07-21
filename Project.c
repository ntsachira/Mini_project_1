#include <stdio.h>
#include <string.h>

int counter1,counter2,temp2;          //global variables
float temp1[20], tHours[20];

int main()
{
    printf("==================================================================");
    printf("\n\t\tWelcome to the study plan generator");
    printf("\n==================================================================");

    int modTotal;   //holds the number of modules

    printf("\n\nEnter the number of modules you wish to include\t: ");
    scanf("%d",&modTotal);

    char mods[modTotal][20];    //array of strings use to record modules

    recorder(&mods[0], modTotal); //calling the recorder function

    ranker(&tHours[0],&mods[0], modTotal); //calling the ranker function

    /*  for(counter1=0; counter1<modTotal; counter1++)
     {
         printf("\n\n%s : %.1f\n\n",mods[counter1],tHours[counter1]);
     }*/



    return 0;
}


void divider()
{
    printf("____________________________________________________________________\n");
}

void sleepCheck()
{

    if(temp1[10]>6)
    {
        printf("\n*****************************ALERT!*****************************");
        printf("\n\nYOU ARE SLEEPING TOO MUCH! Do you wish to reduce sleeping? [Y/N] : ");
        char c;
        scanf("%s",&c);

        if(c == 'y'||c == 'Y')
        {
            printf("\nEnter your new sleeping time (in hours)\t: ");
            scanf("%f",&temp1[10]);

            sleepCheck();   //recurssion
        }
    }

}


void recorder(char *mods, int modTotal)
{
    for(counter1 = 0; counter1 < modTotal; counter1++)
    {
        printf("\n\nEnter module %d\t: ",counter1+1);
        scanf("%s",mods);

        printf("\nEnter the number of lecture recordings\t: ");
        scanf("%f",&temp1[0]);

        printf("\nEnter the average length of a recording\t: ");
        scanf("%f",&temp1[1]);

        printf("\nEnter the total number of pages of lecture notes\t: ");
        scanf("%f",&temp1[2]);

        printf("\nEnter the average time do you need to read 10 pages (in hours)\t: ");
        scanf("%f",&temp1[3]);

        tHours[counter1]= (temp1[0]*temp1[1])+(temp1[2]*temp1[3]) ;

        temp1[4]+= tHours[counter1]; //temp1[4] = sum of the total hours per module

        divider();
        mods+=20;
    }



    printf("\n\nEnter your average sleeping time per day (in hours)\t: ");
    scanf("%f",&temp1[10]);

    sleepCheck();

    printf("\nEnter the average number of hours you free for study in a normal day (in hours)\t: ");
    scanf("%f",&temp1[11]);


    temp1[12]= temp1[4]/temp1[11];      //temp1[12] = estimated number of days

    temp2 = (int)temp1[12]; //integer casting

    if(temp2 == temp1[12])
    {
        printf("\n\n-----------------------------------------------------------------");
        printf("\nEstimated time duration to complete you workload\t: %d Days",temp2);
        printf("\n-----------------------------------------------------------------");
    }
    else
    {
        printf("\n\n-----------------------------------------------------------------");
        printf("\nEstimated time duration to complete you workload\t: %d Days",++temp2);
        printf("\n-----------------------------------------------------------------");
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


