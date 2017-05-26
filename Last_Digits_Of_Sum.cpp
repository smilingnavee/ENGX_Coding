/*
FIND THE LAST TEN DIGITS OF THE SUM OF SERIES, 11 + 33 + 55... + 999999
ANSWER = 9559449000
*/

#include <iostream>
#include "math.h"
using namespace std;

unsigned long long power(int n)
{
	unsigned long long temp = n;
	for(int i = 1;i<n; i++){
		temp = temp*n;
		temp = temp%10000000000;	
	}
	return temp;
}
int main()
{
	unsigned long long sum= 0;
	for(int i = 1; i<1000;i=i+2) {
		unsigned long long value = power(i);
		sum = sum+value;
	}
	cout<<sum%10000000000<<endl; 
	return 0;
}
