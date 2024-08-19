#define BIG_NUM (1000000ll)
#define X first
#define Y second
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> Edge;
typedef pair<ll,ll> Pos;
ll N,M;
ll cntOfVertex;
ll numOfVertex;
ll dx[4] = {1,0,-1,0};
ll dy[4] = {0,1,0,-1};
ll add_val;
//vector<vector<int>> A;
vector<vector<ll>> board;
vector<vector<ll>> posArt;
vector<vector<ll>> tmpBoard;
vector<vector<ll>> vis;
vector<vector<ll>> emptyBoard;
vector<Pos> ans;

bool OOB(int nx, int ny, int N, int M);
ll DFS_Point(Pos cur, bool root);
ll DFS_Bridge(Pos cur, Pos parent);
void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	board.resize(N+1,vector<ll>(N+1));
	posArt.resize(N+1,vector<ll>(N+1));
	tmpBoard.resize(N+1,vector<ll>(N+1));
	vis.resize(N+1,vector<ll>(N+1));
	emptyBoard.resize(N+1,vector<ll>(N+1));
	
	//Input
	for(int x=1;x<=N;x++){
		string s;
		cin >> s;
		for(int y=1;y<=N;y++){
			if(s[y-1] == '#'){
				numOfVertex++;
				board[x][y] = 1;
			}
		}
	}

	//Get 'M' : Number of Edge
	for(int x=1;x<=N;x++){
		for(int y=1;y<=N;y++){
			if(board[x][y] == 0) continue;
			for(int dir=0;dir<4;dir++){
				ll nx = x + dx[dir];
				ll ny = y + dy[dir];
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
	

	vis=emptyBoard;
	tmpBoard=board;
	ll n = numOfVertex-1;
	
	//Get Articulation Bridge
	for(int x=1;x<=N;x++){
		for(int y=1;y<=N;y++){			
			if(board[x][y]==0) continue;
			if(posArt[x][y]) continue;
			ll m = M;

			for(int dir=0;dir<4;dir++){
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if(OOB(nx,ny,N,N)) continue;
				if(board[nx][ny]==0) continue;
				m--;
			}
			// cout << "	n : " << n;
			// cout << "	m : " << m;
			// cout << "\n";

			if(n-m==1)	//트리가 맞으면 ans에 추가.
				ans.push_back({x,y});
			
		}
	}

	/*
	//Get Articulation Bridge
	for(int x=1;x<=N;x++){
		for(int y=1;y<=N;y++){			
			if(board[x][y]==0) continue;
			if(posArt[x][y]) continue;
			//vis = emptyBoard; //시간 초과의 원인..
			tmpBoard[x][y] = 0;
			cntOfVertex = 0;
			ll ret = DFS_Bridge({x,y},{0,0});
			tmpBoard[x][y] = 1;
			add_val += BIG_NUM;

			if(ret>0)	//모든 간선이 단절선이면 ans에 추가.
				ans.push_back({x,y});
			//ShowArr();
		}
	}
	*/

	cout << ans.size() << "\n";
	for(Pos cur:ans)
		cout << cur.X << " " << cur.Y << "\n";
		
	return 0;
}

bool OOB(int nx, int ny, int N, int M){
	return nx <= 0 || ny <= 0 || nx > N || ny > M;
}

ll DFS_Point(Pos cur, bool root){
	ll ret = vis[cur.X][cur.Y] = ++cntOfVertex;
	ll child=0;

	for(int dir=0;dir<4;dir++){
		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];
		if(OOB(nx,ny,N,N)) continue;
		if(board[nx][ny] == 0) continue;
		Pos next = {nx,ny};
		if(!vis[next.X][next.Y]){
			child++;
			//cout << "^";
			ll min_V = DFS_Point(next, false);
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

ll DFS_Bridge(Pos cur, Pos parent){
	ll ret = vis[cur.X][cur.Y] = (++cntOfVertex) + add_val;

	for(int dir=0;dir<4;dir++){
		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];
		if(OOB(nx,ny,N,N)) continue;
		if(tmpBoard[nx][ny] == 0) continue;
		Pos next = {nx,ny};
		if(next == parent) continue;
		if(vis[next.X][next.Y] <= add_val){
			ll min_V = DFS_Bridge(next, cur);
			if(min_V <= -1) return -1;
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
01:28:49 sweet 문제 해결.

10:34 TC passed.
13:55 출력초과...
함수 반환형을 전부 ll로 변경.
16:26 cntOfVertex = 0;를 최초 1회가 아닌, 2중 for문 매번 하도록 변경.
23:40 트리 판별 아이디어,
N과 M의 갯수 비교하기.
31:43 TC passed.

240818 01:28:49 + 31:43
*/