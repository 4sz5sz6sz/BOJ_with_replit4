#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	int money, S;
	cin >> money >> S;
	vector<int> A(N);
	vector<int> price(N);

	for(int i=0;i<N;i++){
		cin >> price[i] >> A[i];
	}

	int ans = 0;
	for(int i=0;i<N;i++){
		if(price[i] <= money){
			if(A[i] > S)
				ans = 1;
		}
	}

	if(ans)
		cout << "YES\n";
	else
		cout << "NO\n";
	
	return 0;
}

/*

230504 04:26
*/