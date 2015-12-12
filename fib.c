/*Question :Given a decimal number represent it in a system where the base is the fib series 
i.e. 1,1,2,3... */
/*Approach :Consider the given decimal number is x. An array(a[])is allocated dynamically and computed 
the sum until the required number like [..]20 12 7 4  2 1 .Before scanning the array create another array(b[]) 
with same length as previous array and assign all its values to 0. Start scaning the array for a number 
greater than x or equal to x. If u hit a number greater than x ( say that index value is i ) then do 
operation x-(a[i]) store that value in x so that u can run ur loop until x is 0 and set b[i] to 1. repeat this 
unitl x is 0.
*/

#include<stdio.h>
#include<stdlib.h>
struct fib
{
	int number;
}f[]={1,3,4,6,7,8,21,23,54,0};

void testCases();
void conversion(struct fib *stpr);

int main(void)
{
	testCases();
}

void testCases()
{
	int noOfElements= sizeof(f)/sizeof(f[0]);//calculate the no of testCases
	for(int index=0;index<noOfElements;index++)
	{
		if(f[index].number==0)//if the decimal is less than or equal to zero raise an error
			printf("Error\n");
		else
			conversion(&f[index]);//else convert it
	}
}

void conversion(struct fib *stpr)
{
	int num=stpr->number;
	int first=0,second=1,sum=0,size=0,index=0,temp=0;
	int *iptr;
	iptr = (int *)malloc(size*sizeof(int));//dynamically create an array which holds sum of fib series
	while(num > temp)//check the value of the number before altering it
	{
		if(num == temp)
			break;
		size++;
		iptr = (int *)realloc(iptr,size*sizeof(int));
		if(index==0)//the first index of fib series starts with 1
		{
			iptr[index]=1;
			temp=iptr[index];
			index++;
			continue;
		}
		sum=first+second;//else calculate the sum of the fibonacci elements ex: in the fib series 3 2 1 so calculate 0+1 
		iptr[index]=sum+iptr[index-1];//calculate the sum of existing fibonacci numbers like 1+1=2 store 2 in the array
		first=second;//interchage the values to generate fibonacci series
		second=sum;
		temp=iptr[index];//update the value of temp
		index++;
	}
	int *result;
	result=(int *)calloc(size,sizeof(int));
	for(index=0;index<size;index++)
	{
		result[index]=0;//new array with all its values initailized to zero
	}
	while(num > 0)//until given number becomes zero 
	{
		for(index=0;index<size;index++)//start scanning the first array
		{
			if(iptr[index]<num)//if the required number is less than the one in array check the next index
				continue;
			else if(iptr[index]==num)//if we hit a number which is exactly equal to the required one 
			{
				for(int index1=index;index1>=0;index1--)// set all the values from that indexes to zero index to zero
					result[index1]=1;
				num=0;
				break;//exit the loop
			}
			else
			{
				result[index]=1;//wherever you hit a number greater than the num set the value at that index to 1
				num=num-(iptr[index]-iptr[index-1]);//update the value of num
				break;
			}
		}
	}
	for(index=size-1;index>=0;index--)//display the resultant array
	{
		printf("%d\t",result[index]);
	}
	free(result);
	free(iptr);
	printf("\n");
}