#include <cstdio>
using namespace std;

int main()
{
	int n;
	int ansx=0, ansy=0;
	char arr[101][101]={};
	scanf("%d", &n);
	for(int i=0; i<n; i++)
        scanf("%s", &arr[i]);

	for(int i=0; i<=n; i++)
	{
		int countx=0, county=0;
		for(int j=0; j<=n; j++)
		{
			if(arr[i][j]=='.')
				countx++;

			else if(arr[i][j]=='X'|| j==n)
			{
				if(countx>=2)
					ansx++;

				countx=0;
			}
			if(arr[j][i]=='.')
				county++;

			else if(arr[j][i]=='X'|| j==n)
			{
				if(county>=2)
					ansy++;

				county=0;
			}

		}

	}
	printf("%d %d", ansx, ansy);
}

