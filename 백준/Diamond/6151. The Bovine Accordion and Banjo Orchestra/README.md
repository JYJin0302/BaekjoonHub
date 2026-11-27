# [Diamond V] The Bovine Accordion and Banjo Orchestra - 6151 

[문제 링크](https://acmicpc.net/problem/6151) 

### 성능 요약

메모리: 26776 KB, 시간: 104 ms

### 분류

볼록 껍질을 이용한 최적화, 다이나믹 프로그래밍

### 제출 일자

2024년 06월 25일 01:50:49

### 문제 설명

<p>The 2*N (3 <= N <= 1,000) cows have assembled the Bovine Accordion and Banjo Orchestra!  They possess various levels of skill on their respective instruments: accordionist i has an associated talent level A_i (0 <= A_i <= 1,000); banjoist j has an associated talent level B_j (0 <= B_j <= 1,000).</p>

<p>The combined `awesomeness' of a pairing between cows with talents A_i and B_j is directly proportional to the talents of each cow in the pair so a concert with those two cows will earn FJ precisely A_i * B_j dollars in "charitable donations".  FJ wishes to maximize the sum of all revenue obtained by his cows by pairing them up in the most profitable way.</p>

<p>Unfortunately, FJ's accordionists are a bit stuck up and stubborn. If accordionist i is paired with banjoist j, then accordionists i+1..N refuse to be paired with banjoists 1..j-1. This creates restrictions on which pairs FJ can form. FJ thus realizes that in order to maximize his profits, he may have to leave some cows unpaired.</p>

<p>To make matters worse, when one or more of the musicians is skipped, they will be greatly upset at their wasted talent and will engage in massive binge drinking to wash away their sorrows.</p>

<p>After all pairings are made, a list is constructed of the groups of each of the consecutive skipped musicians (of either instrument). Every group of one or more consecutive skipped cows will gather together to consume kegs of ice cold orange soda in an amount proportional to the square of the sum of their wasted talent.</p>

<p>Specifically, FJ has calculated that if the x-th to y-th accordionists are skipped, they will consume precisely (A_x + A_x+1 + A_x+2 + ... + A_y)^2 dollars worth of orange soda in the process of drinking themselves into oblivion. An identical relationship holds for the banjoists. FJ realizes that he'll end up getting stuck with the bill for his cows' drinking, and thus takes this into account when choosing which pairings to make.</p>

<p>Find the maximum amount of total profit that FJ can earn after the contributions are collected and the orange soda is paid for.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N+1: Line i+1 contains the single integer: A_i</li>
	<li>Lines N+2..2*N+1: Line i+N+1 contains the single integer: B_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer that represents the maximum amount of cash that FJ can earn.</li>
</ul>

<p> </p>

