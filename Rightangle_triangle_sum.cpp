// Triangular_sum.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
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
	// Logic to find maximum of three adjacent members
	for (int i = 1 ; i < input.size(); ++i) {
		vector<int> &Var = input[i];
			int local_max = Var[j];
			int local_index = j;
			if(Var[j+1] > local_max) {
				local_max = Var[j+1];
				local_index = j+1; 
			}	
			if(j-1 >=0 && (Var[j-1] > local_max)){
				local_max = Var[j-1];
				local_index = j-1;
			}
			sum +=local_max;
			j = local_index;
	}
	cout<<"Triangular Sum = "<<sum<<endl;
	return 0;
}

