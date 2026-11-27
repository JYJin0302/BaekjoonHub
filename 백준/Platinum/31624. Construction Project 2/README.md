# [Platinum V] Construction Project 2 - 31624 

[문제 링크](https://acmicpc.net/problem/31624) 

### 성능 요약

메모리: 32780 KB, 시간: 352 ms

### 분류

이분 탐색, 데이크스트라, 그래프, 최단 경로, 정렬

### 제출 일자

2025년 07월 14일 19:33:10

### 문제 설명

<p>There are $N$ stations in JOI Kingdom, numbered from $1$ to $N$. There are $M$ train lines in JOI Kingdom, numbered from $1$ to $M$. The train line $i$ ($1 ≤ i ≤ M$) connects station $A_i$ and station $B_i$ bi-directionally, and requires $C_i$ minutes for travel.</p>

<p>You, a minister of JOI Kingdom, decided to construct a new train line as follows.</p>

<ul>
	<li>You choose integers $u$ and $v$, which satisfy $1 ≤ u < v ≤ N$. You construct a new train line, which connects station $u$ and station $v$ bi-directionally, and requires $L$ minutes for travel. Note that you can choose $2$ integers such that there already be a train line connecting station $u$ and station $v$.</li>
</ul>

<p>After you construct a new train line, the King of JOI Kingdom becomes happy if he can move from station $S$ to station $T$ within $K$ minutes by using some train lines. Note that transit times and waiting times for train lines are not considered.</p>

<p>There are $\frac{N(N-1)}{2}$ ways when you choose $2$ integers $u$ and $v$, and you want to know how many of these ways make the King happy.</p>

<p>Write a program which, given information of stations, the train lines, and the King’s request, calculates number of ways to choose $2$ integers that make the King happy.</p>

### 입력 

 <p>Read the following data from the standard input.</p>

<blockquote>
<p>$N$ $M$</p>

<p>$S$ $T$ $L$ $K$</p>

<p>$A_1$ $B_1$ $C_1$</p>

<p>$A_2$ $B_2$ $C_2$</p>

<p>$\vdots$</p>

<p>$A_M$ $B_M$ $C_M$</p>
</blockquote>

### 출력 

 <p>Write one line to the standard output. The output should contain number of ways to choose $2$ integers that make the King happy.</p>

