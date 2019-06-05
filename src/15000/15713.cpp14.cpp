#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
pair<ll, ll> arr[100000];
struct ch{
	ll c, h;
};
inline bool operator<(const ch& a, const ch& b)
{
	if (a.c + a.h != b.c + b.h)
		return a.c + a.h > b.c + b.h;

	return a.c > b.c;
}
priority_queue<ch> pq;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, s;
    cin>>n>>s;
    for(int i=0; i<n; i++)
    {
        ll a, b;
        cin>>a>>b;
        arr[i]={a, b};
    }

    sort(arr, arr+n);
    pq.push({0, 0});
    for(int i=0; i<n; i++)
    {
		while(arr[i].first>pq.top().h)
        {
			if (pq.top().h == s)
			{
				cout << pq.top().c;
				return 0;
			}
            pq.pop();
            if(pq.empty())
            {
                cout<<"Ducks can't fly";
                return 0;
            }
        }

		ll h = pq.top().h, c = pq.top().c;

		if (arr[i].first + arr[i].second > s)
			pq.push({ c + s - arr[i].first + h - arr[i].first , s });

        else
            pq.push({c - arr[i].first +arr[i].second+h, arr[i].first+arr[i].second});
    }

	while (pq.size())
	{
		if (pq.top().h == s)
		{
			cout << pq.top().c;
			return 0;
		}
		pq.pop();
	}
    cout<<"Ducks can't fly";
    return 0;
}