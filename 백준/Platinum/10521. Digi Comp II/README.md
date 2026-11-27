# [Platinum IV] Digi Comp II - 10521 

[문제 링크](https://acmicpc.net/problem/10521) 

### 성능 요약

메모리: 14516 KB, 시간: 172 ms

### 분류

방향 비순환 그래프, 다이나믹 프로그래밍, 그래프, 위상 정렬

### 제출 일자

2023년 10월 07일 21:36:30

### 문제 설명

<p>The Digi Comp II is a machine where balls enter from the top and find their way to the bottom via a certain circuit defined by switches. Whenever a ball falls on a switch it either goes to the left or to the right depending on the state of the switch and flips this state in the process. Abstractly it can be modelled by a directed graph with a vertex of outdegree 2 for each switch and in addition a designated end vertex of outdegree 0. One of the switch vertices is the start vertex, it has indegree 0. Each switch vertex has an internal state (L/R). A ball starts at the start vertex and follows a path down to the end vertex, where at each switch vertex it will pick the left or right outgoing edge based on the internal state of the switch vertex. The internal state of a vertex is flipped after a ball passes through. A ball always goes down and therefore cannot get into a loop.</p>

<p>One can “program” this machine by specifying the graph structure, the initial states of each switch vertex and the number of balls that enter. The result of the computation is the state of the switches at the end of the computation. Interestingly one can program quite sophisticated algorithms such as addition, multiplication, division and even the stable marriage problem. However, it is not Turing complete.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line with two integers n (0 ≤ n ≤ 10<sup>18</sup>) and m (1 ≤ m ≤ 500 000), the number of balls and the number of switches of the graph;</li>
	<li>m lines describing switches 1 to m in order. Each line consists of a single character c (‘L’ or ‘R’) and two integers L and R (0 ≤ L, R ≤ m), describing the initial state (c) of the switch and the destination vertex of the left (L) and right (R) outgoing edges. L and R can be equal.</li>
</ul>

<p>Vertex number 0 is the end vertex and vertex 1 is the start vertex. There are no loops in the graph, i.e., after going through a switch a ball can never return to it.</p>

### 출력 

 <p>Output one line with a string of length m consisting of the characters ‘L’ and ‘R’, describing the final state of the switches (1 to m in order).</p>

