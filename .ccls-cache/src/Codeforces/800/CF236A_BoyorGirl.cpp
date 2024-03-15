#include<bits/stdc++.h>
using namespace std;

int cnt[26];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	int ans=0;
	cin >> s;
	for(int i=0;i<s.size();i++){
		int cur = s[i] - 'a';
		if(cnt[cur]==0){
			ans++;
		}
		cnt[cur]++;
	}
	if(ans%2==0){
		cout << "CHAT WITH HER!\n";
	}
	else{
		cout << "IGNORE HIM!\n";
	}
	//cout << ans;
	
	return 0;
}

/*
06:54 Problem Analysis
08:23 main() Completed
09:20 문제 다시 해석..
240314 18:04
*/