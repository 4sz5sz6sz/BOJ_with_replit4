#define INF 0x3f3f3f3f3f3f3f3f
#define IDX_MAX 501
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll DP[IDX_MAX][IDX_MAX];
vector<ll> A;

void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	A.resize(N+1);
	for(int i=0;i<IDX_MAX;i++){
		for(int j=0;j<IDX_MAX;j++){
			DP[i][j] = INF;
		}
	}
	
	for(int i=0;i<N;i++){
		ll b;
		cin >> A[i] >> b;
		if(i==N-1) A[N]=b;
	}
	N++;

	for(int i=0;i<N;i++){
		if(i+2 >= N) break;
		DP[i][i+2] = A[i]*A[i+1]*A[i+2];
	}

	for(int i=0;i<N;i++){
		DP[i][i] = 0;
		if(i+1>=N) continue;
		DP[i][i+1]=0;
	}

	for(int d=2;d<N;d++){
		for(int i=0;i<N;i++){
			if(i+d >= N) break;
			int j = i+d;
			//for(int j=i+d;j<N;j++){
				for(int k=i+1;k<j;k++){
					// cout << "	i : " << i;
					// cout << "	k : " << k;
					// cout << "	j : " << j;
					// cout << "\n";
					if(DP[i][k] + DP[k][j] + A[i] * A[k] * A[j] < DP[i][j]){
						DP[i][j] = DP[i][k] + DP[k][j] + A[i] * A[k] * A[j];
						//cout << "cnt\n";
					}
				}
			//}
		}
	}

	//ShowArr();

	cout << DP[0][N-1] << "\n";
	
	return 0;
}

void ShowArr(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(DP[i][j] == INF) cout << "x	";
			else cout << DP[i][j] << "	";
		}
		cout << "\n";
	}
}

/*
23:58 Problem Analysis.
32:29 main() Completed.
33:54 TC : INF 출력..

44:59
if(i+2 > N) break;
에서
if(i+2 >= N) break;
로 수정.

48:52
DP[i][i] = 0;
DP[i][i+1]=0;
추가함.

TC passed.

6
20 10
10 30
30 40
40 20
20 30
30 50

4중 for문이 아니라, 3중 for문으로 줄일 수 있으려나..
54:26 저녁 식사..

재개.
02:03
j for문 제거 후.
int j = i+d; 도입.

i j가 간격 d를 유지하면서, k를 먼저 순회시켜야 되지 않을까 하는 생각도 든다.
0 2다음은, 1 3 이런 식으로...

지금 보면, 0,6이 제일 먼저 채워지고 있다.. 순서에 안 맞다.

for(int i=0;i<N;i++){
	for(int d=2;d<N;d++){
에서
for(int d=2;d<N;d++){
	for(int i=0;i<N;i++){
로 변경.

출력이 78000 -> 51000으로 바뀜.

240502 49:07 + 11:05
*/