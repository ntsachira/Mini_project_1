#include <stdio.h>
#include <string.h>

int main()
{
    printf("=================================================");
    printf("\n\tWelcome to the study plan generator");
    printf("\n=================================================");

    int modTotal;   //holds the number of modules

    printf("\n\nEnter the number of modules you wish to include\t: ");
    scanf("%d",&modTotal);

    char mods[modTotal][20];
    int counter, temp1[20];


    for(counter = 0; counter < modTotal; counter++)
    {
        printf("\n\nEnter module %d\t: ",counter+1);
        scanf("%s",&mods[counter]);

        printf("\nEnter the number of lecture recordings\t: ");
        scanf("%d",&temp1[0]);

        printf("\nEnter the average length of a recording\t: ");
        scanf("%d",&temp1[1]);

        temp1[2]+= temp


    }


    return 0;
}


