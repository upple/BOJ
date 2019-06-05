#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

/*
    segment tree algorithm
    created by Choi Chang Gyu.
                                */

typedef long long ll;
ll tree[4 * MAX];
int n, m, k, s;

void update(int p, ll x)
{
    p += s - 1;
    ll old_value = tree[p];
    while (p)
    {
        tree[p] += x - old_value;
        p >>= 1;
    }
}

ll query(int l, int r, int p, int x, int y)
{
    if (l > y || r < x) return 0;
    if (l <= x && r >= y) return tree[p];
    int mid = (x + y) >> 1;
    return query(l, r, p << 1, x, mid) + query(l, r, (p << 1) + 1, mid + 1, y);
}

int main()
{
    cin >> n >> m >> k;               // n : number of element, m : number of query
    s = 1 << int(ceil(log2(n))); // start point

    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x; // value of i'th element
        update(i, x);
    }

	m += k;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) update(b, ll(c));    				// query (change value of b to c)
        else cout << query(b, c, 1, 1, s) << "\n";  // query (return sum of from b to c)
    }
}