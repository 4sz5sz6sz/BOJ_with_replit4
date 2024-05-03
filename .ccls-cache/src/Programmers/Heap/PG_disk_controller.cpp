//#define DIST first
//#define POS second
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
	int DIST,POS;
}Node;

vector<Node> A;


bool cmp2(const Node &a, const Node &b);

struct cmp1{
	bool operator()(const Node &a, const Node &b){
		return a.DIST > b.DIST;
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int N = jobs.size();
	for(int i=0;i<N;i++){
		int a = jobs[i][0];
		int b = jobs[i][1];
		A.push_back({b,a});
	}

	sort(A.begin(),A.end(),cmp2);// 헷갈림..
	int idx = 0;
	int lastE=0;
	int sum=0;
	priority_queue<Node,vector<Node>,cmp1> Q;
	while(!Q.empty() ||idx < N){
		// cout << "   idx : " << idx << "\n";
		if(!Q.empty()){
			Node cur = Q.top(); Q.pop();
			lastE = max(lastE, cur.POS);
			lastE += cur.DIST;
			sum += lastE - cur.POS;
			cout << "   cur.POS : " << cur.POS;
			cout << "   cur.DIST : " << cur.DIST;
			cout << "   lastE : " << lastE;
			cout << "   sum : " << sum;
			cout << "\n";
		}
		while(idx < N && lastE>=A[idx].POS){
			Q.push(A[idx++]);
			cout << "push()\n";
		}
		if(Q.empty() && idx < N && lastE<A[idx].POS){    //작업이 더이상 진행되지 않는 경우.
			Q.push(A[idx++]);
			cout << "push() 22\n";
		}
		//cout << "   idx : " << idx << "\n";

	}
	answer=sum/N;

	return answer;
}

bool cmp2(const Node &a, const Node &b){
	if(a.POS != b.POS) return a.POS < b.POS;
	return a.DIST < b.DIST;
}


/*
18:35 Problem Analysis.
30:17 저녁..
재개..

10:25 TC passed.
WA...
20:48 반례 발견. 작업을 아예 하지 않는 구간에서 문제 발생.
lastE = max(lastE, cur.POS); 추가.

42:46
while(idx < N && lastE<=A[idx].POS){
에서
while(idx < N && lastE>=A[idx].POS){
로 변경.

46:20
if(idx < N && lastE<A[idx].POS){    //작업이 더이상 진행되지 않는 경우.
삽입.
정확도 70%로 향상.

47:41
if(Q.empty() && idx < N && lastE<A[idx].POS){
로 변경.
정답입니다!!!

240503 30:17 + 47:33
*/