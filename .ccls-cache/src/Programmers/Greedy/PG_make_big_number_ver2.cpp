#include<bits/stdc++.h>
using namespace std;

string solution(string arr, int k) {

	int N = arr.size();
	stack<int> S;
	int cnt=0;

	//arr[i] < arr[i+1]이면 arr[i]가 삭제되어야 한다.
	for(int i=0;i<N;i++){
		while(!S.empty() && S.top() < arr[i]-'0'){
			if(cnt >= k) break;
			S.pop();
			cnt++;
		}
		S.push(arr[i]-'0');
	}

	string ret;
	while(!S.empty()){
		//cout << S.top() << "\n";
		ret.push_back(to_string(S.top())[0]);
		S.pop();
	}

	reverse(ret.begin(),ret.end());
	// cout << ret << "\n";

	return ret.substr(0,ret.size()-(k-cnt));
	//return ret;
}


int main(){
	cout << solution("99988",3);
}


/*
02:56 Problem Analysis.
04:59 solution() Completed.

28:02 다시 짬. 유니온 파인드.
38:05 main() Completed.
45:08 UF 3개 구현 완료.
47:01 TC passed.
WA..
49:39
while(j-1>0 && cnt < k){
에서
while(find(j-1)>0 && cnt < k){
로 수정.

반례. 6555555555....55555555555554면 시간초과 확정.

59:41 스택으로 풀기??? 최솟값을 찾아야된다는 목표를 세움. 덱으로 최솟값 찾는 P5 문제 떠오름. 그러나, 구간제한이 없으므로, front_pop()이 없어도 된다. 그래서 stack을 떠올림.

01:05:56 다시 stack으로 품.
01:14:25 TC passed.
딱 하나만 WA..
01:17:37
ret.substr(k-cnt); 추가.

240427 01:22:47
*/