# [Platinum I] Neo-Robin Hood - 21916 

[문제 링크](https://acmicpc.net/problem/21916) 

### 성능 요약

메모리: 16264 KB, 시간: 948 ms

### 분류

이분 탐색, 자료 구조, 그리디, 매개 변수 탐색, 우선순위 큐

### 제출 일자

2025년 10월 22일 13:09:02

### 문제 설명

<p>There are $n$ aspiring politicians in Neverland. They are wealthy, but not wealthy enough to gain political influence. Since Neverland is a financially transparent haven, we know the bank statements of each politician: the $i$-th politician ($1 \le i \le n$) has $m_i$ dollars, and needs $p_i$ more dollars to achieve his political goals.</p>

<p>You are the infamous modern superhero Neo-Robin Hood. You earn your living by stealing from the rich and wealthy, in order to help... well, whoever promises to help you back. For each of the $n$ politicians you can chose to do one of the following:</p>

<ol>
	<li>Steal his $m_i$ dollars;</li>
	<li>Do nothing to him;</li>
	<li>Help him gain political influence, by giving him $p_i$ dollars.</li>
</ol>

<p>But your services don’t come for free. Once you help a politician gain political influence, he is bound to help you cover-up one of your thefts so that you won’t get in trouble – for instance, by providing an alibi. In turn, you are also bound to not steal his money in the future.</p>

<p>Initially you start with no money. Your task is to rob as many politicians as possible; however, you can’t afford to get caught, so you need a politician to account for each crime you commit.</p>

<p>What is the maximum number of people you can rob?</p>

### 입력 

 <p>The first line of the input contains a positive integer $n$ ($1 \le n \le 100\,000$), the number of politicians. The second line of the input contains $n$ positive integers $m_i$ ($1 \le m_i \le 10^9$, for all $1 \le i \le n$). The third line of the input contains $n$ positive integers $p_i$ ($1 \le p_i \le 10^9$, for all $1 \le i \le n$).</p>

### 출력 

 <p>Output a single non-negative integer, the maximum number of people that you can steal from.</p>

<p>Note that you do not have to maximize your own wealth, but rather the number of people that you are stealing from.</p>

