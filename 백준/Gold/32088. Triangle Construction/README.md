# [Gold III] Triangle Construction - 32088 

[문제 링크](https://acmicpc.net/problem/32088) 

### 성능 요약

메모리: 3584 KB, 시간: 32 ms

### 분류

그리디

### 제출 일자

2024년 10월 17일 13:30:44

### 문제 설명

<p>You are given a regular $N$-sided polygon. Label one arbitrary side as side $1$, then label the next sides in clockwise order as side $2, 3, \dots , N$. There are $A_i$ special points on side $i$. These points are positioned such that side $i$ is divided into $A_i + 1$ segments with equal length.</p>

<p>For instance, suppose that you have a regular $4$-sided polygon, i.e., a square. The following illustration shows how the special points are located within each side when $A = [3, 1, 4, 6]$. The uppermost side is labelled as side $1$.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 199px; height: 200px;"></p>

<p>You want to create as many <strong>non-degenerate triangles</strong> as possible while satisfying the following requirements. Each triangle consists of $3$ distinct special points (not necessarily from different sides) as its corners. Each special point can only become the corner of at most $1$ triangle. All triangles must not intersect with each other.</p>

<p>Determine the maximum number of non-degenerate triangles that you can create.</p>

<p>A triangle is <strong>non-degenerate</strong> if it has a positive area.</p>

### 입력 

 <p>The first line consists of an integer $N$ ($3 ≤ N ≤ 200\, 000$).</p>

<p>The following line consists of $N$ integers $A_i$ ($1 ≤ A_i ≤ 2 \cdot 10^9$).</p>

### 출력 

 <p>Output a single integer representing the maximum number of non-degenerate triangles that you can create.</p>

