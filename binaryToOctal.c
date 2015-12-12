/* Convert the given binary number in string format to octal number in string format */
#include<stdio.h>
#include<stdlib.h>
struct conversion
{
	char *input;
}c[]={
		{"0"},
		{"1"},
		{"000010"},
		{"100"},
		{"111"},
		{"1000"},
		{"1010"},
		{"11110"},
	 };
void testCases();
void binaryToOctal(struct conversion *stpr);
int computeLength(char *str);

int main(void)
{
	testCases();
}

void testCases()
{
	int noOfElements = sizeof(c) / sizeof(c[0]);//calculate the number of testcases
	for(int index=0;index < noOfElements;index++)
		binaryToOctal(&c[index]);
}

void binaryToOctal(struct conversion *stpr)
{
	char *binary,*octal;
	int index,index1,index2=0;
	int size=0,sum,value;
	binary=stpr->input;//assign the input string in the structure to binary
	octal=(char *)malloc(size*sizeof(char));//dynamically allocate the char array to store octal values
	int length=computeLength(binary);//calculate the length of the binary string
	if(binary[0]=='0' && length==1)//if the string is only 0
	{
		size++;
		octal=(char *)realloc(octal,size*sizeof(char));//realloc the ocatal array to store the result
		*(octal+index2)=48;//then print it to output screen 
		printf("%c\n",*(octal+index2));
	}
	else
	{
		for(index=length-1;index > 1;)//scan the array from end and excute it until zero or one or two  
		{//elements are left over, the worst case is two elements are left over so we consider it 
		// if two elements are left over then index will be equal 1 then loop stops
			sum=0;  
			value=1;
			for(index1=0;index1 < 3;index1++)//it exexutes 3 times because to convert binary to octal
			{                         // we take we take 3 places at a time and convert it to decimal 
				sum=sum+ value * ((binary[index])-'0');//multiply the powers of 2 to value stored in binary array
				value*=2;//calculate the power of 2
				index--;//decrement the value of index
			}
			size++;
			octal=(char *)realloc(octal,size*sizeof(char));//realloc the octal array to store the result
			*(octal+index2)=sum+48;//convert interger value to char value and store it in octal array 
			index2++;//increment the index in the octal array
		}
		if(index==1)//if index=1 then we have two left over elements 
		{
			sum= binary[index]-'0' + ((binary[index-1]-'0') * 2);//multiply the two elements with corresponding powers of 2 
			size++;
			octal=(char *)realloc(octal,size*sizeof(char));
			*(octal+index2)=sum+48;
		}
		if(index==0)//if index=0 then we have one element left over in the binary array
		{
			sum=binary[index]-'0';//calculate if it is zero or one
			size++;
			octal=(char *)realloc(octal,size*sizeof(char));
			*(octal+index2)=sum+48;
		}
		for(index=size-1;index>=0;index--)//display the binary numbers in octal
		{
			if(index==size-1 && *(octal+index)=='0')//avoid redudant zeros
				continue;
			printf("%c\t",*(octal+index));
		}
		printf("\n");
	}
	free(octal);//free the allocated memory
}

int computeLength(char *str)
{
	int count=0;
	while(*str!='\0')
	{
		count++;
		str++;
	}
	return count;
}