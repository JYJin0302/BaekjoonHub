# [Diamond V] Min Max Convert - 16331 

[문제 링크](https://acmicpc.net/problem/16331) 

### 성능 요약

메모리: 8772 KB, 시간: 48 ms

### 분류

자료 구조, 그리디, 스택, 두 포인터

### 제출 일자

2023년 11월 16일 13:42:21

### 문제 설명

<p>Let A be a sequence of N elements. You can perform two types of operations on this sequence:</p>

<ol>
	<li>Select an interval of positions [a, b](1 ≤ a ≤ b ≤ N). Let x be the maximum value on this interval. Replace all the elements in the interval with x.</li>
	<li>Select an interval of positions [a, b](1 ≤ a ≤ b ≤ N). Let x be the minimum value on this interval. Replace all the elements in the interval with x.</li>
</ol>

<p>Determine a sequence of operations such that sequence A becomes another given sequence B (of also N elements). The number of operations must be less or equal than 2 ∗ N.</p>

### 입력 

 <p>The first line of the input contains a single number N. The second line contains A, a sequence of N elements. The third line contains B, another sequence of N elements.</p>

### 출력 

 <p>If there is no solution such that sequence A becomes B, print –1. Otherwise, print on the first line a single number x, the minimum number of operations needed to transform sequence A in B. Each of the next x lines will contain a character (the type of the operation: m if the operation use the minimum and M for the maximum) and an interval (a, b), describing the operations needed for the process. If there are multiple solutions, print any of them.</p>

