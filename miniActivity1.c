/*Question: Accept a string of any length */
/*Approach : use dynamic memory allocation*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char *input,c;
	int length=0;
	input = (char *)malloc(length*sizeof(char));//dynamically allocate memory for string
	if(input==NULL)
		printf("Insufficient memory");
	else
	{
		while((c=getchar())!='\n')//accept each character from keyboard if its not a new line character continue
		{
			length++;//increment the value of length
			input = (char *)realloc(input,length*sizeof(char));//realloc the memory for string
			*(input+length-1)=c;//append the character to the string
		}
		*(input+length)='\0';//after completing the accepting to the string assign last character to NULL character
	}
	printf("%d",length);//display the length of the string
	free(input);//free the allocated memory
}
