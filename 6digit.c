/*Question: Given a number in the range of 2 to 9 (inclusive) say n, display all 6 digits such that when a 
6 digit is multiplied with n gives a 6 digit number exactly with same digits in the considered 
6 digit number.
Example : consider a 6 digit like 125874 and n value as 2
when 125874 is multiplied with 2 gives 251748 
print all such 6 digits where n value ranges from 2 to 9 */

/*Approach: Calculate the max value till where we have to run by dividing 1000000 by the value of n.
Consider an array of length 9 which contains prime numbers. Each digit in the 6 digits 
is associated with a prime number.Calucate the product of digits in the given number by multiplying all the
prime numbers associated with the 6 digit number. Multiply the 6 digit number with given value of n and 
calculate the product of digits in result if both products match then display or continue the loop until
condition in the loop fails.
*/

#include<stdio.h>
struct multiplication
{
	int multiplier;
}m[]={2,3,4,5,6,7,8,9}; // multiplier varies from 2 to 9

void testCases();
void sameDigits(struct multiplication *stpr);

int main(void)
{
	testCases();
}

void testCases()
{
	int noOfElements = sizeof(m) / sizeof(m[0]);//calculate no of test cases
	for(int index=0;index<noOfElements;index++) 
	{
		printf("When multiplier is %d:\n",m[index].multiplier);
		sameDigits(&m[index]);
	}
}

void sameDigits(struct multiplication *stpr)
{
	int number=1000000;//the first seven digit
	int max=number/stpr->multiplier;//calculate the maximum number till where we to check 
	int start=100000;// starting is smallest 6 digit number
	int prime[]={2,3,5,7,11,13,17,19,23,29};// array contains 9 prime numbers
	while(start!=max) //execute the loop from 100000 to max
	{
		long int product1=1;
		long int product2=1;
		int num=start;
		while(num!=0)//calculate the product of digits in the number and store it in product1
		{
			product1=prime[num%10]*product1;
			num/=10;
		}
		int product=start*(stpr->multiplier);// carry out the multiplication
		while(product!=0)//calculate the product of digits in the product that is obtained after multiplication
		{
			product2=prime[product%10]*product2;
			product/=10;
		}
		if(product2==product1)// if product1 is equal to product2 then print to output screen 
		{
			printf("%d\n",start);
		}
		start++;// increment it to next number;
	}
}