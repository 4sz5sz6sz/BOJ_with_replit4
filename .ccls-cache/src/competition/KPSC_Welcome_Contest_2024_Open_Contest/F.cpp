#define IDX_MAX 13007
#include<bits/stdc++.h>
using namespace std;

int s[IDX_MAX];
int curPrice=10000;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		int p,x,f;
		cin >> p >> x >> f;
		//판매
		if(f == -1){
			//구매물량 이미 있다면
			if(s[p] > 0){
				curPrice = p;
				s[p] = s[p] - x;
			}
			//없다면
			else{
				s[p] = s[p] - x;
			}
		}
		//구매
		else{
			//판매물량 이미 있다면
			if(s[p] < 0){
				curPrice = p;
				s[p] = s[p] + x;
			}
			//없다면
			else{
				s[p] = s[p] + x;
			}
		}
	}

	cout << curPrice << "\n";
	
	return 0;
}

/*
12:46 Problem Analysis.
25:43 main() Completed.
240512 25:53
*/