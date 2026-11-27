# [Diamond II] Just Long Neckties 2 - 33727 

[문제 링크](https://acmicpc.net/problem/33727) 

### 성능 요약

메모리: 3984 KB, 시간: 188 ms

### 분류

비트마스킹, 비트 집합, 비트필드를 이용한 DP, 다이나믹 프로그래밍, 그리디

### 제출 일자

2025년 07월 01일 16:41:23

### 문제 설명

<p>Just Odd Inventions Co., Ltd. is a company renowned for doing ”just odd inventions.” Here we just call it JOI Company.</p>

<p>To celebrate the 5th anniversary of their flagship product, ”Just Long Neckties,” JOI Company has invented a new product: ”Just Stretchable Neckties.” As its name suggests, this new necktie has the unique feature of being able to extend its length indefinitely.</p>

<p>JOI Company has decided to hold a showcase event to promote the new necktie, and you have been selected as the host of the event. At the event, several models wearing the new neckties will appear on stage. Initially, the <strong>length</strong> of every necktie worn by the models is set to $1$.</p>

<p>After that, you will carry out a total of $N$ <strong>performances</strong> to demonstrate the necktie’s stretchable feature to the audience. Each performance is conducted as follows:</p>

<ol>
	<li>First, you ask the audience to call out a number of their choice. Let this number be $x$.</li>
	<li>Next, you decide whether to respond or ignore it.
	<ul>
		<li>If you choose to respond to it, you must select one of the models on stage whose necktie length is currently <strong>less than or equal to</strong> $x$ and set the length of that model’s necktie to exactly $x$. (Note that you may select a model whose necktie length is already $x$.) However, if no model can be selected, the showcase event will fail.</li>
		<li>If you choose to ignore it, you do nothing.</li>
	</ul>
	</li>
</ol>

<p>However, if you ignore the audience’s number two or more times in a row, the audience will get angry, and the showcase event will fail.</p>

<p>The number of models on stage, denoted as $k$ ($k ≥ 1$), has not yet been determined. Since hiring models costs considerable money, it is desirable to keep $k$ as small as possible. The minimum value of $k$ required to prevent the showcase event from failing depends on the numbers called out by the audience during the performances. Fortunately, you possess precognitive abilities and have foreseen that the number called out by the audience during the $i$-th performance ($1 ≤ i ≤ N$) will be $A_i$.</p>

<p>Write a program which, given the numbers called out by the audience during the showcase event, calculates the minimum number of models $k$ required to prevent the showcase event from failing.</p>

### 입력 

 <p>Read the following data from the standard input.</p>

<blockquote>
<p>$N$</p>

<p>$A_1$ $A_2$ $\cdots$ $A_N$</p>
</blockquote>

### 출력 

 <p>Write one line to the standard output. The output should contain the minimum number of models $k$ required to prevent the showcase event from failing.</p>

