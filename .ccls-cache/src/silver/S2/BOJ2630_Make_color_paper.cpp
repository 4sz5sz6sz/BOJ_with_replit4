#define IDX_MAX 128
#include<bits/stdc++.h>
using namespace std;

int board[IDX_MAX][IDX_MAX];

int ans[2];
void func(int x_st, int x_en, int y_st, int y_en);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> board[i][j];
		}
	}

	func(0,N,0,N);
	cout << ans[0] << "\n";
	cout << ans[1] << "\n";
	
	return 0;
}

void func(int x_st, int x_en, int y_st, int y_en){
	int flag=0;
	int curColor = board[x_st][y_st];
	for(int x=x_st;x<x_en;x++){
		for(int y=y_st;y<y_en;y++){
			if(curColor != board[x][y]){
				flag = 1;	//다른 색종이 검출.
				break;
			}
		}
	}
	/*
	cout << "	x_st	:" << x_st;
	cout << "	x_en	:" << x_en;
	cout << "	y_st	:" << y_st;
	cout << "	y_en	:" << x_en;
	cout << "	flag	:" << flag;
	if(flag==0)
		cout << "	curColor	:" << curColor;
	cout << "\n";
	*/
	if(flag){
		int x_mid = (x_st + x_en) / 2;
		int y_mid = (y_st + y_en) / 2;
		func(x_st, x_mid, y_st, y_mid);
		func(x_st, x_mid, y_mid, y_en);
		func(x_mid, x_en, y_st, y_mid);
		func(x_mid, x_en, y_mid, y_en);
	}
	else{
		ans[curColor]++;
	}
		
}

/*
10:46 Problem Analysis.
17:10 main(), func() Completed.
18:04 WC..
	10,6 출력.

25:12
	func(x_st, x_mid, y_mid+1, y_en);
	에서
	func(x_st, x_mid, y_mid, y_en);
	로 수정.
정상 작동.

240414 25:33
*/