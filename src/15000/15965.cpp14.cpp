#include <cstdio>
#include <vector>
using namespace std;
bool arr[10000001];
vector<int> P;
int main()
{
	int k;
	scanf("%d", &k);
	for(int i=2; i<=10000000; i++)
	{
		if(!arr[i])
		{
			P.push_back(i);
			if(P.size()==k) break;
 
			int tmp=i;
			while((tmp+=i)<=10000000)
			{
				arr[tmp]=1;
			}
		}
	}
 
	printf("%d", P.back());
}