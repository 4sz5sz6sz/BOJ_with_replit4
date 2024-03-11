#define INF 0x3f3f3f3f
#define NOT_AVAIL 1
#define IDX_MAX 1001
#define X first
#define Y second
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Pos;

int board[IDX_MAX][IDX_MAX];
int dist[IDX_MAX][IDX_MAX];

int ddx[8] = {1,0,-1,0,1,-1,1,-1};
int ddy[8] = {0,1,0,-1,1,1,-1,-1};

int N,M,K;

void BFS(Pos start);
bool oob(int nx, int ny, int N, int M);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			dist[i][j] = INF;
		}
	}

	for(int i=0;i<K;i++){
		int x,y;
		cin >> x >> y;
		board[x][y] = NOT_AVAIL;
	}

	BFS({0,0});

	if(dist[N-1][M-1] == INF)
		cout << "-1\n";
	else
		cout << dist[N-1][M-1] << "\n";
	
	return 0;
}

void BFS(Pos start){
	queue<Pos> Q; dist[start.X][start.Y] = 0;
	Q.push(start);

	while(!Q.empty()){
		Pos cur = Q.front(); Q.pop();
		for(int dir=0;dir<8;dir++){
			if((cur.X & 1) && (dir==6 || dir==7)) continue;
			if(!(cur.X & 1) && (dir==4 || dir==5)) continue;
			int nx = cur.X + ddx[dir];
			int ny = cur.Y + ddy[dir];
			int ndist = dist[cur.X][cur.Y]+1;
			if(oob(nx,ny,N,M)) continue;
			if(board[nx][ny] == NOT_AVAIL || ndist >= dist[nx][ny]) continue;
			Q.push({nx,ny}); dist[nx][ny] = ndist;
		}
	}
}

bool oob(int nx, int ny, int N, int M){
	return nx < 0 || ny < 0 || nx>=N || ny>=M;
}

/*
04:09 문제 분석 
09:22 main() Completed
14:24 BFS() Completed
15:24 첫 컴파일
16:51 oob() Completed
18:39 반례 발견, 
	x가 홀수면 1시 5시 이동 가능.
	x가 짝수면 7시 11시 이동 가능.

if((cur.X & 1) && dir==6 || dir==7) continue;
에서
if((cur.X & 1) && (dir==6 || dir==7)) continue;
로 수정.
3번째 테스트 케이스 통과
33:50
240310 34:10
*/