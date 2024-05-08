#define INF 0x3f3f3f3f3f3f3f3f
#define IDX_MAX 1007
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef struct Edge{
	ll DIST,POS,COST;
}Edge;
struct cmp1{
	bool operator()(const Edge &a, const Edge &b){
		return a.DIST>b.DIST;
	}
};
ll N,M,K;
int st,en;
vector<vector<Edge>> A;

ll dist[IDX_MAX][IDX_MAX];

void Init();
void Dijkstra(int start);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	cin >> st >> en;

	Init();
	for(int i=0;i<M;i++){
		int S,E,W;
		cin >> S >> E >> W;
		A[S].push_back({W,E,1});
		A[E].push_back({W,S,1});
	}

	Dijkstra(st);

	ll ans = INF;
	for(ll cost=0;cost<N;cost++){
		ans = min(ans,dist[en][cost]);
	}
	cout << ans << "\n";

	ll tax=0;
	for(int i=0;i<K;i++){
		ll add;
		cin >> add;
		tax+=add;
		ll ans = INF;
		for(ll cost=0;cost<N;cost++){
			ans = min(ans,dist[en][cost]+cost*tax);
		}
		cout << ans << "\n";
	}
	return 0;
}

void Init(){
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			dist[i][j] = INF;
		}
	}
	A.resize(N+1);
}

void Dijkstra(int start){
	priority_queue<Edge,vector<Edge>,cmp1> Q;
	Q.push({0,start,0}); dist[start][0] = 0;
	while(!Q.empty()){
		Edge cur = Q.top(); Q.pop();
		if(cur.DIST != dist[cur.POS][cur.COST]) continue;
		int ncost = cur.COST+1;
		for(Edge next: A[cur.POS]){
			if(dist[cur.POS][cur.COST] + next.DIST < dist[next.POS][ncost]){
				dist[next.POS][ncost] = dist[cur.POS][cur.COST] + next.DIST;
				Q.push({dist[next.POS][ncost],next.POS,ncost});
			}
		}
	}
}


/*
13:00 Problem Analysis.
26:45 main(), Init() Completed.
32:23 Dijkstra Completed.
40:30 TC passed.
WA.. OOB..
42:18 Init(), 양방향 간선 수정.
Wa..
46:56 전부 ll로 수정.
50:49 N,M,K도 ll로 수정. 
정답...?!?!?!?!
IDX_MAX를 1007에서 1001로 줄이면 오답 처리됨.
아무래도, 간선이 1000번을 넘는 사례가 존재하는 듯.
240508 51:01
*/