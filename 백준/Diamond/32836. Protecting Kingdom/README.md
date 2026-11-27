# [Diamond IV] Protecting Kingdom - 32836 

[문제 링크](https://acmicpc.net/problem/32836) 

### 성능 요약

메모리: 92372 KB, 시간: 472 ms

### 분류

센트로이드, 센트로이드 분할, 분할 정복, 다이나믹 프로그래밍, 트리, 트리DP, 두 포인터

### 제출 일자

2025년 11월 10일 15:37:14

### 문제 설명

<p>In the kingdom of <strong>CPIC</strong> (Committee for Public Infrastructure Conservation), there are $n$ villages numbered from $1$ to $n$ and connected by a network of $n - 1$ roads forming a tree structure. Each road connects two villages and has a positive length. Specifically, the $i$-th road connects village $i + 1$ with village $p_i$ ($1 ≤ p_i ≤ i$) and has a length of $l_i$. Due to treacherous terrains and past incidents, some points along these roads are identified as hazardous.</p>

<p>On the $i$-th road, there are $k_i$ hazardous points located at specific distances $x_{i,1}, x_{i,2}, \dots , x_{i, k_i}$ from village $p_i$, satisfying $0 < x_{i, 1} < x_{i, 2} < \cdots < x_{i, k_i} < l_i$. These distances are integers, indicating positions along the road.</p>

<p>The newly established <strong>CPIC</strong> Safety Committee aims to enhance traveler safety by deploying a protective measure. They can select any two points on the roads, including villages, and secure the shortest path between them. The path can cover all hazardous points located exactly on it, including its endpoints, and its length must not exceed a given length $w$.</p>

<p>Given the road network, the positions of the hazardous points, and the maximum allowable path length $w$, write a program to determine the maximum number of hazardous points that can be covered by optimally choosing the two points and securing the shortest path between them with length $≤ w$.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing two integers, $n$ and $w$ ($2 ≤ n ≤ 250\,000$, $1 ≤ w ≤ 10^{18}$), where $n$ is the number of villages and $w$ is the maximum allowable length of the secured path. In the following $n - 1$ lines, the $i$-th line, which provides information about the $i$-th road, starts with three integers $p_i$, $l_i$, and $k_i$ ($1 ≤ p_i ≤ i$, $1 ≤ l_i ≤ 10^{12}$, $k_i ≥ 0$), where $p_i$ is the village connected to village $i + 1$ by the road, $l_i$ is the length of the road, and $k_i$ is the number of hazardous points on the road. If $k_i > 0$, the line is followed by $k_i$ integers $x_{i,1}, x_{i,2}, \dots , x_{i, k_i}$ ($0 < x_{i, 1} < x_{i, 2} < \cdots < x_{i, k_i} < l_i$), representing the distances from village $p_i$ to each hazardous point along the road. The total number of hazardous points $k_1 + k_2 + \cdots + k_{n-1}$ does not exceed $10^6$.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the maximum number of hazardous points that can be covered by a shortest path of length $w$ or less between any two points on the roads.</p>

