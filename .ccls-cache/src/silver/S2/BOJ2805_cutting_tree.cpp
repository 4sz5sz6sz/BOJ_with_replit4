#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	cin >> N >> M;
	vector<ll> A(N+1);
	vector<ll> S(N+1);

	for(int i=1;i<=N;i++){
		cin >> A[i];
	}
	
	sort(A.begin(),A.end());

	//Prefix Sum
	for(int i=1;i<=N;i++){
		S[i] = S[i-1] + A[i];
	}

	//Height
	ll st=0;
	ll en=A[N];

	while(st<=en){
		ll mid = (st+en)/2;
		ll curH = mid;
		
		//Index
		int l = 1;
		int r = N;

		while(l<=r){
			int m = (l+r)/2;

			// cout << "	l :" << l;
			// cout << "	r :" << r;
			// cout << "	m :" << m;
			// cout << "	A[m] :" << A[m];
			// cout << "\n";
			if(A[m] >= curH)	//성공
				r = m-1;
			else	//실패
				l = m+1;
		}
		//startIdx : curH보다 같거나 큰 나무가 시작하는 Index.
		//l이 우리가 구하는 startIdx
		
		int startIdx = l;

		ll totalT = S[N] - S[startIdx-1];
		ll cutT = (N-startIdx+1) * curH;

		ll retT = totalT - cutT;
		
		// cout << "	st :" << st;
		// cout << "	en :" << en;
		// cout << "	mid :" << mid;
		// cout << "	l :" << l;
		// cout << "	r :" << r;
		// cout << "	startIdx :" << startIdx;
		// cout << "	totalT :" << totalT;
		// cout << "	cutT :" << cutT;
		// cout << "	retT :" << retT;
		//cout << "	m :" << m;
		//cout << "\n";
		
		if(retT >= M)	//성공
			st = curH+1;
		else	//실패
			en = curH-1;

	}

	cout << en << "\n";
	
	return 0;
}

/*
14:11 Problem Analysis.
32:03 main() Completed.
42:02 l과 r 값이 이상함..
49:30 retT 값이 이상함.

01:08:02
값 추적 결과, cutT가 이상함..
ll cutT = (N-startIdx-1) * curH;
에서
ll cutT = (N-startIdx+1) * curH;
로 수정..

01:09:02 TC passed.

성공이면, l을 변경해야할 지, r을 변경해야 할 지 고민했어야 함.
결국, 각각 달랐음.

index를 굳이 1부터 시작하게 만들었어야 하는 생각이 들기도 함.

cutT를 수정하는 과정에서, N과 startIdx에 구체적인 값을 넣어서 떠올려보니, 잘못된 식이라는 사실을 깨달음.
따라서 (N-startIdx-1) 에서 (N-startIdx+1) 로 수정.

240419 01:09:14
*/