B. Binary Path
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a 2×n
 grid filled with zeros and ones. Let the number at the intersection of the i
-th row and the j
-th column be aij
.

There is a grasshopper at the top-left cell (1,1)
 that can only jump one cell right or downwards. It wants to reach the bottom-right cell (2,n)
. Consider the binary string of length n+1
 consisting of numbers written in cells of the path without changing their order.

Your goal is to:

Find the lexicographically smallest†
 string you can attain by choosing any available path;
Find the number of paths that yield this lexicographically smallest string.
†
 If two strings s
 and t
 have the same length, then s
 is lexicographically smaller than t
 if and only if in the first position where s
 and t
 differ, the string s
 has a smaller element than the corresponding element in t
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (2≤n≤2⋅105
).

The second line of each test case contains a binary string a11a12…a1n
 (a1i
 is either 0
 or 1
).

The third line of each test case contains a binary string a21a22…a2n
 (a2i
 is either 0
 or 1
).

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output two lines:

The lexicographically smallest string you can attain by choosing any available path;
The number of paths that yield this string.
Example
inputCopy
3
2
00
00
4
1101
1100
8
00100111
11101101
outputCopy
000
2
11000
1
001001101
4
Note
In the first test case, the lexicographically smallest string is 000
. There are two paths that yield this string:


In the second test case, the lexicographically smallest string is 11000
. There is only one path that yields this string:



### Solution
11:09 문제 읽기

int A[][];
int dp[][];
Node hist[][];
typedef pair<int,int> Node;


A[][]와 dp[][]는 1-indexed이다.
A[0][] A[][0]은 전부 INF으로 초기화해준다.
dp[0][] dp[][0]은 전부 0으로 초기화해준다.

현재 구하고자 하는 A[x][y]가 마지막 문자일 때,

if(A[x-1][y] <= A[x][y-1])이면,
	dp[x][y]+=dp[x-1][y];
	hist[x][y] = {x-1,y};

if(A[x-1][y] >= A[x][y-1])이면,
	dp[x][y]+=dp[x][y-1];
	hist[x][y] = {x,y-1};


//dp[x-1][y] <= dp[x][y-1]

### 경로 복원
경로복원은 hist[][]를 이용해준다.	prev index가 포함되어있다.

hist[2][N]부터 탐색을 시작한다.


Node cur = {2,N};
while(!(cur.X == 1 && cur.Y == 1)){
	ans.push_back(cur);
	cur = hist[cur.X][cur.Y];
}
ans.push_back({1,1});

ans 역순 출력.

### 출력
ans 역순 출력.
dp[2][N] 출력.


반례 발견
1
10
0110110010
1100110100

01101100100
41