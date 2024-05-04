#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	int ans=0;
	cin >> N;
	vector<int> A(N);
	for(int i=0;i<N;i++)
		cin >> A[i];

	sort(A.begin(),A.end(),greater<int>());

	int last = A[0];
	ans++;
	for(int i=0;i<N;i++){
		int cur = A[i];
		if(cur*2 > last) continue;
		ans++;
		last=cur;
	}

	cout << ans << "\n";
	
	return 0;
}

/*
05:47
09:58 TC passed
240504 10:01
*/