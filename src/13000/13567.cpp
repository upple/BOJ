#include <iostream>
#include <string>
using namespace std;

int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
int main()
{
	int m, n, d;
	string cmd;
	cin>>m>>n;

	int x=0, y=0, cd=0;
	while(n--)
	{
		cin>>cmd>>d;
		if(cmd=="MOVE")
		{
			x=x+dx[cd]*d, y=y+dy[cd]*d;
			if(x<0 || x>=m || y<0 || y>=m)
			{
				cout<<-1;
				return 0;
			}
		}
		else
		{
			cd=(d?(cd+3)%4:(cd+1)%4);
		}

	}

	cout<<x<<" "<<y;
}
