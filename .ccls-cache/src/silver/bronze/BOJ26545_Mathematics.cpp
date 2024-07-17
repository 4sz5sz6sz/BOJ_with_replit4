#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	int ans=0;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		ans+=num;
	}

	cout << ans << "\n";
	
	return 0;
}

/*
01:32
240717
*/