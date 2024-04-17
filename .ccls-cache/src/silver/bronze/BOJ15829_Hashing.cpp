#define MMM 1234567891
#define RRR 31
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll POW(ll a, ll b, ll MOD);



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int L;
	ll ans=0;
	string s;
	cin >> L;
	cin >> s;
	vector<int> A(L);
	for(int i=0;i<L;i++){
		A[i] = s[i] - 'a' + 1;
		ans = (ans + A[i]*POW(RRR,i,MMM))%MMM;
	}

	//cout << POW(5,3,MMM) << "\n";

	cout << ans << "\n";
	
	return 0;
}

ll POW(ll a, ll b, ll MOD){
	ll ret=1;
	for(;b;b>>=1,a=(a*a)%MOD){
		if(b & 1)
			ret = (ret*a)%MOD;
	}
	return ret;
}

/*
08:04 Problem Analysis.
09:56 main() Completed.
14:28 POW() Completed.
20:36 TC passed.
240417 20:42
*/