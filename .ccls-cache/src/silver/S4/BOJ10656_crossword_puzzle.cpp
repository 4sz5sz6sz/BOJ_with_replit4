#define X first
#define Y second
#define IDX_MAX 52
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Pos;
enum DIR{
	DIR_D,
	DIR_R,
	DIR_U,
	DIR_L
};

int board[IDX_MAX][IDX_MAX];
bool isused[IDX_MAX][IDX_MAX];
vector<Pos> ans;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool OOB(int nx, int ny, int N, int M);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	cin >> N >> M;

	for(int x=1;x<=N;x++){
		string s;
		cin >> s;
		for(int y=1;y<=M;y++){
			if(s[y-1] == '#')
				board[x][y] = 1;
		}
	}

	for(int x=1;x<=N;x++){
		for(int y=1;y<=M;y++){
			Pos cur = {x,y};
			// cout << "	x : " << x;
			// cout << "	y : " << y;
			// cout << "\n";
			if(board[cur.X][cur.Y] == 1) continue;
			for(int dir=0;dir<2;dir++){
				int px = cur.X - dx[dir];
				int py = cur.Y - dy[dir];
				if(!OOB(px,py,N,M) && board[px][py]==0) continue;
				for(int add=1;add<=2;add++){
					int nx = cur.X + dx[dir]*add;
					int ny = cur.Y + dy[dir]*add;
					// cout << "	nx : " << nx;
					// cout << "	ny : " << ny;
					// cout << "\n";
					if(OOB(nx,ny,N,M) || board[nx][ny]) break;
					if(add==2 && !isused[cur.X][cur.Y]){
						isused[cur.X][cur.Y] = true;
						ans.push_back(cur);
					}
				}
			}
		}
	}

	cout << ans.size() << "\n";
	for(Pos cur:ans){
		cout << cur.X << " " << cur.Y << "\n";
	}
	
	return 0;
}

bool OOB(int nx, int ny, int N, int M){
	return nx <= 0 || ny<=0 || nx>N || ny>M;
}

/*
05:40 Problem Analysis.
22:40 main() Completed.
28:42 TC passed.
240617 28:45
*/