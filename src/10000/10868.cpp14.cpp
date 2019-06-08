#include<cstdio>
#include<vector>
using namespace std;
class Tree
{
public:
    class Node
    {
    public:
        int s, e, mid;
        int min;
        Node *left, *right;
        Node(int a, int b): s(a), e(b), min(1000000001)
        {
            mid=(s+e)/2;
            left=right=NULL;
        }
    };
    Node *root;
    Tree(int s, int e)
    {
        root=new Node(s, e);
    }
    void push(int pos, int val)
    {
        Node *p=root;
        while(1)
        {
            p->min=p->min<val?p->min:val;
            if(p->s==p->e)
                return;
            if(pos<=p->mid)
            {
                if(p->left==NULL)
                    p->left=new Node(p->s, p->mid);

                p=p->left;
            }
            else
            {
                if(p->right==NULL)
                    p->right=new Node(p->mid+1, p->e);

                p=p->right;
            }
        }
    }
    int getMin(Node &p, int begin, int end)
    {
        if(p.s>=begin && p.e<=end)
            return p.min;

        else if(p.mid<begin)
            return getMin(*p.right, begin, end);

        else if(p.mid>=end)
            return getMin(*p.left, begin, end);

        else
        {
            int m1=getMin(*p.right, begin, end);
            int m2=getMin(*p.left, begin, end);
            return m1<m2?m1:m2;
        }

    }
};
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    Tree tree(1, n);

    for(int i=1; i<=n; i++)
    {
        int val;
        scanf("%d", &val);

        tree.push(i, val);
    }

    while(m--)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", tree.getMin(*tree.root, s, e));
    }
}
