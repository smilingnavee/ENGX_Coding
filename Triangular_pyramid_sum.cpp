// Triangular_sum.cpp : Defines the entry point for the console application.
/*By starting at the top of the triangle below and moving to adjacent numbers on the row below, 
the maximum total from top to bottom is 23. That is, 3 + 7 + 4 + 9 = 23.

3
7 4
2 4 6
8 5 9 3
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	ifstream in("input.txt");
	if(!in) {
		cout << "Cannot open input file.\n";
		return 1;
	}

	string line;
	vector< vector<int> > input;	

	while ( getline( in, line ) ) {
      istringstream is( line );
	  input.push_back( vector<int>( istream_iterator<int>(is),istream_iterator<int>() ) );
	}
	
	vector<int> &Var = input[0];
	int sum = Var[0];
	int j = 0;
	// Actual Logic
	for (int i = 1 ; i < input.size(); ++i) {
		vector<int> &Var = input[i];
		if(Var[j+1] >Var[j])
			j = j+1;					
		sum += Var[j];
	}

	cout<<"Trianggular Sum = "<<sum<<endl;
	return 0;
}

