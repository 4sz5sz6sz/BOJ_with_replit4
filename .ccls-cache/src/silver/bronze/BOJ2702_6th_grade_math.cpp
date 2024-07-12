#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll LCM(ll a, ll b);
ll GCD(ll a, ll b);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		int a,b;
		cin >> a >> b;
		int ans1 = LCM(a,b);
		int ans2 = GCD(a,b);
		cout << ans1 << " " << ans2 << "\n";
	}
	
	return 0;
}

ll LCM(ll a, ll b){
	return a/GCD(a,b)*b;
}

ll GCD(ll a, ll b){
	return b?GCD(b,a%b):a;
}


/*
240712 08:56
*/