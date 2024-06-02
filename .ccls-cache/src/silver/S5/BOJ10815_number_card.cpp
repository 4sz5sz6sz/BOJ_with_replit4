#include<bits/stdc++.h>
using namespace std;

int N,M;
unordered_map<int, int> m;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		m[num] = 1;
	}

	cin >> M;
	for(int i=0;i<M;i++){
		int num;
		cin >> num;
		cout << m[num] << " ";
	}
	
	return 0;
}

/*
01:27 Problem Analysis.
240602 03:29
*/