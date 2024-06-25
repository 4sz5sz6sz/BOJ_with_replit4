#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	int a,b;
	cin >> N;
	a = N/5;
	b = N%5;

	for(int i=0;i<a;i++)
		cout << "V";
	for(int i=0;i<b;i++)
		cout << "I";
	
	return 0;
}

/*
240625 01:40
*/