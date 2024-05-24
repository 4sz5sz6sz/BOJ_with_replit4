#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	int sum = 0;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		sum+=num;
	}

	cout << sum - N +1 ;
	
	return 0;
}

/*
240523 02:05
*/