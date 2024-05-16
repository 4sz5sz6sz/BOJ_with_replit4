#define X first
#define Y second
#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair<int,int> Pos;

ld dist(Pos x, Pos y);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		//int x[2], y[2], r[2];
		ld x1,y1,r1,x2,y2,r2;
		int ans;
		/*
		for(int i=0;i<2;i++){
			cin >> x[i] >> y[i] >> r[i];
		}
		*/

		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if(r1 > r2){
			swap(x1,x2);
			swap(y1,y2);
			swap(r1,r2);
		}

		//ld d = dist({x[0], y[0]} , {x[1], y[1]});
		ld d = dist({x1,y1} , {x2,y2});
		if(x1==x2 && y1==y2 && r1 == r2)
			ans = -1;
		else if(d == r1 + r2)
			ans = 1;
		else if(d > r1 + r2)
			ans = 0;
		else if(d < r2 - r1)
			ans = 0;
		else if(d == r2 - r1)
			ans = 1;
		else if(d < r1 + r2)
			ans = 2;
		else
			ans = 99;
			
		cout << ans << "\n";
	}
	
	return 0;
}

ld dist(Pos a, Pos b){
	ld A = (a.X - b.X);
	ld B = (a.Y - b.Y);
	return sqrt(A*A + B*B);
}

/*
12:42 Problem Analysis.
19:37 TC passed.
WA...
-1 추가.
25:51
swap 추가.

if(x1==y1 && y2==x2 && r1 == r2)
조건문
if(x1==x2 && y1==y2 && r1 == r2)
로 수정...
240516 31:36
*/