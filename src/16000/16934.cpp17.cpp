#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *next[26];
    int cnt;
};
node *alloc_node()
{
    static node data[1000000];
    static int it=0;
    for(int i=0; i<26; i++)
        data[it].next[i]=0;

    data[it].cnt=0;
    return &data[it++];
}
struct trie
{
    node *root;
    trie()
    {
        root=alloc_node();
    }
    string get_id(string &str)
    {
        string ret;
        bool find=false;
        node *p=root;
        for(int i=0; i<str.size(); i++)
        {
            if(p->next[str[i]-'a']==0) 
            {
                p->next[str[i]-'a']=alloc_node();
                if(find==false) find=true, ret=str.substr(0, i+1);
            }
            p=p->next[str[i]-'a'];
        }

        p->cnt++;
        if(find==false)
        {
            if(p->cnt==1) ret=str;
            else ret=str+to_string(p->cnt);
        }

        return ret;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    trie tr;
    int n;
    string str;
    cin>>n;
    while(n--)
    {
        cin>>str;
        cout<<tr.get_id(str)<<'\n';
    }
}