D번 - 근로장학생
시간 제한	메모리 제한
1 초	1024 MB
문제
하루는 문장 내에 있는 영어 단어를 찾아 그 뜻을 알려주는 프로그램을 만드는 근로장학생이 되었다.

하지만 하루는 너무 귀찮은 나머지 프로그램을 만들지 않았고, 제작 마감일 $1$일전 당신에게 급하게 프로그램을 만드는 걸 도와달라고 요청했다. 하루를 도와주자.

각 정보는 $(Q_i, A_i)$로 이루어져 있으며, $Q_i$는 영어 단어, $A_i$는 그 단어의 뜻을 의미한다.
프로그램에게 $N$개의 정보와 $M$개의 문장이 주어질 때, 각 문장에 대해 프로그램이 답하는 과정은 다음과 같다.
문장 $S$의 가장 왼쪽에 있는 문자의 위치를 $1$, 가장 오른쪽에 있는 문자의 위치를 $|S|$라고 하자. 이때 $|S|$는 문장 $S$의 길이를 의미한다.
프로그램은 각 문장 $S$의 첫 번째 문자부터, 마지막 문자까지 $S_1,$ $S_2,$ $\cdots,$ $S_{|S|-1},$ $S_{|S|}$의 순서로 읽는다.
문장을 읽는 도중, 만약 위치 $k$에서 위치 $k$, $k+1$, $\cdots$, $k+|Q_i|-1$에 있는 문자를 순서대로 이어 붙였을 때 $Q_i$를 만들 수 있다면 $A_i$로 답해야 하며, $k$에 대해 만들 수 있는 $Q_i$가 여러 개라면, 사전순으로 앞선 $Q_i$부터 $A_i$로 답하면 된다.
한 문장에 대해 답해야 하는 $A_i$는 여러개일 수 있다.
예를 들어, 정보 $(Q_i, A_i)$가 (ABC, X), (A, Y), (CDE, Z)이고 질문이 ABCDE라면 프로그램은 YXZ로 답해야 한다.

입력
첫 번째 줄에 정보의 개수를 나타내는 정수 $N$과 문장의 개수를 나타내는 정수 $M$이 공백으로 구분되어 주어진다. ($1 \leq N \leq 1\ 000$; $1 \leq M \leq 10$)

두 번째 줄부터 $N$개의 줄에 걸쳐 $(Q_i, A_i$)를 나타내는 문자열 $Q_i$와 $A_i$가 공백으로 구분되어 주어진다. ($1 \leq |Q_i|, |A_i| \leq 10$; $i \neq j$이면 $Q_i \neq Q_j$)

그다음 줄부터 $M$개의 줄에 걸쳐 문자열 $S_i$가 주어진다. ($1 \leq |S| \leq 100$)

입력되는 모든 문자열은 영어 대문자로만 이루어져 있고, 공백은 없다.

출력
각 문자열 $S_i$에 대해 당신이 만든 프로그램이 답해야 하는 문자열을 한 줄에 하나씩 출력하라.

만약 프로그램이 답할 수 있는 문자열이 없다면 -1을 대신 출력하라.

예제 입력 1 
3 1
ABC X
A Y
CDE Z
ABCDE
예제 출력 1 
YXZ
예제 입력 2 
3 3
KPSC WELCOME
KOOK HELLOWORLD
KOOKMIN FIGHTING
KPSCWELCOME
CONTEXT
KOOKMINUNIVERSITY
예제 출력 2 
WELCOME
-1
HELLOWORLDFIGHTING

### Solution

O(N^2)로 검색하기.

~~우선, 해싱하기.~~

A[i]을 이용하여 s.find() 하기.
존재한다면, Q[i]를 ans에 push();

ans를 가나다순 정렬.

만약 ans가 1개 이상이라면,
	ans 출력.
else
	-1 출력.