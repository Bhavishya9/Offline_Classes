/*
Question: Given an array display a resultant array such that each index in the resultant consists of 
product of the all the elements in the array exculding the number at the given index
Example: given aray is [2,8,4,5,6,1,9,3] the value at index 1 in the resultant is given by product of 
(2*4*5*6*1*9*3) i.e. product of all the elements exculding the value at index 1 i.e. 8
*/

/*Approach : 
Function 1: Calculate the product of the leftside part of index of the array and rightside part of
index of the array. Now multiply these values and display the values

Function 2: Calculate the product of the entire array.When displaying the result divide the product
with value at current index.

Function 3: Use nested loop to skip the current index and multiply the remaining elements
*/

#include<stdio.h>
struct mul
{
	int arr[100],length;
}a[]={
		{{1,2,3,4,5,6,7,8},8},
		{{0,0,1,1,1,1,0,0,0,0},10},
		{{12,8,7,10,6,3},6},
		{{0,0,0,0,0,0},6},
		{{1,2,3,4,1,0,0,0,1,1},10},
		{{-1,-2,-3,-4,-5,-6,-7,-8},8},
		{{},-1}
	 };
void multiply1(int arr[],int length);
void multiply2(int arr[],int length);
void multiply3(int arr[],int length);
void print_array(int output[],int length);
void testCases();
int main(void)
{
	testCases();
	return 0;
}

void testCases()
{
	int noOfElements = sizeof(a) / sizeof(a[0]);
	for(int index=0;index<noOfElements;index++)
	{
		printf("Test Case: %d\n",index);
		if(a[index].length < 1)
			printf("Error");
		else
		{
			printf("Function 1:\n");
			multiply1(a[index].arr,a[index].length);
			printf("Function 2:\n");
			multiply2(a[index].arr,a[index].length);
			printf("Function 3:\n");
			multiply3(a[index].arr,a[index].length);
		}
	}
}
void multiply1(int arr[],int length) //multiplying using a single array and time complexity O(n)
{
	int output[length],flag=1;
	output[length-1]=arr[length-1];
	if(length!=1)//to make sure there are atleast two elements in the array
	{
		for(int index=length-2;index>0;index--)//calculate the product from end to start for the given array
			output[index]=output[index+1]*arr[index];//and store it in a different array
		output[0]=output[1];
		for(int index=1;index<length;index++)
		{
			flag=flag*arr[index-1];//calculate the product of the given array from start
			if(index==length-1)
				output[index]=flag;
			else
				output[index]=flag*output[index+1];//re write the array to display the desired output
		}
	}
	print_array(output,length);
}
void multiply2(int arr[],int length) //multiplying using / operator and time complexity O(n)
{
	int output[length],mul=1,temp=0;
	if(length==1)
		output[0]=arr[0];
	else
	{
		for(int index=0;index<length;index++)
		{
			if(arr[index]!=0)//calculate the total product of the array excluding the zeros
				mul=mul*arr[index];
			else //calculate the zeros in the array
				temp++;
		}
		for(int index=0;index<length;index++)
		{
			if(temp==1)//if there is only one zero
			{
				if(arr[index]!=0)//if the value at the location is not zero then assign 0 to the index
					output[index]=0;
				else//if the value at the location is zero then assign the product calculated above
					output[index]=mul;
			}
			else if(temp>1)//if there are more than one zero in the array and assign values to all
				output[index]=0;//indexes as zero
			else//if there are no zeros then divide the total product by the value at the current index
				output[index]=mul/arr[index];
		}
	}
	print_array(output,length);
}
void multiply3(int arr[],int length)//multiply all elements by skiping current index and time complexity O(n^2)
{
	int output[length];
	for(int index=0;index<length;index++)
	{
		int mul=1;
		for(int index1=0;index1<length;index1++)
		{
			if(index==index1)//if the index is current index then skip it
				continue;
			else //else multiply the elements
			{
				mul*=arr[index1];
			}
		}
		output[index]=mul;
	}
	print_array(output,length);
}
void print_array(int output[],int length)//display the output array
{
	for(int index=0;index<length;index++)
		printf("%d\t",output[index]);
	printf("\n");	
}