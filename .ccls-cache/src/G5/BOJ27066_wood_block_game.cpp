#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector<ll> A;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	
	ll sum=0;
	
	for(int i=0;i<N;i++){
		ll num;
		cin >> num;
		A.push_back(num);
		sum+=num;
	}

	//sort(A.begin(),A.end(),greater<ll>());
	sort(A.begin(),A.end());

	ld ans = (ld)sum/N;

	for(int i=N/2;i<N-1;i++){
		ans = max(ans,(ld)A[i]);
	}

	cout << fixed;
	cout.precision(6);
	cout << ans << "\n";
	
	return 0;
}

/*
27:20 main() Completed.
35:35 TC passed.
240511 35:43
*/