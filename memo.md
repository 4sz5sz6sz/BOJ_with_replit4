dsrc에다가 다 쓴 파일 저장하기.
하나의 프로젝트에는 하나의 main()만 존재한다.
그러므로, 숨김파일 기능을 이용하여 컴파일 대상에서 제외시킨다.
~~컴파일을 회피시킨다.~~

#기회비용
뜻,
ex) 대학 진학, 취업 2000만원 포기

의사결정를 할 때 반드시 고려해야하는 대상.
어떻게?

편익 > 비용 -> O
편익 < 비용 -> X
-> 합리적인 선택

※기회비용은 암묵적인 비용만 뜻하는 것이 아니다.
암묵적 비용 + 명목적 비용(회계적 비용)을 합한 비용이 기회비용이다.

6:25

#매몰 비용



int 형 
	12! 
	F_46
long long 형 
	20! 
	F_92
	


### 프린트하기
백준(BOJ) 11505 구간 곱 구하기 C++ 풀이
https://jinho9610.tistory.com/24

https://github.com/encrypted-def/BOJ/blob/master/11689.cpp

https://www.acmicpc.net/problem/11689

https://www.acmicpc.net/problem/1786


https://physicsmathcoumputer.tistory.com/35
게임이론, 돌게임

**영어 문제 프린트하기**



replit 단축키 모음
https://docs.replit.com/programming-ide/keyboard-shortcuts


### 구간 곱 구하기 - 펜윅 트리 ver.
구간 곱은 펜웩트리에서, 조금의 스킬이 더해져야 한다. 그대로는 활용할 수 없다.
0에 대한 예외처리가 추가되어야 한다.

### 펜윅 트리를 사용하는 조건
구간 합, 구간 곱(0에 대한 예외처리)
1. 구간 업데이트(Range Update), 점 쿼리(Point Query)	//A[i]과 B[i]를 통해 응용.
2. 점 업데이트(Point Update), 구간 쿼리(Range Query)	//대표적인 유형
https://everenew.tistory.com/114

### Lazy propagation
백준은 '나중에 업데이트하기'로 번역함.
'게으른 전파', 여기서 전파는 '전파하다' 할 때의 그 전파다.

### 세그먼트 트리
https://t1.daumcdn.net/cfile/tistory/99E0F54A5BEB884F36
//33p 잘못된 듯. seg[idx] += diff;를 if문 밖으로 빼내야 하지 않을까?
//바킹독 ver이 가장 좋은 예제인 듯.

https://www.acmicpc.net/blog/view/26
백준의 세그먼트 트리 강의

- add()
if(en < l || r < st) return 0;	//현재 노드의 범위가, 쿼리의 범위를 완전히 벗어난 경우. 더 이상 들어가지 않는다.
if(l <= st && en <= r) return seg[idx];	//현재 노드의 범위가, 쿼리의 범위에 완전히 포함되는 경우. 현재 노드의 값을 저장한다. 더 이상 들어가지 않는다.
return sum(idx*2, st, (st+en)/2, l, r) + sum(idx*2+1, (st+en)/2+1, en, l, r);	//현재 노드의 범위가, 쿼리의 범위에 일부 겹치는 경우.
//왼쪽 자식과 오른쪽 자식 모두로 들어간다.

- update()
값을 변경하고 왼쪽 or 오른쪽으로 이동.
st==en이면 더 이상 내려가지 않기.



