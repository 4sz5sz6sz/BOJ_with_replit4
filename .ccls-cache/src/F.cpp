#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll X;
int M;

vector<vector<ll>> arr;
ll ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> X >> M;

	arr.push_back(vector<ll>());
	arr[0].push_back(X);
	ans = X;

	for(int i=1;i<=M;i++){
		arr.push_back(vector<ll>());
		for(ll prev:arr[i-1]){
			ll num1 = (ll)ceil((prev/2.0));
			ll num2 = (ll)floor((prev/2.0));
			arr[i].push_back(num1);
			arr[i].push_back(num2);
			ans+=num1+num2;
			// cout << num1 << "	";
			// cout << num2 << "	";
		}
		// cout << "\n";
	}

	cout << ans << "\n";

	return 0;
}

/*
08:41 Problem Analysis.
12:17 main() Completed.
16:42 TC passed.
240428 16:48
*/