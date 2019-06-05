#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int y=0, k=0, a, b;
		for(int i=0; i<9; i++)
		{
			scanf("%d %d", &a, &b);
			y+=a, k+=b;
		}

		if(y==k)
			printf("Draw\n");

		else
			printf("%s\n", y>k?"Yonsei":"Korea");
	}

}
