#include <stdio.h>
#include <string.h>
int counter1,counter2, temp1[20];

int main()
{
    printf("=================================================");
    printf("\n\tWelcome to the study plan generator");
    printf("\n=================================================");

    int modTotal;   //holds the number of modules

    printf("\n\nEnter the number of modules you wish to include\t: ");
    scanf("%d",&modTotal);

    char mods[modTotal][20];

    recorder(&mods[0], modTotal); //calling the recorder function

    for(counter1=0; counter1<modTotal; counter1++)
    {
        printf("\nModule %d : %s\n",counter1+1,mods[counter1]);
    }

    return 0;
}


void recorder(char *mods, int modTotal)
{
    for(counter1 = 0; counter1 < modTotal; counter1++)
    {
        printf("\n\nEnter module %d\t: ",counter1+1);
        scanf("%s",mods);

        printf("\nEnter the number of lecture recordings\t: ");
        scanf("%d",&temp1[0]);

        printf("\nEnter the average length of a recording\t: ");
        scanf("%d",&temp1[1]);

        mods+=20;
    }
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


