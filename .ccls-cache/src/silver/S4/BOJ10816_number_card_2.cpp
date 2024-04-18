#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	cin >> N;
	unordered_map<string,int> m;
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		m[s]++;
	}

	cin >> M;

	for(int i=0;i<M;i++){
		string q;
		cin >> q;
		cout << m[q] << " ";
	}
	
	return 0;
}

/*
03:28 Problem Analysis.
04:59 TC passsed.
240418 04:59
*/