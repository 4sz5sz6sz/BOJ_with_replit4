#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int M;
	cin >> M;
	cout<<fixed;
	cout.precision(1);
	if(M <= 30){
		cout << M/2.0 << "\n";
	}
	else{
		cout << (M-30.0)/2.0*3+15<<"\n";
	}
	
	return 0;
}

/*
08:02
240310 
*/