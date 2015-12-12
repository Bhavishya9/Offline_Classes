/*Question : Add the numbers in the strings the lengths of the strings may be equal or unequal*/
#include<stdio.h>
#include<stdlib.h>
struct addition
{
	char *input1,*input2;//the two input char arrays which are to be added
}a[]={
		  {"121","121"},
		  {"1234543214691583","1234543214691583"},
		  {"123456","121"},
		  {"9854","19283746"},
		  {"9999121","921"},
		  {"989","769"},
		  {"191","9989"},
		  {"999","11"},
		  {"0","0"},
		  {"213-1","111"},
		  {"241467","*549/"},
		  {"*()&","#@!$~`"}
		};
void testCases();
int computeLength(char *str);
void adder(struct addition *stpr);
int validate(char **str);

int main(void)
{
	testCases();
}

void testCases()
{
	int noOfElements = sizeof(a) / sizeof(a[0]);// calculate the no of testcases
	for(int index=0;index<noOfElements;index++)
	{
		int check1=validate(&a[index].input1);//validate the first string 
		int check2=validate(&a[index].input2);//validate the second string
		if(check1==-1 || check2==-1)//if either of above checks return an error then print invalid input
			printf("Invalid Input\n");
		else //else add the given inputs
			adder(&a[index]);
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

void adder(struct addition *stpr)
{
	char *str1=stpr->input1;//name the first input as str1
	char *str2=stpr->input2;//name the second input as str2
	int length1=computeLength(str1);//calculate the length of input1
	int length2=computeLength(str2);//calculate the length of input2
	//printf("%d\t",length1);
	int *addptr,size,carry=0;
	if(length1>length2)//compare the lengths of the strings 
		size=length1; //the size of the new array to be created is equal to max of the two lengths of strings
	else
		size=length2;
	addptr=(int *)calloc(size+1,sizeof(int));//stores the added result
	int index1=length1-1;
	int index2=length2-1;
	for(int index=size-1;length1 >0 && length2 >0;index--,length1--,length2--)
	{
		int sum= carry + ( *(str1+index1)-'0' ) + ( *(str2+index2)-'0' );//add the numbers in the corresponding positions
		if(sum<10)//if sum is zero then then directly copy the sum to resultant array
		{
			*(addptr+index)=sum;
			carry=0;//make carry as zero 
		}
		else if(sum>9 && index==0)//if the index is 0 then there is no need to calculate carry 
		{
			*(addptr+index)=sum;
		}
		else
		{
			carry=1;//the maximum of carry is 1 if sum is greater than 9.
			sum=sum%10;//the sum is ones place to obtain it find the remainder by 10 to obtain sum
			*(addptr+index)=sum;//copy the value of sum to the resultant array
		}
		index2--;//decrement the indexes by 1
		index1--;
	}
	if(length1>0)//if there are left out elemnts in first string after adding with second string then 
	{			//copy the these elements directly into the resultant array by checking the value of carry 
		for(int index=length1-1;index>=0;index--)
		{
			int sum = *(str1+index)-'0' + carry ;
			if(sum<10)
			{
				*(addptr+index)=sum;
				carry=0;
			}
			else if(sum>9 && index==0)
				*(addptr+index)=sum;
			else
			{
				carry=1;
				sum=sum%10;
				*(addptr+index)=sum;
			}
		}
	}
	if(length2>0)//if there are left out elemnts in second string after adding with first string then 
	{			//copy the these elements directly into the resultant array by checking the value of carry 
		for(int index=length2-1;index>=0;index--)
		{
			int sum = *(str2+index)-'0' + carry ;
			if(sum<10)
			{
				*(addptr+index)=sum;
				carry=0;
			}
			else if(sum>9 && index==0)
				*(addptr+index)=sum;
			else
			{
				carry=1;
				sum=sum%10;
				*(addptr+index)=sum;
			}
		}
	}
	for(int index=0;index<size;index++)//display the array containing the addition results
	{
		printf("%d",*(addptr+index));
	}
	free(addptr);
	printf("\n");
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