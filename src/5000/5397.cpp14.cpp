#include <cstdio>
#include <list>
#include <cstring>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		list<char> text;
		char input[1000001];
		auto it=text.begin();
		scanf("%s", input);

		for(int i=0; input[i]; i++)
		{
			switch(input[i])
			{
			case '<':
				if(it!=text.begin())
					--it;

				break;
			case '>':
				if(it!=text.end())
					++it;

				break;
			case '-':
				if(it!=text.begin())
					it=text.erase(--it);

				break;
			default:
				text.insert(it, input[i]);
			}
		}

		for(auto &j : text)
			printf("%c", j);

		printf("\n");
	}

}
