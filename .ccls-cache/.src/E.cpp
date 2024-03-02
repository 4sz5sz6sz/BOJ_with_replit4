#define X first
#define Y second
#define IDX_MAX 42
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Pos;

char board[IDX_MAX][IDX_MAX];
bool vis[IDX_MAX][IDX_MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
Pos exc1, exc2;
int N;
int numOfCho;
vector<Pos> st;
vector<Pos> ans;

bool isOnePiece(Pos start);
bool oob(int nx, int ny, int x, int y);
bool func1(Pos start);	//1번째 조각 떼어내기.
void Init();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cin.tie(0);

	cin >> N;
	for(int i=1;i<=N;i++){
		string s;
		cin >> s;
		for(int j=1;j<=N;j++){
			board[i][j] = s[j-1];
			if(s[j-1] == '#') numOfCho++;
			if(st.size()<3&& s[j-1] == '#'){
				st.push_back({i,j});
			}
		}
	}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(board[i][j] != '#') continue;
			if(func1({i,j})){
				ans.push_back({i,j});
			}
		}
	}

	sort(ans.begin(),ans.end());

	cout << ans.size() << "\n";
	for(Pos cur:ans){
		cout << cur.X << " " << cur.Y << "\n";
	}
	
	return 0;
}

bool isOnePiece(Pos start){
	Init();
	queue<Pos> Q; Q.push(start);
	vis[start.X][start.Y] = true;
	int cnt;
	if(exc2.X == -1 && exc2.Y == -1) cnt = 1;
	else cnt = 2;	//??
	
	while(!Q.empty()){
		Pos cur = Q.front(); Q.pop();
		for(int dir=0;dir<4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(oob(nx,ny,N,N) || vis[nx][ny]) continue;
			Q.push({nx,ny}); vis[nx][ny] = true;
			cnt++;
		}
	}
	if(cnt==numOfCho) return true;
	return false;
}
bool oob(int nx, int ny, int x, int y){
	return nx <= 0 || ny<=0 || nx>x || ny>y; 
}
bool func1(Pos start){
	exc1 = start; exc2 = {-1,-1};
	Pos curF;
	for(Pos cur:st){
		if(exc1 == cur) continue;
		curF = cur;
	}

	if(isOnePiece(curF)){
		for(int x=1;x<=N;x++){
			for(int y=1;y<=N;y++){
				if(board[x][y] != '#' || (exc1.X == x && exc1.Y == y)) continue;
				exc2 = {x,y};
				for(Pos cur:st){
					if(exc1 == cur) continue;
					if(exc2 == cur) continue;
					curF = cur;
				}
				if(isOnePiece(curF)){
					return false;
				}
			}
		}
	}
	return true;
}

void Init(){
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			vis[i][j] = false;
		}
	}
}

/*
23:05 잠시 중단..

10:18 문제 분석
18:15 main() 작성 완료.
24:43 func1() 작성 완료.
25:56 oob() 작성 완료.
33:16 isOnePiece() 작성 완료.
34:06 Init() 작성 완료.
36:11 첫 컴파일.
36:26 1-indexed로 완벽히 변경시키기.
240301 
*/