#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int W,H,N,D;
	cin >> W >> H;
	cin >> N >> D;

	int a;
	double p; 
	for(int i=0;i<N;i++)
		cin >> a >> p;
		

	cout << fixed;
	cout.precision(8);
	cout << sqrt(W*W+D*D)*p;
	
	return 0;
}


/*
가로 : w
세로 : d
240309 04:29
*/