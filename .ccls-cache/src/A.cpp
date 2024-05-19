#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;
	int posRobot,posBox, posGoal;
	for(int i=0;i<10;i++){
		char cur = s[i];
		if(cur == '@')
			posRobot = i;
		else if(cur == '#')
			posBox = i;
		else if(cur == '!')
			posGoal = i;
	}

	int ans = -1;
	if((posRobot < posBox && posBox < posGoal) || (posRobot > posBox && posBox > posGoal)){
		ans = abs(posGoal - posRobot)-1;
	}

	cout << ans << "\n";
	
	return 0;
}

/*
06:51
240519 
*/