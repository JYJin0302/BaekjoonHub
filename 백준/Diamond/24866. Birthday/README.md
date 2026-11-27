# [Diamond V] Birthday - 24866 

[문제 링크](https://acmicpc.net/problem/24866) 

### 성능 요약

메모리: 206660 KB, 시간: 1460 ms

### 분류

분할 정복, 자료 구조, 누적 합, 세그먼트 트리, 작은 집합에서 큰 집합으로 합치는 테크닉

### 제출 일자

2026년 01월 15일 17:20:28

### 문제 설명

<p>Bogdan received a birthday gift: a board game called "Subsegment sum". This entertaining game consists of $n$ two-sided cards. An integer is written on each side of each card. The cards are arranged in a row on the table and are indexed from 1 to $n$, left to right. After the arrangement the cards can be turned over, but not swapped.</p>

<p>The player receives tasks, each task is a pair of numbers $l$ and $r$. After receiving a task, the player places each card with index from $l$ to $r$, inclusive, some side up. The target is to make the sum of the numbers on the upper sides of cards with index from $l$ to $r$, inclusive, as large as possible.</p>

<p>Bogdan became bored with achieving maximum sums, so he decided to make the game harder. Now Bogdan selects a number $k$, and when he solves the task for cards from $l$ to $r$, inclusive, he places these cards with some side up in such a way that the sum of the numbers on their upper sides was as large as possible, but not divisible by $k$. If Bogdan is able to solve this task, he denotes the received maximum sum as $f(l, r)$. If he is unable to select sides to make the sum on the upper sides indivisible by $k$, he considers $f(l,r)=0$.</p>

<p>After some playing, Bogdan started thinking about the following problem. He wants to calculate the sum of $f(l, r)$ for all possible pairs $l$ and $r$, in other words, calculate $\sum\limits_{1 \le l \le r \le n}f(l,r)$. </p>

<p>Help Bogdan find this sum. Since the answer can be very large, calculate it by modulo $10^9+ 7$.</p>

### 입력 

 <p>The first line contains two integers $n$ and $k$ ($1 \le n \le 5 \cdot 10^5$; $1 \le k \le 10^9$).</p>

<p>Each of the next $n$ lines contains a description of a card on the table: two integers $a_i$ and $b_i$ ($1 \le a_i, b_i \le 10^9$) --- the numbers written on two sides of the card with index $i$.</p>

### 출력 

 <p>Output one integer, the answer taken modulo $10^9+7$.</p>

