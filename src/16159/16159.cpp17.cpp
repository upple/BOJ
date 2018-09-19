#include <bits/stdc++.h>
using namespace std;

int d[10][2]={{11100, 100010}, {10000, 111110}, {101110, 101010}, {100010, 101010}, {100, 1100}, {111010, 101001}, {111110, 1010}, {100000, 100000}, {111110, 101010}, {1111000, 1001000}};
char arr[7][100];
int dd[10];
vector<int> ans;
int main()
{
    for(int i=0; i<7; i++)
    {
        cin>>arr[i];
    }

    for(int i=0; arr[0][i+1]; i++)
    {
        int a=0, b=0;
        for(int j=0; j<7; j++)
        {
            a*=10, b*=10;
            a+=arr[j][i]-'0';
            b+=arr[j][i+1]-'0';
        }

        for(int j=0; j<10; j++)
        {
            if(a==d[j][0] && b==d[j][1])
            {
                ans.push_back(j);
                dd[j]=i/6;
                break;
            }
        }
    }

    if(next_permutation(ans.begin(), ans.end()))
    {
        for(int i=0; i<7; i++)
        {
            for(int a : ans)
            {
                for(int j=0; j<6; j++)
                {
                    cout<<arr[i][dd[a]*6+j];
                }
            }
            cout<<"\n";
        }
    }

    else cout<<"The End";
}