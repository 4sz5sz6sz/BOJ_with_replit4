#define X first
#define Y second
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Edge;
typedef pair<int,int> Pos;
int N,M;
int cntOfVertex;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
//vector<vector<int>> A;
vector<vector<int>> board;
vector<vector<int>> posArt;
vector<vector<int>> tmpBoard;
vector<vector<int>> vis;
vector<vector<int>> emptyBoard;
vector<Pos> ans;

bool OOB(int nx, int ny, int N, int M);
int DFS_Point(Pos cur, bool root);
int DFS_Bridge(Pos cur, Pos parent);
void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	board.resize(N+1,vector<int>(N+1));
	posArt.resize(N+1,vector<int>(N+1));
	tmpBoard.resize(N+1,vector<int>(N+1));
	vis.resize(N+1,vector<int>(N+1));
	emptyBoard.resize(N+1,vector<int>(N+1));
	
	//Input
	for(int x=1;x<=N;x++){
		string s;
		cin >> s;
		for(int y=1;y<=N;y++){
			if(s[y-1] == '#')
				board[x][y] = 1;
		}
	}

	//Get 'M' : Number of Edge
	for(int x=1;x<=N;x++){
		for(int y=1;y<=N;y++){
			if(board[x][y] == 0) continue;
			for(int dir=0;dir<4;dir++){
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if(OOB(nx,ny,N,N)) continue;
				if(board[nx][ny] == 0) continue;
				M++;
			}
		}
	}
	M/=2;

	//Get Articulation Point
	for(int x=1;x<=N;x++){
		for(int y=1;y<=N;y++){
			// cout << "	x : " << x;
			// cout << "	y : " << y;
			// cout << "	";
			// ShowArr();
			if(!board[x][y]) continue;
			if(vis[x][y]) continue;
			DFS_Point({x,y},true);
			
		}
	}
	cntOfVertex = 0;
	
	tmpBoard=board;
	//Get Articulation Bridge
	for(int x=1;x<=N;x++){
		for(int y=1;y<=N;y++){			
			if(board[x][y]==0) continue;
			if(posArt[x][y]) continue;
			//if(vis[x][y]) continue;
			//tmpBoard=board;
			vis = emptyBoard;
			tmpBoard[x][y] = 0;
			int ret = DFS_Bridge({x,y},{0,0});
			tmpBoard[x][y] = 1;

			if(ret>0)	//모든 간선이 단절선이면 ans에 추가.
				ans.push_back({x,y});
			//ShowArr();
		}
	}

	cout << ans.size() << "\n";
	for(Pos cur:ans)
		cout << cur.X << " " << cur.Y << "\n";
		
	return 0;
}

bool OOB(int nx, int ny, int N, int M){
	return nx <= 0 || ny <= 0 || nx > N || ny > M;
}

int DFS_Point(Pos cur, bool root){
	int ret = vis[cur.X][cur.Y] = ++cntOfVertex;
	int child=0;

	for(int dir=0;dir<4;dir++){
		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];
		if(OOB(nx,ny,N,N)) continue;
		if(board[nx][ny] == 0) continue;
		Pos next = {nx,ny};
		if(!vis[next.X][next.Y]){
			child++;
			//cout << "^";
			int min_V = DFS_Point(next, false);
			if(!root && min_V >= vis[cur.X][cur.Y]){//'>='??
				posArt[cur.X][cur.Y] = true;
			}
			ret = min(ret, min_V);
		}
		else{
			ret = min(ret, vis[next.X][next.Y]);
		}
	}

	if(root && child>=2) posArt[cur.X][cur.Y] = 1;
	return ret;
}

int DFS_Bridge(Pos cur, Pos parent){
	int ret = vis[cur.X][cur.Y] = ++cntOfVertex;

	for(int dir=0;dir<4;dir++){
		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];
		if(OOB(nx,ny,N,N)) continue;
		if(tmpBoard[nx][ny] == 0) continue;
		Pos next = {nx,ny};
		if(next == parent) continue;
		if(!vis[next.X][next.Y]){
			int min_V = DFS_Bridge(next, cur);
			if(min_V<0) return -1;
			//단절선이 아님, 그 즉시 return;
			if(min_V < vis[cur.X][cur.Y]) return -1;
			//단절선이 아닌 경우를 발견.
			//단절선을 굳이 기록할 필요는 없으므로, return -1;
			ret = min(ret, min_V);
		}
		else{
			ret = min(ret, vis[next.X][next.Y]);
		}
	}

	return ret;
}

void ShowArr(){
	cout << "	***ShowArr()***	\n";
	for(int x=1;x<=N;x++){
		for(int y=1;y<=N;y++){
			cout << tmpBoard[x][y] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}


/*
14:01 Problem Analysis.
31:08 main() Completed.
34:17 OOB() Completed.
45:19 DFS_Point() Completed.
54:25 DFS_Bridge() Completed.
58:59 전부 0으로 출력..
01:18:24 예제 입력 2개 전부 다 vis는 전부 0이 떠야 맞음!!
01:28:43 TC passed.
240818 01:28:49
*/