#define INF 0x3f3f3f3f
#define IDX_MAX 10
#include<bits/stdc++.h>
using namespace std;

int N = 10;
int ans = INF;
int cntOfToggle;

int board[IDX_MAX][IDX_MAX];
int board_copy[IDX_MAX][IDX_MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void CopyBoard();
void Toggle(int x, int y);
bool CheckAllOff();
bool OOB(int nx, int ny, int N, int M);

void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for(int x=0;x<N;x++){
		string s;
		cin >> s;
		for(int y=0;y<N;y++){
			if(s[y]=='O')
				board[x][y] = 1;
		}
	}

	for(int bit=0;bit<1<<N;bit++){
		cntOfToggle = 0;
		int mask = bit;
		CopyBoard();
		for(int a=0;mask;mask>>=1,a++){
			if(mask & 1)
				Toggle(0,a);
		}

		for(int x=1;x<N;x++){
			for(int y=0;y<N;y++){
				if(board_copy[x-1][y]){
					Toggle(x,y);
					/*
					if(bit==864){
						cout << "	x : " << x;
						cout << "	y : " << y;
						cout << "\n";
						ShowArr();
					}
					*/
				}
					
			}
		}
		//cout << bit << "\n";
		if(CheckAllOff()){
			//cout << bit << "\n";
			ans = min(ans,cntOfToggle);
		}
		
	}

	if(ans == INF) ans = -1;
	cout << ans << "\n";
	
	return 0;
}

void CopyBoard(){
	for(int x=0;x<N;x++){
		for(int y=0;y<N;y++){
			board_copy[x][y] = board[x][y];
		}
	}
}

void Toggle(int x, int y){
	board_copy[x][y] ^= 1;
	for(int dir=0;dir<4;dir++){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(OOB(nx,ny,N,N)) continue;
		board_copy[nx][ny] ^= 1;
	}
	cntOfToggle++;
}

bool CheckAllOff(){
	for(int x=0;x<N;x++){
		for(int y=0;y<N;y++){
			if(board_copy[x][y]) return false;
		}
	}
	return true;
}

bool OOB(int nx, int ny, int N, int M){
	return nx < 0 || ny < 0 || nx >= N || ny >= M;
}

void ShowArr(){
	cout << "*ShowArr()*\n";
	for(int x=0;x<N;x++){
		for(int y=0;y<N;y++){
			if(board_copy[x][y]) cout << "O";
			else cout << "#";
		}
		cout << "\n";
	}
	cout << "\n";
}


/*
05:27 Problem Analysis.
17:55 ALL completed.
20:16 TC passed.
27:46 -1이 안 뜸..

재개..
18:06 여전히 반례 못 찾음.. 일단 제출해보기..
의외로 정답.
240507 20:16 + 18:14
*/