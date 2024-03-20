#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,K;
	cin >> N >> K;

	vector<int> arr(N+1);
	vector<int> avail(N+1);

	for(int i=1;i<=N;i++){
		cin >> arr[i];
	}

	avail[1] = 1;

	for(int i=1;i<=N;i++){
		if(avail[i]==0) continue;
		for(int j=i+1;j<=i+K;j++){
			if(j>N) break;
			if((j-i)*(1+abs(arr[i]-arr[j])) <= K)
				avail[j] = 1;
		}
	}

	if(avail[N] == 1)
		cout << "YES\n";
	else
		cout << "NO\n";
	
	return 0;
}

/*
07:45 Problem Analysis.
15:23 main() Completed.
15:49 TC passed.
240320 15:54
*/