#include<iostream>
#include<string>

using namespace std;

int main()
{
    int no_case;
    cin>>no_case;

    while(no_case--)
    {
        string num;
        cin>>num;

        int k=num.size()/2;
        int n1, n2;
        switch(num.size()%2)
        {
            case 0:
            n1=num.at(k-1), n2=num.at(k);
            break;

            case 1:
            n1=num.at(k-2), n2=num.at(k);
        }

        if(n1==n2)
            cout<<"Do-it";

        else
            cout<<"Do-it-Not";

        cout<<endl;
    }

    return 0;
}