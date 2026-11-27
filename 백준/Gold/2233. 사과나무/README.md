# [Gold II] 사과나무 - 2233 

[문제 링크](https://acmicpc.net/problem/2233) 

### 성능 요약

메모리: 2160 KB, 시간: 0 ms

### 분류

자료 구조, 그래프, 최소 공통 조상, 스택, 트리

### 제출 일자

2021년 09월 22일 22:24:06

### 문제 설명

<p>Figure 1 shows an apple tree in which each node has exactly one apple and every internal node has at least two children nodes.</p>

<p><img alt="" src="" style="height:250px; width:320px"></p>

<p>Figure 1</p>

<p>Consider a worm in the apple tree. The worm visits apples (i.e., nodes) following the order of depth-first traversal from the root of the apple tree. (Notice that, the branching priority of an internal node is left-first order.) Figure 2 shows a binary representation of the depth-first traversal by a worm in the apple tree.</p>

<p><img alt="" src="" style="height:176px; width:638px"></p>

<p>The binary representation is defined as follows: During the depth-first traversal,</p>

<ul>
	<li>“0” is printed, if a new node is visited, and</li>
	<li>“1” is printed, if a node is returned after visiting all descendent nodes.</li>
</ul>

<p>The second line of the table shows the first visited node corresponding to each “0” and the third line shows the returned node corresponding to each “1”. For example, the apple tree in Figure 1 can be represented by the definition above.</p>

<p><img alt="" src="" style="height:72px; width:556px"></p>

<p>If there are wormy apples in the apple tree, we should remove them. When we cut a node z, every apple in the subtree rooted at node z (including the apple of node z) is going down. For example, apples k, l, m, and n are going down by cutting node k and apples b, c, d, e, f, g and h are going down by cutting node b in the apple tree in Figure 1. In order to remove wormy apples, we should find the subtree rooted at a node in which every wormy apple exists, and then cut the node.</p>

<p>Given two wormy apples (possibly same) in an apple tree, the problem is to find a node satisfying that two wormy apples must drop and the minimum number of normal apples drop simultaneously by cutting the node. For example, suppose that nodes c and f are given as wormy apples in the apple tree in Figure 1. By cutting nodes a or b , two wormy apples can be removed. However, the smaller number of normal apples drop by cutting node b than the case that we cut node a. So, we want to find the node b.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case is composed of three lines. In first line, the number of nodes N ( 3 ≤ N ≤ 2000 ) is given. In next second line, 2N binary representation of an apple tree is given. There is no space between each representation. In last third line, two indices A and B ( 1 ≤ A, B ≤ 2N ) corresponding to two wormy apples in the binary representation are given. These two indices are not corresponding to node directly but index of binary representation. Notice that, the value of each index can be “0” or “1”.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. For each test case, find a node satisfying that the wormy apples must be removed and the minimum number of normal apples are removed simultaneously by cutting the node, and then print an index of “0” where the node was first visited and the other index of “1” where the node was returned in the binary representation. Print exactly one line for each test case index of “0” first, and index of “1” later. And there must be a single space between two indices.</p>

