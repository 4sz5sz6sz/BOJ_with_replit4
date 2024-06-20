#define IDX_MAX 10000
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> arr(IDX_MAX+1);
	for(int loop=0;loop<N;loop++){
		int l,r;
		cin >> l >> r;
		for(int i=l;i<r;i++){
			arr[i]=1;
		}
	}

	int ans=0;
	for(int i=1;i<=IDX_MAX;i++){
		if(arr[i])
			ans++;
	}

	cout << ans << "\n";
	
	return 0;
}

/*
03:39
240620 
*/