# [Platinum III] Dark Alley - 32480 

[문제 링크](https://acmicpc.net/problem/32480) 

### 성능 요약

메모리: 8324 KB, 시간: 88 ms

### 분류

자료 구조, 수학, 모듈로 곱셈 역원, 정수론, 세그먼트 트리

### 제출 일자

2026년 01월 06일 14:06:44

### 문제 설명

<p>One cold and foggy night, you walk down a shady alley. There should be a lamp every few metres but none of them seem to work, and in this night, not even the moon enlightens your path. Alone and in the dark, you wonder: "Even if there was a working lamp somewhere, how much would it lighten my way?". Now, back at home, you want to calculate this.</p>

<p>The alley can be modelled as a line with a length of $n$ metres. The fog has a uniform density and reduces the light of a lamp by a factor of $1-p$ every metre. The brightness at one point is the sum of the light that reaches this point from every lamp. You want to calculate this brightness at some points after placing some lamps.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers $n$ and $q$ and one real number $p$ ($1\leq n, q\leq 2\cdot10^5, 0 < p < 1$), the length of the alley, the number of queries and the density of the fog. The density $p$ of the fog will be given with at most $6$ digits behind the decimal point.</li>
	<li>$q$ lines containing one of three query types:
	<ol>
		<li>"<strong><code>+ b x</code></strong>" given two integers $b$ and $x$ ($1\leq b \leq 10^9$ and $1\leq x \leq n$), place a lamp with brightness $b$ at position $x$.</li>
		<li>"<strong><code>- b x</code></strong>" given integers $b$ and $x$ ($1\leq b \leq 10^9$ and $1\leq x \leq n$), remove a lamp with brightness $b$ at position $x$. It is guaranteed that a lamp with that brightness was placed there earlier.</li>
		<li>"<strong><code>? x</code></strong>" given one integer $x$ ($1\leq x \leq n$), calculate the brightness at position $x$.</li>
	</ol>
	</li>
</ul>

### 출력 

 <p>It can be shown that the brightness can be calculated as a fraction $\frac{P}{Q}$ where $Q$ is not divisible by $10^9+7$. For each query of type "<code>?</code>", print the brightness as $P\cdot Q^{-1} \bmod 10^9+7$ in a single line.</p>

