#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll ans=1;

	ll N;
	cin >> N;
	for(ll i=1;i<=N;i++){
		ans*=i;
	}
	cout << ans << "\n";
}

/*
240612 01:45 
*/