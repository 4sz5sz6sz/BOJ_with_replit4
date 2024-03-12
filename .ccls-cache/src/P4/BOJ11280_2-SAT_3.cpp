#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> A;
vector<vector<int>> revA;
vector<int> vis;
vector<int> mygrp;
vector<vector<int>> grp;
stack<int> S;

int cntOfGroup;
int N,M;

void SCC();
void DFS(int cur);
void rev_DFS(int cur);
void Init();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	Init();

	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		int AIdx = a > 0 ? a : N-a;
		int BIdx = b > 0 ? b : N-b;
		int negAIdx = a > 0 ? N+a : -a;
		int negBIdx = b > 0 ? N+b : -b;
		
		A[negAIdx].push_back(BIdx);
		A[negBIdx].push_back(AIdx);
		revA[BIdx].push_back(negAIdx);
		revA[AIdx].push_back(negBIdx);
	}

	SCC();

	int ans = 1;
	
	for(int i=1;i<=N;i++){
		if(mygrp[i] == mygrp[N+i]){
			ans = 0;
			break;
		}
	}

	cout << ans << "\n";
	
	return 0;
}

void SCC(){
	for(int i=1;i<=2*N;i++)
		DFS(i);

	vis.clear(); vis.resize(2*N+1);

	while(!S.empty()){
		int cur = S.top(); S.pop();
		if(!vis[cur]){
			grp.push_back(vector<int>());
			rev_DFS(cur);
			cntOfGroup++;
			//sort();
		}
	}
	//sort();
}

void DFS(int cur){
	if(vis[cur])
		return ;
	vis[cur] = 1;

	for(int next:A[cur])
		DFS(next);

	S.push(cur);
}

void rev_DFS(int cur){
	if(vis[cur])
		return ;
	vis[cur] = 1;

	mygrp[cur] = cntOfGroup;
	grp[cntOfGroup].push_back(cur);

	for(int next:revA[cur])
		rev_DFS(next);
}

void Init(){
	A.resize(2*N+1);
	revA.resize(2*N+1);
	vis.resize(2*N+1);
	mygrp.resize(2*N+1);
}




/*
01:42 Problem Analysis
04:50 Create global variable
06:22 Init() Complete
09:56 main() Complete
13:46 SCC() Complete
15:24 DFS(), rev_DFS() Complete
16:31 TC passed

240311 16:42
*/