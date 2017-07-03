// Find_number_peopple.cpp : Defines the entry point for the console application.
/*
Problem Statement
---------------------------------------------------------------------------------------------------------------------------------
You are the greatest builder who has recently acquired a construction project where in you are supposed to build house/houses on bare land . 
Constraints:
1.	You have to finish the project within given budget (total cost)
2.	You should accommodate maximum number of homeless.
While you have limited cost to complete the project, the land is limitless, hence you can create any number of houses.

Each house type has cost and can accommodate fixed number of people, stored as a pair : 
1.	An integer representing the cost of the house
2.	An integer representing the number of people it can accommodate

For example:
# costs 7 Lakhs and can accommodate 160 people (7, 160)
# costs 3 Lakhs and can accommodate 90 people (3, 90)

Write a program that takes a list of house types and a cost limit, and returns the maximum number of homeless people the houses can accommodate.  
For example: 
                             Input:
house_types  = [(7, 160), (3, 90), (2, 15)]
cost_limit         = 20 (lakhs)

Output:
555 (6 of the 3 Lakhs type of house and 1 of the 2 Lakhs of house;     Total Number: 90*6 + 15*1 = 555;    Cost Limit: 3*6 + 2*1 = 20 Lakhs)
-------------------------------------------------------------------------------------------------------------------------------
Algorithm
-------------------------------------------------------------------------------------------------------------------------------
L =  limit
N = number of people
M[L] =  maximum number of people that can be fit in a building of cost L

M[L] =  max { M[L-Ci] +Ni, M[L-1]}   where Ci = cost limit of ith  type house,  Ni = number of pople in ith type house 
i will vary from 0 - size of input array
---------------------------------------------------------------------------------------------------------------------------------
Input
---------------------------------------------------------------------------------------------------------------------------------
house_types   = [(7,50), (3, 25), (2, 15), (5, 35), (15, 100), (11,77), (13,111) ]
cost_limit    = 10000
---------------------------------------------------------------------------------------------------------------------------------
Output
---------------------------------------------------------------------------------------------------------------------------------
85384

*/

#include<iostream>
using namespace std;

int find_max(int index, int House_Cost[], int People_Limit[], int Max_People[]) {
	int temp[7];
	int max = Max_People[index-1];
	for(int i=0;i<7;i++) {
		int local = index-House_Cost[i];
		if(local > 0)
			temp[i]= Max_People[index-House_Cost[i]] + People_Limit[i];
		else
			temp[i]=0;
		if(temp[i] > max)
			max = temp[i];
	}
	return max;
}

int Max_People_Count(void) {
	int House_Cost[]= {7,3,2,5,15,11,13};
	int People_Limit[]= {50,25,15,35,100,77,111};
	int Cost_Limit = 10000;
	int Cost_Limit_Index = Cost_Limit + 2; //+2 is for array index which start from 0
	int *Max_People=new int[Cost_Limit_Index];
	Max_People[0]=0;
	for(int i = 1;i <Cost_Limit_Index;i++){
		Max_People[i] = find_max(i, House_Cost, People_Limit, Max_People);
	}
	return Max_People[Cost_Limit_Index-1];
}

int main()
{
	cout<<"Maximum number of homeless people the houses can accommodate = "<<Max_People_Count()<<endl;
}

