# [Diamond IV] 공장들 - 11933 

[문제 링크](https://acmicpc.net/problem/11933) 

### 성능 요약

메모리: 85928 KB, 시간: 4140 ms

### 분류

센트로이드, 센트로이드 분할, 분할 정복, 최소 공통 조상, 트리, 트리 압축

### 제출 일자

2024년 05월 23일 20:17:08

### 문제 설명

<p>In IOI Kingdom, there are N cities numbered from 0 to N−1. These cities are connected by N−1 roads through which you can pass in both directions. You can travel from any city to any other city by passing through some of these roads.</p>

<p>In IOI Kingdom, there are many companies producing special components. Each company produces only one kind of components. No two companies produce the same kind of components. Each company has at least one factory. Each factory is built in one of the cities. More than one company may have factories in the same city.</p>

<p>Sometimes, a company requires components of another company. Assume the company C<sub>A</sub> requires the components of the company C<sub>B</sub> (C<sub>A</sub>, C<sub>B</sub>). In this case, they need to transport components from C<sub>B</sub> to C<sub>A</sub>. They may transport components from any of the factories of the company C<sub>B</sub> to any of the factories of the company C<sub>A</sub>. They need to choose factories appropriately to minimize the distance between factories.</p>

<p>First, the number of cities and the information of roads in IOI Kingdom are given. Then, Q queries are given. Each query is written in the following form: the company U<sub>j</sub> having factories in cities X<sub>j,0</sub>, . . . , X<sub>j,S<sub>j</sub>−1</sub> requires components of the company V<sub>j</sub> having factories in cities Y<sub>j,0</sub>, . . . , Y<sub>j,T<sub>j</sub>−1</sub>. Write a program which, for each query, returns the minimum distance to transport the components.</p>

<p>You are to write a program which implements procedures to answer the queries.</p>

<p>Your program should include the header file factories.h by #include "factories.h"</p>

<p>Your program should implement the following procedures.</p>

<ul>
	<li><code>void Init(int N, int A[], int B[], int D[])</code></li>
</ul>

<p>This procedure is called only once in the beginning. The parameter N is the number of cities in IOI Kingdom. The parameters A, B and D are arrays of length N − 1. The elements A[i], B[i] and D[i] are three integers A<sub>i</sub>, B<sub>i</sub> and D<sub>i</sub> (0 ≤ i ≤ N − 2) respectively. This means, for each i (0 ≤ i ≤ N − 2), there is a road of length D<sub>i</sub> connecting the city A<sub>i</sub> and the city B<sub>i</sub>.</p>

<ul>
	<li><code>long long Query(int S, int X[], int T, int Y[])</code></li>
</ul>

<p>This procedure is called for each of Q queries. In the query j, the parameters S and T are two integers S<sub>j</sub> and T<sub>j</sub> respectively. These are the numbers of cities where the companies U<sub>j</sub>, V<sub>j</sub> have factories respectively.</p>

<p>The parameter X is an array of length S<sub>j</sub>. The company U<sub>j</sub> has factories in cities X[0], X[1], . . . , X[S-1].</p>

<p>The parameter Y is an array of length T<sub>j</sub>. The company V<sub>j</sub> has factories in cities Y[0], Y[1], . . . , Y[T-1].</p>

<p>This procedure should return the minimum distance to transport components from the company V<sub>j</sub> to the company U<sub>j</sub>.</p>

### 입력 

 <ul>
	<li>The first line contains two space separated integers N, Q, which means there are N cities in IOI Kingdom, and Q queries are given to your program.</li>
	<li>The (i + 1)-st line (0 ≤ i ≤ N − 2) of the following (N − 1) lines contains three space separated integers Ai,Bi, Di, which means there is a road of length Di connecting the city Ai and the city Bi.</li>
	<li>The information of the j-th query is written from the (3j + 1)-st line to the (3j + 3)-rd line (0 ≤ j ≤ Q − 1) of the following 3Q lines.</li>
	<li>The (3j + 1)-st line (0 ≤ j ≤ Q − 1) contains two space separated integers S<sub>j</sub> and T<sub>j</sub> (1 ≤ S<sub>j</sub> ≤ N − 1, 1 ≤ T<sub>j</sub> ≤ N − 1), which means the companies U<sub>j</sub> and V<sub>j</sub> have factories in S<sub>j</sub> and T<sub>j</sub> cities respectively.</li>
	<li>The (3j + 2)-nd line (0 ≤ j ≤ Q − 1) contains S<sub>j</sub> space separated integers X<sub>j,0</sub>, . . . , X<sub>j,S<sub>j</sub>−1</sub>, which means the company U<sub>j</sub> has factories in the cities X<sub>j,0</sub>, . . . , X<sub>j,S<sub>j</sub>−1</sub>.</li>
	<li>The (3j + 3)-rd line (0 ≤ j ≤ Q − 1) contains T<sub>j</sub> space separated integers Y<sub>j,0</sub>, . . . , Y<sub>j,T<sub>j</sub>−1</sub>, which means the company Vj has factories in the cities Y<sub>j,0</sub>, . . . , Y<sub>j,T<sub>j</sub>−1</sub>.</li>
</ul>

<p>All input data satisfy the following conditions.</p>

<ul>
	<li>2 ≤ N ≤ 500 000.</li>
	<li>1 ≤ Q ≤ 100 000.</li>
	<li>0 ≤ A<sub>i</sub> ≤ N − 1 (0 ≤ i ≤ N − 2).</li>
	<li>0 ≤ B<sub>i</sub> ≤ N − 1 (0 ≤ i ≤ N − 2).</li>
	<li>1 ≤ D<sub>i</sub> ≤ 100 000 000 (0 ≤ i ≤ N − 2).</li>
	<li>A<sub>i</sub> , B<sub>i</sub> (1 ≤ i ≤ N − 2).</li>
	<li>You can travel from any city to any other city through some of these roads.</li>
	<li>1 ≤ S<sub>j</sub> ≤ N − 1 (0 ≤ j ≤ Q − 1).</li>
	<li>0 ≤ X<sub>j,k</sub> ≤ N − 1 (0 ≤ j ≤ Q − 1, 0 ≤ k ≤ S<sub>j</sub> − 1).</li>
	<li>1 ≤ T<sub>j</sub> ≤ N − 1 (0 ≤ j ≤ Q − 1).</li>
	<li>0 ≤ Y<sub>j,k</sub> ≤ N − 1 (0 ≤ j ≤ Q − 1, 0 ≤ k ≤ T<sub>j</sub> − 1).</li>
	<li>X<sub>j,0</sub>, X<sub>j,1</sub>, . . . , X<sub>j,S<sub>j</sub>−1</sub>, Y<sub>j,0</sub>, Y<sub>j,1</sub>, . . . , Y<sub>j,T<sub>j</sub>−1</sub> are different from each other (0 ≤ j ≤ Q − 1) ．</li>
	<li>S<sub>0</sub> + S<sub>1</sub> + · · · + S<sub>Q−1</sub> ≤ 1 000 000.</li>
	<li>T<sub>0</sub> + T<sub>1</sub> + · · · + T<sub>Q−1</sub> ≤ 1 000 000.</li>
</ul>

### 출력 

 <p>When the program terminates successfully, the sample grader writes to the standard output the values returned by Query one per line.</p>

