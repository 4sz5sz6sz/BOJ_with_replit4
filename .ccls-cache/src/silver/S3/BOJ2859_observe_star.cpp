#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> s;

int GCD(int a, int b);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//(Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday)
	s.push_back("Sunday");
	s.push_back("Monday");
	s.push_back("Tuesday");
	s.push_back("Wednesday");
	s.push_back("Thursday");
	s.push_back("Friday");
	s.push_back("Saturday");

	int curT[2];
	int addT[2];

	for(int i=0;i<2;i++){
		string t;
		cin >> t;
		string s1 = t.substr(0,2);
		string s2 = t.substr(3,2);
		curT[i] = stoi(s1)*60 + stoi(s2);
	}
	
	for(int i=0;i<2;i++){
		string t;
		cin >> t;
		string s1 = t.substr(0,2);
		string s2 = t.substr(3,2);
		addT[i] = stoi(s1)*60 + stoi(s2);
	}
	
	int gcd = GCD(addT[0], addT[1]);
	int sub = abs(curT[0] - curT[1]);

	// cout << "	gcd : " << gcd;
	// cout << "	sub : " << sub;
	// cout << "\n";
	
	if(sub % gcd > 0){
		cout << "Never\n";
		return 0;
	}

	while(curT[0] != curT[1]){
		if(curT[0] < curT[1])
			curT[0] += addT[0];
		else
			curT[1] += addT[1];
	}

	int DD = curT[0] / (60 * 24);
	int MM_total = curT[0] % (60 * 24);
	int week = 6;
	week = (week + DD)%7;
	//cout << week << "\n";

	int HH = MM_total / 60;
	int MM = MM_total % 60;

	cout << s[week] << "\n";
	if(HH < 10) cout << "0";
	cout << HH;
	cout << ":";
	if(MM < 10) cout << "0";
	cout << MM;

	return 0;
}


int GCD(int a, int b){
	return b?GCD(b,a%b):a;
}

/*
09:50 Problem Analysis.
31:30 main() Completed.
32:44 GCD() Completed.
38:50 TC passed.
240426 38:55
*/