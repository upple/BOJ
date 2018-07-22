#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        map<int, int>M;
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            char c;
            int num;
            cin>>c>>num;
            if(c=='I')
                M[num]++;

            else if(c=='D')
            {
                if(M.empty())
                    continue;
                else
                {
                    auto s=M.begin();
                    if(num>0)
                        s=--M.end();

                    if(s->second==1)
                        M.erase(s->first);

                    else
                        s->second--;
                }

            }
        }

        if(M.empty())
            cout<<"EMPTY\n";

        else
            cout<<(--M.end())->first<<" "<<M.begin()->first<<"\n";
    }
}
