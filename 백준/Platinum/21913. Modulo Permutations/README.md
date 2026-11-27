# [Platinum II] Modulo Permutations - 21913 

[문제 링크](https://acmicpc.net/problem/21913) 

### 성능 요약

메모리: 9840 KB, 시간: 184 ms

### 분류

다이나믹 프로그래밍, 조화수, 수학, 정수론

### 제출 일자

2025년 10월 17일 18:19:16

### 문제 설명

<p>Given a natural number $n$, count the number of permutations $(p_1, p_2, \dots , p_n)$ of the numbers from $1$ to $n$, such that for each $i$ ($1 \le i \le n$), the following property holds: $p_i \bmod p_{i+1} \le 2$, where $p_{n+1} = p_1$.</p>

<p>As this number can be very big, output it modulo $10^9 + 7$.</p>

### 입력 

 <p>The only line of the input contains the integer $n$ ($1 \le n \le 10^6$).</p>

### 출력 

 <p>Output a single integer — the number of the permutations satisfying the condition from the statement, modulo $10^9 + 7$.</p>

