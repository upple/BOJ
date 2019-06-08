#include<cstdio>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main()
{
	unordered_set<int> cards;
	int no_card, no_case;
	scanf("%d", &no_card);
	while(no_card--)
	{
		int card;
		scanf("%d", &card);
		cards.insert(card);
	}

	scanf("%d", &no_case);
	while(no_case--)
	{
		int card;
		scanf("%d", &card);
		if(cards.find(card)==cards.end())
			printf("0 ");

		else
			printf("1 ");
	}

	return 0;
}
