# [Platinum II] Haybale Guessing - 6153 

[문제 링크](https://acmicpc.net/problem/6153) 

### 성능 요약

메모리: 8928 KB, 시간: 112 ms

### 분류

이분 탐색, 자료 구조, 세그먼트 트리, 집합과 맵, 정렬

### 제출 일자

2024년 07월 10일 13:58:36

### 문제 설명

<p>The cows, who always have an inferiority complex about their intelligence, have a new guessing game to sharpen their brains.</p>

<p>A designated 'Hay Cow' hides behind the barn and creates N (1 <= N <= 1,000,000) uniquely-sized stacks (conveniently numbered 1..N) of hay bales, each with 1..1,000,000,000 bales of hay.</p>

<p>The other cows then ask the Hay Cow a series of Q (1 <= Q <= 25,000) questions about the the stacks, all having the same form:</p>

<blockquote>
<p>What is the smallest number of bales of any stack in the range of stack numbers Ql..Qh (1 <= Ql <= N; Ql <= Qh <= N)?</p>
</blockquote>

<p>The Hay Cow answers each of these queries with a single integer A whose truthfulness is not guaranteed.</p>

<p>Help the other cows determine if the answers given by the Hay Cow are self-consistent or if certain answers contradict others.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and Q</li>
	<li>Lines 2..Q+1: Each line contains three space-separated integers that represent a single query and its reply: Ql, Qh, and A</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: Print the single integer 0 if there are no inconsistencies among the replies (i.e., if there exists a valid realization of the hay stacks that agrees with all Q queries).  Otherwise, print the index from 1..Q of the earliest query whose answer is inconsistent with the answers to the queries before it.</li>
</ul>

<p> </p>

