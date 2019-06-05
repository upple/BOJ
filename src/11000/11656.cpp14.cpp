#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	string str;
	vector<string> post;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
		post.push_back(str.substr(i, str.size()));

	sort(post.begin(), post.end());

	for (int i = 0; i < str.size(); i++)
		cout << post.at(i) << "\n";

	return 0;
}
