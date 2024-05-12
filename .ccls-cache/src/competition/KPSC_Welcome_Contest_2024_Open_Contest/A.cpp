#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<int> A;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		A.push_back(num);
	}

	int ans=0;

	cin >> M;

	for(int i=0;i<M;i++){
		int num;
		cin >> num;
		ans += A[num-1];
	}

	cout << ans << "\n";

	return 0;
}

/*
02:00
240502  04:41
*/