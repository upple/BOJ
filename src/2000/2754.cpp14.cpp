#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;

int main()
{
	map<string, double> M;

	M["A+"]=4.3, M["A0"]=4.0, M["A-"]=3.7;
	M["B+"]=3.3, M["B0"]=3.0, M["B-"]=2.7;
	M["C+"]=2.3, M["C0"]=2.0, M["C-"]=1.7;
	M["D+"]=1.3, M["D0"]=1.0, M["D-"]=0.7;
	M["F"]=0.0;

	string grade;
	cin>>grade;
	printf("%.1lf", M[grade]);
}
