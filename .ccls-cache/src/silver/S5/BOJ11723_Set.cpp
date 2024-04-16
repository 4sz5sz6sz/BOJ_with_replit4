#define IDX_MAX 21
#include<bits/stdc++.h>
using namespace std;

int arr[IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	while(N--){
		string comm;
		int num;
		cin >> comm;
		if(comm == "add"){
			cin >> num;
			arr[num]=1;
		}
		else if(comm == "remove"){
			cin >> num;
			arr[num]=0;
		}
		else if(comm == "check"){
			cin >> num;
			if(arr[num])
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if(comm == "toggle"){
			cin >> num;
			if(arr[num])
				arr[num] = 0;
			else
				arr[num] = 1;
		}
		else if(comm == "all"){
			for(int i=0;i<IDX_MAX;i++){
				arr[i] = 1;
			}
		}
		else{
			for(int i=0;i<IDX_MAX;i++){
				arr[i] = 0;
			}
		}
	}
	
	return 0;
}

/*
05:00 main() Completed.
05:26 TC passed.
240414 05:32
*/