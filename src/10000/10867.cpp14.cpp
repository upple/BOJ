#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> arr;
	int no_data, pos = 1001;
	scanf("%d", &no_data);

	while (no_data--)
	{
		int num;
		scanf("%d", &num);
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++)
	{
		if (pos != arr.at(i))
			pos = arr.at(i), printf("%d ", pos);
	}

	printf("\n");
	return 0;

}