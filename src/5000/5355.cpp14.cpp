#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
    int no_case;
    cin>>no_case;

    while(no_case--)
    {
        double num;
        cin>>num;
        string str;
        getline(cin, str);
        for(int i=0; i<str.size(); i++)
        {
            switch(str.at(i))
            {
                case ' ':
                break;

                case '@':
                num*=3;
                break;

                case '%':
                num+=5;
                break;

                case '#':
                num-=7;
            }

        }

        printf("%.2lf\n", num);
    }

}