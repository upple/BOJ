#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
int arr[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   int n;
   cin >> n;

   stack<int> st; // 스택
   queue<char> q; //출력 저장용 큐

   for (int i = 1; i <= n; i++) {
      cin >> arr[i];
   }
   int now = 1;
   int pivot = 1;

   while (now != n+1) { // 1 ~ N까지 푸시
      st.push(now);
      q.push('+');

      while(!st.empty() && arr[pivot] == st.top()) { //저장된 배열과 스택 탑이 같다면, 팝
         pivot++;
         st.pop();
         q.push('-');
      }
      now++;
   }

   if (st.empty()) { //스택이 비어있다면, 큐에 저장한 스택 기록 출력
      while (!q.empty()) {
         cout << q.front() << "\n";
         q.pop();
      }
   }
   else cout << "NO";

   return 0;
}