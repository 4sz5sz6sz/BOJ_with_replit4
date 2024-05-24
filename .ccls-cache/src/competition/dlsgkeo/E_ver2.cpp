#define INF 0x3f3f3f3f
#define IDX_MAX 1007
#include<bits/stdc++.h>
using namespace std;

typedef struct Edge{
	int DIST,X,Y,COST;
}Edge;

struct cmp1{
	bool operator()(const Edge &a, const Edge &b){
		/*
		if(a.DIST != b.DIST) return a.DIST > b.DIST;
		return a.COST > b.COST;
		*/
		if(a.COST != b.COST) return a.COST > b.COST;
		return a.DIST > b.DIST;
	}
};

bool OOB(int nx, int ny, int N, int M);

int N,M,R,C;

int board[IDX_MAX][IDX_MAX];
int dist[IDX_MAX][IDX_MAX];
int cost[IDX_MAX][IDX_MAX];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	priority_queue<Edge,vector<Edge>,cmp1> Q;
	cin >> N >> M >> R >> C;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			dist[i][j] = INF;
		}
	}
	
	while(R--){
		int a,b,c;
		cin >> a >> b >> c;
		board[a][b] = c;
		//dist[a][b] = 0;
		cost[a][b] = c;
		Q.push({0,a,b,c});
	}
	
	while(C--){
		int a,b;
		cin >> a >> b;
		//int cur = GetPosToInt({a,b});
		//dist[a][b] = 0;
		board[a][b] = -1;
	}

	while(!Q.empty()){
		Edge cur = Q.top(); Q.pop();
		if(cur.DIST == 0) dist[cur.X][cur.Y] = 0;
		if(cur.DIST != dist[cur.X][cur.Y] /*&& cur.COST >= cost[cur.X][cur.Y]*/) continue;
		for(int dir=0;dir<4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			int ndist = dist[cur.X][cur.Y] + cur.COST;
			if(OOB(nx,ny,N,M)) continue;
			if(ndist < dist[nx][ny]){	//거리 같은데, 월세 갱신 가능하다면..?
				dist[nx][ny] = ndist;
				//cost[nx][ny] = cur.COST;
				Q.push({dist[nx][ny],nx,ny,cur.COST});
			}
				/*
			else if(cur.COST < cost[nx][ny]){	//월세 갱신 가능
				//cost[nx][ny] = cur.COST;	//??
				Q.push({ndist,nx,ny,cur.COST});
			}
			*/
			
		}
	}

	int ans = INF;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(board[i][j] < 0 && dist[i][j] < ans){
				ans = dist[i][j];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

bool OOB(int nx, int ny, int N, int M){
	return nx <= 0 || ny <= 0 || nx > N || ny > M;
}

/*
07:53 Problem Analysis.
34:11 Dijkstra() Completed.
42:31 TC passed.
60:51 cost[][] 추가.
10:13 
cost를 우선순위 앞으로 두기.

17:59
if(cur.DIST == 0) dist[cur.X][cur.Y] = 0;
삽입..

240519 70:00
*/