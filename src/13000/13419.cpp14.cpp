#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        string a="", b="", d;
        cin>>d;
        int size=d.size();
        for(int i=0; i<size; i++)
        {
            if(i%2)
                b+=d[i];
            else
                a+=d[i];
        }

        if(size%2)
        {
            string temp=b;
            b+=a;
            a+=temp;
        }

        cout<<a<<endl<<b<<endl;
    }
}
