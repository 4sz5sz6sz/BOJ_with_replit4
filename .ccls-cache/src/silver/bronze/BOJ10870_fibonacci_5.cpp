#include<bits/stdc++.h>
using namespace std;

int arr[50];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	arr[1] = 1;
	for(int i=2;i<=N;i++){
		arr[i] = arr[i-1] + arr[i-2];
	}

	cout << arr[N] << "\n";
	
	return 0;
}

/*
240613 01:33
*/