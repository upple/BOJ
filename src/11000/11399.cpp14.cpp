#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int no_person, ans=0;
    cin>>no_person;

    int *line=new int[no_person];
    for(int i=0; i<no_person; i++)
        cin>>line[i];

    sort(line, line+no_person);

    for(int i=0; i<no_person; i++)
        ans+=line[i]*(no_person-i);

    cout<<ans<<endl;
    return 0;
}