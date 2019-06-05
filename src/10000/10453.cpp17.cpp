#include <iostream>
#include <string>
using namespace std;

string a, b;
int solve(int x)
{
    if(x==a.size()-1) return -1;
    if(a[x]!=a[x+1])
    {
        swap(a[x], a[x+1]);
        return 1;
    }

    int tmp=solve(x+1);
    if(tmp==-1) return -1;
    swap(a[x], a[x+1]);
    return tmp+1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        int ans=0;
        for(int i=0; i<a.size()-1; i++)
        {
            if(a[i]!=b[i])
            {
                if(a[i]==a[i+1])
                {
                    int tmp=solve(i+1);
                    if(tmp==-1)
                    {
                        cout<<-1<<"\n";
                        break;
                    }
                    ans+=tmp+1;
                    swap(a[i], a[i+1]);
                }
                else
                {
                    swap(a[i], a[i+1]);
                    ans++;
                }
            }

            if(i==a.size()-2)
            {
                cout<<ans<<"\n";
                break;
            }
        }
    }
}