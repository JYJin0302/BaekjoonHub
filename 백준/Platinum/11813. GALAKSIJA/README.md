# [Platinum I] GALAKSIJA - 11813 

[문제 링크](https://acmicpc.net/problem/11813) 

### 성능 요약

메모리: 40576 KB, 시간: 204 ms

### 분류

자료 구조, 분리 집합, 해시를 사용한 집합과 맵, 오프라인 쿼리, 작은 집합에서 큰 집합으로 합치는 테크닉, 트리

### 제출 일자

2023년 07월 04일 11:32:47

### 문제 설명

<p>A long time ago in a galaxy far, far away, there were N planets. There were also N − 1 interplanetary paths that connected all the planets (directly or indirectly). In other words, the network of planets and paths formed a tree. Additionally, each path was enumerated with an integer that denoted the curiosity of the path.</p>

<p>A pair of planets A, B is boring if the following holds:</p>

<ul>
	<li>A and B are different planets</li>
	<li>travelling between planet A and B is possible using one or more interplanetary paths</li>
	<li>binary XOR of the curiosity of all the paths in that travel is equal to 0</li>
</ul>

<p>Alas, the times have changed and an evil emperor is ruling the galaxy. He decided to use the Force to destroy all the interplanetary paths in a certain order. Determine the number of boring pairs of planets before the emperor started the destruction and after each destruction.</p>

### 입력 

 <p>The first line of input contains the integer N (1 ≤ N ≤ 100 000).</p>

<p>Each of the following N − 1 line contains three integers A<sub>i</sub>, B<sub>i</sub>, Z<sub>i</sub> (1 ≤ A<sub>i</sub>, B<sub>i</sub> ≤ N, 0 ≤ Z<sub>i</sub> ≤ 1 000 000 000) that denote that planets A<sub>i</sub> and B<sub>i</sub> are directly connected with a path of curiosity Z<sub>i</sub>.</p>

<p>The following line of input contains the permutation of the first N − 1 integers that denote the order in which the emperor is destroying the paths. If the ith element of the permutation is j, then the emperor destroyed the path between planets A<sub>j</sub> and B<sub>j</sub> in the ith step.</p>

### 출력 

 <p>The output must contain N lines, the kth line containing the number of boring pairs A, B from the task after the emperor destroyed exactly k − 1 paths.</p>

