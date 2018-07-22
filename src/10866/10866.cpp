#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE=11111;

int deq[MAX_SIZE], frt, bck, dsize;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string cmd;
	int n, num;
	cin>>n;
	while(n--)
	{
		cin>>cmd;
		if(cmd=="push_back")
		{
			cin>>num;
			deq[bck=((bck+1)%MAX_SIZE)]=num;
			++dsize;
		}

		else if(cmd=="push_front")
		{
			cin>>num;
			deq[frt]=num;
			frt=(MAX_SIZE+frt-1)%MAX_SIZE;
			++dsize;
		}

		else if(cmd=="pop_front")
		{
			if(dsize)
			{
				frt=(frt+1)%MAX_SIZE;
				cout<<deq[frt]<<"\n";
				--dsize;
			}

			else
				cout<<"-1\n";
		}
		else if(cmd=="pop_back")
		{
			if(dsize)
			{
				cout<<deq[bck]<<"\n";
				bck=(MAX_SIZE+bck-1)%MAX_SIZE;
				--dsize;
			}
			else
				cout<<"-1\n";
		}
		else if(cmd=="size")
		{
			cout<<dsize<<"\n";
		}
		else if(cmd=="empty")
		{
			cout<<(dsize==0?1:0)<<"\n";
		}
		else if(cmd=="front")
		{
			cout<<(dsize==0?-1:deq[(frt+1)%MAX_SIZE])<<"\n";
		}
		else if(cmd=="back")
		{
			cout<<(dsize==0?-1:deq[bck])<<"\n";
		}
	}
}
