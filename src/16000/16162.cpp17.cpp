#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, int> M;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, d;
	cin>>n>>a>>d;
	int ans=0;
	for(int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		if(x==a) M[x]=1;
		else if(x>=d+a && M[x-d]>0) M[x]=max(M[x], M[x-d]+1);
		ans=max(ans, M[x]);
	}

	cout<<ans;
}