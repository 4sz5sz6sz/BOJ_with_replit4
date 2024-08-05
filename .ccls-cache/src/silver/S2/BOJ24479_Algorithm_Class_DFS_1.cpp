#include<bits/stdc++.h>
using namespace std;

int curN;
int N,M,start;
vector<int> vis;
vector<vector<int>> A;

void DFS(int cur);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> start;
	vis.resize(N+1);
	A.resize(N+1);
	for(int i=0;i<M;i++){
		int s,e;
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}

	for(int i=1;i<=N;i++){
		sort(A[i].begin(),A[i].end());
	}

	DFS(start);

	for(int i=1;i<=N;i++){
		cout << vis[i] << "\n";
	}
	
	return 0;
}

void DFS(int cur){
	if(vis[cur])
		return;
	vis[cur] = ++curN;
	for(int next:A[cur])
		DFS(next);
}

/*
00:56 Problem Analysis.
03:43 main() Completed.
04:52 DFS() Completed.
240805 05:54
*/