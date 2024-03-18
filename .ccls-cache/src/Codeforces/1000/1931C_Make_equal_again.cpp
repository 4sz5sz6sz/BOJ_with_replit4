#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<int> arr(N);
		for(int i=0;i<N;i++){
			cin >> arr[i];
		}
		int numL = arr[0];
		int numR = arr[N-1];
		int cntL = 0;
		int cntR = 0;
		for(int i=0;i<N;i++){
			if(numL == arr[i]){
				cntL++;
			}
			else break;
		}
		for(int i=N-1;i>=0;i--){
			if(numR == arr[i]){
				cntR++;
			}
			else break;
		}

		int ans;
		if(numL == numR){
			ans = N - (cntL + cntR);
			if(ans<0) ans=0;
		}
		else{
			ans = N - max(cntL, cntR);
		}
		cout << ans << "\n";
	}
	
	return 0;
}


/*
12:51 Problem reading & analysis.
20:17 TC passed.
240317 20:48 
*/