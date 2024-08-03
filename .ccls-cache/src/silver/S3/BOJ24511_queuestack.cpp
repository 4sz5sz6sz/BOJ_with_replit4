#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	queue<int> Q;
	stack<int> S;
	int N;
	int cnt=0;
	cin >> N;
	vector<int> arr(N);
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		if(num==0) cnt++;
		else arr[i]=1;
	}

	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		if(arr[i]==1) continue;
		S.push(num);
	}

	while(!S.empty()){
		Q.push(S.top());
		S.pop();
	}

	int M;
	cin >> M;
	for(int i=0;i<M;i++){
		int num;
		cin >> num;
		Q.push(num);
		cout << Q.front() << " ";
		Q.pop();
	}
	
	return 0;
}

/*
03:36 Problem Analysis.
12:45 TC passed.
240803 12:48
*/