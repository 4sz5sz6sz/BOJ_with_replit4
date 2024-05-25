#include <bits/stdc++.h>
using namespace std;

int N,M,K;
vector<int> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	priority_queue<int,vector<int>> Q;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		Q.push(num);
	}

	int prev = 0;
	while(!Q.empty() && Q.top()>K){
		int cur = Q.top(); Q.pop();
		ans.push_back(cur+prev/2);
		Q.push(cur-M);
		prev = cur+prev/2;
	}

	cout << ans.size() << "\n";
	for(int cur:ans)
		cout << cur << "\n";

	return 0;
}

/*
01:07 Problem Analysis.
06:35 main() Completed.
240518 07:45
*/