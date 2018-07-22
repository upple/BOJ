#include<cstdio>
using namespace std;
class Tree
{
	class Node
	{
	public:
		Node *num[10];
		bool last;
		Node(): last(false)
		{
			for(int i=0; i<10; i++)
				num[i]=NULL;
		}

	};

	Node *node;
public:
	Tree()
	{
		node=new Node();
	}
	~Tree()
	{
		delete node;
	}
	bool isFill(char *str)
	{
		Node *p=node;
		bool f=true;

		for(int i=0; *(str+i); i++)
		{
			if(p->last==true)
				return true;

			if(p->num[str[i]-'0']==NULL)
				f=false, p->num[str[i]-'0']=new Node();

			p=p->num[str[i]-'0'];
		}

		p->last=true;
		return f;
	}
};
int main()
{
	char num[11];
	bool end;
	int no_case, no_data;
	scanf("%d", &no_case);
	while(no_case--)
	{
		Tree tree;
		end=false;
		scanf("%d", &no_data);
		for(int i=0; i<no_data; i++)
		{
			scanf("%s", num);
			if(!end && tree.isFill(num))
			{
				end=true;
				printf("NO\n");
			}

			else if(i==no_data-1 && !end)
			{
				printf("YES\n");
				break;
			}
		}
	}

	return 0;
}
