#define IDX_MAX 1000000
#include<bits/stdc++.h>
using namespace std;

vector<int> prime(IDX_MAX+1,true);
vector<int> arr;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	prime[1]=false;
	for(int i=2;i<=sqrt(IDX_MAX);i++){
		for(int j=i*i;j<=IDX_MAX;j=j+i){
			prime[j]=false;
		}
	}

	for(int i=2;i<=IDX_MAX;i++){
		if(prime[i])
			arr.push_back(i);
	}
	int len = arr.size();
	
	int T;
	cin >> T;
	while(T--){
		int N;
		int ans=0;
		cin >> N;
		for(int i=0;i<len;i++){	//len?
			int cur = arr[i];
			// cout << "	[cur] : " << cur;
			if(cur>N/2) break;
			if(prime[N-cur]){
				// cout << "	N : " << N;
				// cout << "	cur : " << cur;
				// cout << "\n";
				ans++;
			} 
		}
		cout << ans << "\n";
	}
	
	return 0;
}

/*
02:05 Problem Analysis.
10:57 main() Completed.
22:17 TC passed.
240719 22:20
*/