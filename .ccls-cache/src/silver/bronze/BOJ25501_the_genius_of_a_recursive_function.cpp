#include<bits/stdc++.h>
using namespace std;
// #include <stdio.h>
// #include <string.h>

int cnt;
string s;

int recursion(int l, int r){
	cnt++;
	if(l >= r) return 1;
	else if(s[l] != s[r]) return 0;
	else return recursion(l+1, r-1);
}

int isPalindrome(){
	int len = s.size();
	return recursion(0, len-1);
}

/*
int isPalindrome(string s){
	int len = s.size();
	for(int i=0;i<len;i++){
		cnt++;
		int j = len-1-i;
		if(l>=r) break;
		if(s[l]!=s[r])
		
	}
	
	return 
}
*/

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		//string s;
		cin >> s;
		cnt=0;
		cout << isPalindrome() << " " << cnt << "\n";
	}
	return 0;
}

/*
00:59 Problem Analysis.
04:13 TC passed.
TLE...
10:05 (int)s.size()
21:02 매개변수 s 삭제. 전역변수로 변경
240804 21:05
*/