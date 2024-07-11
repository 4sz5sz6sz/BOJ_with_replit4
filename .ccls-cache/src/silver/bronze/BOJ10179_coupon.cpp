#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	cout << fixed;
	cout.precision(2);
	while(N--){
		double num;
		cin >> num;
		cout << "$";
		cout << num*0.8 << "\n";
	}
	
	return 0;
}

/*
240711 02:16
*/