#define INF 0x3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<int> dist;
vector<vector<int>> A;

void BFS(int start);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	dist.resize(N+1,INF);
	A.resize(N+1);

	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}

	int ans=0;
	for(int i=1;i<=N;i++){
		dist.clear();
		dist.resize(N+1,INF);
		BFS(i);
		for(int j=1;j<=N;j++){
			if(dist[j]>6){
				ans = 1;
			}
		}
		if(ans) break;
	}

	if(ans)
		cout << "Big World!\n";
	else
		cout << "Small World!\n";
	
	return 0;
}

void BFS(int start){
	queue<int> Q; Q.push(start);
	dist[start] = 0;
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		for(int next:A[cur]){
			if(dist[cur] + 1 >= dist[next]) continue;
			Q.push(next); dist[next] = dist[cur]+1;
		}
	}
}

/*
03:32 Problem Analysis.
08:05 main() Completed.
09:59 BFS() Completed.
240324 10:09
*/