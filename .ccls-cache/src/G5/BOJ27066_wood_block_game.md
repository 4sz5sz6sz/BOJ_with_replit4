나무 블럭 게임 스페셜 저지
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	1024 MB	437	236	200	54.645%
문제
올해도 집에서 쓸쓸히 혼자 새해를 맞이하는 주원이는 제야의 종이 울리기 전까지 심심함을 달랠 무언가를 찾고 있다.

주원이는 근처에 굴러다니는 
$N$개의 나무 블럭을 발견했다. 각 나무 블럭에는 음이 아닌 정수가 한 개씩 적혀있었다. 심심한 주원이는 나무 블럭들을 가지고 혼자서 할 수 있는 간단한 게임을 떠올렸다.

처음에 
$N$개의 나무 블럭은 
$N$개의 주머니에 한 개씩 들어있다. 이때 주원이는 다음 작업을 원하는 만큼 반복할 수 있다.

서로 다른 두 주머니를 고른 다음 둘을 하나로 합친다.
예를 들어, 첫 번째 주머니에 2가 적힌 나무 블럭과 5가 적힌 나무 블럭이, 두 번째 주머니에 3이 적힌 나무 블럭이 들어있다고 하자. 이 두 주머니를 합치면 각각 2, 3, 5가 적힌 나무 블럭 총 세 개가 하나의 주머니에 들어 있게 된다. 따라서 주머니의 총 개수는 하나 줄어든다.

게임의 모든 과정이 끝난 뒤 남아있는 주머니의 개수가 
$K$개라고 할 때, 각각에 대해 들어있는 나무 블럭에 적힌 수의 평균을 구하자. 각 주머니에서 계산한 
$K$개의 평균들을 오름차순으로 나열했을 때 

$\left\lfloor\cfrac{K+1}{2}\right\rfloor$번째에 위치한 값이 주원이의 점수가 된다.

제야의 종이 울리기 전에 주원이가 게임을 마스터할 수 있도록 나무 블럭의 정보가 주어지면 얻을 수 있는 점수의 최댓값을 구해주는 프로그램을 만들어주자.

입력
첫째 줄에 나무 블럭의 개수 
$N$이 주어진다.

둘째 줄에 각 나무 블럭에 적혀있는 정수 
$A_1, A_2, \cdots, A_N$이 공백으로 구분되어 주어진다.

출력
게임에서 얻을 수 있는 가장 큰 점수를 출력한다. 절대/상대 오차는 
$10^{-6}$까지 허용한다.

제한

$1\leq N\leq 100\,000$ 

$0\leq A_i\leq 10\,000$ 
예제 입력 1 
4
2 0 2 2
예제 출력 1 
2
각 주머니에 들어 있는 나무 블럭에 적힌 수들을 중괄호 
$\{\}$ 에 넣어 표시하자.

아무런 작업을 하지 않는다면 주머니는 
$\{2\}, \{0\}, \{2\}, \{2\}$와 같이 되고, 평균은 각각 
$2, 0, 2, 2$가 되기 때문에 
$2$점을 얻는다.

첫 번째와 두 번째 주머니를 합친다면 
$\{2, 0\}, \{2\}, \{2\}$가 되어 평균은 각각 
$1, 2, 2$가 되기 때문에 
$2$점을 얻는다.

이후 첫 번째와 두 번째를 합친 주머니와 세 번째 주머니를 합친다면 
$\{2, 0, 2\}, \{2\}$가 되어, 평균은 각각 

$\frac{4}{3}, 2$가 되기 때문에 

$\frac{4}{3}$점을 얻는다.

예제 입력 2 
2
1 2
예제 출력 2 
1.500000


### Solution

- greedy
- sort

내림차순으로 정렬한다. pop을 O(1)만에 하기 위함.

mid = 

2 -> 2
3 -> 2
4 -> 3
5 -> 3
6 -> 4
7 -> 4번째

4번쨰 -> index : 3

int mid = A.size()/2;

답 :
다 더해서 N로 나눈 경우, 
또는
[mid]에서 [마지막-1]까지 최댓값.


