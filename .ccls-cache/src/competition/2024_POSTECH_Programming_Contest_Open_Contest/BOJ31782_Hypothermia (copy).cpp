#define IDX_MAX 2001
#define X first
#define Y second
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Pos;
int N,M,K;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[IDX_MAX][IDX_MAX];
vector<int> alive; 

int numOfColor;
int ans;

bool oob(int nx, int ny, int N, int M);
bool CheckSurvive(Pos cur);
void BFS();
void BFS_flood_fill(Pos start);
void ShowBoard();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;

	for(int x=0;x<N;x++){
		string s;
		cin >> s;
		for(int y=0;y<M;y++){
			if(s[y] == 'O')
				board[x][y] = -1;	//생존, 무소속이면 -1.
			else
				board[x][y] = 0;
		}
	}

	BFS();

	//flood fill 수행
	for(int x=0;x<N;x++){
		for(int y=0;y<M;y++){
			if(board[x][y] == -1){
				numOfColor++;
				BFS_flood_fill({x,y});
				int h = 0; int w = 0;
				while(x+h < N && board[x+h][y] == numOfColor){
					h++;
				}
				while(y+w < M && board[x][y+w] == numOfColor){
					w++;
				}
				if(h > K && w > K) ans+=h*w;
			}
		}
	}

	//ShowBoard();

	cout << ans << "\n";
	
	return 0;
}

bool oob(int nx, int ny, int N, int M){
	return nx < 0 || ny < 0 || nx >= N || ny >= M;
}

bool CheckSurvive(Pos cur){
	int cnt=0;
	for(int dir=0;dir<4;dir++){
		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];
		if(oob(nx,ny,N,M)) continue;
		if(board[nx][ny] == 0) continue;
		cnt++;
	}
	return cnt >= 2;
}

void BFS(){
	queue<Pos> Q;
	for(int x=0;x<N;x++){
		for(int y=0;y<M;y++){
			if(board[x][y] == 0){
				if(CheckSurvive({x,y})){
					board[x][y] = -1;
					Q.push({x,y});
				}
			}
		}
	}

	while(!Q.empty()){
		Pos cur = Q.front(); Q.pop();
		for(int dir=0;dir<4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(oob(nx,ny,N,M)) continue;
			if(board[nx][ny] != 0) continue;	//이미 생존했다면 부활 필요 X
			if(!CheckSurvive({nx,ny})) continue;
			board[nx][ny] = -1;
			Q.push({nx,ny});
		}
	}
}

void BFS_flood_fill(Pos start){
	queue<Pos> Q; Q.push(start);
	board[start.X][start.Y] = numOfColor;
	while(!Q.empty()){
		Pos cur=Q.front(); Q.pop();
		for(int dir=0;dir<2;dir++){	//dir 2로 감소.
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(oob(nx,ny,N,M)) continue;
			//if(board[nx][ny] == 0) continue;	//저체온증이라면, 탐색 중단.
			if(board[nx][ny] != -1) continue;	//무소속이 아니라 이미 색칠되어 있다면, PASS.
			//if(!CheckSurvive({nx,ny})) continue;
			Q.push({nx,ny});
			board[nx][ny] = numOfColor;
		}
	}
}

void ShowBoard(){
	for(int x=0;x<N;x++){
		for(int y=0;y<M;y++){
			cout << board[x][y] << " ";
		}
		cout << "\n";
	}
}


/*
20:13 문제 분석.
35:05 main() Completed.
PM 17:06에 main() 완료..

39:01 CheckSurvive() Completed.
42:01 BFS() Completed.
46:07 BFS_flood_fill() Completed.
48:58 wa..

if(h >= K && w >= K) ans+=h*w;
에서
if(h > K && w > K) ans+=h*w;
로 수정.
50:57 TC passed.

PM 17:22 마무리..


재개..
61%에서 메모리 초과..

07:24
if(board[nx][ny] != -1) continue;	//무소속이 아니라 이미 색칠되어 있다면, PASS.
flood fill에 삽입.

240428 51:07 + 07:38
*/