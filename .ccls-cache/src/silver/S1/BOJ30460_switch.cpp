#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<int> A(N+1);
	vector<int> S(N+1);
	vector<int> dp(N+1);

	int sum=0;

	for(int i=1;i<=N;i++){
		cin >> A[i];
		sum+=A[i];
	}

	for(int i=1;i<=N;i++){
		for(int j=0;j<=2;j++){
			if(i+j > N) continue;
			S[i] += A[i+j]; 
		}
	}

	for(int i=1;i<=3;i++){
		dp[i] = max(S[i], dp[i-1]);
	}
	
	for(int i=4;i<=N;i++){
		dp[i] = max(dp[i-3] + S[i], dp[i-1]);
	}

	/*
	for(int i=1;i<=N;i++){
		cout << dp[i] << " ";
	}
	cout << "\n";
	*/

	cout << sum + dp[N] << "\n";
	
	return 0;
}


/*
21:40 + 10:41 Problem Analysis.
17:52 main() Completed.
30:35 TC passed.
240408 21:40 + 30:41
*/