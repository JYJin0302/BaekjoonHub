# [Platinum I] Mag - 13487 

[문제 링크](https://acmicpc.net/problem/13487) 

### 성능 요약

메모리: 135852 KB, 시간: 520 ms

### 분류

다이나믹 프로그래밍, 그리디, 수학, 트리, 트리DP

### 제출 일자

2025년 02월 27일 19:10:01

### 문제 설명

<p>You are given an undirected tree with each of its node assigned a magic X<sub>i</sub>.</p>

<p>The magic of a path is defined as the product of the magic of the nodes on that path divided by the number of the nodes on the path. For example, the magic of a path that consists of nodes with magic 3 and 5 is 7.5 (3⋅5 / 2).</p>

<p>In the given tree, find the path with the minimal magic and output the magic of that path. </p>

### 입력 

 <p>The first line of input contains the integer N (1 ≤ N ≤ 10<sup>6</sup>), the number of nodes in the tree.</p>

<p>Each of the following N - 1 lines contains two integers, A<sub>i</sub> and B<sub>i</sub> (1 ≤ A<sub>i</sub>, B<sub>i</sub> ≤ N), the labels of nodes connected with an edge.<br>
The ith of the following N lines contains the integer X<sub>i</sub> (1 ≤ X<sub>i</sub> ≤ 10<sup>9</sup> ), magic of the ith node. </p>

### 출력 

 <p>Output the magic of the path with minimal magic in the form of a completely reduced fraction P/Q (P and Q are relatively prime integers).</p>

<p>In all test cases, it will hold that the required P and Q are smaller than 10<sup>18</sup>.</p>

