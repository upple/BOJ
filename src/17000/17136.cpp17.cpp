#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
bool arr[12][12];
int p[]={5, 5, 5, 5, 5};
int global_min=INF;
int solve(int x, int y, int c)
{
    for(int i=x; i<=10; i++)
    {
        for(int j=y; j<=10; j++)
        {
            if(arr[i][j]==0) continue;
			if(c+1==global_min) return c+1;
            int min_x=5, min_y=5;
            for(int k=0; k<min_x; k++)
            {
                for(int l=0; l<min_y; l++)
                {
                    if(arr[i+k][j+l]==0)
                    {
                        min_x=min_y=min(min_x, max(k, l));
                    }
                }
            }

            int size=min_x;
            int ans=INF;
            for(int k=0; k<size; k++)
            {
                for(int l=0; l<=k; l++)
                {
                    arr[i+l][j+k]=0;
                    arr[i+k][j+l]=0;
                }

                if(p[k])
                {
                    p[k]--;
                    ans=min(ans, solve(i, j+1, c+1));
                    p[k]++;
                }
            }

            for(int k=0; k<size; k++)
            {
                for(int l=0; l<size; l++)
                {
                    arr[i+k][j+l]=1;
                }
            }

            return ans;
        }
        y=1;
    }

	global_min=min(global_min, c);
    return c;
}
int main()
{
    for(int i=1; i<=10; i++)
    {
        for(int j=1; j<=10; j++)
        {
            cin>>arr[i][j];
        }
    }
    
    int ans=solve(1, 1, 0);
    cout<<(ans==INF?-1:ans);
}