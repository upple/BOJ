#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

class Student
{
public:
	char name[11];
	int korean, english, math;
	Student(char n[], int a, int b, int c) : korean(a), english(b), math(c)
	{
		strcpy(name, n);
	}
	Student() {}
};

bool compare(Student a, Student b)
{
	if (a.korean == b.korean && a.english == b.english && a.math == b.math)
		return strcmp(a.name, b.name)<0;

	else if (a.korean == b.korean && a.english == b.english)
		return b.math<a.math;

	else if (a.korean == b.korean)
		return a.english<b.english;

	else
		return b.korean<a.korean;
}
int main()
{
	int no_case;
	char name[11];
	int k, e, m;

	scanf("%d", &no_case);
	vector<Student> students;
	for (int i = 0; i<no_case; i++)
	{
		scanf("%s %d %d %d", name , &k, &e, &m);
		Student temp(name, k, e, m);
		students.push_back(temp);
	}

	sort(students.begin(), students.end(), compare);
	for (int i = 0; i<no_case; i++)
		printf("%s\n", students[i].name);

	return 0;
}
