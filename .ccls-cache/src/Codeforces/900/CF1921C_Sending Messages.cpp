#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		vector<LL> arr;
		LL N,f,a,b;
		cin >> N >> f >> a >> b;
		arr.resize(N+1);
		for(int i=1;i<=N;i++){
			cin >> arr[i];
		}

		LL curE = 0;
		for(int i=1;i<=N;i++){
			LL na = (arr[i] - arr[i-1]) * a;
			LL nb = b;

			curE += min(na,nb);
		}

		if(curE < f){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	
	return 0;
}


/*
23:49 Problem Reading
27:51 Problem Analysis
33:06 TC passed
240315 33:11
*/