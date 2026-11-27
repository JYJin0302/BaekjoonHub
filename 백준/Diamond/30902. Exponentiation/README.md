# [Diamond III] Exponentiation - 30902 

[문제 링크](https://acmicpc.net/problem/30902) 

### 성능 요약

메모리: 4704 KB, 시간: 740 ms

### 분류

애드 혹, 자료 구조, 수학

### 제출 일자

2024년 04월 29일 16:22:28

### 문제 설명

<p>In her spare time, Zoe develops an online calculator. Unfortunately, the calculator was targeted by a denial-of-service attack last week. The attacker created a lot of integer variables, exponentiated them with each other, and tried to do a bunch of comparisons. The huge integers were too much for the server to handle, so it crashed. Before Zoe fixes the issue, she decides to actually perform the calculations that the attacker requested.</p>

<p>There are $n$ integer variables $x_1, x_2, \dots, x_n$. At the start, each variable is set to $2023$. You have to perform $m$ instructions of the following two types:</p>

<ul>
	<li><em>Operations</em>, of the form "<code>!</code> $i$ $j$", where $i \neq j$. This means that $x_i$ gets set to $x_i^{x_j}$.</li>
	<li><em>Queries</em>, of the form "<code>?</code> $i$ $j$", where $i \neq j$. This means that you should print '<code>></code>' if $x_i$ is greater than $x_j$, '<code>=</code>' if $x_i$ is equal to $x_j$, and '<code><</code>' if $x_i$ is smaller than $x_j$.</li>
</ul>

<p>Consider the first sample. After the $5$ operations, the values of the variables are: $$\begin{align*} x_1&=\left({2023}^{2023}\right)^{{2023}^{2023}},& x_2&=\left({2023}^{{2023}^{2023}}\right)^{2023},& x_3&={2023},& x_4&={2023}^{2023}. \end{align*}$$</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers $n$ and $m$ ($2 \leq n \leq 1000$, $1 \leq m \leq 1000$), the number of variables and the number of instructions.</li>
	<li>$m$ lines, each containing a character $c$ (either '<code>!</code>' or '<code>?</code>') and two integers $i$ and $j$ ($1 \leq i, j \leq n$, $i \neq j$), describing the instructions.</li>
</ul>

### 출력 

 <p>For every query in the input, output its answer.</p>

