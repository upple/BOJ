#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> arr;
	int no_case;
	cin>>no_case;
	while(no_case--)
	{
		int num;
		cin>>num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	for(int i=0; i<arr.size(); i++)
		cout<<arr.at(i)<<endl;
		
	return 0;
}
