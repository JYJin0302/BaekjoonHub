# [Gold III] 덧셈 - 10504 

[문제 링크](https://acmicpc.net/problem/10504) 

### 성능 요약

메모리: 2020 KB, 시간: 28 ms

### 분류

브루트포싱, 수학

### 제출 일자

2023년 08월 28일 23:23:08

### 문제 설명

<p>Given an integer N, express it as the sum of at least two consecutive positive integers. For example:</p>

<ul>
	<li>10 = 1 + 2 + 3 + 4</li>
	<li>24 = 7 + 8 + 9</li>
</ul>

<p>If there are multiple solutions, output the one with the smallest possible number of summands.</p>

### 입력 

 <p>The first line of input contains the number of test cases T. The descriptions of the test cases follow:</p>

<p>Each test case consists of one line containing an integer N (1 ≤ N ≤ 10<sup>9</sup>).</p>

### 출력 

 <p>For each test case, output a single line containing the equation in the format:</p>

<pre>N = a + (a+1) + ... + b</pre>

<p>as in the example. If there is no solution, output a single word IMPOSSIBLE instead.</p>

