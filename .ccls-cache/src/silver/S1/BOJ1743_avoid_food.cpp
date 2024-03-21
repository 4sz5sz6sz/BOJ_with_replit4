#define FOOD 1
#define WALL 0
#define IDX_MAX 101
#define X first
#define Y second
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> Pos;

int vis[IDX_MAX][IDX_MAX];
int board[IDX_MAX][IDX_MAX];
int ans=0;
int curColor=0;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N,M,K;

void BFS(Pos start);
bool oob(int nx, int ny, int N, int M);
//void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;

	for(int i=0;i<K;i++){
		int a,b;
		cin >> a >> b;
		board[a][b] = FOOD;
	}

	

	for(int x=1;x<=N;x++){
		for(int y=1;y<=M;y++){
			if(!vis[x][y] && board[x][y] == FOOD)
				BFS({x,y});
		}
	}

	cout << ans << "\n";

	
	
	return 0;
}

void BFS(Pos start){
	queue<Pos> Q; Q.push(start);
	vis[start.X][start.Y] = ++curColor;
	int cnt=0;
	while(!Q.empty()){
		Pos cur = Q.front(); Q.pop();
		cnt++;
		for(int dir=0;dir<4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(oob(nx,ny,N,M)) continue;
			if(board[nx][ny] == WALL || vis[nx][ny] > 0) continue;
			vis[nx][ny] = curColor; Q.push({nx,ny});
		}
	}
	ans = max(ans,cnt);
}

bool oob(int nx, int ny, int N, int M){
	return nx <= 0 || ny <= 0 || nx > N || ny > M;
}

/*
03:08 Problem Analysis.
06:49 main() Completed.
11:00 BFS() Completed.
11:56 oob() Completed.
13:20 TC 오답.. 가장 큰 크기를 출력해야 하는데, 영역 갯수를 출력함.
16:44 TC passed.
240321 17:01
*/