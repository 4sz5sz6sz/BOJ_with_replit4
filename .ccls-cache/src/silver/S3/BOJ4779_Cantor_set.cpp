#include<bits/stdc++.h>
using namespace std;

void func(int k);
void WriteBlank(int k);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	while(cin >> N){
		func(N);
		cout << "\n";
	}
	
	return 0;
}

void func(int k){
	if(k==0){
		cout << "-";	
		return;
	}

	func(k-1);
	WriteBlank(k-1);
	func(k-1);
}

void WriteBlank(int k){
	int len = pow(3,k);
	for(int i=0;i<len;i++){
		cout << " ";
	}
}

/*
02:47 Problem Analysis.
03:46 main() Completed.
05:30 func() Completed.
06:13 WriteBlank() Completed.
06:46 TC passed.
240813 06:51
*/