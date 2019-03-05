#include <cstdio>
#include <vector>
using namespace std;

class baloon
{
public:
	int num;
	int next;
};
int main(void)
{
	vector<baloon> arr;
	int no_case, pos=0;
	scanf("%d", &no_case);
	arr.resize(no_case);
	for (int i = 0; i < no_case; i++)
		arr[i].num=i+1, scanf("%d", &arr[i].next);

	while (no_case--)
	{
		int next = arr[pos].next;
		if (next > 0)
			next--;

		printf("%d ", arr[pos].num);
		if (!no_case)
			break;

		arr.erase(arr.begin() + pos);
		pos = pos+next;
		if (pos < 0)
			pos = (no_case*(-pos)) + pos;

		pos %= no_case;
	}

	return 0;
}
