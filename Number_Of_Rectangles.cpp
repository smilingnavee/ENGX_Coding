// Number_Of_Rectangles.cpp : Defines the entry point for the console application.
//Problem Statement: Find all coordinates from the dataset enclosed, which form a rectangle. 
//Points are given in x,y format. One can assume that we are only considering rectangles parallel to X and Y Axis.

/*
INPUT FORMAT of file
------------------
-125,122
23,149
-67,11
35,12
-75,82
-17,71
75,47
-125,58
87,114
94,-86
-16,-87
1,73
-128,0
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct point
{
	int x;
	int y;
};

struct line
{
	point p1;
	point p2;
};

int main()
{
	ifstream in("Rectangles.txt");

	if(!in) {
		cout << "Cannot open input file.\n";
		return 1;
	}

	string line;
	int p_x = 0, p_y =  0;
	char ch;
	vector<pair<int,int>> Points_Vector;
	int i= 0;
	//Reading from file and storing the points in vector
	while(getline(in, line)) {
		istringstream iss(line);
		if (!(iss >> p_x >> ch >> p_y)) {
			cerr << "Input parsing error !!! - " << line << endl;
			break; // error
		}
		Points_Vector.push_back(make_pair(p_x,p_y));
		i++;
	}
	i = Points_Vector.size();

	sort(Points_Vector.begin(), Points_Vector.end());

	int j =0, k=0;
	//Vector which stores Horizontal points
	vector<struct line> Horizontal_Lines;

	//Logic to find Horizontal Lines
	for(j=0; j<i-1; j++) {
		for(k=j+1; k<i; k++) {
			// Horizontal Line found from two points
			if((Points_Vector[j].second == Points_Vector[k].second) && (Points_Vector[j].first != Points_Vector[k].first)) {
				struct line line_obj;
				line_obj.p1.x=Points_Vector[j].first;
				line_obj.p1.y=Points_Vector[j].second;
				line_obj.p2.x=Points_Vector[k].first;
				line_obj.p2.y=Points_Vector[k].second;
				Horizontal_Lines.push_back(line_obj);
			}
		}
	}

	i = Horizontal_Lines.size();
	int count =1;
	//Logic to find points which form rectangle
	for(j=0; j<i-1;j++) {
		for(k=j+1;k<i;k++) {
			// Rectangle Found
			if(((Horizontal_Lines[j].p1.x == Horizontal_Lines[k].p1.x) && (Horizontal_Lines[j].p2.x == Horizontal_Lines[k].p2.x))) {
				cout<<"Rectangle "<<count++<<":";
				cout<<"["<<Horizontal_Lines[j].p1.x<<","<<Horizontal_Lines[j].p1.y<<"]["
					<<Horizontal_Lines[k].p1.x<<","<<Horizontal_Lines[k].p1.y<<"]["
					<<Horizontal_Lines[j].p2.x<<","<<Horizontal_Lines[j].p2.y<<"]["
					<<Horizontal_Lines[k].p2.x<<","<<Horizontal_Lines[k].p2.y<<"]"<<endl;
			}
		}
	}
	return 0;
}