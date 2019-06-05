#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll threeple[50];
ll n, m, k;
vector<int> arr;

void chk()
{
    static int u=0;
    if(u==k)
    {
        for(int i=1; i<=n; i++)
            cout<<arr[i]<<' ';

        exit(0);
    }
    u++;
}
void solve2(int n, int f, int t)
{
	if(n==0) return;
	int m=6-f-t;
	if((t+3-f)%3==1)
	{
		solve2(n-1, f, m);
		arr[n]=t;
        chk();
		solve2(n-1, m, t);
	}
	else
	{
		solve2(n-1, f, t);
		arr[n]=m;
        chk();
		solve2(n-1, t, f);
		arr[n]=t;
		chk();
		solve2(n-1, f, t);
	}
}
int main()
{
    cin>>m>>n>>k;
    threeple[0]=1;
    for(int i=1; i<=40; i++)
        threeple[i]=threeple[i-1]*3;

    switch(m)
    {
        case 1:

        for(int i=1; i<=n; i++)
        {
            if(k<(1LL<<(i-1))) 
            {
                cout<<1<<' ';
                continue;
            }
            if((n-i)%2)
            {
                cout<<(((k-(1LL<<(i-1)))>>i)+1)%3+1<<' ';
            }
            else
            {
                cout<<3-(((k-(1LL<<(i-1)))>>i))%3<<' ';
            }
            
        }
        break;
        case 2:
        for(int i=1; i<=n; i++)
        {
            ll q=k%(threeple[i]*2);
            if(q/threeple[i]==0)
            {
                cout<<q%threeple[i]/threeple[i-1]+1<<' ';
            }
            else
            {
                cout<<3-(q%threeple[i]/threeple[i-1])<<' ';
            }
           
        } break;
        case 3:
        {
            arr.assign(n+1, 1);
            chk();
            solve2(n, 1, 3);
        }
    }

    return 0;
}