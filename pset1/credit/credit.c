#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    int i, x=0, y=0, sumx, sumy, lika, likb, x1, gal, amex, mc, card;
    long number, dal, sk, liek, liek1, naujas;

    do
    {
        number = get_long("Enter cards number: \n");
    }
    while (number<1);

    liek=number%10;
    sk=number-liek;

    for(i=2; sk>0; i++)
    {
        dal=pow(10,i);
        liek1=(sk%dal)/pow(10,i-1);
        if(i%2==0)
        {
            if(liek1>4)
            {
                lika=(liek1*2)%10;
                likb=((liek1*2)-lika)/10;
                x1=lika+likb;
            }
            else
            {
                x1=liek1*2;
            }
            x=x+x1;
        }
        else
        {
            y=y+liek1;
        }
        sk=sk-liek1*pow(10,i-1);
        if(i==14)
        {
            amex=liek1;
        }
        if(i==15)
        {
            mc=liek1;
        }
    }

    mc=mc+liek1*10;

    y=y+liek;
    gal=x+y;
    
    if(gal%10==0)
    {
        if(i==14)
        {
            printf("VISA\n");
        }
        else if(liek1==3)
        {
            if(amex==4 || amex==7)
            {
            printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if(i==17)
        {
            if(liek1==4)
            {
                printf("VISA\n");
            }
            else if(mc>=51 && mc<=55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    
}