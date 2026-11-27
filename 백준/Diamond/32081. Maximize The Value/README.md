# [Diamond V] Maximize The Value - 32081 

[문제 링크](https://acmicpc.net/problem/32081) 

### 성능 요약

메모리: 18796 KB, 시간: 172 ms

### 분류

자료 구조, 오프라인 쿼리, 세그먼트 트리, 스위핑

### 제출 일자

2024년 10월 17일 15:02:45

### 문제 설명

<p>You are given a one-based array consisting of $N$ integers: $A_1, A_2, \cdots , A_N$. Initially, the value of each element is set to $0$.</p>

<p>There are $M$ operations (numbered from $1$ to $M$). Operation $i$ is represented by $⟨L_i , R_i , X_i⟩$. If operation $i$ is executed, all elements $A_j$ for $L_i ≤ j ≤ R_i$ will be increased by $X_i$.</p>

<p>You have to answer $Q$ <strong>independent</strong> queries. Each query is represented by $⟨K, S, T⟩$ which represents the following task. Choose a range $[l, r]$ satisfying $S ≤ l ≤ r ≤ T$, and execute operations $l, l + 1, \dots , r$. The answer to the query is the maximum value of $A_K$ after the operations are executed among all possible choices of $l$ and $r$.</p>

### 입력 

 <p>The first line consists of two integers $N$ $M$ ($1 ≤ N, M ≤ 100\, 000$).</p>

<p>Each of the next $M$ lines consists of three integers $L_i$ $R_i$ $X_i$ ($1 ≤ L_i ≤ R_i ≤ N$; $-100\, 000 ≤ X_i ≤ 100\, 000$).</p>

<p>The following line consists of an integer $Q$ ($1 ≤ Q ≤ 100\, 000$).</p>

<p>Each of the next $Q$ lines consists of three integers $K$ $S$ $T$ ($1 ≤ K ≤ N$; $1 ≤ S ≤ T ≤ M$).</p>

### 출력 

 <p>For each query, output in a single line, an integer which represent the answer of the query.</p>

