#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N,p;
	cin >> N >> p;
	vector<int>A(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}

	//int ans = 1;	//1 : YES, 0 : NO.
	//vector<int> B = A;
	//sort(B.begin(), B.end());
	
	for(int i=1;i<N;i++){ 	//오름차순 조건 검사. 인접한 수의 차가 1 이하.
		if(A[i] >= A[i-1] && A[i] - A[i-1] <= 1) continue;
		cout << "NO\n";
		// cout << "NO22\n";
		return 0;
	}

	//최솟값 조건 검사.
	for(int i=0;i<N;i++){
		int _min = i/p+1;
		if(A[i] >= _min) continue;
		cout << "NO\n";
		// cout << "NO22\n";
		return 0;
	}

	//최댓값 조건 검사.
	int _max = ceil((long double)N/p);
	//cout << ceil((long double)100000/99999) << "\n";
	for(int i=0;i<N;i++){
		if(A[i] <= min(_max,i+1)) continue;
		cout << "NO\n";
		// cout << "NO33\n";
		return 0;
	}

	cout << "YES\n";
	return 0;
}

/*
01:07:37 Problem Analysis.
재개
09:24 최댓값, 최솟값, 오름차순 조건 작성 완료.
14:50 main() Completed.
19:23 TC passed.
WA..
37:06 반례 발견. 최댓값 조건 오류.
4 2 2 2 2 2 -> YES
if(A[i] <= _max) continue;
에서
if(A[i] <= min(_max,i+1)) continue;
로 변경.

45:46
반례 발견. 오름차순 조건 오류.
5 2 1 1 3 3 3 -> YES

47:10 TC passed.

240505 01:07:37 + 47:10
*/