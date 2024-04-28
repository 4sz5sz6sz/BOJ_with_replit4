#define IDX_MAX 200001
#include<bits/stdc++.h>
using namespace std;

int N,K;
int curK;
int sub[IDX_MAX];
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	cin >> s;

	curK = K;

	for(int i=0;i<N;i++){
		sub[i] = 26 - (s[i]-'A');
	}

	for(int i=0;i<N;i++){
		if(s[i] == 'A') continue;
		if(curK >= sub[i]){
			s[i] = 'A';
			curK-=sub[i];
		}
	}

	s[N-1]+=(curK%26);

	cout << s << "\n";
	
	return 0;
}

/*
08:33 Problem Analysis.
12:59 main() Completed.
14:29 TC passed.
240428 14:36
*/