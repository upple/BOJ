#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> arr(8),st, rv;
    for(int i=0; i<8; i++)
        scanf("%d", &arr[i]);

    st=arr;
    sort(st.begin(), st.end());
    rv=st;
    reverse(rv.begin(), rv.end());

    if(arr==st)
        printf("ascending");

    else if(arr==rv)
        printf("descending");

    else
        printf("mixed");
}
