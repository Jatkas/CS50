#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float doll;
    int i=0, cents;
    
   do{
       doll = get_float("How much change are you giving? (in dollars)\n");
   } 
   while(doll<0);
   
   cents = round(doll * 100); //dont change upwards!
   
   while(cents>=25)
   {
       cents=cents-25;
       i++;
   }
   while(cents>=10)
   {
       cents=cents-10;
       i++;
   }
   while(cents>=5)
   {
       cents=cents-5;
       i++;
   }
   while(cents>=1)
   {
       cents=cents-1;
       i++;
   }
   
   printf("You will need this many coins:%d\n", i);
   //works like a charm
}