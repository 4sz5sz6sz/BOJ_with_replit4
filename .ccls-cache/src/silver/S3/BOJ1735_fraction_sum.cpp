#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll GCD(ll a, ll b);
ll LCM(ll a, ll b);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll a,b,c,d;
	cin >> a >> b >> c >> d;

	ll ans1 =  a*(LCM(b,d)/b) + c*(LCM(b,d)/d);
	ll ans2 =  LCM(b,d);

	ll tmp = GCD(ans1,ans2);
	ans1/=tmp;
	ans2/=tmp;

	cout << ans1 << " " << ans2 << "\n";
	
	return 0;
}

ll GCD(ll a, ll b){
	return b?GCD(b,a%b):a;
}

ll LCM(ll a, ll b){
	return a / GCD(a,b) * b;
}


/*
05:40 WA..
4 4 4 4 일 때 8 4 출력되는 현상 fix.
240610 09:39
*/
	