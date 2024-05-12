#define IDX_MAX 1000001
#include<bits/stdc++.h>
using namespace std;

bool isprime[IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,K;
	cin >> N >> K;

	fill(isprime,isprime+IDX_MAX,true);
	isprime[1] = false;

	for(int i=2;i<=sqrt(IDX_MAX-1);i++){
		for(int j=i*i;j<=IDX_MAX-1;j = j+i){
			isprime[j] = false;
		}
	}

	vector<int> ans;

	for(int num=3;num<IDX_MAX-1;num+=2){
		if(isprime[num] && num%K == 1)
			ans.push_back(num);
	}

	for(int i=0;i<N;i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}

/*
21:08 Problem Analysis.
27:10 TC passed.
240512 27:15
*/