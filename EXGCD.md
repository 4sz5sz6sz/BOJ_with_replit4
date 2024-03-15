nCr = n!/(n-r)!/r!

n!%MOD /
작은 수 / 큰 수인 경우?

(a*b*c)%MOD

6! / 3! / 3!

원래 숫자에서, (나누는 수와 몫을 곱한 값)을 뺀다.

#### 시그마
BOJ 13172 Σ
https://www.acmicpc.net/problem/13172
모듈러 곱셈의 역원에 대한 개념 등장.

이해안되는 개념이 많음..

====



#### 필요한 내용



https://seastar105.tistory.com/64
베주 항등식(Bezout's Identity)
확장 유클리드 알고리즘(Extended Euclid Algorithm)

https://seastar105.tistory.com/65
모듈러 역원 설명(Modular Inverse)



https://velog.io/@kasterra/큰-수의-이항-계수-mod-K-구하는-방법

https://oberon.tistory.com/103
페르마의 소정리

https://rkm0959.tistory.com/category/PS/PS%20정수론%20가이드
rkm 블로그.


https://thfist-1071.tistory.com/251

https://velog.io/@yoon_0/알고리즘-유클리드-호제법-확장-유클리드-호제법

====

https://www.youtube.com/watch?v=5Q5yxFGtfhE
정수론 1강: 암호 이론 (한글 자막)[쑤튜브]

#시저 암호
평문 -> 암호문
HELLO -> KHOOR
key : 3
키(key)는 암호를 해독하기 위한 열쇠이다.

공개키 암호
키가 공개, 암호화 속도가 느림. 공개되어도 안 뚫림.

대칭키 암호
키를 비밀로 함.

#합동식 기호
x + key = y 
y % 26

40 ≡ 14 (mod 26)
≡ : (합동식 기호)

40과 14는 26을 법으로 하는 합동이다.


#
키를 무작위로 뒤섞기.
key의 경우의 수가 26!-1개로 증가.

->언어의 통계적 특성에 의해 파훼.
	-> 2글자를 2글자로 바꾸기.
	-> 통계적인 특성이, 완만한 그래프로 바뀜.

- 치환 후 순서 섞기, 치환 후 순서 섞기
2000년대 초까지 쓰인 DES 암호 체계는 16번 반복.

https://www.youtube.com/watch?v=Obs-HC5j5bI
정수론 2 강: 유클리드 호제법 (한글자막)[쑤튜브]


