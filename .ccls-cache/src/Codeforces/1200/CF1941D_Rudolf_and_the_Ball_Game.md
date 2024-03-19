# D. Rudolf and the Ball Game
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Rudolf and Bernard decided to play a game with their friends. n
 people stand in a circle and start throwing a ball to each other. They are numbered from 1
 to n
 in the clockwise order.

Let's call a transition a movement of the ball from one player to his neighbor. The transition can be made clockwise or counterclockwise.

Let's call the clockwise (counterclockwise) distance from player y1
 to player y2
 the number of transitions clockwise (counterclockwise) that need to be made to move from player y1
 to player y2
. For example, if n=7
 then the clockwise distance from 2
 to 5
 is 3
, and the counterclockwise distance from 2
 to 5
 is 4
.

Initially, the ball is with the player number x
 (players are numbered clockwise). On the i
-th move the person with the ball throws it at a distance of ri
 (1≤ri≤n−1
) clockwise or counterclockwise. For example, if there are 7
 players, and the 2
nd player, after receiving the ball, throws it a distance of 5
, then the ball will be caught by either the 7
th player (throwing clockwise) or the 4
th player (throwing counterclockwise). An illustration of this example is shown below.


The game was interrupted after m
 throws due to unexpected rain. When the rain stopped, the guys gathered again to continue. However, no one could remember who had the ball. As it turned out, Bernard remembered the distances for each of the throws and the direction for some of the throws (clockwise or counterclockwise).

Rudolf asks you to help him and based on the information from Bernard, calculate the numbers of the players who could have the ball after m
 throws.

### Input
The first line of the input contains a single integer t
 (1≤t≤104
) — the number of test cases. Then follow the descriptions of the test cases.

The first line of each test case contains three integers n,m,x
 (2≤n≤1000
, 1≤m≤1000
, 1≤x≤n
) — the number of players, the number of throws made, and the number of the player who threw the ball first, respectively.

The next m
 lines contain information about each throw in order. Each of them contains an integer ri
 (1≤ri≤n−1
) — the distance at which the i
-th throw was made, and a symbol ci
, equal to '0', '1', or '?':

if ci
='0', then the i
-th throw was made clockwise,
if ci
='1', then the i
-th throw was made counterclockwise,
if ci
='?', then Bernard does not remember the direction and the i
-th throw could have been made either clockwise or counterclockwise.
It is guaranteed that the sum n⋅m
 (n
 multiplied by m
) over all test cases does not exceed 2⋅105
.

### Output
For each test case, output two lines.

In the first line, output the number of players k
 (1≤k≤n
) who could have the ball at the end of the game.

In the next line, output k
 numbers bi
 (1≤bi≤n
) — the numbers of the players in increasing order. All numbers must be different.

### Example
### inputCopy
5
6 3 2
2 ?
2 ?
2 ?
12 1 2
3 1
10 7 4
2 ?
9 1
4 ?
7 0
2 0
8 1
5 ?
5 3 1
4 0
4 ?
1 ?
4 1 1
2 ?
### outputCopy
3
2 4 6 
1
11 
4
3 5 7 9 
3
2 3 5 
1
3 
### Note
Below is an illustration of three throws for the first test case. The arrows denote possible throw directions. Players who could have the ball after the throw are highlighted in gray.

### Solution

본대 탐방 1 처럼 풀기?

시작점에서, 다음 지점으로 가능한 곳 1,1,2곳 선발,

for(){	//현재 점 제작하기.

}

if(comm[i]==0 || comm[i]==2){
	for(j){	
		//이전 점에서 현재 점으로 갈 수 있으면, 현재점에 반영.
		next[j] = (cur[j]+r[i])%N;
		if(next[j] == 0) next[j] = N;
	}
}

if(comm[i]==1 || comm[i]==2){
	for(j){	
		//이전 점에서 현재 점으로 갈 수 있으면, 현재점에 반영.
		next[j] = (cur[j]-r[i]+N)%N;
		if(next[j] == 0) next[j] = N;
	}
}

for(j){
	cur[j] = next[j];
}



//next[j]=1;
//cur[j]=next[j];

### 변수
int comm[]; // 명령어
int cur[];	// 현재 점
int next[];	// 다음 점
int r[];	// 몇 칸 던지는지 저장

### 출력
cur[1~N]에서 0 이상인 값만 ans에 저장.
ans 오름차순 정렬.

ans.size() 출력.
ans의 내용을 오름차순으로 출력.


22:00 문제 읽기
34:50 문제 분석



