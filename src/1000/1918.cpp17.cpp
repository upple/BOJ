#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;
string str;

int main()
{
    stack<char> S;
    string str;
    cin>>str;

    for(char c : str)
    {
        if(isalpha(c)) cout<<c;
        else if(c=='+' || c=='-')
        {
            while(S.size())
            {
                if(S.top()=='(') break;
                cout<<S.top();
                S.pop();
            }
            S.push(c);
        }
        else if(c=='*' || c=='/')
        {
            while(S.size())
            {
                if(S.top()=='(' || S.top()=='+' || S.top()=='-') break;
                cout<<S.top();
                S.pop();
            }
            S.push(c);
        }
        else if(c=='(')
        {
            S.push(c);
        }
        else
        {
            while(S.size())
            {
                char a=S.top();
                S.pop();
                if(a=='(') break;
                cout<<a;
            }
        }
        
        
    }
    while(S.size())
    {
        char a=S.top();
        S.pop();

        if(a=='(') continue;
        cout<<a;
    }
}