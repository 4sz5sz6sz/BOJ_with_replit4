#define DATA first
#define INDEX second
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Node;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	deque<Node> Q;
	int N;
	cin >> N;
	for(int i=1;i<=N;i++){
		int num;
		cin >> num;
		Q.push_back({num,i});
	}

	// int add = Q.front().DATA;
	// int ans = Q.front().INDEX;
	// cout << ans << " ";
	// Q.pop_front();
	

	while(!Q.empty()){
		int add = Q.front().DATA;
		int ans = Q.front().INDEX;
		cout << ans << " ";
		Q.pop_front();
		for(int i=0;i<abs(add);i++){
			Node cur;
			if(add>0){
				if(i==abs(add)-1) continue;	//한번 덜하기
				cur = Q.front();
				Q.push_back(cur);
				Q.pop_front();
			}
			else{
				cur = Q.back();
				Q.push_front(cur);
				Q.pop_back();
			}
		}
		// if(add<0){//한번 더
		// 	cur = Q.back();
		// 	Q.push_front(cur);
		// 	Q.pop_back();
		// }
		
		// int add = Q.front().DATA;
		// int ans = Q.front().INDEX;
		// cout << ans << " ";
		// Q.pop_front();
	}
	
	return 0;
}

/*
05:43 Problem Analysis.
01:03:58 TC passed.
240802 01:04:04
*/