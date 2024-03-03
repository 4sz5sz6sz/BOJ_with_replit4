#define NOT_VISITED 0
#define DIR_CW 0	//시계방향
#define DIR_CCW 1	//반시계방향
#define X first
#define Y second
#define IDX_MAX 2005
#include<bits/stdc++.h>
using namespace std;

enum Dir{
	DIR_U,
	DIR_R,
	DIR_D,
	DIR_L
}Dir;

typedef pair<int,int> Pos;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int ddir[4] = {DIR_U, DIR_R, DIR_D, DIR_L};
int board[IDX_MAX][IDX_MAX];

int N,M;
char dir;


void solve(Pos start, int startDir, int dir_CW);
void Init(Pos start, int dirN);	//board의 시작열, 시작행 초기화.
bool oob(int nx, int ny, int N, int M);
void ShowArr();
int Rotating(int curDir,int dir_CW);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	cin >> dir;
	int dirN=0;
	Pos start;

	if(dir == 'U'){
		start.X = 1;
		start.Y = M/2+1;
		dirN = DIR_U;
	}
	else if(dir == 'D'){
		start.X = N;
		start.Y = M/2+1;
		dirN = DIR_D;
	}
	else if(dir == 'L'){
		start.X = N/2+1;
		start.Y = 1;
		dirN = DIR_L;
	}
	else if(dir == 'R'){
		start.X = N/2+1;
		start.Y = M;
		dirN = DIR_R;
	}

	solve(start,dirN,DIR_CW);
	//ShowArr();
	Init(start, dirN);
	solve(start,dirN,DIR_CCW);
	ShowArr();

	return 0;
}

void solve(Pos start, int startDir, int dir_CW){
	int curNum=1;
	Pos cur = start;
	int curDir = (startDir+2)%4;
	int cnt=0;
	board[start.X][start.Y] = curNum++;
	cnt++;
	while(1){
		int nx = cur.X + dx[curDir];
		int ny = cur.Y + dy[curDir];

		if(oob(nx,ny,N,M) || board[nx][ny] != NOT_VISITED){
			if(cnt==0) return;	//더 이상 회전이 의미가 없는 경우. 탐색 종료.
			cnt=0;
			curDir = Rotating(curDir,dir_CW);
		}
		else{
			board[nx][ny] = curNum++;
			cnt++;
			cur.X = nx;
			cur.Y = ny;
		}
	}
}

void Init(Pos start, int dirN){
	if(dirN == DIR_U || dirN == DIR_D){
		for(int row=1;row<=N;row++){
			board[row][start.Y] = 0;
		}
	}
	else{
		for(int col=1;col<=M;col++){
			board[start.X][col] = 0;
		}
	}
}

bool oob(int nx, int ny, int N, int M){
	return nx < 1 || ny < 1 || nx > N || ny > M;
}

void ShowArr(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

int Rotating(int curDir,int dir_CW){
	if(dir_CW == DIR_CW) return (curDir+4+1)%4;
	else return (curDir+4-1)%4;
}

/*
10:08 문제 분석
21:56 main() 작성 완료.
28:35 solve() 작성 완료.
33:28 Init() 작성 완료.
35:47 ShwArr() 작성 완료.
37:42 Rotating() 작성 완료.

43:18
int dirN=0;	//초기화 되지 않으면 에러 발생.

58:24 테스트 케이스 2개 통과

240303 59:16
*/