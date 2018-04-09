#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> arr(9);
	int sum = 0, more;
	for (int i = 0; i < 9; i++)
		scanf("%d", &arr[i]), sum+=arr[i];

	more = sum - 100;

	for(int i=0; i<9; i++)
		for (int j = i + 1; j < 9; j++)
			if (arr[i] + arr[j] == more)
			{
				arr.erase(arr.begin() + j), arr.erase(arr.begin() + i);
				i = 9;
				break;
			}

	sort(arr.begin(), arr.end());
	for (int i = 0; i < 7; i++)
		printf("%d\n", arr[i]);
	
	return 0;
}