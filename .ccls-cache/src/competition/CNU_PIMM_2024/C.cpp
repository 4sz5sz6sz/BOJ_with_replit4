#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

vector<LL> S;
vector<LL> A;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,Q;
	//int curIdx;
	int addIdx=0;

	cin >> N >> Q;
	
	LL MOD = N;
	A.resize(2*N+1);
	S.resize(2*N+1);
	for(int i=1;i<=N;i++){
		cin >> A[i];
		A[i+N]=A[i];
	}

	for(int i=1;i<=2*N;i++){
		S[i] = S[i-1] + A[i];
	}

	while(Q--){
		int comm,k;
		cin >> comm;
		if(comm == 2){
			cin >> k;
			addIdx=(addIdx+k)%MOD;
		}
		else if(comm == 1){
			cin >> k;
			addIdx=(addIdx+MOD-k)%MOD;
		}
		else{
			int a,b;
			cin >> a >> b;
			int curIdx = a;
			int dist = b-a;
			
			curIdx = (curIdx+addIdx)%MOD;
			if(curIdx == 0) curIdx = MOD;
			cout << S[curIdx+dist]-S[curIdx-1] << "\n";
		}
		// cout << "	addIdx :" << addIdx << "\n";
	}
	
	return 0;
}

/*
14:00 문제 분석
34:24 테스트 케이스 오답떠서, comm 1 2 바꾸니 해결됨.
240310 34:40
*/
