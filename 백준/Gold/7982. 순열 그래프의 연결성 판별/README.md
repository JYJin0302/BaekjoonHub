# [Gold I] 순열 그래프의 연결성 판별 - 7982 

[문제 링크](https://acmicpc.net/problem/7982) 

### 성능 요약

메모리: 61984 KB, 시간: 424 ms

### 분류

애드 혹, 자료 구조

### 제출 일자

2022년 06월 12일 23:38:04

### 문제 설명

<p>Byteasar discovered a new family of undirected graphs that can be represented using permutations. Let V = {1, 2, ..., n} be the set of vertices. The description of a graph is given as a permutation a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> of the set V (that is, a sequence of distinct numbers from V ). The vertices ai and aj are connected by an edge if the pair (i, j) forms an inversion in the permutation, that is, i < j and a<sub>i</sub> > a<sub>j</sub> .</p>

<p>For example, let n = 4 and consider the permutation 2, 3, 1, 4. From this permutation we obtain the following graph:</p>

<p style="text-align:center"><img alt="" src="" style="height:45px; width:153px"></p>

<p>Byteasar would like to check if the representation that he invented is useful indeed. He has decided to write a program that finds all the connected components of the graph. Recall that two vertices u; v ∈ V belong to the same connected component if there exists a sequence of vertices starting with u and ending with v such that every two subsequent vertices in the sequence are connected by an edge. In our example we have two connected components: {1, 2, 3} and {4}.</p>

<p>Help Byteasar!</p>

### 입력 

 <p>The first line of input contains one integer n (1 ≤ n ≤ 1 000 000), the number of vertices of the graph. The second line contains n integers a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>.</p>

### 출력 

 <p>The first line of output should contain the number of connected components in the graph. Denote this number by m. Each of the following m lines should hold a description of one connected component. First a number k should be written: the size of the component. Then, an increasing sequence of k vertex numbers of the component should be written. The components should be listed in such order that the numbers of the first nodes of the components form an increasing sequence. In other words, if S and S′ are two connected components, u ∈ S, v ∈ S′ are their nodes with the smallest number and u < v, then the component S should be listed earlier than S′.</p>

