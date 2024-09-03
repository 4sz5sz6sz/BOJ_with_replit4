#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int N;
	cin >> N;
	string s1,s2;
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		s1 = s1+s;
	}

	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		s2 = s2+s;
	}

	ll n1,n2;
	n1 = stoll(s1);
	n2 = stoll(s2);
	ll ans = min(n1,n2);
	cout << ans;
	
	return 0;
}

/*
01:53 Problem Analysis.
05:46 TC passed.

240903 06:24
*/