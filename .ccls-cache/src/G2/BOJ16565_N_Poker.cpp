#define IDX_MAX 55
#define MOD 10007
#include<bits/stdc++.h>
using namespace std;

int C[IDX_MAX][IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for(int i=0;i<IDX_MAX;i++){
		C[i][0] = 1;
		C[i][i] = 1;
		C[i][1] = i;
	}
	
	for(int i=0;i<IDX_MAX;i++){
		for(int j=1;j<i;j++){
			C[i][j] = (C[i-1][j-1] + C[i-1][j])%MOD;
		}
	}

	int sum=0;

	for(int i=1;i<=N/4;i++){
		if(i%2 == 1){
			sum = sum + (C[13][i] * C[52-i*4][N-i*4])%MOD;
			sum = sum%MOD;
		}
		else{
			sum = sum - (C[13][i] * C[52-i*4][N-i*4])%MOD;
			sum = (sum + MOD)%MOD;
		}
		//cout << "	sum : 	" << sum << "\n";
	}
	/*
	if(N == 52){
		cout << 1 << "\n";
		return 0;
	}
	*/
	cout << sum << "\n";
	
	return 0;
}

/*
10:30 Problem Analysis
16:10 main() Completed
18:27 Set C[][] Completed.
28:00 테스트 케이스 통과?


52일때 왜 0이 뜨는지는 모르겠다. 일단 52에 대해서 예외처리를 하니 정답으로 뜸.

for(int i=1;i<IDX_MAX;i++){
를
for(int i=0;i<IDX_MAX;i++){
로 고치니 예외처리를 제거해도 된다.

240313 28:07
*/