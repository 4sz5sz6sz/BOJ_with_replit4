#define IDX_MAX 5007
#include<bits/stdc++.h>
using namespace std;

int DP[IDX_MAX][IDX_MAX];
int ans[IDX_MAX][IDX_MAX];
int N,Q;

void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> N;
	cin >> s;

	for(int st=0;st<N;st++){
		for(int d=0;d<N;d++){
			int p1 = st-d;
			int p2 = st+1+d;
			if(p1 < 0 || p2 >= N) continue;
			DP[p1][p2] = DP[p1+1][p2-1];
			if(s[p1] == s[p2])
				DP[p1][p2]++;
		}
	}

	for(int d=1;d<N;d++){
		for(int st=0;st<N;st++){
			int p1 = st;
			int p2 = st+d;
			if(p1 < 0 || p2 >= N) continue;
			ans[p1][p2] = max(ans[p1][p2],DP[p1][p2]);
			ans[p1][p2] = max(ans[p1][p2],ans[p1+1][p2]);
			ans[p1][p2] = max(ans[p1][p2],ans[p1][p2-1]);
			/*
			cout << "	p1	:" << p1;
			cout << "	p2	:" << p2;
			cout << "\n";
			*/
		}
	}
	
	cin >> Q;
	while(Q--){
		int l,r;
		cin >> l >> r;
		l--; r--;
		cout << ans[l][r] << "\n";
	}

	//ShowArr();

	return 0;
}

void ShowArr(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << DP[i][j]<< " ";
		}
		cout << "\n";
	}

	cout << "\n";
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << ans[i][j]<< " ";
		}
		cout << "\n";
	}
}

/*
01:52 Problem Analysis.
03:25 query Completed.
08:37 DP completed.
18:05 main() Completed.
37:07 TC passed.

240519 37:11
*/