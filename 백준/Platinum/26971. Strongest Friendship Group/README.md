# [Platinum II] Strongest Friendship Group - 26971 

[문제 링크](https://acmicpc.net/problem/26971) 

### 성능 요약

메모리: 15172 KB, 시간: 108 ms

### 분류

자료 구조, 분리 집합, 그래프, 그리디, 집합과 맵

### 제출 일자

2023년 02월 22일 13:50:44

### 문제 설명

<p>Farmer John has $N$ cows ($2\le N\le 10^5$), conveniently labeled $1 \ldots N$. There are $M$ ($1\le M\le 2\cdot 10^5$) pairs of friends among these cows.</p>

<p>A group of cows is called a "friendship group" if every cow in the group is reachable from every other cow in the group via a chain of friendships that lies solely within the group (friendships connecting to cows outside the group have no impact). The "strength" of a friendship group is the minimum number of friends of any cow in the group within the group times the number of cows in the group (again, note that friendships connecting to cows outside the group do not count for this definition).</p>

<p>Please find the maximum strength over all friendship groups.</p>

### 입력 

 <p>The first line contains $N$ and $M$.</p>

<p>The next $M$ lines contain two integers $u_i$ and $v_i$ denoting that cows $u_i$ and $v_i$ are friends ($1\le u_i,v_i\le N$, $u_i\neq v_i$). No unordered pair of cows appears more than once.</p>

### 출력 

 One line containing the maximum strength over all friendship groups.

