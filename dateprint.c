/*Question: Convert the given date into words */

#include<stdio.h>
struct date
{
	char *charDate;
}da[]={
	   {"24/6/1000"},
	   {"12/9/1100"},
	   {"31/1/2000"},
	   {"28/2/2100"},
	   {"28/9/1009"},
	   {"31/5/1105"},
	   {"27/6/2007"},
	   {"22/1/2109"},
	   {"9/3/1015"},
	   {"8/4/1980"},
	   {"9/7/1994"},
	   {"19/10/2015"},
	   {"29/12/2020"},
	   {"23/11/3145"},
	   {"32/7/1995"},//invalid date format
	   {"31/2/2015"},//invalid date format
	   {"0/2/2014"},//invalid date format
	   {"2/0/2013"},//invalid date format
	   {"4/4/0000"},//invalid date format
	   {"0/0/0"},//invalid date format
	   {"29/2/1700"}//invalid date format
	  };
void testCases();
void text(int *intDate);
int validate(int *intDate);
void convert(char *charDate,int intDate[]);
int  main(void)
{
	testCases();
	return 0;
}
void testCases()
{
	int index;
	int noOfElements = sizeof(da) / sizeof(da[0]);
	for(index=0;index < noOfElements;index++)
    {
    	int intDate[3]={0};
    	convert(da[index].charDate,intDate);//call the function which changes date from char to integer array
        int temp=validate(intDate);
        if(temp==1) //if the date is valid then convert it to words
		{
	    	printf("\n");
            	text(intDate);
		}
        else
            printf("\nInvalid Date Format");
    }
}
int validate(int intDate[])
{
    int daysInMonths[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int index;
    int monthNo= intDate[1];
    if(intDate[1]==2) //if the month is feburary
    {
        if(intDate[2]%400==0||(intDate[2]%4==0 && intDate[2]%100!=0))//leap year condition
            daysInMonths[1]=29;
        else
            daysInMonths[1]=28;
    }
    if(intDate[0]>daysInMonths[monthNo-1]||intDate[0]<1||monthNo>12||monthNo<1||intDate[2]<1)//condition for date to be invalid
        return 0;
    else
        return 1;//date is valid
}
void text(int *intDate)
{
	int temp,temp1,temp2,flag=0;
	int index;
	char months[12][10]=   {"january","febuary","march","april","may","june","july","august","september",
						    "october","november","december"};
	char days[21][12] =    {"first","second","third","fourth","fifth","sixth","seventh","eigth","nineth",
					        "tenth","eleventh","twelefth","thirteenth","fourteenth","fifteenth","sixteenth",
					        "seventeenth","eigthteenth","nineteenth","twentieth","thirtieth"};
	char yearType1[10][10]={"ten","eleven","tweleve","thirteen","fourteen","fifteen","sixteen","seventeen",
							"eighteen","nineteen"};
	char yearType2[8][10]= {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	char partTwo[9][9]=    {"one","two","three","four","five","six","seven","eight","nine"};

	if(intDate[0]>20 && intDate[0]<30)//checks if the day in the date is the range of 21 to 29
	{
		temp1= intDate[0]%20;
		if(temp1==0)
			printf(" %s",days[19]);
		else
			printf("%s %s",yearType2[0],days[temp1-1]);
	}
	else if(intDate[0] > 29) // checks if the day in the date is 30 or 31 
	{
		temp1= intDate[0]%30;
		if(temp1==0)
			printf(" %s",days[20]);
		else
			printf("%s %s",yearType2[1],days[temp1-1]);
	}
	else // executes when the day in the date is in the range of 1 to 20
		printf("%s",days[intDate[0]-1]);

	printf(" %s",months[intDate[1]-1]); // prints the name of the month

	temp1=intDate[2]%100; //stores the second half of the year  
	temp2=intDate[2]/100; //stores the first half of the year
	if(temp1==0) // if the second half is zero like in 2000 or 4000
	{
		if(temp2 % 10==0)
			printf(" of %s thousand",partTwo[temp2/10 -1]);
		else if(temp2 < 20)
			printf("  of %s hundred",yearType1[temp2%10]);
		else
			printf(" of %s %s hundred",yearType2[temp2/10 -2],partTwo[temp2%10 -1]);

	}
	else if(temp1 < 10)// if the second half of year is single digit like in 5005 or 1904
	{
		if(temp2 % 10 == 0)
			printf(" of %s thousand %s ",partTwo[temp2/10 -1],partTwo[temp1-1]);
		else if(temp2 < 20)
			printf(" of %s hundred %s ",yearType1[temp2%10],partTwo[temp1-1]);
		else
			printf(" of %s %s hundred %s",yearType2[temp2/10 -2],partTwo[temp2%10-1],partTwo[temp1-1]);
	}
	else //if the second half of year is a two digit number like in 2013 or 1857
	{
		if(temp2!=0)
		{
			if(temp2<20) //if the first half of the year is less than 20 like in 1987 or 1857
				printf(" of %s ",yearType1[temp2%10]);
			else if(temp2%10==0) // if the first half of year is divisble by 10 like in 2010 or 4035
				printf(" of %s ",yearType2[temp2/10-2]);
			else // executes when the first half of year is greater 20 and not divisible by 10 like in 3145 or 5634
				printf(" of %s %s ",yearType2[temp2/10-2],partTwo[temp2%10-1]);
		}
		if(temp1 > 9 && temp1 < 20) //if the second half of the year is in the range of 10 to 19 like in 2010 or 4519
			printf(" %s ",yearType1[temp1%10]);
		else if(temp1 > 19)// if the second half of the year is greater than 19
		{
			if(temp1%10==0)// if the second half of the year is divisible by 10 as in 4040 or 3250 
				printf("  %s ",yearType2[temp1/10-2]);
			else // if the second half of the year is greater than 19 and not divisible by 10 as 2015 or 3425
			{
				printf("%s %s",yearType2[temp1/10-2],partTwo[temp1%10-1]);
			}
		}
	}
}
void convert(char *charDate,int intDate[])
{
	int j=0;
	for(int i=0;charDate[i]!='\0';i++)
	{
		if(charDate[i]=='/')
		{
			j++;			
			continue;
		}
		else
		{
			intDate[j]=intDate[j]*10 + (charDate[i]-'0');
		}
	}
}