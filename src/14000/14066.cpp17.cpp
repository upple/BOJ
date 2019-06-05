#include <bits/stdc++.h>
using namespace std;

char sq[6][8]={"..+---+", "./   /|", "+---+ |", "|   | +", "|   |/.", "+---+.."};

char arr[251][301];
int input[51][51];
int n, m, sx, sy;

void draw(int x, int y)
{
	for(int c=0; c<input[x][y]; c++)
	{		
		for(int i=0; i<6; i++)
		{
			for(int j=0; j<7; j++)
			{
				if(sq[i][j]=='.') continue;
				arr[sx-c*3+x*2+i][sy+y*4-x*2+j]=sq[i][j]; 
			}
		}

	}

}
int main()
{
	cin>>n>>m;
	sy=(n-1)*2;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin>>input[i][j];
			sx=max(sx, (input[i][j]-1)*3-i*2);
		}
	}

	for(int j=0; j<m; j++)
		for(int i=0; i<n; i++)
			draw(i, j);

	for(int i=0; i<=sx+n*2+3; i++)
	{
		for(int j=0; j<=sy+m*4+2; j++)
		{
			cout<<(arr[i][j]==0?'.':arr[i][j]);
		}
		cout<<"\n";
	}
}