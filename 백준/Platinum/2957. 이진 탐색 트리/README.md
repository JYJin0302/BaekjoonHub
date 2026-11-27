# [Platinum V] 이진 탐색 트리 - 2957 

[문제 링크](https://acmicpc.net/problem/2957) 

### 성능 요약

메모리: 17320 KB, 시간: 164 ms

### 분류

자료 구조, 집합과 맵, 트리를 사용한 집합과 맵

### 제출 일자

2025년 09월 03일 10:42:40

### 문제 설명

<p>A binary search tree is a tree in which every node has at most two children nodes (a left and a right child). Each node has an integer written inside it. If the number X is written inside a node, then the numbers in its left subtree are less than X and the numbers in its right subtree are greater than X. </p>

<p>You will be given a sequence of integers between 1 and N (inclusive) such that each number appears in the sequence exactly once. You are to create a binary search tree from the sequence, putting the first number in the root node and inserting every other number in order. In other words, run insert(X, root) for every other number: </p>

<pre>insert( number X, node N ) 
    increase the counter C by 1 
    if X is less than the number in node N 
        if N has no left child 
            create a new node with the number X and set it to be the left child of node N 
        else 
            insert(X, left child of node N) 
    else (X is greater than the number in node N) 
        if N has no right child 
            create a new node with the number X and set it to be the right child of node N 
        else 
            insert(X, right child of node N) 
</pre>

<p>Write a program that calculates the value of the counter C after every number is inserted. The counter is initially 0.</p>

### 입력 

 <p>The first line contains the integer N (1 ≤ N ≤ 300000), the length of the sequence. </p>

<p>The remaining N lines contain the numbers in the sequence, integers in the interval [1, N]. The numbers will be distinct.</p>

### 출력 

 <p>Output N integers each on its own line, the values of the counter C after each number is inserted into the tree. </p>

