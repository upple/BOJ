#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cube[25];
int pattern[3][2][4]={{{1, 2, 3, 4}, {9, 10, 11, 12}}, {{5, 6, 7, 8}, {21, 22, 23, 24}}, {{13, 14, 15, 16}, {17, 18, 19, 20}}};
int check[3][2][4][4]={{{{13, 14, 7, 8}, {5, 6, 19, 20}, {17, 18, 23, 24},{21, 22, 15, 16}}, {{5, 6, 15, 16}, {17, 18, 7, 8}, {21, 22, 19, 20}, {13, 14, 23, 24}}}, 
                    {{{3, 4, 18, 20}, {17, 19, 11, 12}, {9, 10, 13, 15}, {14, 16, 1, 2}}, {{3, 4, 13, 15}, {14, 16, 11, 12}, {9, 10, 20, 18}, {19, 17, 1, 2}}}, 
                    {{{1, 3, 6, 8}, {5, 7, 10, 12}, {9, 11, 21, 23}, {22, 24, 2, 4}}, {{1, 3, 21, 23}, {22, 24, 10, 12}, {9, 11, 6, 8}, {5, 7, 2, 4}}}};

bool same(int a[])
{
    for(int i=1; i<4; i++)
    {
        if(cube[a[i]]!=cube[a[0]]) return false;
    }
    return true;
}
int main()
{
    for(int i=1; i<=24; i++)
        cin>>cube[i];

    for(int i=0; i<3; i++)
    {
        if(same(pattern[i][0]) && same(pattern[i][1]))
        {
            for(int j=0; j<2; j++)
            {
                bool ck=true;
                for(int k=0; k<4; k++)
                {
                    if(!same(check[i][j][k]))
                    {
                        ck=false;
                        break;
                    }
                }

                if(ck==true)
                {
                    cout<<1;
                    return 0;
                }
            }
        }
    }

    cout<<0;
}