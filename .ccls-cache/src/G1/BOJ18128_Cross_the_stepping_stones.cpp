#define X first
#define Y second
#define INF 0x3f3f3f3f
#define IDX_MAX 1001
#include<bits/stdc++.h>
using namespace std;
int dist_water[IDX_MAX][IDX_MAX];  //물로부터 떨어진 거리
int dist_human[IDX_MAX][IDX_MAX];  //치삼이로부터 떨어진 거리. 매번 초기화되면서 바뀜.
int board[IDX_MAX][IDX_MAX];  //돌의 위치 
//전부 1-indexed
int N, W;
int mid;
typedef pair<int,int> Pos;
vector<Pos> posW;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int ddx[8] = {1,0,-1,0,1,1,-1,-1};
int ddy[8] = {0,1,0,-1,1,-1,1,-1};

void BFS_water();
void BFS_human();
void Init();
void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> W;
	for(int i=0;i<W;i++){
		int a,b;
		cin >> a >> b;
		posW.push_back({a,b});
	}
	
	//Set board[][]
	for(int x=1;x<=N;x++){
		string s;
		cin >> s;
		for(int y=1;y<=N;y++){
			board[x][y] = s[y-1]-'0';
		}
	}

  	//dist_water[][]는 최초 1번만 Init
	for(int x=0;x<=N;x++){
		for(int y=0;y<=N;y++){
			dist_water[x][y] = INF;
		}
	}

	BFS_water();  //물의 거리 재기. dist_water[][] 세팅.
	dist_water[1][1] = 0;
	dist_water[N][N] = 0;
	int st = 0;
	int en = N*N;
	while(st<=en){
		Init();  //dist_human[][] 초기화.
		mid = (st+en)/2;
		BFS_human();  //사람이 도달할 수 있는 거리 재기. dist_human[][] 세팅.
		// cout << "st : " << st << "\n";
		// cout << "mid : " << mid << "\n";
		// cout << "en : " << en << "\n";
		  //ShowArr();
		if(dist_human[N][N] == INF){  //도달 실패
			st = mid+1;
			// cout << "실패\n";
		}
		else{  //도달 성공
			// cout << "성공\n";
			en = mid-1;
		}
		//cout << "\n";
	}
	// cout << "st : " << st << "\n";
	// cout << "mid : " << mid << "\n";
	// cout << "en : " << en << "\n";
	
	if(en >= N*N)
		cout << "-1\n";
	else
		cout << en+1 << "\n";
  	return 0;
}

void BFS_water(){
	queue<Pos> Q;
	for(Pos curPos:posW){
		int nx = curPos.X;
		int ny = curPos.Y;
		Q.push({nx,ny});
		dist_water[nx][ny] = 0;
  	}

	while(!Q.empty()){
		Pos cur = Q.front(); Q.pop();
		for(int dir=0;dir<4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			int ndist = dist_water[cur.X][cur.Y] + 1;
			if(nx <= 0 || ny <= 0 || nx>N || ny>N) continue;
			if(ndist >= dist_water[nx][ny]) continue;
			Q.push({nx,ny}); dist_water[nx][ny] = ndist;
		}
	}

}

void BFS_human(){
	queue<Pos> Q; Q.push({1,1});
	dist_human[1][1] = 0;
	
	while(!Q.empty()){
		Pos cur = Q.front(); Q.pop();
		for(int dir=0;dir<8;dir++){
			int nx = cur.X + ddx[dir];
			int ny = cur.Y + ddy[dir];
			int ndist = dist_human[cur.X][cur.Y] + 1;
			if(nx <= 0 || ny <= 0 || nx>N || ny>N) continue;  //배열의 범위를 벗어나면 PASS
			//if(ndist >= dist_human[nx][ny]) continue;  //현재 거리가 최단 거리가 아니면 PASS
			if(dist_human[nx][ny] != INF) continue;	//이미 방문했으면 PASS
			if(dist_water[nx][ny] > mid) continue;  //돌이 식혀지지 않았으면 PASS
			if(board[nx][ny] != 1) continue; //1이 아니면(=돌이 아니면) PASS
			Q.push({nx,ny}); dist_human[nx][ny] = ndist;
		}
	}
}

void Init(){
	for(int x=1;x<=N;x++){
		for(int y=1;y<=N;y++){
			dist_human[x][y] = INF;
		}
	}
}

void ShowArr(){
	for(int x=1;x<=N;x++){
		for(int y=1;y<=N;y++){
			if(dist_human[x][y] == INF){
				cout << "x ";
			}
			else
		  		cout << dist_human[x][y] << " ";
		}
		cout << "\n";
	}
}



/*
80분 정도 걸린 듯.. 집단지성.
240423
*/