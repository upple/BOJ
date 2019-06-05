#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        string url;
        cin>>url;
        cout<<"URL #"<<i<<'\n';
        cout<<"Protocol = ";
        int state=0;
        for(int i=0; i<url.size(); i++)
        {
            switch(state)
            {
                case 0:
                if(url[i]==':')
                {
                    i+=2;
                    state=1;
                    cout<<"\nHost     = ";
                    break;
                }
                cout<<url[i];
                break;
                case 1:
                if(url[i]==':' || url[i]=='/')
                {
                    cout<<"\nPort     = ";
                    if(url[i]==':')
                    {
                        state=2;
                        break;
                    }
                    else
                    {
                        state=3;
                        cout<<"<default>\nPath     = ";
                        break;
                    }
                }
                cout<<url[i];
                break;
                case 2:
                if(url[i]=='/')
                {
                    state=3;
                    cout<<"\nPath     = ";
                    break;
                }
                cout<<url[i];
                break;
                case 3:
                cout<<url[i];
            }
        }
        if(state<2)
            cout<<"\nPort     = <default>";

        if(state<3)
            cout<<"\nPath     = <default>";

        cout<<"\n\n";
    }
}