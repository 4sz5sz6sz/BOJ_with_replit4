#include <string>
#include <vector>

using namespace std;

int N;
int ans = 0;
int target;
vector<int> arr;
int cur;

void DFS(int depth);

int solution(vector<int> numbers, int t) {

	N = numbers.size();
	target = t;
	arr = numbers;

	DFS(0);
	
	return ans;
}

void DFS(int depth){
	if(depth >= N){
		/*base condition*/
		if(cur == target){
			ans++;
		}
		return;
	}

	for(int mode=0;mode<2;mode++){
		if(mode == 0){	//+
			cur+=arr[depth];
			DFS(depth+1);
			cur-=arr[depth];
		}
		else if(mode == 1){	//-
			cur-=arr[depth];
			DFS(depth+1);
			cur+=arr[depth];
		}
	}
	
}

/*
00:59 Problem Analysis.
07:16 Solution() Completed.
240419 08:48
*/