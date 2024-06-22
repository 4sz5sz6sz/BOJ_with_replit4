#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	string ans;
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		for(char cur:s){
			if(cur == 'S'){
				ans = s;
			}
		}
	}
	cout << ans << "\n";
	
	return 0;
}

/*
02:29
240622 
*/