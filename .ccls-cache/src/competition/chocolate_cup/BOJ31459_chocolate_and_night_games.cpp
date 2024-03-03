#define IDX_MAX 107
#include<bits/stdc++.h>
using namespace std;

bool oob(int nx, int ny, int row, int col);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		bool vis[IDX_MAX][IDX_MAX];
		int X, Y, dx, dy;
		cin >> X >> Y >> dx >> dy;
		int ans=0;

		//Init();
		for(int i=0;i<IDX_MAX;i++){
			for(int j=0;j<IDX_MAX;j++){
				vis[i][j] = false;
			}
		}

		for(int curX=0;curX<X;curX++){
			for(int curY=0;curY<Y;curY++){
				int nx = curX;
				int ny = curY;
				while(!oob(nx,ny,X,Y) && vis[nx][ny] == false){
					if(!oob(nx-dx,ny-dy,X,Y) && vis[nx-dx][ny-dy] == true) break;
					if(!oob(nx+dx,ny+dy,X,Y) && vis[nx+dx][ny+dy] == true) break;
					vis[nx][ny] = true;
					ans++;
					nx += dx+dx; ny += dy+dy;
				}
			}
		}

		cout << ans << "\n";
	}
	
	return 0;
}

bool oob(int nx, int ny, int row, int col){
	return nx < 0 || ny < 0|| nx >= row|| ny >= col;
}

/*
13:55 문제 분석
17:46 main() 작성 완료
가로 세로가 다르긴 한데, 문제 없을 가능성 높음.
20:01 oob() 작성 완료. 첫 컴파일
26:51
	if(oob(nx-dx,ny-dy,X,Y) || vis[nx-dx][ny-dy] == true) break;
	삽입
		->
		if(!oob(nx-dx,ny-dy,X,Y) && vis[nx-dx][ny-dy] == true) break;
		로 수정.
	nx += dx+dx; ny += dy+dy;
	삽입
28:27 테스트 케이스 통과

240301 28:34
*/