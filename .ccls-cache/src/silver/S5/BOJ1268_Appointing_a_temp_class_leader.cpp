#define IDX_MAX 1001
#include<bits/stdc++.h>
using namespace std;

int arr[IDX_MAX][6];
int isused[IDX_MAX][IDX_MAX];
int result[IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for(int i=1;i<=N;i++){
		for(int j=1;j<=5;j++){
			cin >> arr[i][j];
		}
	}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i==j) continue;
			for(int k=1;k<=5;k++){
				if(arr[i][k] == arr[j][k]){
					isused[i][j] = 1;
					isused[j][i] = 1;
				}
			}
		}
	}

	int ans1=0, ans2=1;

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(isused[i][j])
				result[i]++;
		}
	}

	for(int i=1;i<=N;i++){
		if(result[i] > ans1){
			ans1 = result[i];
			ans2 = i;
		}
	}

	cout << ans2 << "\n";
	
	return 0;
}

/*
15:13 Problem Analysis.
22:42 TC passed.
240607 22:49
*/