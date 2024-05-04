#define INF 0x3f3f3f3f
#define X first
#define Y second
#define IDX_MAX 1001
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Pos;

int N,M;
int total_T;
int HP;
int X;
int B;

int board[IDX_MAX][IDX_MAX];	//체력 저장.
int dist[IDX_MAX][IDX_MAX];	//거리 저장.
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<Pos> Q;

void BFS();
bool OOB(int nx, int ny, int N, int M);
void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	cin >> total_T >> HP >> X >> B;

	for(int x=1;x<=N;x++){
		for(int y=1;y<=M;y++){
			dist[x][y] = INF;
		}
	}

	for(int x=1;x<=N;x++){
		string s;
		cin >> s;
		for(int y=1;y<=M;y++){
			char cur = s[y-1];
			if(cur == '*'){
				board[x][y] = -1;
				Q.push({x,y});
				dist[x][y] = 0;
			}
			else if(cur == '#'){
				board[x][y] = HP;
			}
		}
	}

	BFS();
	//ShowArr();

	int cnt=0;
	for(int x=1;x<=N;x++){
		for(int y=1;y<=M;y++){
			if(dist[x][y] == INF){
				cnt++;
				cout << x << " " << y << "\n";
			}
		}
	}

	if(cnt==0)
		cout << -1;
	
	return 0;
}

void BFS(){
	while(!Q.empty()){
		Pos cur = Q.front(); Q.pop();
		//int ndist = dist[cur.X][cur.Y] + 1;
		//board[cur.X][cur.Y]--;
		//if(ndist > total_T) continue;
		/*
		if(board[cur.X][cur.Y]-1 >= 0){
			//if(ndist >= dist[cur.X][cur.Y]) continue;
			ndist = dist[cur.X][cur.Y] + HP;
			dist[cur.X][cur.Y] = ndist;
			Q.push(cur);
			continue;
		} 
		*/
		for(int dir=0;dir<4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(OOB(nx,ny,N,M)) continue;
			int ndist = dist[cur.X][cur.Y] + 1 + max(board[nx][ny],0);
			if(ndist >= dist[nx][ny]) continue;
			if(ndist > total_T) continue;
			dist[nx][ny] = ndist; Q.push({nx,ny});
		}
	}
}

bool OOB(int nx, int ny, int N, int M){
	return nx <= 0 || ny <= 0 || nx > N || ny > M;
}

void ShowArr(){
	for(int x=1;x<=N;x++){
		for(int y=1;y<=M;y++){
			if(dist[x][y] == INF)
				cout << "INF ";
			else
				cout << dist[x][y] << " ";
		}
		cout << "\n";
	}

	for(int x=1;x<=N;x++){
		for(int y=1;y<=M;y++){
			if(board[x][y] == INF)
				cout << "INF ";
			else
				cout << board[x][y] << " ";
		}
		cout << "\n";
	}
}

/*
17:45 Problem Analysis.
24:29 main() Completed.
30:05 BFS() Completed.
30:46 OOB() Completed.
33:55 바이러스 전파 안됨.. => DIST를 0으로 초기화.
38:18 if(board[cur.X][cur.Y] >= 0) continue; 삽입.
48:16 TC passed.
59:37 시간초과.. 체력에 대한 개념 수정.
int ndist = dist[cur.X][cur.Y] + 1 + max(board[cur.X][cur.Y],0);
에서
int ndist = dist[cur.X][cur.Y] + 1 + max(board[nx][ny],0);
로 수정.
01:07:33 TC passed.
240504 01:07:33
*/