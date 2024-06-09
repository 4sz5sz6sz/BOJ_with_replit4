#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll GCD(ll a, ll b);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll A,B;
	cin >> A >> B;
	ll ans = A/GCD(A,B)*B;
	cout << ans << "\n";
	
	return 0;
}

ll GCD(ll a, ll b){
	return b?GCD(b,a%b):a;
}

/*
02:39
240609
*/