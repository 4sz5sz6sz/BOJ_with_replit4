#define IDX_MAX 1001
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll sumA[IDX_MAX];
ll sumB[IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll ans=0;
	unordered_map<ll,ll> m;
	ll T;
	int N,M;
	cin >> T;
	cin >> N;
	for(int i=1;i<=N;i++){
		ll cur;
		cin >> cur;
		sumA[i] = sumA[i-1] + cur;
	}
	cin >> M;
	for(int i=1;i<=M;i++){
		ll cur;
		cin >> cur;
		sumB[i] = sumB[i-1] + cur;
	}

	for(int i=1;i<=N;i++){
		for(int j=i;j<=N;j++){
			ll curA = sumA[j] - sumA[i-1];
			m[curA]++;
			// cout << "	curA : " << curA;
			// cout << "\n";
		}
	}

	for(int i=1;i<=M;i++){
		for(int j=i;j<=M;j++){
			ll curB = sumB[j] - sumB[i-1];
			ans+=m[T - curB];
			// cout << "	i : " << i;
			// cout << "	j : " << j;
			// cout << "	curB : " << curB;
			// cout << "	m[curB] : " << m[curB];
			// cout << "\n";
		}
	}
	cout << ans << "\n";
	return 0;
}

/*
12:18 Problem Analysis.
18:23 main() Completed.
23:44 TC passed.
WA..
30:36 전부 ll로 변경.
아무래도, 1,000,000 * 1,000,000 인 경우 있는 듯.
0만 1,000,000,000면 가능하다..

자력솔 성공.

240503 31:54
*/