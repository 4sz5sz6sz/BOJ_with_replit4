#define DIST first
#define POS second
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define IDX_MAX 26*26
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Pos;
typedef pair<int,int> Edge;
int N,M,T,D;
int board[IDX_MAX][IDX_MAX];
int dist[IDX_MAX];
int dist_2[IDX_MAX];
vector<vector<Edge>> A;	//정방향
vector<vector<Edge>> revA;	//역방향
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int GetPosToInt(Pos cur);
Pos GetIntToPos(int cur);
//void BFS(Pos start);
bool OOB(int nx, int ny, int N, int M);
void ShowArr();
void Dijkstra(Pos start);
void Dijkstra_2(Pos start);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> T >> D;
	for(int x=0;x<N;x++){
		string s;
		cin >> s;
		for(int y=0;y<M;y++){
			int d;
			if(s[y] <= 'Z') d = s[y] - 'A';
			else d = s[y] - 'a' + 26;
			board[x][y] = d;
		}
	}

	for(int x=0;x<N*M;x++){
		dist[x] = INF;
	}

	for(int x=0;x<N*M;x++){
		dist_2[x] = INF;
	}

	A.resize(N*M+1);
	revA.resize(N*M+1);

	for(int x=0;x<N;x++){
		for(int y=0;y<M;y++){
			Pos cur = {x,y};
			for(int dir=0;dir<4;dir++){
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if(OOB(nx,ny,N,M)) continue;
				int add;
				if(abs(board[nx][ny] - board[cur.X][cur.Y]) > T) continue;
				if(board[nx][ny] > board[cur.X][cur.Y]) 
					add = pow(board[nx][ny] - board[cur.X][cur.Y],2);
				else
					add = 1;
				int curPos = GetPosToInt({x,y});
				int nextPos = GetPosToInt({nx,ny});
				A[curPos].push_back({add,nextPos});
				revA[nextPos].push_back({add,curPos});
			}
		}
	}

	//BFS({0,0});
	Dijkstra({0,0});
	Dijkstra_2({0,0});

	int ans=0;
	
	for(int x=0;x<N*M;x++){
		if(dist[x] == INF || dist[x] + dist_2[x] > D) continue;
		ans = max(ans, board[x/M][x%M]);
	}
	//ShowArr();

	cout << ans << "\n";
	
	return 0;
}

/*
void BFS(Pos start){
	queue<Pos> Q; Q.push(start);
	dist[start.X][start.Y] = 0;
	while(!Q.empty()){
		Pos cur = Q.front(); Q.pop();
		for(int dir=0;dir<4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(OOB(nx,ny,N,M)) continue;
			int add;
			if(abs(board[nx][ny] - board[cur.X][cur.Y]) > T) continue;
			if(board[nx][ny] > board[cur.X][cur.Y]) 
				add = pow(board[nx][ny] - board[cur.X][cur.Y],2);
			else
				add = 1;
			int ndist = dist[cur.X][cur.Y] + add;
			if(ndist > D || ndist >= dist[nx][ny]) continue;
			Q.push({nx,ny}); dist[nx][ny] = ndist;
			//ShowArr();
		}
	}
}
*/

bool OOB(int nx, int ny, int N, int M){
	return nx < 0 || ny < 0 || nx >= N || ny >= M;
}

void ShowArr(){
	for(int x=0;x<N;x++){
		for(int y=0;y<M;y++){
			cout << board[x][y] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
	
	for(int x=0;x<N*M;x++){
		cout << dist[x] << " ";
		if(x % M == 0) cout << "\n";
	}
	cout << "\n";

	for(int x=0;x<N*M;x++){
		cout << dist_2[x] << " ";
		if(x % M == 0) cout << "\n";
	}
	cout << "\n";
}

int GetPosToInt(Pos cur){
	return cur.X * M + cur.Y;
}

Pos GetIntToPos(int cur){
	return {cur / M, cur % M};
}

void Dijkstra(Pos start){
	priority_queue<Edge,vector<Edge>, greater<Edge>> Q; Q.push({0,GetPosToInt(start)});
	dist[GetPosToInt(start)] = 0;
	while(!Q.empty()){
		Edge cur = Q.top(); Q.pop();
		if(cur.DIST != dist[cur.POS]) continue;
		for(Edge next:A[cur.POS]){
			if(dist[cur.POS] + next.DIST < dist[next.POS]){
				dist[next.POS] = dist[cur.POS] + next.DIST;
				Q.push({dist[next.POS],next.POS});
			}
		}
	}
}

void Dijkstra_2(Pos start){
	priority_queue<Edge,vector<Edge>, greater<Edge>> Q; Q.push({0,GetPosToInt(start)});
	dist_2[GetPosToInt(start)] = 0;
	while(!Q.empty()){
		Edge cur = Q.top(); Q.pop();
		if(cur.DIST != dist_2[cur.POS]) continue;
		for(Edge next:revA[cur.POS]){
			if(dist_2[cur.POS] + next.DIST < dist_2[next.POS]){
				dist_2[next.POS] = dist_2[cur.POS] + next.DIST;
				Q.push({dist_2[next.POS],next.POS});
			}
		}
	}
}


/*
07:57 Problem Analysis.
13:24 main() Completed.
23:54 BFS() Completed.
24:39 OOB() Completed.
25:51 WA..
26:48 ShowArr() Completed.
31:43 'a'가 32으로 나오는 현상 발생. 대소문자 전처리 다시 제대로 고침.
41:08 BFS({1,1})를 BFS({0,0})으로 수정..
+ 문제 조건 놓침, 출발점으로 다시 되돌아 와야한다..

출발지가 모든 곳이고, 도착점이 한 곳인 경우의 최단경로.
역방향 간선을 제작해야 한다.

43:41 다익스트라로 다시 짜는게 나을 듯. revA 제작하기..
50:14 GetPosToInt() Completed.
56:01 간선 생성기 Completed.
01:00:38 GetIntToPos() Completed.
01:06:44 Dijkstra_1,2() Completed.
01:13:59 0 출력.. WA..
01:20:47 TC passed.
240510 01:21:11
*/
