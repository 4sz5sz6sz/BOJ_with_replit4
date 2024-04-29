#include<bits/stdc++.h>
using namespace std;

int isused[3];	//l,k,p

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int flag=1;
	vector<string> arr;
	for(int i=0;i<3;i++){
		string s;
		cin >> s;
		arr.push_back(s);
		if(s[0] == 'l') isused[0]=1;
		if(s[0] == 'k') isused[1]=1;
		if(s[0] == 'p') isused[2]=1;
	}

	for(int i=0;i<3;i++){
		if(isused[i] == 0) flag = 0;
	}
	
	if(flag)
		cout << "GLOBAL";
	else
		cout << "PONIX";
	
	return 0;
}

/*
A
03:42
240428 
*/