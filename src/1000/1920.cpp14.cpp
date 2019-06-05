#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> arr;
	int no_size, no_case, num;
	scanf("%d", &no_size);
	arr.resize(no_size);
	for (int i = 0; i < no_size; i++)
		scanf("%d", &arr[i]);

	sort(arr.begin(), arr.end());
	scanf("%d", &no_case);
	while (no_case--)
	{
		scanf("%d", &num);
		if (binary_search(arr.begin(), arr.end(), num))
			printf("1\n");

		else
			printf("0\n");

	}

	return 0;

}
