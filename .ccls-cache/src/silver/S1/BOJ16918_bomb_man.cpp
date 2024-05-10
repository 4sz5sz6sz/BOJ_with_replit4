#define EMPTY -1
#define IDX_MAX 201
#include<bits/stdc++.h>
using namespace std;

int N,M,K;
int curT;

int board[IDX_MAX][IDX_MAX];
int board_copy[IDX_MAX][IDX_MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool OOB(int nx, int ny, int N, int M);
void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;

	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		for(int j=0;j<M;j++){
			if(s[j] == '.')
				board[i][j] = EMPTY;
		}
	}

	for(curT=2;curT<=K;curT++){
		if(curT%2 == 0){	//폭탄 설치하기. 현재 시간대로.
			for(int x=0;x<N;x++){
				for(int y=0;y<M;y++){
					if(board[x][y] == EMPTY)
						board[x][y] = curT;
				}
			}
		}
		else{
			//터뜨린 곳 기록한 곳 초기화
			for(int x=0;x<N;x++){
				for(int y=0;y<M;y++){
					board_copy[x][y] = EMPTY;
				}
			}

			//터뜨린 곳 기록
			for(int x=0;x<N;x++){
				for(int y=0;y<M;y++){
					//폭탄이면서, 3초 이전에 설치되었으면 폭파.
					if(board[x][y] >= 0 && board[x][y] < curT-2){
						// cout << curT;
						board_copy[x][y] = 1;
						for(int dir=0;dir<4;dir++){
							int nx = x + dx[dir];
							int ny = y + dy[dir];
							if(OOB(nx,ny,N,M)) continue;
							board_copy[nx][ny] = 1;
							// cout << curT;
						}
					}
				}
			}

			//터뜨린 곳 반영
			for(int x=0;x<N;x++){
				for(int y=0;y<M;y++){
					if(board_copy[x][y] == 1){
						board[x][y] = EMPTY;
						// cout << curT;
					}
				}
			}
		}
		//ShowArr();
	}

	ShowArr();
	
	return 0;
}

bool OOB(int nx, int ny, int N, int M){
	return nx < 0 || ny < 0 || nx>=N || ny>=M;
}

void ShowArr(){
	//cout << "	curT : " << curT << "\n";
	for(int x=0;x<N;x++){
		for(int y=0;y<M;y++){
			if(board[x][y] == EMPTY)
				cout << '.';
			else
				cout << 'O';
		}
		cout << "\n";
	}

	/*
	cout << "\n"
	for(int x=0;x<N;x++){
		for(int y=0;y<M;y++){
			if(board[x][y] == EMPTY)
				cout << 'x';
			else
				cout << board[x][y];
		}
		cout << "\n";
	}
	*/
}

/*
07:44 Problem Analysis.
20:19 main() Completed.
21:57 ShowArr() Completed.
37:43
if(board[x][y] > 0 && board[x][y] < curT-1){
에서
if(board[x][y] >= 0 && board[x][y] < curT-1){
로 수정..

홀짝 잘못 봄......
슈도코드를 잘못 작성함. 슈도코드를 수정하지 않은 채로 그대로 옮겨적음..

52:57 TC passed.
240509 53:02
*/