# [Platinum V] 일차원 세포 자동자 - 3827 

[문제 링크](https://acmicpc.net/problem/3827) 

### 성능 요약

메모리: 2820 KB, 시간: 2000 ms

### 분류

분할 정복을 이용한 거듭제곱, 선형대수학, 수학

### 제출 일자

2022년 12월 03일 14:40:54

### 문제 설명

<p>There is a one-dimensional cellular automaton consisting of N cells. Cells are numbered from 0 to N - 1.</p>

<p>Each cell has a state represented as a non-negative integer less than M. The states of cells evolve through discrete time steps. We denote the state of the i-th cell at time t as S(i, t). The state at time t + 1 is de ned by the equation</p>

<p>S(i,t+1) = (A × S(i-1,t) + B × S(i,t) + C × S(i+1,t)) mod M (1)</p>

<p>where A, B and C are non-negative integer constants. For i < 0 or N ≤ i, we de ne S(i, t) = 0.</p>

<p>Given an automaton de nition and initial states of cells, your mission is to write a program that computes the states of the cells at a speci ed time T.</p>

### 입력 

 <p>The input is a sequence of datasets. Each dataset is formatted as follows.</p>
<pre>N M A B C T
S(0,0) S(1,0) ... S(N-1,0)</pre>


<p>The fi rst line of a dataset consists of six integers, namely N, M, A, B, C and T. N is the number of cells. M is the modulus in the equation (1). A, B and C are coeﬃcients in the equation (1). Finally, T is the time for which you should compute the states.</p>

<p>You may assume that 0 < N ≤ 50, 0 < M ≤ 1000, 0 ≤ A, B, C < M and 0 ≤ T ≤ 10<sup>9</sup></p>

<p>The second line consists of N integers, each of which is non-negative and less than M. They represent the states of the cells at time zero.</p>

<p>A line containing six zeros indicates the end of the input.</p>

### 출력 

 <p>For each dataset, output a line that contains the states of the cells at time T. The format of the output is as follows.</p>
<pre>S(0,T) S(1,T) ... S(N-1,T)</pre>
<p>Each state must be represented as an integer and the integers must be separated by a space.</p>

