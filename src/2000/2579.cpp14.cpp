#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> max_score;
int cascade[300];

int get_score(int n)
{
	if (n * 2 <= max_score.size()+2)
		return max(max_score[n*2], max_score[n*2+1]);

	for (int i = max_score.size()/2-1 ; i < n; i++)
	{
		max_score.push_back(max_score.at(i*2+1) + cascade[i]);
		max_score.push_back(max(max_score.at(i*2-2), max_score.at(i*2-1))+ cascade[i]);
	}

	return max(max_score[n*2], max_score[n*2+1]);
}
int main()
{
	int no_cascade, pos, ans;

	scanf("%d", &no_cascade);
	for (int i = 0; i < no_cascade; i++)
		scanf("%d", &cascade[i]);

	max_score.push_back(0);
	max_score.push_back(0);
	max_score.push_back(cascade[0]);
	max_score.push_back(cascade[0]);
	printf("%d\n", get_score(no_cascade));
	return 0;
}
