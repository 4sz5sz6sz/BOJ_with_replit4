#define IDX_MAX 20
#include<bits/stdc++.h>
using namespace std;

int sub[IDX_MAX];

int solution(string name) {
	int N = name.size();
	int ans;
	string target;

	for(int i=0;i<N;i++)
		target.push_back('A');
	
	for(int i=0;i<N;i++){
		sub[i] = min(name[i] - 'A','Z' - name[i]+1);
	}

	/*
	for(int i=0;i<N;i++){
		cout << "	i:	" << i;
		cout << "	sub[i]:	" << sub[i];
		cout << "\n";
	}
	*/

	int i=1;
	int cnt=sub[0];
	string str = name;
	str[0] = 'A';
	while(str != target){
		str[i] = 'A';
		cnt+=sub[i];
		i++;
		cnt++;
	}
	int ans1 = cnt;

	i=N-1;
	cnt=sub[0];
	str = name;
	str[0] = 'A';
	while(str != target){
		str[i] = 'A';
		cnt+=sub[i];
		i--;
		cnt++;
	}
	int ans2 = cnt;
	
	return min(ans1,ans2);
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << solution("ZZAAAAAAAAZ") << "\n";
	
	return 0;
}


/*
15:16 Problem Analysis.
33:23 TC passed

43:00 "ZZAAAAAAAZ" 에서 반례 발생...
240427 33:29
*/