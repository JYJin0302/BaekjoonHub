# [Gold III] Finicky Grazers - 26991 

[문제 링크](https://acmicpc.net/problem/26991) 

### 성능 요약

메모리: 2344 KB, 시간: 152 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 04월 06일 15:26:28

### 문제 설명

<p>Farmer John's N (1 ≤ N ≤ 10,000) cows (conveniently numbered 1..N) graze in a straight line in their pasture whose length is L+1 (N ≤ L ≤ 100,000) meters. Every morning, they place themselves at various unique integer locations along that line. FJ has observed that the cows produce more milk when the distance to the other grazing cows is maximized.</p>

<p>Always the enterprising farmer, FJ wants to maximize the distance between each and every pair of neighboring cows by moving the cows to the right or left, but always with integer inter-cow spacing and never changing their order on the line. He spends 1 minute to move a cow 1 meter. When he's finished, he knows that the distances between every adjacent pair of cows will be one of two integers: D or D+1.</p>

<p>Help FJ to calculate minimum time he needs to arrange the positions of the cows.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers, N and L</li>
	<li>Lines 2..N+1: Line i+1 describes cow i with a single integer (range 0..L) representing the position of a cow; 0 is the left-most position. The list is sorted by position with the smallest position value first.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single line with minimum time FJ needs to arrange the positions of the cows.</li>
</ul>

