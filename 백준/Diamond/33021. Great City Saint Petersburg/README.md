# [Diamond V] Great City Saint Petersburg - 33021 

[문제 링크](https://acmicpc.net/problem/33021) 

### 성능 요약

메모리: 43840 KB, 시간: 1088 ms

### 분류

이분 탐색, 자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리

### 제출 일자

2025년 06월 30일 18:37:26

### 문제 설명

<p>Saint Petersburg is the most beautiful city in the world unless it is raining. For the sake of this problem, we will assume it is raining every single day.</p>

<p>One of the streets in Saint Petersburg has an unusual shape --- it is a narrow stripe of $n$ sections $1$ meter long each, where section $i$ is at the height $a_i$ meters from the ground. The stripe is $1$ meter deep and bounded on the front and on the back by incredibly high buildings. Because of this, when it is raining, a certain amount of rain will accumulate, unable to flow out of the street from either its leftmost or rightmost end. Given the heights $a_1$, $a_2$, \ldots, $a_n$, you need to determine the amount of rain (in cubic meters) which will accumulate on the street.</p>

<p>Moreover, your colleagues from the metropolitan construction company will be visiting for $q$ days and on day $i$ they will be laying asphalt on all sections from $l_i$ to $r_i$ inclusive, thus increasing the height of each section $l_i$, $l_i+1$, \ldots, $r_i$ by $1$ meter. You need to determine the total amount of water which accumulates on the street before the construction works, and also after every single day of the construction works.</p>

### 입력 

 <p>The first line contains the number of blocks $n$ and the number of construction events $q$ ($1 \le n, q \le 2 \cdot 10^5$). The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) --- the height of each section before all the events. Each of the following $q$ lines contains a pair of integers $l_i$, $r_i$ ($1 \le l_i \le r_i \le n$), denoting the construction work from $l_i$ to $r_i$ inclusive.</p>

### 출력 

 <p>Print $q+1$ integers --- the amount of water on the street before all updates, and also after every update. </p>

