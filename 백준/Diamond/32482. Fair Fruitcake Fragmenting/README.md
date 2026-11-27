# [Diamond III] Fair Fruitcake Fragmenting - 32482 

[문제 링크](https://acmicpc.net/problem/32482) 

### 성능 요약

메모리: 26572 KB, 시간: 188 ms

### 분류

많은 조건 분기, 기하학, 스위핑

### 제출 일자

2026년 01월 06일 13:52:29

### 문제 설명

<p>Frida's birthday is just coming up, and as her best friend, you obviously baked a cake for her. Since you know that Frida loves rotational symmetry, you thought to bake a cake that looks the same from above when rotated by $180^\circ$. Of course, you could have simply baked a boring round cake, but without a perfectly round cake tin, this sounds easier than done. Therefore, you decided to bake a cake whose shape can be described by straight line segments.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 397px; height: 400px;"></p>

<p style="text-align: center;">Figure F.1: Visualization of Sample Input 2. The swirly cake looking like an <em>S</em> can be cut into the red and blue part with a single cut.</p>

<p>However, after you are done with your cake, you notice that you also want to cut the cake into two equal pieces, one for Frida and one for yourself. More precisely, you wonder if it is possible to cut the cake along an infinite line such that it splits into exactly two parts of equal weight. You can assume that the cake has uniform density and height.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line containing an <em>even</em> integer $n$ ($4 \leq n\leq 10^5$), the number of points needed to describe the cake's shape.</li>
	<li>$n$ lines, each containing two integers $x$, $y$ ($0\leq x,y \leq 10^6$), the $x$ and $y$ coordinates of a point on the border of the cake's shape.</li>
</ul>

<p>The following additional guarantees are given for the shape of the cake:</p>

<ul>
	<li>The cake has a $180^\circ$ rotational symmetry.</li>
	<li>The points are given in counterclockwise order.</li>
	<li>No three consecutive points are collinear.</li>
	<li>The shape is simple (no segments intersect and only consecutive segments touch at their ends).</li>
</ul>

### 출력 

 <p>Output two different points on the desired line as $x_1$<code>/</code>$c_1$<code> </code>$y_1$<code>/</code>$d_1$<code> </code>$x_2$<code>/</code>$c_2$<code> </code>$y_2$<code>/</code>$d_2$, where $|x_i|$, $|y_i|$, $|c_i|$ and $|d_i|$ are integers and at most $10^9$, and $x_i$<code>/</code>$c_i$ is the first coordinate of point $i$ and $y_i$<code>/</code>$d_i$ is the second ($1\leq i\leq2$). If the denominator of a fraction is $1$ you may output only the numerator. Fractions do not have to be reduced. If there is no such line, output "<code>impossible</code>" instead.</p>

<p>It can be shown that if there is a line as desired, it is possible to represent it in the given format.</p>

