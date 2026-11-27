# [Platinum I] Zbunjenost - 32536 

[문제 링크](https://acmicpc.net/problem/32536) 

### 성능 요약

메모리: 38128 KB, 시간: 100 ms

### 분류

조합론, 다이나믹 프로그래밍, 그래프, 수학, 평면 그래프, 트리, 트리DP

### 제출 일자

2025년 07월 04일 17:35:13

### 문제 설명

<p>Mr. Malnar decided to spend his summer traveling around the world by flying randomly. After some time, he found himself in an unknown country’s capital where streets reminded him of a triangulation! More precisely, the city consists of $N$ interesting locations numbered from $1$ to $N$ connected by $2N - 3$ streets. Locations $1, 2, \dots , N$ are connected in that order to form a convex polygon with $N$ sides. Remaining $N - 3$ streets connect locations in such a way that no two streets cross, except maybe at their ends.</p>

<p>While walking the streets of this country’s capital Mr. Malnar found himself at the location where he started from without visiting any location more than once. A bit confused he came to the realization that this is completely normal and came up with a measure of confusion as the number of simple closed loops. Simple closed walk is a sequence of locations $V_1, V_2, \dots , V_m$ such that $V_i$ is connected via street with location $V_{i+1}$ for every $i = 1, 2, \dots , m - 1$ and that location $V_m$ is connected with $V_1$. Two walks are equivalent if one can be obtained by a cyclic rotation of the other, or by reversing the other. For example, walk $(1, 2, 3, 4)$ is equivalent to the walk $(2, 3, 4, 1)$. Simple closed loop is a set of equivalent walks. Mr. Malnar now asks for your help in calculating the confusion of this city!</p>

### 입력 

 <p>In the first line is an integer $N$ ($1 ≤ N ≤ 2 \cdot 10^5$), number of interesting locations.</p>

<p>In the next $N - 3$ lines are integers $X_i$, $Y_i$ ($1 ≤ X_i , Y_i ≤ N$), labels of locations connected by $i$-th street.</p>

### 출력 

 <p>In the first and only line output the confusion of the given city modulo $10^9 + 7$.</p>

