# [Diamond IV] It’s a Kind of Magic - 32897 

[문제 링크](https://acmicpc.net/problem/32897) 

### 성능 요약

메모리: 15196 KB, 시간: 656 ms

### 분류

애드 혹, 브루트포싱, 해 구성하기, 포함 배제의 원리, 수학, 정수론, 런타임 전의 전처리, 누적 합, 에라토스테네스의 체, 소수 판정

### 제출 일자

2025년 01월 12일 18:06:42

### 문제 설명

<p>Everyone knows that a $3\times3$ magic square must meet two criteria:</p>

<ol>
	<li>All nine numbers must be positive and distinct.</li>
	<li>The sums along all rows, columns, and diagonals are equal.</li>
</ol>

<p>Everyone, except  maybe Matt Parker<sup>1</sup>. He wants to create a magic square of squares, that is, a magic square that also meets a third criterion:</p>

<ol start="3">
	<li>Each number is a square of a positive integer.</li>
</ol>

<p>His "result" can be seen in the picture in the corner. As you may notice, his square is not that magic... Not only do most of the values appear twice, it also has a diagonal with the wrong sum. To be honest, apart from containing non-square values, there is not much that could make this square worse. Well, at least he tried!</p>

<p>But that is all in the past. After finding the <em>Parker Square</em>, he decided to completely ignore property $3$ from now on and to instead give property $2$ a new twist. He now considers multiplicative magic squares, which are exactly like normal magic squares except that the <em>products</em> along all rows, columns, and diagonals have to be equal, instead of the sums. Who knows, Matt might even manage to find a proper multiplicative magic square in the future!</p>

<p>With this definition at hand, Matt wrote some terrible Python code -- his words, not ours -- to count the number of multiplicative magic $3\times 3$ squares where the product of the numbers in a single row, column, or diagonal is at most $n$. As you may have guessed by now, his code is way too slow. Therefore, we task you to do the same, just more efficiently. Given an integer $n$, count the number of multiplicative magic $3\times 3$ squares with product at most $n$.</p>

<hr>
<p><sup>1</sup>Recreational mathematician, author, comedian, YouTube personality, and science communicator.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with an integer $t$ ($1 \leq t \leq 10^5$), the number of test cases.</li>
	<li>$t$ lines, each with an integer $n$ ($1 \leq n \leq 10^{18}$), the maximum product.</li>
</ul>

### 출력 

 <p>For each test case, output the number of multiplicative magic squares with product at most $n$.</p>

