#include <iostream>
#include <vector>

using namespace std;

int cash[45]={1, 1};
int last_pos=1;
int fibo(int n)
{
    if(n<1)
        return 0;

    else if(cash[n-1]==0)
    {
        for(int i=last_pos+1; i<45; i++)
            cash[i]=cash[i-1]+cash[i-2];

        last_pos=n-1;
    }

    return cash[n-1];
}

int main()
{
    int num, a, b;
    cin>>num;
    a=fibo(num-1);
    b=fibo(num);
    cout<<a<<" "<<b<<endl;
    
}
