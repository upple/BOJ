#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

int main()
{//97
    char data[100];
    int alpha[26]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    cin>>data;
    for(int i=0; data[i]!=0; i++)
    {
        if(alpha[data[i]-97]==-1)
            alpha[data[i]-97]=i;

    }

    for(int i=0; i<26; i++)
    {
        cout<<alpha[i]<<" ";

    }
    return 0;
}
