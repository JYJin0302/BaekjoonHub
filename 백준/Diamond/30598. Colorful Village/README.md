# [Diamond IV] Colorful Village - 30598 

[문제 링크](https://acmicpc.net/problem/30598) 

### 성능 요약

메모리: 68776 KB, 시간: 428 ms

### 분류

2-SAT, 그래프, 강한 연결 요소, 트리

### 제출 일자

2024년 09월 25일 23:42:03

### 문제 설명

<p>Colorful Village is a popular tourist destination. It has $2n$ houses, numbered from $1$ to $2n$. Every house has one of $n$ colors, numbered from $1$ to $n$. Coincidentally, for each of the $n$ colors, exactly two houses are colored into it.</p>

<p>There are $2n-1$ bidirectional roads in Colorful Village. Each road connects two different houses, and it is possible to reach any house from any other house using these roads.</p>

<p>Catherine is planning a trip to Colorful Village. Her time is limited, so she wants to choose a set $S$ of $n$ houses to visit, with exactly one house of each color. However, since Catherine also needs to move between houses, the set of houses she is going to visit must be connected. In other words, it must be possible to reach any house in $S$ from any other house in $S$ using the roads, and only visiting houses in $S$ on the way.</p>

<p>Help Catherine to find a connected set $S$ of $n$ houses, one of each color, or report that no such set exists.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^5$). The description of the test cases follows.</p>

<p>The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$).</p>

<p>The second line contains $2n$ integers $c_1, c_2, \ldots, c_{2n}$, denoting the colors of the houses in Colorful Village ($1 \le c_i \le n$). Every integer from $1$ to $n$ appears exactly twice in this line.</p>

<p>The $i$-th of the following $2n-1$ lines contains two integers $u_i$ and $v_i$, denoting the houses connected by the $i$-th road ($1 \le u_i, v_i \le 2n$; $u_i \ne v_i$).</p>

<p>It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.</p>

### 출력 

 <p>For each test case, print a single integer $-1$ if the required set of houses does not exist.</p>

<p>Otherwise, print $n$ distinct integers $s_1, s_2, \ldots, s_n$ in any order, denoting a connected set $S$ of $n$ houses, one of each color ($1 \le s_i \le 2n$). If there are multiple answers, print any of them.</p>

