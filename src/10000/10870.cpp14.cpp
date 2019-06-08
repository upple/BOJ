#include<iostream>
#include<vector>
#include<string>

using namespace std;

int fibo[21]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765};
using namespace std;

int main()
{
	int num;
	cin>>num;
	cout<<fibo[num]<<endl;
}
