#define INF 0x7f7f7f7f
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<int> vP;
	vector<int> vM;
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		if(num>=0)
			vP.push_back(num);
		else
			vM.push_back(num);
	}

	sort(vP.begin(),vP.end());
	sort(vM.begin(),vM.end(),greater<int>());

	int ans=INF;
	int ans1, ans2;

	if(vP.size()>= 2 && abs(vP[0] + vP[1]) < ans){
		ans1 = vP[0]; 
		ans2 = vP[1];
		ans = abs(ans1 + ans2);
	}

	if(vM.size()>= 2 && abs(vM[0] + vM[1]) < ans){
		ans1 = vM[1]; 
		ans2 = vM[0];
		ans = abs(ans1 + ans2);
	}
	
	int j=0;
	for(int i=0;i<vP.size();i++){
		for(;j<vM.size();j++){
			if(abs(vP[i] + vM[j]) < ans){
				ans1 = vM[j];
				ans2 = vP[i];
				ans = abs(ans1 + ans2);
			}
			if(vP[i] + vM[j] <= 0) break;
		}
	}

	cout << ans1 << " " << ans2;
	
	return 0;
}

/*
00:43 Problem Analysis.
14:43 main() Completed.
16:01 TC passed.
WA..
28:15 특성값의 오름차순으로 출력하도록 변경.
240807 28:23
*/