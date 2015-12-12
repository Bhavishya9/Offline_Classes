/* Question : Convert the given positive decimal number to a number in base -2 system */
#include<stdio.h>
#include<stdlib.h>
struct conversion
{
	int decimal_num;
}c[]={0,1,2,4,5,6,8,10,15,19,22,100};

void testCases();
void convertToBase_2(int num);

int main(void)
{
	testCases();
}
void testCases()
{
	int noOfElements = sizeof(c) / sizeof(c[0]);//calculate no of test cases
	for(int index=0;index<noOfElements;index++)
		convertToBase_2(c[index].decimal_num);
}
void convertToBase_2(int num)
{
	int rem,index=0,base=-2,size=0;
	char *answer;
	answer=(char *)malloc(size*sizeof(char));//dynamically allocate the memory for storing the value of number in base-2
	if(num==0)//if the given number is zero 
	{
		size++;//allocate 1 byte
		answer=(char *)realloc(answer,size*sizeof(char));
		*(answer+index)=48;//assign the value at index 0 to zero 
	}
	else
	{
		while(num!=0)//execute the loop until the num is not zero
		{
			size++;
			rem=num%base;//calculate the remainder
			if(rem < 0)//if remainder is negative
			{
				rem*=-1; // make it positive
				answer=(char *)realloc(answer,size*sizeof(char));//allocate the memory of 1 byte of memory
      			*(answer+index)=rem+48;//convert the integer to char to store it in char array
      			num/=base;//update the number value
     			num=num+1;//increment the value of number
      			rem=num%base;//calculate the remainder
      			index++;//update the value of index 
      			size++;//increment the size to allocate a byte of memory
			}
			answer=(char *)realloc(answer,size*sizeof(char));//realloc the memory
			*(answer+index)=rem+48;//convert the integer value into a character 
			num/=base;//update the number value
			index++;//increment the value at index
		}
 	}
  		for(index=size-1;index>=0;index--)//display the values in the array answer 
 		printf("%c\t",answer[index]);
 	free(answer);//free the allocated memory
 	printf("\n");
 }