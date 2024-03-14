#define INF 0x3f3f3f3f3f3f3f3f
#define IDX_MAX 100005
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef struct Edge{
	LL DIST;
	LL TASTE;	//음수
	int POS;
	int BRK;
	bool operator >(const struct Edge &temp)const{
		if(DIST != temp.DIST) return DIST > temp.DIST;
		return TASTE > temp.TASTE;
	}
}Edge;

int N,M;
LL dist[2][IDX_MAX];

vector<vector<Edge>> A;

void Init();
void Dijkstra_0(int start);
//void Dijkstra_1(int start);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	Init();

	for(int i=0;i<M;i++){
		int s,e,t,k;
		cin >> s >> e >> t >> k;
		A[s].push_back({t,-k,e,0});
		A[e].push_back({t,-k,s,0});
	}

	Dijkstra_0(1);
	//Dijkstra_1(1);

	for(int i=2;i<=N;i++){
		cout << dist[1][i] << "\n";
	}
	
	return 0;
}

void Init(){
	A.resize(N+1);
	for(int i=0;i<2;i++){
		for(int j=0;j<IDX_MAX;j++){
			dist[i][j] = INF;
		}
	}
}

void Dijkstra_0(int start){
	priority_queue<Edge,vector<Edge>,greater<Edge>> Q;
	Q.push({0,0,start,0}); dist[0][start] = 0;
	while(!Q.empty()){
		Edge cur = Q.top(); Q.pop();
		if(cur.BRK == 0 && cur.DIST != dist[0][cur.POS]) continue;
		if(cur.BRK == 1 && cur.DIST != dist[1][cur.POS]) continue;
		//이게 맞나?
		for(Edge next:A[cur.POS]){
			if(cur.BRK == 0 && dist[0][cur.POS] + next.DIST < dist[0][next.POS]){
				dist[0][next.POS] = dist[0][cur.POS] + next.DIST;
				Q.push({dist[0][next.POS],next.TASTE,next.POS,cur.BRK});
			}
			if(cur.BRK == 0 && dist[0][cur.POS] + next.DIST + next.TASTE < dist[1][next.POS]){
				dist[1][next.POS] = dist[0][cur.POS] + next.DIST + next.TASTE;
				Q.push({dist[1][next.POS],next.TASTE,next.POS,cur.BRK+1});
			}
			if(cur.BRK == 1 && dist[1][cur.POS] + next.DIST < dist[1][next.POS]){
				dist[1][next.POS] = dist[1][cur.POS] + next.DIST;
				Q.push({dist[1][next.POS],next.TASTE,next.POS,cur.BRK});
			}
		}
	}
}

/*
void Dijkstra_1(int start){
	priority_queue<Edge,vector<Edge>,cmp1> Q;
	Q.push({0,0,start,0}); dist[0][start] = 0;
	while(!Q.empty()){
		Edge cur = Q.top(); Q.pop();
		if(cur.BRK == 0 && cur.DIST != dist[0][cur.POS]) continue;
		if(cur.BRK == 1 && cur.DIST != dist[1][cur.POS]) continue;
		//이게 맞나?
		for(Edge next:A[cur.POS]){
			if(dist[0][cur.POS] + next.DIST >= dist[0][next.POS]) continue;
			dist[0][next.POS] = dist[0][cur.POS] + next.DIST;
			Q.push({dist[0][next.POS],TASTE,next.POS,BRK});
		}
	}
}
*/

/*
12:32 Problem Analysis
24:44 main(), Init() Completed
39:45 Dijkstra_0() Completed
50:50 Dijkstra_0() 재작성 Completed
01:02:13 실행 성공. 테스트 케이스 오답. 전부 음수 뜸.

01:04:27
돈까스 먹을 때, 거리도 같이 더해줘야 했었는데 누락됨.
dist[1][next.POS] = dist[0][cur.POS] + next.TASTE;
에서
dist[1][next.POS] = dist[0][cur.POS] + next.DIST + next.TASTE;
로 수정.

01:04:37 테스트 케이스 통과.

시간초과... 비교함수 부등호 뒤집어보기.

240313 01:04:41
*/