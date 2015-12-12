/* re-arrange the array of 0s and 1s in such a way that 0s are followed by 1s.  
ex. the array is {0,1,0,1,1,0,0,1} it is should be re-arranged as {0,0,0,0,1,1,1,1} the ways to solve
1. use bubble sort 
2.count the number of 0s in the array and assign values from starting of array
3.count the number 1s in the array and assign values from ending of array
4.calculate the sum of the array and assign values from ending of the array
5.swap 0 and 1 from ending and starting of the array respectively
*/
#include<stdio.h>
struct sort
{
    int arr[100],length;
}s[]={
        {{0,1,0,1,0,1,0,1,0,1,0,1},12},
        {{1,1,0,0,1,1,0,0,1,1,0,1,1,0},14},
        {{1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},15},
        {{0,0,0,1,0,0},6},
        {{1,1,1,1,0,1},6},
        {{0,1,1,1,1,0},6},
        {{1,2,3,4,0,0,0,0,0,0,0,0,1,1,1,1,1,2},18},
        {{},-1}
     };

void testCases();
void validate_input(int arr[],int length);
void sort1(int arr[],int length);
void sort2(int arr[],int length);
void sort3(int arr[],int length);
void sort4(int arr[],int length);
void sort4(int arr[],int length);
void sort5(int arr[],int length);
void print_array(int arr[],int length);
int main(void)
{
    testCases();
}
void testCases()
{
    int noOfElements = sizeof(s) / sizeof(s[0]);//calculating no of testcases
    for(int index=0;index<noOfElements;index++)
    {
        printf("\nTest Case: %d",index);
        if(s[index].length < 1)
            printf("\nInvalid Input");
        else
            validate_input(s[index].arr,s[index].length);
    }
}
void validate_input(int arr[],int length)//function checks if the elements in the array are only 0s and 1s
{
    int flag=0;
    for(int index=0;index<length;index++)
    {
        if(arr[index]!=0 && arr[index]!=1)
        {
            flag=1; 
            break;
        }          
    }
    if(flag!=1)
    {
        printf("\nFunction 1:");
        sort1(arr,length);
        printf("\nFunction 2:");
        sort2(arr,length);
        printf("\nFunction 3:");
        sort3(arr,length);
        printf("\nFunction 4:");
        sort4(arr,length);
        printf("\nFunction 5:");
        sort5(arr,length);
    }
    else
        printf("\nError");
}
void sort1(int arr[],int length)//bubble sort with time complexity O(n^2)
{
    int index,temp1;
    for(index=0;index<length;index++)
        for(temp1=index;temp1<length;temp1++)
            if(arr[index]>arr[temp1])
            {
                int temp=arr[index];
                arr[index]=arr[temp1];
                arr[temp1]=temp;
            }
    print_array(arr,length);
}
void sort2(int arr[],int length)//count the number of 0s in the array and assign values from starting of array
{
    int index,temp=0;
    for(index=0;index<length;index++)
        if(arr[index]==0)
            temp++;
    for(index=0;index<temp;index++)
        arr[index]=0;
    for(index=temp;index<length;index++)
        arr[index]=1;
    print_array(arr,length);
}
void sort3(int arr[],int length)//count the number 1s in the array and assign values from ending of array
{
    int index,temp1=length-1,temp=0;
    for(index=0;index<length;index++)
    {
        if(arr[index]==1)
            temp++;
    }
    while(temp>0)
    {
        arr[temp1]=1;
        temp1--;
        temp--;
    }
    for(index=0;index<temp1;index++)
        arr[index]=0;
    print_array(arr,length);
}
void sort4(int arr[],int length)//calculate the sum of the array and assign values from ending of the array
{
    int index,temp1=length-1,sum=0;
    for(index=0;index<length;index++)
        sum+=arr[index];
    while(sum>0)
    {
        arr[temp1]=1;
        temp1--;
        sum--;
    }
    for(index=0;index<temp1;index++)
        arr[index]=0;
    print_array(arr,length);   
}
void sort5(int arr[],int length)//scan the array from the start and end simultaneously and swap if
{                               //there is 1 in the first half of array and 0 in second half array.
    int index=0,j=length-1;
    while(1)
    {
        
        while(arr[j]==1)
            j--;
        while(arr[index]==0)
            index++;
        if(index<j)
        {
            int temp=arr[index];
            arr[j]=arr[index];
            arr[index]=temp;
        }
        else
            break;
    }
    print_array(arr,length);
}
void print_array(int arr[],int length)//prints the array
{
    int index=0;
    printf("\n");
    for(index=0;index<length;index++)
        printf("%d\t",arr[index]);
}
