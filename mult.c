#include<stdio.h>
struct mult
{
 int multiplier,multiplicand;
}m[]={
	     {1024,1024},
	     {1024,-1024},
	     {-1024,1024},
	     {-1024,-1024},
	     {0,1024}
      };
void multiplication(struct mult *p);
void testCases()
{
  int noOfElements= sizeof(m)/sizeof(m[0]);
  for(int index=0;index < noOfElements;index++)
    multiplication(&m[index]);
}
int main(void)
{
 testCases();
 return 0;
}
void multiplication(struct mult *p)
{
 int product=0,flag=0;
 if(p->multiplier<0) //check if multiplier is -ve because the for -ve numbers 
 {		     //logical right shift becomes arithematic right shift
  flag=1;	     //to avoid this take the absolute values of multiplier
  p->multiplier*=-1;
 }
 while(p->multiplier!=0)//repeat the loop until all multiplier bits are zero
 {
  if(p->multiplier&1) //checks if multiplier bit is 1
   product+=p->multiplicand;//if it is 1 then performs addition for partial product
   
  p->multiplier=p->multiplier>>1;//right shift multiplier so that we can multiply with every bit
  p->multiplicand=p->multiplicand<<1;//left shift multiplicand to move the partial product 
  				                          //after multiplication with each multiplier bit
 }
 if(flag==1)//if multiplier is -ve then multiply the produt with -1 for accurate answer
   product*=-1;
 printf("%d\n",product);
}
