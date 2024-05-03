#define IDX_MAX 101
#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<int>> A;
vector<vector<int>> revA;
int vis[IDX_MAX];

void Init();
void BFS(int start);
void rev_BFS(int start);

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	N = n;
	M = results.size();
	A.resize(N+1);
	revA.resize(N+1);
	for(int i=0;i<M;i++){
		int S,E;
		S = results[i][0];
		E = results[i][1];
		A[S].push_back(E);
		revA[E].push_back(S);
	}
	for(int i=1;i<=N;i++){
		Init(); //vis[]
		BFS(i);
		rev_BFS(i);
		int cnt=0;
		for(int j=1;j<=N;j++){
			if(vis[j]) cnt++;
			cout << "   cnt :" << cnt;
		}
		if(cnt==N) answer++;
		cout << "\n";
	}

	return answer;
}

void Init(){
	for(int i=0;i<=N;i++)
		vis[i] = 0;
}

void BFS(int start){
	queue<int> Q; Q.push(start);
	vis[start] = 1;
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		for(int next:A[cur]){
			if(vis[next]) continue;
			Q.push(next); vis[next] = 1;
		}
	}
}

void rev_BFS(int start){
	queue<int> Q; Q.push(start);
	vis[start] = 1;
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		for(int next:revA[cur]){
			if(vis[next]) continue;
			Q.push(next); vis[next] = 1;
		}
	}
}


/*
15:26 Problem Analysis.
22:15 solution() Completed.
24:53 BFS(), rev_BFS() Completed.
29:26 WA...
if(vis[cur]) continue;
에서
if(vis[next]) continue;
로 수정...

29:39 TC passed.

240503 30:00
*/