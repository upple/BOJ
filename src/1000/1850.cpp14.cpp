#include<iostream>
using namespace std;

unsigned long long big(unsigned long long n1, unsigned long long n2)
{
	if (n2%n1 == 0)
		return n1;

	return big(n2%n1, n1);
}
int main()
{
	unsigned long long n1, n2;
	cin >> n1 >> n2;

	if (n2 < n1)
		swap(n1, n2);

	unsigned long long num = big(n1, n2);
	for (unsigned long long i = 0; i < num; i++)
		cout << "1";

	cout << endl;
	return 0;
}