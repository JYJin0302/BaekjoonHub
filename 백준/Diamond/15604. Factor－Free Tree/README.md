# [Diamond IV] Factor-Free Tree - 15604 

[문제 링크](https://acmicpc.net/problem/15604) 

### 성능 요약

메모리: 55944 KB, 시간: 1216 ms

### 분류

분할 정복, 수학, 정수론, 에라토스테네스의 체, 소수 판정, 작은 집합에서 큰 집합으로 합치는 테크닉

### 제출 일자

2023년 11월 21일 12:22:37

### 문제 설명

<p>A factor-free tree is a rooted binary tree where every node in the tree contains a positive integer value that is coprime with all of the values of its ancestors. Two positive integers are coprime if their greatest common divisor equals 1.</p>

<p>The inorder sequence of a rooted binary tree can be generated recursively by traversing first the left subtree, then the root, then the right subtree. See Figure F.1 below for the inorder sequence of one factor-free tree.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 265px; height: 215px;"></p>

<p style="text-align: center;">Figure F.1: Illustration of Sample 1. The tree is factor-free; for example, the value of the node marked “5” is coprime with all of the values of its ancestors, marked “9”, “8”, and “7”.</p>

<p>Given a sequence a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>n</sub>, decide if it is the inorder sequence of some factor-free tree and if so construct such a tree.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with one integer n (1 ≤ n ≤ 10<sup>6</sup>), the length of the sequence.</li>
	<li>One line with n integers a<sub>1</sub>, . . . , a<sub>n</sub> (1 ≤ a<sub>i</sub> ≤ 10<sup>7</sup> for each i), the elements of the sequence.</li>
</ul>

### 출력 

 <p>If there exists a factor-free tree whose inorder sequence is the given sequence, output n values. For each value in the sequence, give the 1-based index of its parent, or 0 if it is the root. If there are multiple valid answers, print any one of them.</p>

<p>If no such tree exists, output “impossible” instead</p>

