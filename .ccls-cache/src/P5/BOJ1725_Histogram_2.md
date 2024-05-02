#define IDX_MAX 1007
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll A[IDX_MAX];
ll DP[IDX_MAX][IDX_MAX];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;	
	cin >> N;
	
	ll ans=0;

	for(int i=1;i<=N;i++){
		cin >> A[i];
	}

	for(int i=1;i<=N;i++){
		DP[i][i] = A[i];
	}

	for(int i=1;i<=N-1;i++){
		for(int j=i+1;j<=N;j++){
			DP[i][j] = min(DP[i][j-1],A[j]);
			ll cur = (j-i+1) * DP[i][j];
			ans = max(ans,cur);
		}
	}

	cout << ans << "\n";
	
	return 0;
}



/*

*/