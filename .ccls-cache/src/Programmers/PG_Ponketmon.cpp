#define IDX_MAX 200000
#include <vector>
using namespace std;

int solution(vector<int> nums)
{
	int N = nums.size();
	vector<int> cnt(IDX_MAX+1);
	for(int i=0;i<N;i++){
		cnt[nums[i]]++;
	}

	int ans = 0;
	for(int i=1;i<=IDX_MAX;i++){
		if(cnt[i]>0) ans++;
	}

	if(ans>N/2) ans = N/2;
	
	return ans;
}

/*
240419 10:00
*/