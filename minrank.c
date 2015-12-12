#include<stdio.h>
struct Minrank
{
	int n;
}min[]={1024,241,987,1342,564,101};

int factorial(int n);
void minrank(struct Minrank *p);
void testCases();

int main(void)
{
	testCases();
	return 0;
}

void testCases()
{
	int noOfElements = sizeof(min) / sizeof(min[0]);//calculate the no of test cases
	for(int index=0;index < noOfElements;index++)
		minrank(&min[index]);
}

void minrank(struct Minrank *p)
{
	int arr[8],rank=0,k,maxindex=0,rev=0;
	int n1=p->n;
	while(n1!=0)//convert the number into an array
	{
		k=n1%10;
		rev=rev*10+k;
		n1/=10;
	}
	while(rev!=0)//reverse the array to get given number format
	{
		k=rev%10;
		arr[maxindex++]=k;
		rev/=10;
	}
	for(int index=0;index < maxindex;index++)//scan the array from start to end
	{
	   int flag=0;
	   for(int index1=index+1;index1 < maxindex;index1++)//from current position count the digits which
	   {	
	   	 if(arr[index]>arr[index1])//less than value at current index
	   	 		flag++;
	   }	
	   rank=rank+(flag*factorial(maxindex-(index+1))); // multiply the no of above elements and factorial  
	}												   // of that place
	printf("%d\n",rank);//display the rank
}

int factorial(int n)//calculate the factorial
{
	int f=1;
	if(n==0||n==1)
		f=1;
	else
	{
		for(int i=2;i<=n;i++)
		{
			f=f*i;
		}
	}
	return f;
}