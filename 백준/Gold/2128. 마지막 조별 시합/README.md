# [Gold IV] 마지막 조별 시합 - 2128 

[문제 링크](https://acmicpc.net/problem/2128) 

### 성능 요약

메모리: 2164 KB, 시간: 72 ms

### 분류

비트마스킹, 브루트포싱, 조합론, 수학

### 제출 일자

2021년 12월 04일 22:01:17

### 문제 설명

<p>Alas! A set of D (1 <= D <= 15) diseases (numbered 1..D) is running through the farm. Farmer John would like to milk as many of his N (1 <= N <= 1,000) cows as possible. If the milked cows carry more than K (1 <= K <= D) different diseases among them, then the milk will be too contaminated and will have to be discarded in its entirety. Please help determine the largest number of cows FJ can milk without having to discard the milk.</p>

### 입력 

 <ul>
	<li>Line 1: Three space-separated integers: N, D, and K</li>
	<li>Lines 2..N+1: Line i+1 describes the diseases of cow i with a list of 1 or more space-separated integers. The first integer, d_i, is the count of cow i's diseases; the next d_i integers enumerate the actual diseases. Of course, the list is empty if d_i is 0.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: M, the maximum number of cows which can be milked.</li>
</ul>

