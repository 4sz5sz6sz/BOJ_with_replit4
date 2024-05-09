#define DATA first 
#define INDEX second 
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Node;
stack<Node> S;

vector<int> solution(vector<int> prices) {
	int N = prices.size();
	vector<int> answer(N);
	vector<Node> A;
	for(int i=0;i<N;i++){
		A.push_back({prices[i],i});
	}

	for(int i=0;i<N;i++){
		Node cur = A[i];
		while(!S.empty() && S.top().DATA > cur.DATA){
			// cout << "   pop()   ";
			// cout << "   S.top().INDEX   " << S.top().INDEX;
			// cout << "   S.top().DATA   " << S.top().DATA;
			// cout << "   cur.INDEX   " << cur.INDEX;
			// cout << "   cur.DATA   " << cur.DATA;
			// cout << "\n";
			Node delNode = S.top(); S.pop();
			int tmp = cur.INDEX - delNode.INDEX;
			answer[delNode.INDEX] = tmp;
		}
		if(S.empty() || S.top().DATA <= cur.DATA){
			S.push(cur);
		}
	}

	while(!S.empty()){
		cout << "   pop()22   ";
		cout << "   S.top().INDEX   " << S.top().INDEX;
		cout << "   S.top().DATA   " << S.top().DATA;
		cout << "   N   " << N;
		//cout << "   cur.INDEX   " << cur.INDEX;
		//cout << "   cur.DATA   " << cur.DATA;
		cout << "\n";
		Node delNode = S.top(); S.pop();
		int tmp = N-1 - delNode.INDEX;
		answer[delNode.INDEX] = tmp;
	}

	return answer;
}

/*
06:18 Problem Analysis.
12:43 solution() Completed.
35:54 push()와 pop() 위치 변경. pop()이 먼저 오도록 변경.
240509 36:09
*/

