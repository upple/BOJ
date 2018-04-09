#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int no_case;

    cin>>no_case;
    for(int i=0; i<no_case; i++)
    {
        unsigned int num;
        bool bi[32]={0, };
        
        cin>>num;
        for(int j=31; j>=0; j--)
        {
            if(num/(unsigned int)pow(2, j)>0)
            {
                num-=(unsigned int)pow(2, j);
                bi[j]=1;
            }
        }

        for(int j=0; j<32; j++)
        {
            if(bi[j])
                cout<<j<<" ";
        }

    }
    return 0;
}
