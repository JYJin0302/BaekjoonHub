# [Diamond V] Lucky Draws - 30857 

[문제 링크](https://acmicpc.net/problem/30857) 

### 성능 요약

메모리: 1565396 KB, 시간: 1700 ms

### 분류

분할 정복, 분할 정복을 사용한 최적화, 다이나믹 프로그래밍, 자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리, 스위핑

### 제출 일자

2023년 12월 21일 15:40:30

### 문제 설명

<p>The ICPC committee is planning a surprise event to cheer on the participating teams. The committee provides each team with a pair of two numbers, $A$ and $B$ ($A ≤ B$), before the competition, which will be used for the lucky draws after the competition. The committee wants to hold $K$ draws. In each draw, a single number $C$ is chosen by the committee, and all teams with a pair $(A, B)$ such that $A ≤ C ≤ B$ win in this draw. To make more teams happy, the committee wants to choose the $K$ numbers used in the $K$ draws in advance so that the most teams win. A team can win multiple times but is considered to have won once.</p>

<p>For example, five teams are participating in ICPC and their pairs are $(1, 2)$, $(1, 4)$, $(3, 6)$, $(4, 7)$, $(5, 6)$, and $K = 2$. When the committee chooses two numbers $2$ and $4$, four teams with $(1, 2)$, $(1, 4)$, $(3, 6)$ and $(4, 7)$ win. The team with $(1, 4)$ wins twice because the pair contains both chosen numbers. In fact, all five teams can win if $2$ and $5$ are chosen. The maximum number of winning teams is five.</p>

<p>Given $n$ pairs of two integers for teams and the number of lucky draws $K$, write a program to output the maximum number of winning teams.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing two integers, $n$ and $K$ ($1 ≤ n ≤ 10\,000$, $1 ≤ K ≤ n$, $1 ≤ n \times K ≤ 500\,000$), where $n$ is the number of teams and $K$ is the number of lucky draws. Each of the following $n$ lines contains two integers $A$ and $B$ that represent the pair of a team, where $-10^6 ≤ A ≤ B ≤ 10^6$.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the maximum number of winning teams. Teams that win more than once should only be counted once.</p>

