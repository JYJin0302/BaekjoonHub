# [Diamond IV] Genealogy of Puppets - 24963 

[문제 링크](https://acmicpc.net/problem/24963) 

### 성능 요약

메모리: 219348 KB, 시간: 196 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 09월 18일 16:47:20

### 문제 설명

<p>The <em>Inventive and Creative Puppets Corporation (ICPC)</em> sells a variety of educational <em>puppets</em> for children, and also for grown-ups who were once children and still remember it. To celebrate its centennial anniversary, ICPC has decided to offer for sale a collection of many of its most popular puppets in its history of one hundred years, which will be a collectors’ envy for sure.</p>

<p>Each puppet has a ring attached to its head, with which it can be hung below one of two toes of another puppet. At most one puppet can be hung on one toe. As puppets do not feel comfortable in handstand positions, loops of puppets should be avoided. A <em>tree</em> of puppets can thus be made by hanging all the puppets to a toe of another puppet, leaving the ring of the topmost puppet to be hung on the wall.</p>

<p>You are enthusiastic in ICPC puppets since childhood. You like imagining genealogies of the puppets, assuming that puppets are hung on a parent puppet. You also imagine personalities of puppets, and decided to obey the following rules on forming the tree:</p>

<ul>
	<li>each puppet has its own constraints on the number of children, that are its minimum and maximum, and</li>
	<li>if a puppet has any children, at least one of them should have release date later than the parent.</li>
</ul>

<p>Note that, if a puppet has two children, one of them may have its release date earlier than the parent.</p>

<p>You want to write a program to calculate how many <em>different</em> trees can be made by the collection, satisfying the rules. Two trees are considered different if any of the puppets are hung on different parents, or hung on different toes of the same parent.</p>

### 입력 

 <p>The input consists of a single test case of the following format.</p>

<p>$\begin{align*}& n \\ & x_1 \, y_1 \\ & \vdots \\ &x_n \, y_n \end{align*}$</p>

<p>The first line contains an integer $n$ ($2 ≤ n ≤ 300$), representing the number of puppets. The $i$-th line of the following $n$ lines describes the personality of a puppet. Lines are in the order of the release dates of the puppets, from older to newer. Two integers in the line, $x_i$ and $y_i$, are the minimum number and the maximum number of children of the puppet, respectively. $0 ≤ x_i ≤ y_i ≤ 2$ holds.</p>

### 출력 

 <p>Output a single integer in a line which is the number of the different trees satisfying the rules modulo $10^9 + 7$.</p>

