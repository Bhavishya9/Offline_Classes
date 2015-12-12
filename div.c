/* check the divisibility by 11 for the number which is given as input in the form of string */
#include<stdio.h>
struct divisible
{
	char *input;//input array with max size of 10000 chars
}d[]={
		{"121"},
		{"11"},
		{"1234543214691583"},
		{"0"},
		{"ABC"},
		{"*(/+av"}
	    };
void testCases();
int computeLength(char *str);//returns the length of the number stored in the character array
int divisibility(struct divisible *str);//checks the divisibility by 11
int validate(char **str);

int main(void)
{
	testCases();
}

void testCases()
{
	int noOfElements= sizeof(d) / sizeof(d[0]);
	int returnValue;
	for(int index=0;index < noOfElements;index++)
	{
		int check=validate(&d[index].input);
		if(check==-1)
			printf("Invalid input\n");
		else
		{
			returnValue=divisibility(&d[index]);
			if(returnValue==0)//if returned value is zero then the given number in the char array is
				printf("Divisible\n");//divisible by 11
		
			else if(returnValue==1)//if returned value is one then the given number in the char array is
				printf("Not Divisible\n");//not divisible by 11
		}
	}
}

int validate(char **str)
{
	int flag=0;
	char *str1=*str;//use an alias
	for(int index=0;str1[index]!='\0';index++) //
	{
		if((str1[index]-'0')>=0 && (str1[index]-'0')<=9)//if the each character is in the range 0 to 9
			continue;
		else //else stop executing the loop
		{
			flag=1;// set to 1
			break;
		}
	}
	if(flag==1)//if flag=1 then return an error case
		return -1;
	else
		return 0;
}

int divisibility(struct divisible *str)
{
	char *cptr = str->input;//use a character pointer cptr to refer to the input char array in the testcase
	int length=computeLength(cptr);//calculate the length of the given number which is stored as char array  
	int sum=0;
	for(int index=0;index<length;index+=2)
	{
		if(length%2!=0 && index==length-1)//if the length is odd we have an element being left out 
     		sum+= cptr[index]-'0';
   		else
     		sum+= cptr[index]- cptr[index+1];
	}
	if(sum%11==0)//if sum is divisible by 11 then the given number is divisible by 11
		return 0;
	else
		return 1;//else the given number is not divisible by 11
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

