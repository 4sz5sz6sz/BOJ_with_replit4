#define STORE 1
#define HOME 2
#define DIST first
#define POS second
#define INF 0x3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Edge;	//DIST, POS
typedef pair<int,int> Vertex; //DIST, POS; answer 

int N,M;
vector<vector<Edge>> A;
vector<int> dist;
vector<int> state;

void Init();
void Dijkstra(int start);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	Init();

	for(int i=0;i<M;i++){
		int s,e,w;
		cin >> s >> e >> w;
		A[s].push_back({w,e});
		A[e].push_back({w,s});
	}

	int p,q;
	cin >> p >> q;
	while(p--){
		int v;
		cin >> v;
		state[v] = HOME;
	}

	while(q--){
		int v;
		cin >> v;
		state[v] = STORE;
	}

	for(int i=1;i<=N;i++){
		if(state[i]==STORE)
			Dijkstra(i);
	}

	Vertex ans = {INF, INF};
	for(int i=1;i<=N;i++){
		// cout << "	i	: " << i;
		// cout << "	dist[i]	: " << dist[i];
		// cout << "\n";
		if(state[i] == HOME){
			ans = min(ans,{dist[i],i});
		}
	}

	cout << ans.POS << "\n";

	return 0;
}

void Init(){
	A.resize(N+1);
	dist.resize(N+1,INF);
	state.resize(N+1);
}

void Dijkstra(int start){
	priority_queue<Edge> Q; Q.push({0,start});
	dist[start]=0;
	while(!Q.empty()){
		Edge cur = Q.top(); Q.pop();
		// cout << "	cur.POS : " << cur.POS;
		// cout << "	cur.DIST : " << cur.DIST;
		// cout << "\n";
		//if(state[cur.POS] == HOME) continue;
		if(cur.POS != start && state[cur.POS] == STORE) continue;
		if(cur.DIST != dist[cur.POS]) continue;

		for(Edge next: A[cur.POS]){
			if(dist[cur.POS] + next.DIST < dist[next.POS]){
				dist[next.POS] = dist[cur.POS] + next.DIST;
				Q.push({dist[next.POS],next.POS});
			}
		}
	}
}


/*
07:53 Problem Analysis
15:25 main() Completed.
16:56 Init() Completed.
21:04 Dijkstra() Completed.
22:46 TC passed.
Wrong Answer...
24:14 
	ans = min(ans,{dist[i],i});
	에서
	if(state[i] == HOME){
		ans = min(ans,{dist[i],i});
	}

26:37
	dist.resize(N+1);
	에서
	dist.resize(N+1,INF);

33:04
	if(state[cur.POS] == STORE) continue;
	에서
	if(cur.POS != start && state[cur.POS] == STORE) continue;
	로 변경.

240315 33:41
*/