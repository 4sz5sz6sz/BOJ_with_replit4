#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//vector<int> arr;
	int sum = 0;
	for(int i=0;i<5;i++){
		int num;
		cin >> num;
		if(num <= 40)
			num = 40;
		sum+=num;
	}
	cout << sum/5;
	
	return 0;
}

/*
01:59
240624
*/