# [Platinum II] The Cross Covers Everything - 24966 

[문제 링크](https://acmicpc.net/problem/24966) 

### 성능 요약

메모리: 11144 KB, 시간: 132 ms

### 분류

이분 탐색, 자료 구조, 기하학, 세그먼트 트리, 스위핑, 두 포인터

### 제출 일자

2025년 09월 16일 18:17:05

### 문제 설명

<p>A cross-shaped infinite area on the $x$-$y$ plane can be specified by two distinct points as depicted on the figure below.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 222px; height: 201px;"></p>

<p style="text-align: center;">Figure J.1. The cross area specified by two points numbered $2$ and $4$</p>

<p>Given a set of points on the plane, you are asked to figure out how many pairs of the points form a cross-shaped area that covers all the points. To be more precise, when $n$ points with coordinates $(x_i , y_i$) ($i = 1, \dots , n$) are given, the ordered pair $<p, q>$ is said to cover a point $(x, y)$ if $x_p ≤ x ≤ x_q$, $y_p ≤ y ≤ y_q$, or both hold. Your task is to find how many pairs $<p, q>$ cover all the $n$ points. No two given points have the same $x$-coordinate nor the same $y$-coordinate.</p>

### 입력 

 <p>The input consists of a single test case of the following format.</p>

<p>$\begin{align*}& n \\ & x_1 \, y_1 \\ & \vdots \\ & x_n \, y_n\end{align*}$</p>

<p>The first line contains an integer $n$ ($2 ≤ n ≤ 2 × 10^5$), which is the number of points given. Two integers $x_i$ and $y_i$ in the $i$-th line of the following $n$ lines are the coordinates of the $i$-th point ($1 ≤ x_i ≤ 10^6$, $1 ≤ y_i ≤ 10^6$). You may assume that $x_j \ne x_k$ and $y_j \ne y_k$ hold for all $j \ne k$.</p>

### 출력 

 <p>Print in a line the number of ordered pairs of points that satisfy the condition.</p>

