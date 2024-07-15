#define X first
#define Y second
#define IDX_MAX 101
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Pos;

int board[IDX_MAX][IDX_MAX];
int answer[IDX_MAX][IDX_MAX];
int N,M;
int ddx[8] = {1,0,-1,0,1,1,-1,-1};
int ddy[8] = {0,1,0,-1,1,-1,1,-1};

bool OOB(int nx, int ny, int N, int M);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while(1){
		cin >> N >> M;
		if(N==0)
			break;
		for(int x=0;x<N;x++){
			string s;
			cin >> s;
			for(int y=0;y<M;y++){
				if(s[y] == '*')
					board[x][y] = 1;
				else
					board[x][y] = 0;
				answer[x][y] = 0;
			}
			
		}

		for(int x=0;x<N;x++){
			for(int y=0;y<M;y++){
				Pos cur = {x,y};
				for(int dir=0;dir<8;dir++){
					int nx = cur.X + ddx[dir];
					int ny = cur.Y + ddy[dir];
					
					if(OOB(nx,ny,N,M)) continue;
					if(board[nx][ny] == 0) continue;
					answer[x][y]++;
				}
			}
		}

		for(int x=0;x<N;x++){
			for(int y=0;y<M;y++){
				Pos cur = {x,y};
				if(board[x][y])
					cout << "*";
				else
					cout << answer[x][y];
			}
			cout << "\n";
		}
	}
	
	
	return 0;
}

bool OOB(int nx, int ny, int N, int M){
	return nx < 0 || ny < 0 || nx >= N || ny >= M;
}

/*
01:00 Problem Analysis.
12:40 main() Completed.
17:07 TC passed.
240715 17:11
*/