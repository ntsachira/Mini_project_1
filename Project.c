#include <stdio.h>

void ranker(int *ptr, int modCount)
{
    int counter1, counter2;

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

int main()
{




    int hour[20]= {12,33,2,43,22,77,5};

    int x, modCount = 7;

    ranker(&hour[0], modCount); //calling the ranker function

    for(x=0; x<modCount; x++)
    {
        printf("%d\n",hour[x]);
    }

    return 0;
}


