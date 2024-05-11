#define IDX_MAX 100007
#include<bits/stdc++.h>
using namespace std;

int N,M;
int A[IDX_MAX];
int DP[2][IDX_MAX];

enum DIR{
	DIR_L,
	DIR_R
};

bool func(int X);
void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for(int i=1;i<=N;i++){
		cin >> A[i];
	}

	int st=0;
	int en=1000000000;
	int mid;
	while(st<=en){
		mid = (st+en)/2;
		bool res = func(mid);
		if(res)
			en = mid-1;
		else
			st = mid+1;
		
		if(res) cout << "True\n";
		else cout << "False\n";
	}

	cout << st << "\n";
	
	return 0;
}

bool func(int X){
	stack<int> S;
	for(int i=1;i<=N;i++){
		int cnt=0;
		int cur = A[i];
		while(!S.empty() && S.top() - X > cur){
			S.pop();
			cnt++;
		}
		S.push(cur);
		DP[DIR_L][i] = DP[DIR_L][i-1] + cnt;
	}

	//S.clear();
	while(!S.empty()) S.pop();

	for(int i=N;i>=1;i--){
		int cnt=0;
		int cur = A[i];
		while(!S.empty() && S.top() - X > cur){
			S.pop();
			cnt++;
		}
		S.push(cur);
		DP[DIR_R][i] = DP[DIR_R][i+1] + cnt;
	}

	for(int i=1;i<=N;i++){
		if(DP[DIR_L][i] + DP[DIR_R][i] <= M)
			return true;
	}

	cout << "	X : " << X << "\n";
	ShowArr();
	return false;	
}

void ShowArr(){
	cout << "***ShowArr()***\n";
	for(int i=1;i<=N;i++){
		cout << A[i] << " ";
	}
	cout << "\n";
	
	for(int k=0;k<2;k++){
		for(int i=1;i<=N;i++){
			cout << DP[k][i] << " ";
		}
		cout << "\n";
	}
}

/*
26:10 Problem Analysis.
31:22 main() Completed.
36:46 func() Completed.
45:38
while(!S.empty() && S.top() + X > cur){
에서
while(!S.empty() && S.top() - X > cur){
로 변경.

53:24. 오큰수가 아니라, LIS로 접근해야 한다..
다시 짜기..

01:22:05 gg
240511 36:53
*/