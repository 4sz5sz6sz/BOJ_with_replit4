#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
	string name;
	int a,b,c;

	bool operator<(const Node &temp){
		if(a!=temp.a) return a>temp.a;
		if(b!=temp.b) return b<temp.b;
		if(c!=temp.c) return c>temp.c;
		return name < temp.name;
	}
}Node;

vector<Node> arr;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		string name;
		int a,b,c;
		cin >> name >> a >> b >> c;
		arr.push_back({name,a,b,c});
	}

	sort(arr.begin(),arr.end());

	for(int i=0;i<N;i++){
		cout << arr[i].name << "\n";
	}
	
	return 0;
}

/*
01:16
240627 06:22
*/