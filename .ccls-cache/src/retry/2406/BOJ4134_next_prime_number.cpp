#define NUM_MAX 4000000ll
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll T;
	cin >> T;
	while(T--){
		ll N;
		unordered_map<ll,int> prime;
		cin >> N;
		prime[0ll] = 1;
		prime[1ll] = 1;
		for(ll i=2;i<=sqrt(N);i++){
			if(i>=4 && i%2 == 0) continue;
			//ll _max = min(NUM_MAX, N*N);
			ll _max = NUM_MAX;
			for(ll j=i*i;j<=_max;j = j + i){
				prime[j] = 1;
			}
		}

		for(ll i=N;i<=NUM_MAX;i++){
			if(prime[i]!=1){
				cout << i << "\n";
				break;
			}
		}
	}
	
	return 0;
}

/*
01:58 Problem Analysis.
10:37 최댓값 4000000ll 로 설정.
17:37 _max 도입.
240612 
*/