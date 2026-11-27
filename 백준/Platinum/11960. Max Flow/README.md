# [Platinum III] Max Flow - 11960 

[문제 링크](https://acmicpc.net/problem/11960) 

### 성능 요약

메모리: 10848 KB, 시간: 80 ms

### 분류

차분 배열 트릭, 최소 공통 조상, 누적 합, 트리

### 제출 일자

2022년 04월 12일 22:37:54

### 문제 설명

<p>Farmer John has installed a new system of \(N-1\) pipes to transport milk between the $N$ stalls in his barn (\(2 \leq N \leq 50,000\)), conveniently numbered \(<span style="line-height:1.6em">1 \ldots N\). Each pipe connects a pair of stalls, and all stalls are connected to each-other via paths of pipes.</span></p>

<p>FJ is pumping milk between \(K\) pairs of stalls (\(1 \leq K \leq 100,000\)). For the \(i\)th such pair, you are told two stalls \(s_i\) and \(t_i\), endpoints of a path along which milk is being pumped at a unit rate. FJ is concerned that some stalls might end up overwhelmed with all the milk being pumped through them, since a stall can serve as a waypoint along many of the \(K\) paths along which milk is being pumped. Please help him determine the maximum amount of milk being pumped through any stall. If milk is being pumped along a path from \(s_i\) to \(t_i\), then it counts as being pumped through the endpoint stalls \(s_i\) and \(t_i\), as well as through every stall along the path between them.</p>

### 입력 

 <p>The first line of the input contains \(N\) and \(K\).</p>

<p>The next \(N-1\) lines each contain two integers \(x\) and \(y\) (\(x \ne y\)) describing a pipe between stalls \(x\) and \(y\).</p>

<p>The next \(K\) lines each contain two integers \(s\) and \(t\) describing the endpoint stalls of a path through which milk is being pumped.</p>

### 출력 

 <p>An integer specifying the maximum amount of milk pumped through any stall in the barn.</p>

