#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  priority_queue<ll, vector<ll>, greater<ll>> Q;

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    ll input;
    cin >> input;
    if (input == 0)
      continue;
    Q.push(input);
  }

  while (Q.size() >= 2) {
    ll n1 = Q.top();
    Q.pop();
    ll n2 = Q.top();
    Q.pop();

    if (n1 == n2) {
      Q.push(n1 + n2);
    } else {
      Q.push(n2);
    }
  }

  cout << Q.top() << "\n";

  return 0;
}

/*
04:00 문제 분석
10:44 테스트 케이스 통과
240227 12:22
*/