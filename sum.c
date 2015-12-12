/* Adding the positive numbers in the strings from left to right */

#include<stdio.h>
#include<stdlib.h>
struct addition
{
	char *input1,*input2;//the two input char arrays which are to be added
}a[]={
		  {"1234567","8765432"},
		  {"1234567","7654321"},
		  {"1234567","1234567"},
		  {"19","11"},
		  {"567","333"},
		  {"56755","33245"},
		  {"111","788"},
		  {"123","111"},
		  {"123","185"},
		  {"123","175"},
		  {"9","9"}
	 };

void testCases();
void sum(struct addition *stpr);
void reverse(char *str);

int main(void)
{
	testCases();
}

void testCases()
{
	int noOfElements = sizeof(a) / sizeof(a[0]);//calculating no of testcases
	int index;
	for(index=0;index<noOfElements;index++)
		sum(&a[index]);
}

void sum(struct addition *stpr)
{
	char *str1=stpr->input1;//name the first input as str1
	char *str2=stpr->input2;//name the second input as str2
	int index,index1,sum,temp1=0,temp2=0;
	int *add,size=0;
	add = (int *)malloc(size*sizeof(int));
	if(str2[0]!='\0' && str2[1]=='\0')
	{
		size++;
		add = (int *)realloc(add,size*sizeof(int));
		sum= str1[0]-'0' + str2[0]-'0';
		if(sum<10)
			*(add+index)=sum;
		else
		{
			size++;
			add = (int *)realloc(add,size*sizeof(int));
			*(add+1)=sum%10;
			*(add+0)=1;
		}
	}
	else
	{
		for(index=0;str2[index]!='\0'; index++)//since lengths are equal add until either of it is null
		{
			sum= str1[index]-'0' + str2[index]-'0';//add the corresponding positions in the string
			size++;
			add = (int *)realloc(add,size*sizeof(int));//allocate a new array dynamically
			if(sum<9)//if the sum is less than 9 then enter it into the array
			{
				*(add+size-1)=sum;
				temp1=index;//use a temporary value to know where 
					//the last index is having value less than 9
			}
			else if(sum==9)//sum is equal to 9
			{	
		       temp2=index;//use a temporary variable to know where there is a value equal to 9
		       *(add+index)=-1;//set value -1 at indexes which have to hold 9
			}
			else// if the sum is greater 9
			{
				if(temp2==index-1)//check if previous index holds 9  
				{
					for(index1=temp1+1;index1<=temp2;index1++)//if it is 9 then make it 
						*(add+index1)=0;//zero
					(*(add+temp1))++;//increment the value at index which holds less than 9 
					temp1=temp2;
				}
				else// if the previous index holds value less than 9
					(*(add+index-1))++;//increment the value at previous index
				*(add+index)=sum%10;//store the value of sum in the current index
			}
		}
	}
	for(index=0;str2[index]!='\0';index++)//if there are any indexes which are not assigned then 
	  if(*(add+index)==-1)//assign them with 9
	      *(add+index)=9;
	for(index=0;index<size;index++)//display the result stored in adder
		printf("%d\t",*(add+index));
	free(add);//free the allocated memory
	printf("\n");
}
