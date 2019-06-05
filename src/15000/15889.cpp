#include <iostream>
#define MAX 30000
using namespace std;

int arr[MAX], s, t, n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];

    for(int i=0; i<n-1; i++)
    {
        cin>>s;
        if(arr[i]>t)
            break;

        t=max(t, s+arr[i]);
    }

    cout<<(t>=arr[n-1]?"권병장님, 중대장님이 찾으십니다":"엄마 나 전역 늦어질 것 같아");
}