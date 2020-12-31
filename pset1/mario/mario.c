#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i, j, k, h, t, m;
    
    do
    {
        h = get_int("enter the height: ");
    }
    while (h<1);//it worked untill here
    
    for(i=0;i<h;i++)
    {
        t=h-1-i;
        for(j=0; j<h;j++)
        {
            if(j<t)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
            printf("  ");
            m=h-t;
            for(k=0; k<m; k++)
            {
                printf("#");
            }
        printf("\n");
        //it works now
    }

}