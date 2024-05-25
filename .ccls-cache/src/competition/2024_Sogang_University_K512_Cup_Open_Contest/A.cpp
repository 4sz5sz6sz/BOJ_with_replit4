#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	cin >> N >> M;

	vector<ll> A(N);
	vector<ll> B(M);

	for(int i=0;i<N;i++){
		cin >> A[i];
	}

	for(int i=0;i<M;i++){
		cin >> B[i];
	}

	ll sum = 0;
	for(int i=0;i<N;i++){
		ll cur = A[i];
		sum+=cur;
	}

	for(int i=0;i<M;i++){
		ll cur = B[i];
		if(cur==0) continue;
		sum*=cur;
	}

	cout << sum << "\n";	
	return 0;
}

/*
03:53 main() Completed.
240525 
*/