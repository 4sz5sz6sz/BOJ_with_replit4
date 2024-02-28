# 새로운 문자열 만들기
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초 (추가 시간 없음)	1024 MB	319	169	130	57.269%
### 문제
$T$개의 줄마다 영어 대문자로만 이루어진 문자열 $S$가 주어질 때, 각 줄마다 아래 조건을 모두 만족하는 문자열 $X$를 출력하여라.

$X$는 $S$로 시작하여야 한다.
$X$를 뒤에서부터 읽은 문자열 $X'$에 대해서도 $S$로 시작하여야 한다.
위 조건을 만족하는 문자열이 여러 가지라면, 가장 길이가 짧은 문자열이 $X$가 된다.
가능한 모든 $S$에 대해서 조건을 만족하는 $X$는 유일함을 증명할 수 있다.

### 입력
첫 번째 줄에 주어지는 문자열의 개수 $T$가 주어진다. ($1 \le T \le 100$)

두 번째 줄부터 $T$개의 줄에 걸쳐 문자열 $S$가 주어진다. 각 줄마다 주어지는 문자열 $S$의 길이는 $1$이상 $20$이하이다.

### 출력
$T$개의 줄에 걸쳐 주어진 문자열 $S$마다 조건을 모두 만족하는 문자열 $X$를 출력한다.


### 예제 입력 1 
```
3
KITPA
BANANA
ROTATOR
```
### 예제 출력 1 
```
KITPAPTIK
BANANAB
ROTATOR
```
### 힌트
첫 번째 예제의 정답인 KITPAPTIK는 KITPA로 시작하고, 뒤에서부터 읽은 문자열 KITPAPTIK도 KITPA로 시작한다.

두 번째 예제에 대해서, BANANANAB도 앞의 조건 두 개를 만족하지만, 더 짧은 문자열 BANANAB도 조건을 만족하므로, 가장 짧은 문자열인 BANANAB가 정답이 된다.

### 풀이
- 문자열
- 팰린드롬



뒤에서부터 팰린드롬 검사해보기.

#BANANA

A
ANA
ANANA


#KITPA

A

#ROTATOR
R
ROTATOR


홀수 팰린드롬 or 짝수 팰린드롬 구분하기.

홀수개만 탐색
BBBCCACC
C
CCACC


짝수개만 탐색
BBBCCAACC

CC
CCAACC

//홀수개만 탐색
for(int i=s.size()-1;i>=0;i--){
	int l = i;
	int r = i;
	while(s[l]==s[r]){
		l--; r++;
		if(l<0) break;
		if(r>=s.size()) break;
	}
	curPos = l+1;
	curLen = (r-1) - (l+1) + 1;

	//min()
	//isodd = true;

}

//짝수개만 탐색
for(int i=s.size()-1;i>=0;i--){
	int l = i-1;
	int r = i;
	while(s[l]==s[r]){
		l--; r++;
		if(l<0) break;
		if(r>=s.size()) break;
	}
	curPos = l+1;
	curLen = (r-1) - (l+1) + 1;

	//min()
	//isodd = false;

}



s[0~s.size()-1] 출력, s[l~0] 출력, 