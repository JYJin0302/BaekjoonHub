# [Platinum III] 완전 이진 트리 - 3038 

[문제 링크](https://acmicpc.net/problem/3038) 

### 성능 요약

메모리: 4084 KB, 시간: 4 ms

### 분류

애드 혹, 해 구성하기, 트리

### 제출 일자

2024년 10월 08일 21:20:16

### 문제 설명

<p>A complete binary tree is made of nodes arranged in a hierarchic structure. One of the nodes is the root node, said to be at level 0. The root node has two child nodes, which are at level 1. Each of those has two children at level 2 etc.</p>

<p>In general, a complete binary tree with N levels has 2<sup>N</sup>–1 nodes, each of which has two child nodes, except those at level L–1. </p>

<p>A number can be written into each node. Write the numbers 1 to 2<sup>N</sup>–1 into a complete binary tree with N levels so that, for each node at level D, the absolute value of the difference of the sum of all numbers in the left subtree and the sum of all numbers in the right subtree is 2<sup>D</sup>. </p>

<p>For example, the sum of the left subtree of the root node must differ from the sum of the right subtree by 1. The sums of the left and right subtrees of a node at level 1 must differ by 2. </p>

<p>Each number must be used exactly once. The solution need not be unique. </p>

### 입력 

 <p>The first and only line of input contains the integer N (1 ≤ N ≤ 15), the number of levels in the tree. </p>

<p> </p>

### 출력 

 <p>Output the 2<sup>N</sup>–1 separated by spaces on a single line, the binary tree in the preorder traversal. The preorder traversal first outputs the number in the root node, then outputs the left subtree (again in the preorder traversal), then the right subtree. </p>

