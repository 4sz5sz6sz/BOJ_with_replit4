#define IDX_MAX 1001
#define INF 0x3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
	int X,Y,VIR;
}Node;

Node s1, s2;

int N,M;
int board[IDX_MAX][IDX_MAX];
int dist[IDX_MAX][IDX_MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int ans[4];

bool oob(int nx, int ny, int N, int M);
void Init();
void BFS();
void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	Init();

	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> board[i][j];
			if(board[i][j] == 1) s1 = {i,j,1};
			if(board[i][j] == 2) s2 = {i,j,2};
		}
	}

	BFS();

	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(board[i][j] == 1) ans[1]++;
			if(board[i][j] == 2) ans[2]++;
			if(board[i][j] == -3) ans[3]++;

		}
	}

	//ShowArr();

	for(int i=1;i<=3;i++) cout << ans[i] << " ";
	
	return 0;
}

void BFS(){
	queue<Node> Q; Q.push(s1); Q.push(s2);
	dist[s1.X][s1.Y] = 0; board[s1.X][s1.Y] = s1.VIR;
	dist[s2.X][s2.Y] = 0; board[s2.X][s2.Y] = s2.VIR;
	while(!Q.empty()){
		Node cur = Q.front(); Q.pop();
		if(board[cur.X][cur.Y] == -3) continue;
		for(int dir=0;dir<4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			int ndist = dist[cur.X][cur.Y] + 1;
			if(oob(nx,ny,N,M)) continue;
			if(board[nx][ny] == -1) continue;
			// cout << "	nx :	" << nx;
			// cout << "	ny :	" << ny;
			// cout << "	ndist :	" << ndist;
			// cout << "	cur.VIR :	" << cur.VIR;
			// cout << "\n";
			if(ndist < dist[nx][ny]){
				dist[nx][ny] = ndist;
				board[nx][ny] = cur.VIR;
				Q.push({nx,ny,cur.VIR});
			}
			else if(ndist == dist[nx][ny]){
				if(cur.VIR == board[nx][ny]) continue;
				// cout << "**\n";
				board[nx][ny] = -3;
			}
			
		}
	}
}

bool oob(int nx, int ny, int N, int M){
	return nx <= 0 || ny <= 0 || nx > N || ny > M;
}

void Init(){
	for(int i=0;i<=N;i++){
		for(int j=0;j<=M;j++){
			dist[i][j] = INF;
		}
	}
}

void ShowArr(){
	cout << "*** ShowArr() ***\n";
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

/*
18:54 Problem Analysis
27:29 main() Completed
28:57 Init(), oob() Completed
37:49 BFS() Completed


TC wrong answer..
55:42
	Q.push({nx,ny,ndist});
	에서
	Q.push({nx,ny,cur.VIR});
	로 변경..

58:59 TC passed.
240314 59:05
*/