# [Platinum III] 정원 정리 - 1772 

[문제 링크](https://acmicpc.net/problem/1772) 

### 성능 요약

메모리: 2148 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 배낭 문제, 트리, 트리DP

### 제출 일자

2020년 11월 16일 09:22:32

### 문제 설명

<p>The cows have reconstructed Farmer John's farm, with its N barns (1 <= N <= 150, number 1..N) after the terrible earthquake last May. The cows didn't have time to rebuild any extra roads, so now there is exactly one way to get from any given barn to any other barn. Thus, the farm transportation system can be represented as a tree.</p>

<p>Farmer John wants to know how much damage another earthquake could do. He wants to know the minimum number of roads whose destruction would isolate a subtree of exactly P (1 <= P <= N) barns from the rest of the barns.</p>

### 입력 

 <ul>
	<li>Line 1: Two integers, N and P</li>
	<li>Lines 2..N: N-1 lines, each with two integers I and J. Node I is node J's parent in the tree of roads.</li>
</ul>

### 출력 

 <p>A single line containing the integer that is the minimum number of roads that need to be destroyed for a subtree of P nodes to be isolated.</p>

