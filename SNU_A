#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		int input[4];
		int BIT[4][3];
		for(int i=0;i<4;i++){
			cin >> input[i];
		}

		for(int i=0;i<4;i++){
			for(int j=0;j<3;j++){
				BIT[i][j] = input[i] & (1<<j);
			}
		}

		int ans;

		for(int j=0;j<3;j++){
			ans = 0;
			int res = BIT[0][j];
			for(int i=0;i<4;i++){
				if(BIT[i][j] != res) ans = 1;
			}
			if(ans==0) break;
		}

		if(ans)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}

/*
38:27 main() Completed.
240601 
*/