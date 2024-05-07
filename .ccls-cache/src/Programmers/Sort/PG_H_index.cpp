#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	vector<int> A = citations;
	int N = A.size();
	sort(A.begin(),A.end(),greater<int>());

	for(int i=0;i<N;i++){
		int curSize = i+1;
		cout << "A[i] : "<< A[i];
		cout << "\n";
		if(A[i] >= curSize){
			answer = max(curSize,answer);
		}
	}
	return answer;
}
/*
14:01 main() Completed.
15:11 TC passed.
Wa..
17:11 answer를 최댓값으로 계속 갱신.
19:32 식 변경. 
curSize >= A[i]
에서
A[i] >= curSize
로 수정..

answer = max(A[i],answer);
에서
answer = max(curSize,answer);
로 수정.

240507 20:08
*/