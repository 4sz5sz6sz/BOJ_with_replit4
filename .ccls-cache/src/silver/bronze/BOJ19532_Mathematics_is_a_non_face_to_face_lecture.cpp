#define X first
#define Y second
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;

	pair<int,int> ans;
	for(int x=-999;x<=999;x++){
		for(int y=-999;y<=999;y++){
			if(a*x + b*y == c)
				if(d*x + e*y == f)
					ans = {x,y};
		}
	}

	cout << ans.X << " " << ans.Y << "\n";
	
	return 0;
}

/*
04:41
240601 
*/