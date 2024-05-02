#define DIST first
#define POS second
#define IDX_MAX 100000
#define INF 0x3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Edge;	//DIST, POS
int N,K;
int dx[3] = {1,-1,0};
int dist[IDX_MAX+1];
vector<vector<Edge>> A;

void Dijkstra(int start);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	A.resize(IDX_MAX+1);
	for(int i=0;i<=IDX_MAX;i++){
		dist[i] = INF;
	}

	for(int cur=0;cur<=IDX_MAX;cur++){
		for(int j=0;j<3;j++){
			int next = cur + dx[j];
			int w = 1;
			if(j==2){
				w=0; next*=2;
			}
			if(next < 0 || next > 100000) continue;
			A[cur].push_back({w,next});
		}
	}

	Dijkstra(N);
	cout << dist[K] << "\n";
	return 0;
}

void Dijkstra(int start){
	priority_queue<Edge,vector<Edge>,greater<Edge>> Q; Q.push({0,start}); dist[start]=0;
	while(!Q.empty()){
		Edge cur = Q.top(); Q.pop();
		if(dist[cur.POS] != cur.DIST) continue;
		for(Edge next:A[cur.POS]){
			if(dist[cur.POS] + next.DIST < dist[next.POS]){
				dist[next.POS] = dist[cur.POS] + next.DIST;
				Q.push({dist[next.POS],next.POS});
			}
		}
	}
}


/*
03:48 Problem Analysis.
11:36 main() Completed.
15:07 Dijkstra() Completed.
16:38 TC passed.
240502 16:47
*/