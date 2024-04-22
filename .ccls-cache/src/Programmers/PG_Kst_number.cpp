#include <algorithm>
#include <string>
#include <vector>

using namespace std;
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	int st,en,k;
	int N = commands.size();
	vector<int> ret;
	for(int i=0;i<N;i++){
		st = commands[i][0]-1;
		en = commands[i][2]-1;
		k = commands[i][2]-1;

		vector<int> arr2 = array;
		sort(arr2.begin()+st,arr2.begin()+en+1);
		ret.push_back(arr2[st+k]);
	}

	//vector<int> answer;
	return ret;
}

/*
240420 05:59 
*/