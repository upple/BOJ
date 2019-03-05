#include<iostream>
#include<string>
using namespace std;

class Student
{
private:
	string name;
	int  day, month, year, birth;

public: 
	Student()
	{
		cin >> name >> day >> month >> year;
		birth = year * 10000 + month * 100 + day;
	}

	int getBirth()
	{
		return birth;
	}

	void printName()
	{
		cout << name << endl;
	}
};

int main()
{
	int no_student;
	cin >> no_student;
	Student *stdt = new Student[no_student];

	for (int i = 0; i < no_student-1; i++)
	{
		if (stdt[i].getBirth() > stdt[i+1].getBirth())
			swap(stdt[i], stdt[i + 1]);
	}

	for (int i = no_student - 2; i > 0; i--)
	{
		if(stdt[i].getBirth()<stdt[i-1].getBirth())
			swap(stdt[i], stdt[i - 1]);
	}

	stdt[no_student - 1].printName();
	stdt[0].printName();

	return 0;
}
