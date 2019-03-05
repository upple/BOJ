#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
    int num, l, t=0;
    int d=0, r, g, t_d;
    cin>>num>>l;

    for(int i=0; i<num; i++)
    {
        t_d=d;
        cin>>d>>r>>g;
        t+=(d-t_d);

        if(t%(r+g)<r)
            t+=r-(t%(r+g));
    }

    t+=l-d;

    cout<<t<<endl;

    return 0;
}
