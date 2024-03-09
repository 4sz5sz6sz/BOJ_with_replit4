#define MOD 1000000007
#define IDX_MAX 1007
#include<bits/stdc++.h>
using namespace std;

int dp[IDX_MAX][IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	cin >> N >> M;

	for(int i=0;i<IDX_MAX;i++){
		dp[i][i] = 1;
		dp[i][1] = i;
		dp[i][0] = 1;
	}
	
	for(int i=0;i<IDX_MAX;i++){
		for(int j=0;j<i;j++){
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
		}
	}

	vector<int> A(N);
	vector<int> B(N);

	int sum=0;
	for(int i=0;i<N;i++){
		cin >> A[i];
		B[i] = M - A[i];
		sum+=B[i];
	}

	if(sum > M){
		cout << "0";
		return 0;
	}

	//init
	sum = M;
	long long ans=1;

	for(int i=0;i<N;i++){
		//cout << "	sum :	" << sum;
		//cout << "	i :	" << i;
		ans = (ans*dp[sum][B[i]])%MOD;
		sum-=B[i];
	}

	cout << ans << "\n";
	
	return 0;
}

/*
31:07 문제 분석
41:10 첫 컴파일
42:22 테스트 케이스 통과
240309 42:27
*/