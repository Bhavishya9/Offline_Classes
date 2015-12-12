/* Question : Given an array and no of adjacent elements(say n) to consider find the winner element such 
that sum of its n/2 adjacent elements is max.
Example: [1,2,4,3,0,1] and given n = 3 then consider the sum of [1,2,4] , [2,4,3] , [4,3,0] ,[3,2,1]
the sums would be [7,9,7,6] so 9 is maximum sum which makes 4 as winner element 
*/

#include<stdio.h>
struct adjacent
{
	int arr[100],length,adjacency;
}a[]={
		{{1,2,4,3,0,1},6,3},
		{{5,7,8,9,10,12,3,4,8,6,7},10,4},
		{{0,3,4,1,9,0,10,3,5,8,1,6,7,2,4},14,5},
		{{1,4,3,1,6,8,0,12,0,7,4,2,15,1,2,5,7,8,9,0,7,3},22,6},
		{{3,5,1,9,4,2,1,3,0,1,2,8,10,6,7,8,9,10,0,2,4,2,1,4,6,9},26,7},
		{{5,2,1,3,4,5,6,7,5,3,1,3,4,4,5,6,6,7,7,8,5,2,1,4,2,4,6,8,9,0,12,3,2,1,2},35,8},
		{{5,2,1,3,4,5,6,7,5,3,1,3,3,5,1,9,4,2,1,3,0,1,2,8,10,1,4,3,1,6,8,0,12,0,3,4,1,9,0,10,3,5,8,5,7,8,9,10,12},50,9},
		{{1,2,3,4,5},5,9}
	 };

void testCases();
void winner(int arr[],int length,int adjacency);

int main(void)
{
	testCases();
}

void testCases()
{
	int noOfElements = sizeof(a) / sizeof(a[0]);//calculate number of testcases
	for(int index=0;index<noOfElements;index++)
		winner(a[index].arr,a[index].length,a[index].adjacency);
}

void winner(int arr[],int length,int adjacency)
{
	if(length>=adjacency)//check if value of adjacency is valid
	{
		int index=0;
		int total[length-adjacency+1];//create an array to store the value of the sums that are being calculated
		while(index!=length-adjacency+1)//calculate until we reach an end value that is valid in the array
		{
			int sum=0;
			for(int index1=0;index1<adjacency;index1++)//run the inner loop adjacency times
			{
				sum+=arr[index1+index];//calculate the sum
			}
			total[index]=sum;//store in the array
			index++;
		}
		int max=0;
		for(index=0;index<length-adjacency+1;index++)
		{
			if(total[max] < total[index])//calculate the index where the sum is maximum
			{
				max=index;
			}
		}
		int temp=adjacency/2;
		printf("%d\n",arr[max+temp]);//display the corresponding value in the array
	}
	else
		printf("Error\n");//if the adjacency value is invalid then print error
}

