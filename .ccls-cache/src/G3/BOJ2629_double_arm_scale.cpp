#define ADD_NUM 50000	
//음수와 양수의 경계
#define IDX_MAX 100000
#define N_MAX 30
#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
bool DP[N_MAX+7][IDX_MAX+7];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	arr.resize(N+1);
	for(int i=1;i<=N;i++){
		cin >> arr[i];
	}

	DP[1][ADD_NUM+arr[1]] = true;
	DP[1][ADD_NUM+0] = true;
	DP[1][ADD_NUM-arr[1]] = true;
	
	for(int i=2;i<=N;i++){
		for(int w=1;w<=IDX_MAX;w++){
			int curW = arr[i];
			if(DP[i-1][w]){
				DP[i][w+curW] = true;
				DP[i][w] = true;
				DP[i][w-curW] = true;
			}
		}
	}
	
	int Q;
	cin >> Q;
	for(int i=1;i<=Q;i++){
		int input;
		cin >> input;
		if(DP[N][ADD_NUM+input])
			cout << "Y ";
		else
			cout << "N ";
	}
	
	return 0;
}

/*
37:24 Problem Analysis.
50:30 main() Completed.
50:46 TC passed.
240829 50:49
*/