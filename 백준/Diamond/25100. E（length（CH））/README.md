# [Diamond V] E(length(CH)) - 25100 

[문제 링크](https://acmicpc.net/problem/25100) 

### 성능 요약

메모리: 2188 KB, 시간: 48 ms

### 분류

Bulldozer 트릭, 기댓값의 선형성, 기하학, 수학, 확률론, 스위핑, 두 포인터

### 제출 일자

2023년 08월 09일 16:41:12

### 문제 설명

<p>You are given $n$ points on a plane. The i-th of them is <em>activated</em> with probability $p_i$, provided as part of the input. Find the expected circumference of the convex hull of all activated points.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 299px; height: 230px;"></p>

### 입력 

 <p>The first line contains the number of points $n$ and the number $p^∗$. All points are activated with the probability $p_i = p^∗$, except for the first three, which are always activated ($p_1 = p_2 = p_3 = 1$); this way, the definition of the convex hull circumference is always sound. This is followed by $n$ lines, each containing space-separated coordinates of the $i$-th point, $x_i$, $y_i$.</p>

### 출력 

 <p>Print out a single number — the expected circumference of the convex hull. Your result should differ by less than $0.001$ from the reference solution to be considered correct.</p>

