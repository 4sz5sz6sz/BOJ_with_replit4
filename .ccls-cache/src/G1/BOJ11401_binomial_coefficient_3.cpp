#define MOD 1000000007ll
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N,K;
vector<ll> fact(4000007,1);

ll POW(ll a, ll b, ll MMM);
ll INV(ll b, ll MMM);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for(ll i=2;i<=N;i++){
		fact[i] = (fact[i-1] * i)%MOD;
	}

	ll ans = fact[N];
	ans = (ans * INV(fact[K],MOD))%MOD;
	ans = (ans * INV(fact[N-K],MOD))%MOD;
	cout << ans << "\n";

	return 0;
}

ll POW(ll a, ll b, ll MMM){
	ll ret = 1;
	for(;b;b>>=1, a = (a*a)%MMM)
		if(b & 1)
			ret = (ret*a)%MMM;
	return ret;
}

ll INV(ll b, ll MMM){
	return POW(b,MMM-2,MMM);
}


/*
05:44 Problem Analysis.
12:52 main() Completed.
14:37 2 function Completed.
15:01 TC passed.
240517 15:05
*/