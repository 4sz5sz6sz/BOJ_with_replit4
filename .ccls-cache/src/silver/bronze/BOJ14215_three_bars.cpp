#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int arr[3];
	for(int i=0;i<3;i++)
		cin >> arr[i];

	sort(arr,arr+3);
	if(arr[2] >= arr[0] + arr[1])
		arr[2] = arr[0] + arr[1]-1;
	int sum=0;
	for(int i=0;i<3;i++)
		sum+=arr[i];

	cout << sum << "\n";
	
	return 0;
}

/*
03:38 
240531
*/