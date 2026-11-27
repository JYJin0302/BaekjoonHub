# [Gold IV] Chip Exchange - 35326 

[문제 링크](https://acmicpc.net/problem/35326) 

### 성능 요약

메모리: 2020 KB, 시간: 24 ms

### 분류

사칙연산, 많은 조건 분기, 그리디, 수학

### 제출 일자

2026년 02월 28일 17:14:39

### 문제 설명

<p>Bessie the cow has in her possession $A$ chips of type A and $B$ chips of type B ($0\le A,B\le 10^9$). She can perform the following operation as many times as she likes:</p>

<ul>
<li>If you have at least $c_B$ chips of type B, exchange $c_B$ chips of type B for $c_A$ chips of type A ($1\le c_A,c_B\le 10^9$).</li>
</ul>

<p>Determine the minimum non-negative integer $x$ such that the following holds: after receiving $x$ additional random chips, it is guaranteed that Bessie can end up with at least $f_A$ chips of type A ($0\le f_A\le 10^9$).</p>

### 입력 

 <p>The first line contains $T$, the number of independent test cases ($1\le T\le 10^4$).</p>

<p>Then follow $T$ tests, each consisting of five integers $A,B,c_A,c_B,f_A$.</p>

### 출력 

 <p>Output the answer for each test on a separate line.</p>

<p><strong>Note: The large size of integers involved in this problem may require the use of 64-bit integer data types (e.g., a "long long" in C/C++).</strong></p>

