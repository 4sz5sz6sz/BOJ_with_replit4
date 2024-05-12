#define DIST first
#define POS second
#define INF 0x3f3f3f3f3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> Edge;

vector<vector<Edge>> W;
vector<vector<Edge>> B;
vector<ll> dist;
ll N,K,M1,M2;

void Dijkstra(int start);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K >> M1 >> M2;
	dist.resize(N+1,INF);
	W.resize(N+1);
	B.resize(N+1);

	for(int i=0;i<M1;i++){
		ll s,e,w;
		cin >> s >> e >> w;
		W[s].push_back({w,e});
		W[e].push_back({w,s});
	}

	for(int i=0;i<M2;i++){
		ll s,e,w;
		cin >> s >> e >> w;
		B[s].push_back({w,e});
		B[e].push_back({w,s});
	}
	Dijkstra(1);
	cout << dist[N] << "\n";
	
	return 0;
}

void Dijkstra(int start){
	priority_queue<Edge,vector<Edge>,greater<Edge>> Q; Q.push({0,start});
	dist[start] = 0;
	while(!Q.empty()){
		Edge cur = Q.top(); Q.pop();
		if(cur.DIST != dist[cur.POS]) continue;
		for(Edge next:W[cur.POS]){
			if(dist[cur.POS] + next.DIST < dist[next.POS]){
				dist[next.POS] = dist[cur.POS] + next.DIST;
				Q.push({dist[next.POS],next.POS});
			}
		}
		for(Edge next:B[cur.POS]){
			if(max(dist[cur.POS],K) + next.DIST < dist[next.POS]){
				dist[next.POS] = max(dist[cur.POS],K) + next.DIST;
				Q.push({dist[next.POS],next.POS});
			}
		}
	}
}

/*
08:04 Problem Analysis.
12:35 main() Completed.
16:05 Dijkstra() Completed.
16:18 TC passed.
240512 16:21
*/