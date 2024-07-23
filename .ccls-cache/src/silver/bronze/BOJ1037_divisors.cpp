#define INF 0x3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	ll _min = INF;
	ll _max = -INF;
	while(N--){
		ll num;
		cin >> num;

		if(num < _min) _min = num;
		if(num > _max) _max = num;
	}

	cout << _min * _max << "\n";
	
	return 0;
}

/*
01:28 Problem Analysis.
03:53 main() Completed.
240723 04:00
*/