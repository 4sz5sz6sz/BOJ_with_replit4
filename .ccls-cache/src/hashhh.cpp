#define X first
#define Y second
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	unordered_map<long long,int> m;
	pair<long long,long long> a = {2,2};

	m[(a.X<<32)+(a.Y)] = 77;
	cout << m[(a.X<<32)+(a.Y)];
	
	return 0;
}