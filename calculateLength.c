/* Calculate the n of the array such that the nth element is lesser than n+1th element and n+1th is greater
than n+2th element, n+2th element is followed by n zeros in the array after that can any value
(garbage values) */ 
#include<stdio.h>
struct array
{
	int a[100],length;
}arr[]={
		{{1,2,3,4,5,4,0,0,0,0,12},11},
		{{1,2,4,2,0,0,1},7},
		{{2,4,1,0,12},5},
		{{1,2,3,4,1,0,0,0},8}
	   };
void testCases();
void calculate(struct array *stpr);
void computeLength(int a[],int index1,int index2);

int main()
{
	testCases();
}

void testCases()
{
	int noOfElements= sizeof(arr)/sizeof(arr[0]);//calculate the no of test cases
	for(int index=0;index<noOfElements;index++)
	{
		calculate(&arr[index]);//call the function to calculate for which value of index we will hit zero
	}
}

void calculate(struct array *stpr)
{
	int index=1,flag=0;
	while(stpr->a[index]!=0)//upate the index value until we hit zero
	{
		index*=2;//update in the powers of 2
		if(stpr->a[1]>stpr->a[2])// special case where there is only 1 element in the array
		{
			flag=1;
			break;//break the loop
		}
	}
	if(flag==1)//if there is only one element then display 1
		printf("%d\n",1);
	else	  // call the function computeLength to calculate the n value
		computeLength(stpr->a,index/2,index/4);
}

void computeLength(int a[],int index1,int index2)
{
	int index=index1+index2;//add the index values
	if(index2==0)// this is base condition for recursion after execution of this condition
				// of index2 being zero stops execution 
		printf("%d\n",index-1);
	else
	{
		if(a[index]==0)// if hitting zero then dont consider index1
			computeLength(a,index1,index2/2);
		else
			computeLength(a,index,index2/2);//if it is not htting zero then calculate the computeLength()
	}

}
