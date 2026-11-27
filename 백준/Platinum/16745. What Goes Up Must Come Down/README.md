# [Platinum II] What Goes Up Must Come Down - 16745 

[문제 링크](https://acmicpc.net/problem/16745) 

### 성능 요약

메모리: 9584 KB, 시간: 80 ms

### 분류

자료 구조, 그리디, 세그먼트 트리

### 제출 일자

2023년 03월 04일 14:51:48

### 문제 설명

<p>Several cards with numbers printed on them are lined up on the table.</p>

<p>We’d like to change their order so that first some are in non-decreasing order of the numbers on them, and the rest are in non-increasing order. For example, (1, 2, 3, 2, 1), (1, 1, 3, 4, 5, 9, 2), and (5, 3, 1) are acceptable orders, but (8, 7, 9) and (5, 3, 5, 3) are not.</p>

<p>To put it formally, with n the number of cards and bi the number printed on the card at the i-th position (1 ≤ i ≤ n) after reordering, there should exist k ∈ {1, . . . , n} such that (b<sub>i</sub> ≤ b<sub>i+1</sub> ∀i ∈ {1, . . . , k − 1}) and (b<sub>i</sub> ≥ b<sub>i+1</sub> ∀i ∈ {k, . . . , n − 1}) hold.</p>

<p>For reordering, the only operation allowed at a time is to swap the positions of an adjacent card pair. We want to know the minimum number of swaps required to complete the reorder.</p>

### 입력 

 <p>The input consists of a single test case of the following format.</p>

<pre>n
a<sub>1</sub> . . . a<sub>n</sub></pre>

<p>An integer n in the first line is the number of cards (1 ≤ n ≤ 100 000). Integers a<sub>1</sub> through a<sub>n</sub> in the second line are the numbers printed on the cards, in the order of their original positions (1 ≤ a<sub>i</sub> ≤ 100 000).</p>

### 출력 

 <p>Output in a line the minimum number of swaps required to reorder the cards as specified.</p>

