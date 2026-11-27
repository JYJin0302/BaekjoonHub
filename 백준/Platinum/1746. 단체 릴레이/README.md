# [Platinum III] 단체 릴레이 - 1746 

[문제 링크](https://acmicpc.net/problem/1746) 

### 성능 요약

메모리: 3092 KB, 시간: 40 ms

### 분류

다이나믹 프로그래밍, 분할 정복을 이용한 거듭제곱, 수학

### 제출 일자

2022년 06월 07일 22:30:48

### 문제 설명

<p>For their physical fitness program, N (2 <= N <= 1,000,000) cows have decided to run a relay race using the T (2 <= T <= 100) cow trails throughout the pasture.</p>

<p>Each trail connects two different intersections (1 <= I1_i <= 1,000; 1 <= I2_i <= 1,000), each of which is the termination for at least two trails. The cows know the length_i of each trail (1 <= length_i <= 1,000), the two intersections the trail connects, and they know that no two intersections are directly connected by two different trails. The trails form a structure known mathematically as a graph.</p>

<p>To run the relay, the N cows position themselves at various intersections (some intersections might have more than one cow). They must position themselves properly so that they can hand off the baton cow-by-cow and end up at the proper finishing place.</p>

<p>Write a program to help position the cows. Find the shortest path that connects the starting intersection (S) and the ending intersection (E) and traverses exactly N cow trails.</p>

### 입력 

 <ul>
	<li>Line 1: Four space-separated integers: N, T, S, and E</li>
	<li>Lines 2..T+1: Line i+1 describes trail i with three space-separated integers: length_i, I1_i, and I2_i</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the shortest distance from intersection S to intersection E that traverses exactly N cow trails.</li>
</ul>

