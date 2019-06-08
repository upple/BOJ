#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	int num;
	while (1)
	{
		scanf("%d", &num);
		if (num == -1)
			return 0;

		int sum = 1, root=(int)sqrt(num);
		vector<int> v1, v2;
		for (int i = 2; i <= root; i++)
		{
			if (i*i == num)
				sum+=i, v1.push_back(i);

			else if (!(num%i))
				sum+=i+num/i, v1.push_back(i), v2.push_back(num / i);
		}
		if (sum == num)
		{
			printf("%d = 1", num);
			for (auto i = v1.begin(); i != v1.end(); i++)
				printf(" + %d", *i);

			for (auto i = v2.rbegin(); i != v2.rend(); i++)
				printf(" + %d", *i);

			printf("\n");
		}

		else
			printf("%d is NOT perfect.\n", num);
	}
}