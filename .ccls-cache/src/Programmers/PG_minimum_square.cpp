#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) {
	int N = arr.size();
	int ans1=0, ans2=0;
	for(int i=0;i<N;i++){
		if(arr[i][0] < arr[i][1]) swap(arr[i][0], arr[i][1]);
		ans1 = max(ans1, arr[i][0]);
		ans2 = max(ans2, arr[i][1]);
	}

	int ret = ans1 * ans2;
	return ret;
}

/*
04:31 WA..
240420 05:16
*/