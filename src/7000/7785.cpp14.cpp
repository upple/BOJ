#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, bool> M;
    string name, con;
    int m;
    cin>>m;
    while(m--)
    {
        cin>>name>>con;
        if(con=="enter")
            M[name]=true;
            
        else
            M.erase(name);
    }
    
    for(auto i=M.rbegin(); i!=M.rend(); i++)
        cout<<i->first<<"\n";
}    


