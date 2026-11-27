# [Diamond V] Same Color - 17974 

[문제 링크](https://acmicpc.net/problem/17974) 

### 성능 요약

메모리: 5408 KB, 시간: 32 ms

### 분류

다이나믹 프로그래밍, 자료 구조, 세그먼트 트리

### 제출 일자

2023년 09월 13일 23:23:12

### 문제 설명

<p>There are <em>n</em> distinct points with <em>m</em> colors on the line, where <em>m</em> ≤ <em>n</em>. Let <em>S</em> be the set of those points. We want to select a non-empty subset <em>C</em> ⊆ <em>S</em> that satisfies the following:</p>

<blockquote>
<p>For every point <em>p</em> in <em>S</em> - <em>C</em>, not belonging to <em>C</em>, the closest point of <em>p</em> among points in <em>C</em> has the same color as <em>p</em>. Of course, if there are more than one closest point of <em>p</em> in <em>C</em>, then it is sufficient that one of them has the same color as <em>p</em>.</p>
</blockquote>

<p>For example, there are six points labeled by 1 to 6 with two colors in Figure G.1. Points 4 and 5 are red and the others blue. The set {2, 4, 6} satisfies the above property. But the set {2, 4} does not satisfy the property, because the closest point of point 6 in {2, 4} is point 4, which is different from the color of point 6. In fact, the set {2, 4, 6} is a minimum cardinality subset to satisfy the property.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 373px; height: 60px;"></p>

<p style="text-align: center;">Figure G.1: Six colored points on a line</p>

<p>Given <em>n</em> distinct points on the line and <em>m</em> their colors, write a program to find a non-empty subset <em>C</em> of <em>S</em> with minimum cardinality satisfying the above property and to output the minimum cardinality.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing two integers, <em>m</em> and <em>n</em> (1 ≤ <em>m</em> ≤ <em>n</em> ≤ 100,000), where <em>m</em> is the number of colors and <em>n</em> is the number of points. The points are numbered 1 to <em>n</em> from left to right on the line, and the colors are numbered 1 to <em>m</em>. The second line contains a sequence of sorted <em>n</em> integers in increasing manner, where the <em>i</em>-th number is the coordinate of the point <em>i</em>. The coordinates <em>x</em> of points satisfy 0 ≤ x ≤ 10<sup>9</sup> and are all distinct. The third line contains a sequence of <em>n</em> integers, where the <em>i</em>-th number is the color of the point <em>i</em>, which is between 1 and <em>m</em>.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the minimum cardinality of a non-empty subset <em>C</em> of <em>S</em> to satisfy the above property.</p>

