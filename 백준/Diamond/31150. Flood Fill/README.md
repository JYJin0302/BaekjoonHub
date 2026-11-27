# [Diamond IV] Flood Fill - 31150 

[문제 링크](https://acmicpc.net/problem/31150) 

### 성능 요약

메모리: 8300 KB, 시간: 52 ms

### 분류

유량, 그래프, 최대 유량 최소 컷 정리

### 제출 일자

2026년 01월 30일 15:36:22

### 문제 설명

<p>Given are two black and white $N \times M$ images $A$ and $B$.</p>

<p>The "flood fill" tool works as follows: you choose any cell $(x, y)$, locate its connected component and flip the colors of all the cells in the component (if the cell was black, it becomes white, and if it was white, it becomes black). The connected component of the cell is the set of cells you can reach by going up/down/left/right without changing color.</p>

<p>You can apply the "flood fill" tool to image $A$ any number of times. What is the minimum number of cells in which $A$ can be different from $B$ after some sequence of operations?</p>

### 입력 

 <p>The first line of input contains two integers $N$ and $M$ ($1 \le N, M \le 100$) --- the dimensions of the images.</p>

<p>Each of the next $N$ lines contains a binary string of length $M$, describing the corresponding row of the image $A$.</p>

<p>Each of the next $N$ lines contains a binary string of length $M$, describing the corresponding row of the image $B$.</p>

<p>Here <code>0</code> corresponds to the cell colored white, <code>1</code> corresponds to the cell colored black.</p>

### 출력 

 <p>Output a single integer --- the minimum possible number of cells in which $A$ can be different from $B$ after some sequence of operations.</p>

