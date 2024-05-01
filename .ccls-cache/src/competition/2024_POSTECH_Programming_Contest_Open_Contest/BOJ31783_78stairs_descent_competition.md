I번 - 78계단 내려가기 대회
시간 제한	메모리 제한
1 초	1024 MB
문제
먼 훗날, 포스텍 캠퍼스에서는 점점 늘어만 가는 신입생들을 모두 수용하기 위한 증축 공사가 계속되었다. 그 결과 캠퍼스의 많은 시설이 전과는 비교도 되지 않을 정도로 큰 규모의 시설로 변모하였다. 특히, 78계단은 공사가 거듭된 결과 $N$개의 칸으로 이루어진 거대한 계단이 되었다. 각 칸은 $1$번부터 $N$번까지의 번호로 구분되며, $i$번 칸의 높이는 $H_i$이다. 계단이기 때문에 각 칸의 높이는 번호에 대해 단조감소한다.

미래의 포스텍 재학생들은 이러한 78계단을 가장 잘 활용할 수 있는 방법을 찾았는데, 78계단 내려가기 대회가 바로 그것이다. 대회의 참가자들은 $1$번 칸에서 시작해 번호가 더 큰 계단으로 내려가는 것을 반복해서 $N$번 칸에 도착해야 한다. 이때 여러 칸을 뛰어넘을 수 있으며, 번호가 더 작은 계단으로 이동할 수는 없다. $1$번 칸을 제외한 모든 칸에는 보물 상자가 $1$개씩 놓여 있으며, $i$번 칸에 놓인 보물 상자의 점수는 $A_i$, 내구도는 $B_i$이다. $i$번 칸에 놓인 보물 상자를 열어 점수를 얻기 위해서는 직전에 있던 칸의 높이가 $H_i+B_i$ 보다 크거나 같아야 한다.

당신의 목표는 가장 많은 점수를 얻어 대회에서 우승하는 것이다. 각 칸에 놓인 보물 상자의 점수와 내구도가 주어질 때, 얻을 수 있는 점수의 최댓값을 구하여라.

입력
첫 번째 줄에 78계단을 이루는 칸의 수 $N$이 주어진다. ($2\le N\le 300\ 000$)

두 번째 줄에 각 칸의 높이를 나타내는 $N$개의 정수 $H_1,H_2,\cdots ,H_N$이 공백으로 구분되어 주어진다. ($0\le H_i\le 10^9;H_i\ge H_{i+1}$)

세 번째 줄에 각 칸에 놓인 보물 상자의 점수를 나타내는 $N-1$개의 정수 $A_2,A_3,\cdots ,A_N$이 공백으로 구분되어 주어진다. ($0\le A_i\le 10^9$)

네 번째 줄에 각 칸에 놓인 보물 상자의 내구도를 나타내는 $N-1$개의 정수 $B_2,B_3,\cdots ,B_N$이 공백으로 구분되어 주어진다. ($0\le B_i\le 10^9$)

출력
얻을 수 있는 점수의 최댓값을 출력한다.

예제 입력 1 
5
10 8 5 3 1
1 2 3 4
1 5 1 8
예제 출력 1 
5
$1$번 예제에서, $1$번 계단 - $3$번 계단 - $4$번 계단 - $5$번 계단의 순서로 내려오면 $5$점의 점수를 얻을 수 있다.

예제 입력 2 
3
5 1 1
5 1
5 0
예제 출력 2 
1
예제 입력 3 
4
4 3 2 1
10 10 10
5 5 5
예제 출력 3 
0

### Solution
- DP
- 이분 탐색
- 세그먼트 트리

무조건 dp인 듯..
N=300,000 이므로, 이분탐색, 세그, 스택, 덱 등등.
세그 쓸만한 각이 나올 것 같다.

칸의 높이는 내림차순 정렬되어 있다.

#### DP
DP[i] : 자기 자신을 무조건 포함한다. 0이 될 수도 있다.
오름차순을 보장하지 않는다.

#### 이분 탐색
mid : 상자를 열 수 있는 가장 낮은 높이의 계단, 이 존재하는 인덱스.
int st = 1;
int en = i-1
성공 조건 : H[mid] >= H[i] + A[i]

계단 순서로 보면,
성공 성공 실패 실패... 로 나열된다.

마지막에, en 값(=mid값)이 우리가 구하고자 하는 값이다.

mid값 구해서 계속 활용하기.
======

#### 세그

1~mid 까지의 dp[i] 중, 구간 쿼리로 최댓값 구하기.
dp[i] = 지난 최댓값 +B[i];
//최댓값이 존재하지 않는다면 실행 x


#### dp[N]이 0일 수도 있으므로,
max(dp[N], dp[1~N-1]의 최댓값) 출력.