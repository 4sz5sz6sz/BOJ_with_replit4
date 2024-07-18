#include<bits/stdc++.h>
using namespace std;

string ENTER = "ENTER";

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	unordered_map<string,int> m;
	int N;
	int ans=0;
	cin >> N;
	for(int i=1;i<=N;i++){
		string s;
		cin >> s;
		if(s != "ENTER" && m[s] < m[ENTER])
			ans++;
		m[s] = i;
	}

	cout << ans << "\n";
	
	return 0;
}

/*
02:02 Problem Analysis.
10:42 TC passed.
240718 10:54
*/