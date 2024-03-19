#define INF 0x3f3f3f3f3f3f3f3f
#define DIST first
#define POS second
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,int> Edge;
vector<vector<Edge>> A;
vector<LL> dist;

void BFS(int start);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	cin >> N;
	M = N-1;
	A.resize(N+1);
	dist.resize(N+1,INF);

	for(int i=0;i<M;i++){
		int s,e;
		LL w;
		cin >> s >> e >> w;
		A[s].push_back({w,e});
		A[e].push_back({w,s});
	}

	BFS(1);

	LL ans=0;
	for(int i=1;i<=N;i++){
		ans = max(ans,dist[i]);
	}

	cout << ans<< "\n";

	return 0;
}

void BFS(int start){
	queue<Edge> Q; Q.push({0,start});
	dist[start]=0;
	while(!Q.empty()){
		Edge cur = Q.front(); Q.pop();
		for(Edge next:A[cur.POS]){
			if(dist[cur.POS] + next.DIST >= dist[next.POS]) continue;
			dist[next.POS] = dist[cur.POS] + next.DIST;
			Q.push({dist[next.POS],next.POS});
		}
	}
}


/*
02:48 Problem Analysis.
05:45 main() Completed
09:59 BFS() Completed

240318 11:01
*/