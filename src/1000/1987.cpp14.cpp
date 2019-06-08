#include <cstdio>
#define max(x, y) (x>y?x:y)
using namespace std;
const int move_x[4]={0, 0, 1, -1};
const int move_y[4]={1, -1, 0, 0};

bool alpha[26]={};
char arr[20][21];
int r, c;

int dfs(int x, int y)
{
	static int mx=0;
	static int pos=0;
	pos++;
	for(int i=0; i<4; i++)
	{
		int nx=x+move_x[i], ny=y+move_y[i];
		if(nx>=0 && nx<r && ny>=0 && ny<c && !alpha[arr[nx][ny]-'A'])
			alpha[arr[nx][ny]-'A']=true, dfs(nx, ny);
	}
	mx=max(mx, pos);
	pos--, alpha[arr[x][y]-'A']=false;
	return mx;
}
int main()
{
	scanf("%d %d", &r, &c);

	for(int i=0; i<r; i++)
		scanf("%s", &arr[i]);

	alpha[arr[0][0]-'A']=true;
	printf("%d", dfs(0, 0));
}
