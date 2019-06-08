#include<cstdio>

using namespace std;

int main()
{
	int arr[10001]={};
	for(int i=1; i<=10000; i++)
	{
		int num=i;
		while(1)
		{
			int temp=num;
			while(temp)
				num+=temp%10, temp/=10;

			if(num>10000 || arr[num])
				break;

			arr[num]=1;
		}
	}
	for(int i=1; i<=10000; i++)
		if(!arr[i])
			printf("%d\n", i);
}
