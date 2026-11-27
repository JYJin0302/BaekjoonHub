# [Platinum III] Grazing on the Run - 7036 

[문제 링크](https://acmicpc.net/problem/7036) 

### 성능 요약

메모리: 18108 KB, 시간: 12 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 03월 25일 21:55:09

### 문제 설명

<p>A long, linear field has N (1 <= N <= 1,000) clumps of grass at unique integer locations on what will be treated as a number line.Think of the clumps as points on the number line. </p>

<p>Bessie starts at some specified integer location L on the number line (1 <= L <= 1,000,000) and traverses the number line in the two possible directions (sometimes reversing her direction) in order to reach and eat all the clumps. She moves at a constant speed (one unit of distance in one unit of time), and eats a clump instantly when she encounters it. </p>

<p>Clumps that aren't eaten for a while get stale. We say the "staleness" of a clump is the amount of time that elapses from when Bessie starts moving until she eats a clump. Bessie wants to minimize the total staleness of all the clumps she eats. </p>

<p>Find the minimum total staleness that Bessie can achieve while eating all the clumps.</p>

### 입력 

 <ul>
	<li>Line 1 : Two space-separated integers: N and L. </li>
	<li>Lines 2..N+1: Each line contains a single integer giving the position P of a clump (1 <= P <= 1,000,000). </li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer: the minimum total staleness Bessie can achieve while eating all the clumps.</li>
</ul>

