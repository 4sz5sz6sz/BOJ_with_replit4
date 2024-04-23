#define X first
#define Y second
#define INF 0x3f3f3f3f
#define IDX_MAX 101
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Pos;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N,M;
int dist[IDX_MAX][IDX_MAX];
vector<vector<int>> board;

void BFS(Pos start);

int solution(vector<vector<int> > maps)
{
	N = maps.size();
	M = maps[0].size();
	board = maps;

	for(int i=0;i<IDX_MAX;i++){
		for(int j=0;j<IDX_MAX;j++){
			dist[i][j] = INF;
		}
	}

	BFS({0,0});

	int ret = dist[N-1][M-1];
	if(ret == INF) ret = -1;
	
	return ret;
}

void BFS(Pos start){
	queue<Pos> Q; dist[start.X][start.Y] = 1;
	Q.push({start.X,start.Y});
	while(!Q.empty()){
		Pos cur = Q.front(); Q.pop();
		for(int dir=0;dir<4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			int ndist = dist[cur.X][cur.Y] + 1;
			if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if(board[nx][ny] == 0 || ndist >= dist[nx][ny]) continue;
			dist[nx][ny] = ndist; Q.push({nx,ny});
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<vector<int>> map= {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};
	solution(map);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

/*
05:56 solution() Completed.
08:49 BFS() Completed.
18:10 Q.push() 추가..
240422 18:45
*/