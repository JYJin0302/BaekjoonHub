# [Platinum IV] Tree - 16328 

[문제 링크](https://acmicpc.net/problem/16328) 

### 성능 요약

메모리: 2060 KB, 시간: 4 ms

### 분류

깊이 우선 탐색, 그래프, 그래프 탐색, 트리

### 제출 일자

2023년 11월 16일 12:33:18

### 문제 설명

<p>You are given a tree of n vertices, each with a unique number from 1 to n. A vertex has a color, black or white. Choose exactly m black vertices so that the length of the longest path between any of them is minimal.</p>

### 입력 

 <p>The first line contains two integers n and m (1 ≤ m ≤ n ≤ 100) — the number of vertices and the number of black vertices you have to choose.</p>

<p>The fourth line contains n integers p<sub>1</sub>, p<sub>2</sub>, . . . , p<sub>n</sub> (0 ≤ p<sub>i</sub> ≤ 1). If the p<sub>i</sub> = 1, then the i-th vertex is black; otherwise, it is white. It is guaranteed that the number of black vertices is at least m. Each of the next n − 1 lines contains two integers v<sub>i</sub> and u<sub>i</sub> (1 ≤ v<sub>i</sub> , u<sub>i</sub> ≤ n) meaning that there is an edge between v<sub>i</sub> and u<sub>i</sub>.</p>

<p>It is guaranteed that the input graph is a tree.</p>

### 출력 

 <p>Print a single integer — the answer to the task.</p>

