#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while(1){
		int N;
		int ans=0;
		cin >> N;
		if(N==0) break;
		for(int i=1;i<=N;i++){
			ans+=i;
		}
		cout << ans << "\n";
	}
	
	return 0;
}

/*
01:27
240629
*/