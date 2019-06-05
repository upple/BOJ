#include <bits/stdc++.h>
using namespace std;

int arr[10][3]={{31, 17, 31}, {0, 31, 0}, {23, 21, 29}, {21, 21, 31}, {28, 4, 31}, {29, 21, 23}, {31, 21, 23}, {16, 16, 31}, {31, 21, 31}, {29, 21, 31}};
int main()
{
	int n;
	cin>>n;
	string str;
	cin>>str;
	if(str.size()<15)
	{
		if(str[0]=='#' || str[1]=='#')
		{
			cout<<1;
			return 0;
		}
	}
	for(int i=0; i<str.size()/5-2; i++)
	{
		int a=0, b=0, c=0;
		for(int j=0; j<5; j++)
		{
			a<<=1;
			b<<=1;
			c<<=1;
			a+=(str[j*str.size()/5+i]=='#');
			b+=(str[j*str.size()/5+i+1]=='#');
			c+=(str[j*str.size()/5+i+2]=='#');
		}
		
		for(int j=0; j<10; j++)
		{
			if(a==arr[j][0] && b==arr[j][1] && c==arr[j][2])
			{
				cout<<j;
				break;
			}
			if(j==9)
			{
				if(i==0)
				{
					if(a==31 && b==0)
					{
						cout<<1;
					}
				}
				else if(i==str.size()/5-3)
				{
					if(b==0 && c==31)
					{
						cout<<1;
					}
				}
			}
		}
	}
}