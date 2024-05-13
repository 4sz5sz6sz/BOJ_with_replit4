#include<bits/stdc++.h>
using namespace std;

long long LCM(long long a,long long b);
long long GCD(long long a,long long b);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		long long a,b;
		cin >> a >> b;
		cout << LCM(a,b) << "\n";
	}
	return 0;
}

long long LCM(long long a,long long b){
	return a/GCD(a,b)*b;
}
long long GCD(long long a,long long b){
	return b?GCD(b,a%b):a;
}

/*
240513 01:46
*/