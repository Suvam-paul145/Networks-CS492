#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

int main()
{
    char *p,*q;
    char in[MAXSIZE];
    char stuff[MAXSIZE];

    int count = 0;
    printf("Enter the input character string (0's and 1's only) : \n");
    scanf("%s",in);

    p = in;
    q = stuff;
    while(*p!='\0')
    {
        if(*p == '1')
        {
            count++;
            *q = *p;
            q++;
            if(count == 5) // add '0' after five consecutive '1's
            {
                *q = '0';
                q++;
                count = 0;
            }
        }
        else
        {
            *q = *p;
            q++;
            count = 0; // reset count if '0' is encountered
        }
        p++;
    }
    *q ='\0';
    printf("\nThe stuffed character string is : \n");
    printf("\n%s\n",stuff);

    return 0;
}
