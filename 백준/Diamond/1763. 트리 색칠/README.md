# [Diamond II] 트리 색칠 - 1763 

[문제 링크](https://acmicpc.net/problem/1763) 

### 성능 요약

메모리: 14236 KB, 시간: 12 ms

### 분류

자료 구조, 분리 집합, 그리디, 우선순위 큐, 트리

### 제출 일자

2023년 09월 20일 17:03:30

### 문제 설명

<p>Bob is very interested in the data structure of a tree. A tree is a directed graph in which a special node is singled out, called the "root" of the tree, and there is a unique path from the root to each of the other nodes. </p>

<p>Bob intends to color all the nodes of a tree with a pen. A tree has N nodes, these nodes are numbered 1, 2, ..., N. Suppose coloring a node takes 1 unit of time, and after finishing coloring one node, he is allowed to color another. Additionally, he is allowed to color a node only when its father node has been colored. Obviously, Bob is only allowed to color the root in the first try. </p>

<p>Each node has a "coloring cost factor", C<sub>i</sub>. The coloring cost of each node depends both on C<sub>i</sub> and the time at which Bob finishes the coloring of this node. At the beginning, the time is set to 0. If the finishing time of coloring node i is F<sub>i</sub>, then the coloring cost of node i is C<sub>i</sub> * F<sub>i</sub>. </p>

<p>For example, a tree with five nodes is shown in Figure-1. The coloring cost factors of each node are 1, 2, 1, 2 and 4. Bob can color the tree in the order 1, 3, 5, 2, 4, with the minimum total coloring cost of 33. </p>

<p style="text-align: center;"><img alt="" src="" style="height:321px; width:342px"></p>

<p>Given a tree and the coloring cost factor of each node, please help Bob to find the minimum possible total coloring cost for coloring all the nodes.</p>

### 입력 

 <p>The first line of input contains two integers N and R (1 ≤ N ≤ 1000, 1 ≤ R ≤ N), where N is the number of nodes in the tree and R is the node number of the root node. The second line contains N integers, the i-th of which is C<sub>i</sub> (1 ≤ C<sub>i</sub> ≤ 500), the coloring cost factor of node i. Each of the next N-1 lines contains two space-separated node numbers V<sub>1</sub> and V<sub>2</sub>, which are the endpoints of an edge in the tree, denoting that V<sub>1</sub> is the father node of V<sub>2</sub>. No edge will be listed twice, and all edges will be listed. </p>

### 출력 

 <p>For each test case, output a line containing the minimum total coloring cost required for Bob to color all the nodes.</p>

