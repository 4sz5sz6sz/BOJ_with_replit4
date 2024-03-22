#define X first
#define Y second
#define INF 0x3f3f3f3f
#define IDX_MAX 1001
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Pos;

int dx[8] = {2,2,-2,-2,1,1,-1,-1};
int dy[8] = {1,-1,1,-1,2,-2,2,-2};

int N,K;
Pos start;

int board[IDX_MAX][IDX_MAX];
int dist[IDX_MAX][IDX_MAX];
//int myindex[IDX_MAX][IDX_MAX];
int ans[IDX_MAX];	//1-indexed

void Init();
void BFS(Pos start);
bool oob(int nx, int ny, int N, int M);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	cin >> start.X >> start.Y;

	for(int i=1;i<=K;i++){
		int x,y;
		cin >> x >> y;
		board[x][y] = i;
		//myindex[x][y] = i;
	}

	Init();
	BFS(start);
	
	for(int i=1;i<=K;i++){
		cout << ans[i] << " ";
	}
	return 0;
}

void Init(){
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			dist[i][j] = INF;
		}
	}
}

void BFS(Pos start){
	queue<Pos> Q; Q.push(start);
	dist[start.X][start.Y] = 0;
	while(!Q.empty()){
		Pos cur = Q.front(); Q.pop();
		if(board[cur.X][cur.Y] > 0 && ans[board[cur.X][cur.Y]] == 0){
			//cout << "*";
			ans[board[cur.X][cur.Y]] = dist[cur.X][cur.Y];
		}
		for(int dir=0;dir<8;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			int ndist = dist[cur.X][cur.Y] + 1;
			if(oob(nx,ny,N,N)) continue;
			if(ndist >= dist[nx][ny]) continue;
			Q.push({nx,ny}); dist[nx][ny] = ndist;
		}
	}
}

bool oob(int nx, int ny, int N, int M){
	return nx<=0 || ny<=0 || nx>N || ny>M;
}

/*
04:26 Problem Analysis.
10:26 main() Completed.
11:48 Init() Completed.
15:17 BFS() Completed.
22:34 dx[4] -> dx[8]로 변경.
22:45 TC passed.
240322 22:54
*/

