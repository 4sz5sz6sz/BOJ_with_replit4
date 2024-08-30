#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	priority_queue<ll,vector<ll>,greater<ll>> Q;
	int N,M;
	cin >> N >> M;

	for(int i=0;i<N;i++){
		ll num;
		cin >> num;
		Q.push(num);
	}

	for(int i=0;i<M;i++){
		ll n1 = Q.top(); Q.pop();
		ll n2 = Q.top(); Q.pop();
		ll sum = n1+n2;
		Q.push(sum);
		Q.push(sum);
	}

	ll ans=0;
	while(!Q.empty()){
		ll num = Q.top(); Q.pop();
		ans += num;
	}

	cout << ans << "\n";
	
	return 0;
}

/*
01:26 Problem Analysis.
05:43 main() Completed.
06:00 TC passed.
240830 06:04
*/