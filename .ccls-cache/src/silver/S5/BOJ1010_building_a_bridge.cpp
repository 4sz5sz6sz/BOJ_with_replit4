#define IDX_MAX 50
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll DP[IDX_MAX][IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int T;
	cin >> T;

	for(int i=0;i<IDX_MAX;i++){
		DP[i][i] = 1;
		DP[i][0] = 1;
	}
	
	for(int i=1;i<IDX_MAX;i++){
		for(int j=1;j<IDX_MAX;j++){
			DP[i][j] = DP[i-1][j-1] + DP[i-1][j];
		}
	}
	
	while(T--){
		int a,b;
		cin >> a >> b;
		if(a<b) swap(a,b);
		cout << DP[a][b] << "\n";
	}
	
	return 0;
}

/*
06:38 main() Completed.
240614 
*/