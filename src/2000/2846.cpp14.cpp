#include<iostream>
using namespace std;

int main()
{
    int no_data;
    cin>>no_data;

    int a, b, ans=0, temp=0;
    cin>>a;
    for(int i=1; i<no_data; i++)
    {
        cin>>b;
        if(b-a>0)
            temp+=b-a;

        else
        {
            if(ans<temp)
                ans=temp;

            temp=0;
        }

        a=b;
    }
    if(ans<temp)
        ans=temp;

    cout<<ans<<endl;
    return 0;
}