#define PI 3.141592653589
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	double a,b,h;
	cin >> a >> b >> h;

	if(a==b){
		cout << -1;
		return 0;
	}

	if(a>b) swap(a,b);

	//ans2 : 반지름의 제곱, 이미 제곱된 값임에 유념할 것
	double ans2 = b*b + (h*b/(b-a))*(h*b/(b-a));
	double ans1 = a*a + (h*a/(b-a))*(h*a/(b-a));

	cout << fixed;
	cout.precision(8);

	cout << PI*(ans2 - ans1) << "\n";
	
	return 0;
}

/*
09:05 문제 분석
25:18 문제 재분석, 수기
29:29 테스트 케이스 통과
240309 29:37
*/