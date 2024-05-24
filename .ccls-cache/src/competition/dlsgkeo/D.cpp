#define DATA first
#define INDEX second
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Node;

int N,Q;
vector<int> H;
vector<Node> arr;
vector<int> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		H.push_back(num+i);
	}

	cin >> Q;
	ans.resize(Q);
	for(int i=0;i<Q;i++){
		int num;
		cin >> num;
		arr.push_back({num,i});
	}

	sort(arr.begin(),arr.end(),greater<Node>());

	stack<Node> S;
	for(int i=0;i<Q;i++){
		S.push(arr[i]);
	}

	for(int i=0;i<N;i++){
		int curH = H[i];
		while(!S.empty() && S.top().DATA <= curH){
			ans[S.top().INDEX] = i+1;
			S.pop();
		}
	}

	for(int i=0;i<Q;i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}

/*
06:39 Problem Analysis.
13:05 main() Completed.
16:18 TC passed.
240519 16:24
*/