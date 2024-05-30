#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a,b,c;
	cin >> a >> b >> c;
	if(a+b+c == 180){
		if(a == b && b == c){
			cout << "Equilateral\n";
		}
		else if(a==b || b==c || c==a){
			cout << "Isosceles\n";
		}
		else{
			cout << "Scalene\n";
		}
	}
	else{
		cout << "Error\n";
	}
	
	return 0;
}

/*
00:33
240530 02:56
*/