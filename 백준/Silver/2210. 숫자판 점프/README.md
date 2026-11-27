# [Silver II] 숫자판 점프 - 2210 

[문제 링크](https://acmicpc.net/problem/2210) 

### 성능 요약

메모리: 2420 KB, 시간: 4 ms

### 분류

브루트포싱, 깊이 우선 탐색, 그래프, 그래프 탐색, 격자 그래프, 집합과 맵

### 제출 일자

2024년 03월 26일 15:18:00

### 문제 설명

<p>The cows play the child's game of hopscotch in a non-traditional way. Instead of a linear set of numbered boxes into which to hop, the cows create a 5x5 rectilinear grid of digits parallel to the x and y axes.</p>

<p>They then adroitly hop onto any digit in the grid and hop forward, backward, right, or left (never diagonally) to another digit in the grid. They hop again (same rules) to a digit (potentially a digit already visited).</p>

<p>With a total of five intra-grid hops, their hops create a six-digit integer (which might have leading zeroes like 000201).</p>

<p>Determine the count of the number of distinct integers that can be created in this manner.</p>

### 입력 

 <ul>
	<li>Lines 1..5: The grid, five integers per line</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: The number of distinct integers that can be constructed</li>
</ul>

