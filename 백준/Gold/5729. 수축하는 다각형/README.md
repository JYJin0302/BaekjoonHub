# [Gold II] 수축하는 다각형 - 5729 

[문제 링크](https://acmicpc.net/problem/5729) 

### 성능 요약

메모리: 3604 KB, 시간: 544 ms

### 분류

자료 구조, 기하학, 해시를 사용한 집합과 맵, 누적 합, 집합과 맵

### 제출 일자

2024년 06월 14일 14:30:07

### 문제 설명

<p>A polygon is said to be inscribed in a circle when all its vertices lie on that circle. In this problem you will be given a polygon inscribed in a circle, and you must determine the minimum number of vertices that should be removed to transform the given polygon into a regular polygon, i.e., a polygon that is equiangular (all angles are congruent) and equilateral (all edges have the same length).</p>

<p>When you remove a vertex v from a polygon you ﬁrst remove the vertex and the edges connecting it to its adjacent vertices w1 and w2, and then create a new edge connecting w1 and w2. Figure (a) below illustrates a polygon inscribed in a circle, with ten vertices, and ﬁgure (b) shows a pentagon (regular polygon with ﬁve edges) formed by removing ﬁve vertices from the polygon in (a).</p>

<p><img alt="" src="" style="height:186px; width:386px"></p>

<p>In this problem, we consider that any polygon must have at least three edges.</p>

### 입력 

 <p>The input contains several test cases. The ﬁrst line of a test case contains one integer N indicating the number of vertices of the inscribed polygon (3 ≤ N ≤ 10<sup>4</sup>). The second line contains N integers X<sub>i</sub> separated by single spaces (1 ≤ X<sub>i</sub> ≤ 10<sup>3</sup>, for 0 ≤ i ≤ N − 1). Each Xi represents the length of the arc deﬁned in the inscribing circle, clockwise, by vertex i and vertex (i + 1) mod N. Remember that an arc is a segment of the circumference of a circle; do not mistake it for a chord, which is a line segment whose endpoints both lie on a circle.</p>

<p>The end of input is indicated by a line containing only one zero.</p>

<p>The input must be read from standard input.</p>

### 출력 

 <p>For each test case in the input, your program must print a single line, containing the minimum number of vertices that must be removed from the given polygon to form a regular polygon. If it is not possible to form a regular polygon, the line must contain only the value -1.</p>

<p>The output must be written to standard output.</p>

