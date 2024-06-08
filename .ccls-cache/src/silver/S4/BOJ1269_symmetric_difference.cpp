#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	cin >> N >> M;
	int ans=0;

	unordered_map<int,int> m;
	int cnt=N+M;
	while(cnt--){
		int num;
		cin >> num;
		m[num]++;
		if(m[num] == 1)
			ans++;
		else if(m[num] == 2)
			ans--;
	}

	cout << ans << "\n";
	
	
	return 0;
}
/*
02:34 main() Completed.
240608 
*/