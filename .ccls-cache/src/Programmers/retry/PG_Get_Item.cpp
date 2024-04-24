#define DIR_CW 1
#define DIR_CCW 0
#define INF 0x3f3f3f3f
#define IDX_MAX 50
#define X first
#define Y second
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Pos;
// int N,M;
enum DIR{
	DIR_R,
	DIR_D,
	DIR_L,
	DIR_U
};

int A[IDX_MAX+1][IDX_MAX+1][4];
int board[IDX_MAX+1][IDX_MAX+1];
int dist[IDX_MAX+1][IDX_MAX+1];

int curDir;	//0~3

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int ddx[8] = {1,0,-1,0,1,1,-1,-1};
int ddy[8] = {0,1,0,-1,1,-1,1,-1};

bool oob(int nx, int ny, int N, int M);
void BFS(Pos start);
void ShowArr();
int Rotating(int curDir);
void GoToGoal(Pos start,int mode);

int solution(vector<vector<int>> rect, int stX, int stY, int enX, int enY){
	for(int x=0;x<=IDX_MAX;x++){
		for(int y=0;y<=IDX_MAX;y++){
			dist[x][y] = INF;
		}
	}

	for(int i=0;i<rect.size();i++){
		Pos p1 = {rect[i][0], rect[i][1]};
		Pos p2 = {rect[i][2], rect[i][3]};
		for(int x=p1.X;x<=p2.X;x++){
			for(int y=p1.Y;y<=p2.Y;y++){
				if(x == p1.X || x == p2.X)
					A[x][y][DIR_L] = A[x][y][DIR_R] = 1;
				else if(y == p1.Y || y == p2.Y)
					A[x][y][DIR_U] = A[x][y][DIR_D] = 1;
				/*
				if(x != p1.X && x != p2.X)
					if(y != p1.Y && y != p2.Y)
						continue;
				board[x][y] = i;	//i번째 사각형의 변.
				*/
			}
		}
		A[p1.X][p1.Y][DIR_U] = 0;
		A[p1.X][p1.Y][DIR_R] = 1;
		A[p1.X][p1.Y][DIR_D] = 1;
		A[p1.X][p1.Y][DIR_L] = 0;

		A[p1.X][p2.Y][DIR_U] = 0;
		A[p1.X][p2.Y][DIR_R] = 0;
		A[p1.X][p2.Y][DIR_D] = 1;
		A[p1.X][p2.Y][DIR_L] = 1;

		A[p2.X][p1.Y][DIR_U] = 1;
		A[p2.X][p1.Y][DIR_R] = 1;
		A[p2.X][p1.Y][DIR_D] = 0;
		A[p2.X][p1.Y][DIR_L] = 0;
		
		A[p2.X][p2.Y][DIR_U] = 1;
		A[p2.X][p2.Y][DIR_R] = 0;
		A[p2.X][p2.Y][DIR_D] = 0;
		A[p2.X][p2.Y][DIR_L] = 1;
	}

	/*
	//convert 1 -> 2
	for(int x=1;x<=IDX_MAX;x++){
		for(int y=1;y<=IDX_MAX;y++){
			if(board[x][y] == 0) continue;
			for(int dir=0;dir<8;dir++){
				int nx = x + ddx[dir];
				int ny = y + ddy[dir];
				if(oob(nx,ny,IDX_MAX,IDX_MAX)){
					board[x][y] = 2;
					break;
				}
				else if(board[nx][ny] == 0){
					board[x][y] = 2;
					break;
				}
			}
		}
	}
	*/

	GoToGoal({stX,stY},DIR_CW);
	GoToGoal({stX,stY},DIR_CCW);
	//BFS({stX,stY});

	ShowArr();
	
	return dist[enX][enY];
}

bool oob(int nx, int ny, int N, int M){
	return nx <= 0 || ny<=0 || nx>N || ny>M;
}

void BFS(Pos start){
	queue<Pos> Q; Q.push(start);
	dist[start.X][start.Y] = 0;
	while(!Q.empty()){
		Pos cur = Q.front(); Q.pop();
		for(int dir=0;dir<4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			int ndist = dist[cur.X][cur.Y] + 1;
			if(oob(nx,ny,IDX_MAX,IDX_MAX)) continue;
			if(board[nx][ny] == 0) continue;	//수정.
			if(ndist >= dist[nx][ny]) continue;
			dist[nx][ny] = ndist;
			Q.push({nx,ny});
		}
	}
}

void ShowArr(){
	for(int x=0;x<=15;x++){
		for(int y=0;y<=15;y++){
			if(dist[x][y] == INF)
				cout << "x" << " ";
			else
				cout << dist[x][y] << " ";
		}
		cout << "\n";
	}
}

int Rotating(int curDir, int mode){
	if(mode == DIR_CW){
		curDir = (curDir+1)%4;
		return curDir;
	}
	else{
		curDir = (curDir-1+4)%4;
		return curDir;
	}
}

void GoToGoal(Pos start,int mode){
	queue<Pos> Q; Q.push(start);
	dist[start.X][start.Y] = 0;
	while(!Q.empty()){
		Pos cur = Q.front(); Q.pop();
		for(int dir=0;dir<4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			int ndist = dist[cur.X][cur.Y] + 1;
			if(oob(nx,ny,IDX_MAX,IDX_MAX)) continue;
			if(board[nx][ny] == 0) continue;	//수정.
			if(ndist >= dist[nx][ny]) continue;
			dist[nx][ny] = ndist;
			Q.push({nx,ny});
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << solution({{1,1,7,4},{3,2,5,5},{4,3,6,9},{2,6,8,8}},1,3,7,8);
	
	return 0;
}

/*
05:01 Problem Analysis.
18:47 Solution() Completed.
19:21 oob() Completed.
22:02 BFS() Completed.
29:19 main() Completed.
시간 초과..

32:31
if(board[nx][ny] != 2 && ndist >= dist[nx][ny]) continue;
에서
if(board[nx][ny] != 2 || ndist >= dist[nx][ny]) continue;
로 수정..

5개 중 1개 성공.. 33:47 저녁

12:32 ShowArr() 통해 반례 찾아냄.
if(oob(nx,ny,IDX_MAX,IDX_MAX)){
	board[x][y] = 2;
	break;
}
추가.

출발점에서, 
우회전, 직진, 좌회전 순으로 정하기.
또는
좌회전, 직진, 우회전 순으로 정하기.

52:25 gg..

240423 33:51 + 52:25
*/