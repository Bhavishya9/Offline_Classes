#include<stdio.h>
struct permutation 
{
  int number;
}per[]={
      {12},
      {123},
      {1024},
      {56789}
     };

void testCases();
void convert(struct permutation *stpr);
void permutate(int *a,int startIndex,int maxIndex);

int main(void)
{
  testCases();
}
void testCases()
{
    
   int noOfElements= sizeof(per) / sizeof(per[0]);// calculate the no of test cases
    for(int index=0;index<noOfElements;index++)
    {
      printf("\nTest Case no %d\n",index);
      convert(&per[index]);// convert the number into an array
    }
}

void convert(struct permutation *stpr)
{
  int arr[8],digit,maxindex=0,rev=0;
  int n1=stpr->number;
  while(n1!=0)//execute until all the digits are inserted to array
  {
    digit=n1%10;
    arr[maxindex++]=digit;//enter each digit into array
    n1/=10;
  }
  permutate(arr,0,maxindex-1);//call the permutate function
}

void permutate(int num[], int startIndex, int maxIndex)
{
   if (startIndex == maxIndex)//base condition
   {
    for(int index1=0;index1<=maxIndex;index1++)//display the array when startIndex and maxIndex are equal
      printf("%d ",num[index1]);
    printf("\n");
    }
   else
   {
       for (int index = startIndex; index <= maxIndex; index++)//repeat until index reaches the no of digits value
       {
          int temp= num[startIndex]; // swap the value at index with value at startIndex 
          num[startIndex]= num[index];//there wont be any change when startIndex is equal to index but not equal to no of digits
          num[index]=temp;
          permutate(num, startIndex+1, maxIndex);//recursion : call the function by incrementing the startIndex to meet the base condition eventually 
          temp= num[startIndex];// re swap the indexes of the number because the before swapping shouldnt the affect the number for further computations
          num[startIndex]=num[index];
          num[index]=temp;
       }
   }
}
