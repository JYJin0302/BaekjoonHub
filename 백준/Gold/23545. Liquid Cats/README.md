# [Gold III] Liquid Cats - 23545 

[문제 링크](https://acmicpc.net/problem/23545) 

### 성능 요약

메모리: 10908 KB, 시간: 36 ms

### 분류

너비 우선 탐색, 깊이 우선 탐색, 자료 구조, 분리 집합, 그래프, 그래프 탐색, 매개 변수 탐색

### 제출 일자

2024년 06월 06일 14:39:26

### 문제 설명

<p>It is well known that when cats get into a hollow vessels they demonstrate properties of a liquid.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 600px; height: 179px;"></p>

<p>Mathematician Petrov often observed this phenomena by example of his cats and even conducted a series of experiments constructing different kinds of vessels and putting cats into them. It turned out that cats always choose their position to be as low as possible, more precisely --- to minimize level of highest point of their body. In case of several pits in the vessel, cats choose the lowest one but only from those in which they would fit.</p>

<p>A brilliant thought came into Petrov's head: in fact, cats can be used as an analog computers for solving some problems of quantum optimization! To check his hypothesis, mathematician Petrov developed the following mathematical model:</p>

<p>Let's imagine a vessel as a table $T$ of size $n \times m$. Some cells are walls, the rest of the cells are empty. A placement of a cat in the vessel is <em>optimal</em> if the following conditions met:</p>

<ol>
	<li>The cat occupies several empty cells. And all of the cells occupied by the cat form a <em>connected</em> shape of $k$ cells. A shape is connected if each of its cells can be reached from any other cell by moving through adjacent by-side cells (and all the transitional cells are also occupied by the cat).</li>
	<li>Level of the highest cell $h$ occupied by the cat should be as low as possible. Rows of the table are numbered from $1$ to $n$ and a row is higher if its number is less.</li>
</ol>

<p>Unfortunately, mathematician Petrov is not skilled in programming. He asks you to determine the height of the highest cell $h$ occupied by a cat for a given table $T$ and a cat's volume $k$.</p>

### 입력 

 <p>The first line contains integers $n$, $m$, and $k$ ($1 \le n,m \le 1000$, $1 \le k \le 10^6$).</p>

<p>The following $n$ lines contain $m$ symbols each --- a description of table $T$. The $j$-th symbol of the $i$-th row corresponds to a cell on intersection of the $i$-th row and the $j$-th column of $T$. "<code>\#</code>" means that this cell is a wall, and "<code>.</code>" means that this cell is empty.</p>

### 출력 

 <p>Output the number of a row which contains the highest occupied cell for any optimal placement of a cat. If a cat cannot by placed in vessel, output "<code>-1</code>" (without quotes).</p>

