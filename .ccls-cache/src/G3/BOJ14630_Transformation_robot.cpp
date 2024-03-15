#define DIST first
#define POS second
#define INF 0x3f3f3f3f
#define IDX_MAX 1001
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Edge;

int N;
vector<int> dist;
vector<string> state;
int cost[IDX_MAX][IDX_MAX];

void Init();
void Dijkstra(int start);
void GetCost();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	Init();
	for(int i=1;i<=N;i++) cin >> state[i];
	GetCost();

	int st,en;
	cin >> st >> en;
	Dijkstra(st);

	cout << dist[en] << "\n";
	
	return 0;
}

void Init(){
	dist.resize(N+1,INF);
	state.resize(N+1);
}

void Dijkstra(int start){
	priority_queue<Edge,vector<Edge>,greater<Edge>> Q;
	Q.push({0,start}); dist[start] = 0;
	while(!Q.empty()){
		Edge cur = Q.top(); Q.pop();
		for(int nIdx=1;nIdx<=N;nIdx++){
			Edge next = {cost[cur.POS][nIdx],nIdx};
			if(next.POS == cur.POS) continue;
			if(dist[cur.POS] + next.DIST < dist[next.POS]){
				dist[next.POS] = dist[cur.POS] + next.DIST;
				Q.push({dist[next.POS],next.POS});
			}
		}
	}
}

void GetCost(){
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			if(i==j) continue;
			string A = state[i];
			string B = state[j];
			for(int idx=0;idx<A.size();idx++){
				int num = abs(A[idx] - B[idx]);
				cost[i][j]+=num*num;
				cost[j][i]+=num*num;
			}
		}
	}
}

/*
19:19 Problem Analysis
22:43 main() Completed
23:58 Init() Completed
29:04 Dijkstra() Completed
32:35 GetCost() Completed

33:00 TC passed.
240314 33:09
*/