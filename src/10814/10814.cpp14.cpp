#include<cstdio>
#include<algorithm>

using namespace std;

class People
{
public:
	int age;
	char name[101];
	People()
	{}
};

bool inline compare(const People &a, const People &b)
{
	return a.age - b.age<0;
}

int main()
{
	int no_case;
	scanf("%d", &no_case);
	People arr[100000];

	for (int i = 0; i<no_case; i++)
		scanf("%d %s", &arr[i].age, arr[i].name);

	stable_sort(arr, arr + no_case, compare);

	for (int i = 0; i<no_case; i++)
		printf("%d %s\n", arr[i].age, arr[i].name);

	return 0;
}
