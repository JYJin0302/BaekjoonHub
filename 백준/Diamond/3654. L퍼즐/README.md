# [Diamond IV] L퍼즐 - 3654 

[문제 링크](https://acmicpc.net/problem/3654) 

### 성능 요약

메모리: 61012 KB, 시간: 264 ms

### 분류

2-SAT, 그래프, 강한 연결 요소

### 제출 일자

2024년 04월 20일 20:12:03

### 문제 설명

<p>Tom has developed a special kind of puzzle: it involves a whole bunch of identical puzzle pieces. The pieces have the shape of three adjoint squares in an L-shape. The corner square is black, the two adjacent squares are white.</p>

<p><img alt="" src="" style="height:137px; width:132px"></p>

<p>The puzzler is given a pattern of black and white squares in a rectangular grid. The challenge is to create that pattern using these pieces. The pieces can be rotated, but must not overlap.</p>

<p>Tom has already designed a few nice patterns, but he needs to ﬁnd out if they can be constructed with the pieces at all. Rather than trying to test this for each pattern by hand, he wants to write a computer program to determine this for him. Can you help him?</p>

### 입력 

 <p>On the ﬁrst line a positive integer: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>one line with two integers n and m (1 ≤ n, m ≤ 500): the height and width of the grid containing the pattern, respectively.</li>
	<li>n lines, each containing m characters, denoting the grid. Each character is ‘B’, ‘W’, or ‘.’, indicating a black, white or empty square respectively.</li>
</ul>

<p>The grid contains at least one black or white square.</p>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>one line with either “YES” or “NO”, indicating whether or not it is possible to construct the pattern with the puzzle pieces. You may assume that there is an inﬁnite supply of pieces.</li>
</ul>

