#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<string> arr;
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		arr.push_back(s);
	}

	for(int i=0;i<N;i++){
		string cur = arr[i];

		//조건 1
		int cnt1=0;
		int cnt2=0;
		int cntOfNumber = 0;
		for(char ch:cur){
			if('a' <= ch && ch <= 'z'){
				cnt1++;
			}
			else if('A' <= ch && ch <= 'Z'){
				cnt2++;
			}
			else if('0' <= ch && ch <= '9'){
				cntOfNumber++;
			}
		}
		if(cnt2 > cnt1) continue;

		//조건 2
		if(cur.size() > 10) continue;

		//조건 3
		if(cntOfNumber == cur.size()) continue;
		cout << cur << "\n";
	}
	
	return 0;
}

/*
06:59 TC passed.
240520 07:07
*/