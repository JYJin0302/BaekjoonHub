# [Platinum I] The Farthest Point - 33004 

[문제 링크](https://acmicpc.net/problem/33004) 

### 성능 요약

메모리: 2036 KB, 시간: 4 ms

### 분류

3차원 기하학, 기하학, 삼분 탐색

### 제출 일자

2024년 12월 30일 14:16:38

### 문제 설명

<p>An ant is on one of the vertices, say the <em>starting</em> vertex, of a rectangular cuboid (a hexahedron with all of its faces being rectangular). The surface of the cuboid constitutes the entire world of the ant.</p>

<p>We’d like to know which point on the surface of the cuboid is the farthest for the ant from the starting vertex. You may think that the <em>opposite</em> vertex, that is, the opposite end of the interior diagonal from the starting vertex, is the farthest. The opposite vertex is, however, not necessarily the farthest.</p>

<p>For example, on the surface of a cuboid of size $1 \times 1 \times 2$, the distance from a vertex to the opposite vertex is the square root of $8$. The distance to the farthest point is, however, the square root of $65/8$ (Figure F.1).</p>

<p style="text-align: center;"><img alt="" src="" style="width: 572px; height: 250px;"></p>

<p style="text-align: center;">Figure F.1. Rectangular cuboid of size $1 \times 1 \times 2$, and its net</p>

<p>You are given the size of the rectangular cuboid. Write a program which calculates the distance from the starting vertex to the farthest point.</p>

### 입력 

 <p>The input consists of a single test case of the following format.</p>

<blockquote>
<p>$a$ $b$ $c$</p>
</blockquote>

<p>The three integers $a$, $b$, and $c$ mean that the size of the rectangular cuboid is $a \times b \times c$. All of them are between $1$ and $100$, inclusive.</p>

### 출력 

 <p>Output a line containing the distance from the starting vertex to the farthest point. The relative error of the output must be less than or equal to $10^{-9}$.</p>

