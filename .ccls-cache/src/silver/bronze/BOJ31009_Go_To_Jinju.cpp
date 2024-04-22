#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//unordered_map <string,int>m;
	int N;
	cin >> N;
	int price;
	int idx;

	vector<int> arr;
	
	for(int i=0;i<N;i++){
		string s;
		int num;
		cin >> s >> num;
		//m[s] = num;
		arr.push_back(num);
		if(s=="jinju"){
			price = num;
			idx = i;
		}
	}

	int cnt=0;
	for(int i=0;i<N;i++){
		if(i==idx) continue;
		if(arr[i] > price) cnt++;
	}

	cout << price << "\n";
	cout << cnt << "\n";
	
	return 0;
}

/*
240421 04:22
*/