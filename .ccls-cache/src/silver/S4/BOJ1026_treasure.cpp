#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> A;
vector<int> B;

void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		A.push_back(num);
	}
	
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		B.push_back(num);
	}

	sort(A.begin(),A.end());
	sort(B.begin(),B.end(),greater<int>());

	int ans = 0;
	for(int i=0;i<N;i++){
		ans += A[i]*B[i];
	}

	//ShowArr();

	cout << ans << "\n";
	
	return 0;
}

void ShowArr(){
	for(int i=0;i<N;i++){
		cout << A[i] << " ";
	}
	cout << "\n";
	for(int i=0;i<N;i++){
		cout << B[i] << " ";
	}
	cout << "\n";
}

/*
04:37 Problem Analysis.
07:38 Wa..
09:55 ShowArr() Completed.
11:51
less는 오름차순이다.. greater<int>() 로 변경.
12:31 TC passed.
240430 12:37
*/