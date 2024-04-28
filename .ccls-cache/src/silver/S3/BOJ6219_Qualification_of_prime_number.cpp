#define IDX_MAX 4000001
#include<bits/stdc++.h>
using namespace std;

vector<int> isprime(IDX_MAX,1);
int cnt;
int A,B;
string target;

void Eratosthenes();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	isprime[0] = 0;
	isprime[1] = 0;
	cin >> A >> B >> target;

	Eratosthenes();
	for(int i=A;i<=B;i++){
		if(isprime[i]){
			string s = to_string(i);
			if((int) s.find(target) < 0) continue;
			// cout << "	s.find(target):" << s.find(target);
			// cout << "	s:	" << s << "\n";
			cnt++;
		}
	}

	cout << cnt << "\n";
	
	return 0;
}

void Eratosthenes(){
	for(int i=2;i<=sqrt(B);i++){
		for(int j=i*i;j<=B;j = j + i){
			isprime[j] = 0;
		}
	}
}

/*
03:42 Problem Analysis.
07:26 main() Completed.
09:00 Eratosthenes() Completed.

2 출력..
int target;
에서
string target;
로 변경.

14:44
s.find()의 리턴값이, -1인데, 1844경으로 출력되는 현상 발생..
int형으로 형 변환.

TC passed.

240427 16:16
*/
