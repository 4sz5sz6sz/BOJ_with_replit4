src에다가 다 쓴 파일 저장하기.
하나의 프로젝트에는 하나의 main()만 존재한다.
그러므로, 숨김파일 기능을 이용하여 컴파일 대상에서 제외시킨다.
~~컴파일을 회피시킨다.~~



=============


from sklearn.linear_model import SGDClassifier
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
import numpy as np
import matplotlib.pyplot as plt

cancer = load_breast_cancer()
x = cancer.data
y = cancer.target

x_train, x_test, y_train, y_test = train_test_split(x, y, stratify = y, test_size = 0.2, random_state = 42)
sgd = SGDClassifier(loss = 'log', max_iter = 100, tol = 1e-3, random_state = 42)

sgd.fit(x, y)
sgd.score(x, y)

#사이킷런의 경사 하강법이 구현된 클래스 : SGDClassifier

validation
교차 세트
검증 세트

https://ittrue.tistory.com/42
파라미터와 하이퍼파라미터의 차이

서로 다른 스케일이 있을 때,
스케일 범위가 많이 다른 경우, 표준화(standardization)를 통해  스케일을 맞춰준다.

133p 까지 봄.


==============
카잉 달력??

=====


int 형 
	12! 
	F_46
long long 형 
	20! 
	F_92
	
BOJ29754 버추얼 유튜버 S1

### vi 단축키
%s/abc/aaa/g
에서, abc가 아니라 week/7 같은 특수문자 처리?

Vim에서 VSCode와 같은 멀티커서 기능을 쓰고싶습니다.
https://okky.kr/questions/968581


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

Bo

### alt code
178 ²
179 ³
183 ·
186 º
41446 →
41448 ↑
41449 ↓