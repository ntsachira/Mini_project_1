#include <stdio.h>
#include <string.h>
int counter1,counter2;
float temp1[20], tHours[20];

int main()
{
    printf("==================================================================");
    printf("\n\t\tWelcome to the study plan generator");
    printf("\n==================================================================");

    int modTotal;   //holds the number of modules

    printf("\n\nEnter the number of modules you wish to include\t: ");
    scanf("%d",&modTotal);

    char mods[modTotal][20];

    recorder(&mods[0], modTotal); //calling the recorder function



    return 0;
}


void divider()
{
   // printf("\n******************************************************************");
    printf("____________________________________________________________________\n\n");
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


        mods+=20;
    }
divider();
}


void ranker(int *ptr, int modCount)
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
            }
            ptr++;
        }
        ptr = ptr - (modCount-1);
    }
}


