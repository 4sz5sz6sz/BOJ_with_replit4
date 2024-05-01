#define IDX_MAX 1000007
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> A;
int DP[IDX_MAX][2];

int N;
int M;

void DFS(int cur, int parent);
void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	A.resize(N+1);
	M = N-1;
	for(int i=0;i<M;i++){
		int s,e;
		cin >> s >> e;
		//if(e<s) swap(s,e);
		A[s].push_back(e);
		A[e].push_back(s);
	}

	for(int i=1;i<=N;i++){
		DP[i][1] = 1;
	}

	DFS(1, 0);

	//ShowArr();
	
	int ans = min(DP[1][0], DP[1][1]);
	cout << ans << "\n";
	
	return 0;
}

void DFS(int cur, int parent){
	for(int next:A[cur]){
		if(next == parent) continue;
		DFS(next,cur);
	}
	DP[parent][0] += DP[cur][1];
	DP[parent][1] += min(DP[cur][0],DP[cur][1]);
}

void ShowArr(){
	for(int i=0;i<2;i++){
		for(int j=1;j<=N;j++){
			cout << DP[j][i] << " ";
		}
		cout << "\n";
	}
}

/*
01:13 Problem Analysis.
05:07 main() Completed.
13:27 DFS() Completed.
15:21 TC passed.
WA..

35:52
1 - 5 - 2 같은 경우가 반례일 듯..
if(e<s) swap(s,e);
삭제.
양방향 간선으로 하되, 부모 노드는 next의 대상에서 제외하기.

37:24 TC passed.

240501 37:27
*/