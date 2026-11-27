# [Diamond IV] 제주도 - 3903 

[문제 링크](https://acmicpc.net/problem/3903) 

### 성능 요약

메모리: 2036 KB, 시간: 228 ms

### 분류

이분 탐색, 기하학, 반평면 교집합

### 제출 일자

2023년 10월 06일 09:53:04

### 문제 설명

<p>The main land of Japan called Honshu is an island surrounded by the sea. In such an island, it is natural to ask a question: “Where is the most distant point from the sea?” The answer to this question for Honshu was found in 1996. The most distant point is located in former Usuda Town, Nagano Prefecture, whose distance from the sea is 114.86km.</p>

<p>In this problem, you are asked to write a program which, given a map of an island, ﬁnds the most distant point from the sea in the island, and reports its distance from the sea. In order to simplify the problem, we only consider maps representable by convex polygons.</p>

### 입력 

 <p>The input consists of multiple datasets. Each dataset represents a map of an island, which is a convex polygon. The format of a dataset is as follows.</p>

<pre>n
x<sub>1</sub> y<sub>1</sub>
...
x<sub>n</sub> y<sub>n</sub></pre>

<p>Every input item in a dataset is a non-negative integer. Two input items in a line are separated by a space.</p>

<p>n in the first line is the number of vertices of the polygon, satisfying 3 ≤ n ≤ 100. Subsequent n lines are the x- and y-coordinates of the n vertices. Line segments (xi, yi)–(xi+1, yi+1) (1 ≤ i ≤ n − 1) and the line segment (xn, yn)–(x1, y1) form the border of the polygon in counterclockwise order. That is, these line segments see the inside of the polygon in the left of their directions. All coordinate values are between 0 and 10000, inclusive.</p>

<p>You can assume that the polygon is simple, that is, its border never crosses or touches itself. As stated above, the given polygon is always a convex one.</p>

<p>The last dataset is followed by a line containing a single zero</p>

### 출력 

 <p>For each dataset in the input, one line containing the distance of the most distant point from the sea should be output. An output line should not contain extra characters such as spaces.</p>

<p>The answer should not have an error greater than 0.00001 (10<sup>−5</sup>). You may output any number of digits after the decimal point, provided that the above accuracy condition is satisﬁed.</p>

