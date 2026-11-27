# [Gold III] Allowance - 5994 

[문제 링크](https://acmicpc.net/problem/5994) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

그리디

### 제출 일자

2024년 03월 25일 20:10:04

### 문제 설명

<p>As a reward for record milk production, Farmer John has decided to start paying Bessie a small weekly allowance.</p>

<p>FJ has a set of coins in N (1 <= N <= 20) different denominations, where each denomination of coin evenly divides the next-larger denomination.</p>

<p>Using the given set of coins, he would like to pay Bessie at least some given amount of money C (1 <= C <= 100,000,000) every week. Please help him compute the maximum number of weeks he can pay Bessie.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and C</li>
	<li>Lines 2..N+1: Each line corresponds to a denomination of coin and contains two integers: the value V (1 <= V <= 100,000,000) of the denomination, and the number of coins B (1 <= B <= 1,000,000) of this denomation in Farmer John's possession.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the number of weeks Farmer John can pay Bessie at least C allowance</li>
</ul>

