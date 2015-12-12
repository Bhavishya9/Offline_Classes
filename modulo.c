#include<stdio.h>
struct modulo
{
	int x,y,z; //x,y,z are whole numbers in the form of (x^y)%z i.e. pow(x,y) mod z
}m[]={
		{4,5,12},
		{3,4,14},
		{1024,1024,987},
		{3,3,5},
		{1,1,1},
		{9,0,12},
		{0,4,12},
		{8,9,0},
		{0,0,12},
		{12,0,0},
		{0,0,0}
	   };
void testCases();
void mod(struct modulo *p);
int power(int base,int expo);
int main(void)
{
	testCases();
	return 0;
}
void testCases()
{
	int noOfElements = sizeof(m) / sizeof(m[0]);
	for(int index=0 ;index < noOfElements ; index++)
		mod(&m[index]); //function call to mod function
}
void mod(struct modulo *p)
{
	int temp[100],index=1,lastIndex=0,temp1=0,product=1;
	if(p->z == 0) // if denominator is 0 then the result is undefined
		printf("Invalid\n");
	else if(p->x == 0 && p->y ==0) //the result of pow(0,0) is undefined
		printf("Invalid\n");
	else if(p->x==0) //if numerator is 0 then the result is zero
		printf("%d\n",0);
	else if(p->y==0 && p->z!=1) //any non zero to power 0 is 1 and 1 mod z is 1 where z is natural number
		printf("%d\n",1);
	else
	{
		while(p->y!=1) // calculate the 0s and 1s for given y
		{
			temp[lastIndex++]=(p->y)%2;
			p->y/=2;
		}
		temp[lastIndex++]=1;
		int binary[lastIndex];
		temp1=lastIndex-1;
		for(index=0;temp1>=0;index++,temp1--)// formation of binary number to given y
			binary[index]=temp[temp1];
		temp1=lastIndex-1;
		for(index=0;temp1>=0;index++,temp1--)// calculation of powers of 2
			temp[index]=power(2,temp1);
		for(index=0;index<lastIndex;index++)// check where the y binary bits are 1s
			binary[index]=binary[index]*temp[index];
		for(index=0;index<lastIndex;index++)
		{
			if(binary[index]!=0)//wherever the y binary bits are 1s there compute the results 
				temp[index]= power(p->x,binary[index]) % p->z;
			else
				temp[index]=0;
		}
		for(index=0;index<lastIndex;index++)
			if(temp[index]!=0) //multiply all the individual results obtained above
				product*=temp[index];
		printf("%d\n",product % p->z);//compute the modulus of the product above
	}
}
int power(int base,int expo)// calculation of base^exponent
{
	int pow=1;
	if(expo==0)
		return 1;
	else
	{
		for(int count=0;count<expo;count++)
			pow*=base;
		return pow;
	}

}
