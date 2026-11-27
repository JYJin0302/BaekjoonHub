# [Platinum III] Easily Distinguishable Triangles - 26867 

[문제 링크](https://acmicpc.net/problem/26867) 

### 성능 요약

메모리: 3016 KB, 시간: 28 ms

### 분류

조합론, 수학

### 제출 일자

2023년 07월 15일 22:03:33

### 문제 설명

<p>Eva loves painting. Today she is working with a square canvas of $n \times n$ unit cells. Each cell is painted white, painted black, or empty --- not painted at all.</p>

<p>Eva is going to draw a black triangle inside each empty cell. She wants each triangle to be right-angled and have an area of $\frac{1}{2}$ square unit cells. Thus, there are four ways to draw a single triangle:</p>

<p style="text-align: center;"><img alt="" src="" style="width: 325px; height: 57px;"></p>

<p>Each triangle is a piece of art, and Eva wants them to be easily distinguishable from the rest of the painting. To achieve that, no two black triangles may share a common side with each other, and no black triangle may share a common side with a black square. Note that two black squares are allowed to share a common side.</p>

<p>Help Eva to find out how many ways there are to finish her painting. Since the number can be large, calculate it modulo $998\,244\,353$.</p>

### 입력 

 <p>The first line contains a single integer $n$ --- the side length of the canvas ($1 \le n \le 1000$).</p>

<p>The next $n$ lines describe the canvas from top to bottom. The $i$-th of these lines contains $n$ characters $s_{i, 1}, s_{i, 2}, \ldots, s_{i, n}$. If $s_{i, j} =$ '<code>.</code>', the cell in the $i$-th row and the $j$-th column of the canvas is painted white. If $s_{i, j} =$ '<code>#</code>', that cell is painted black. If $s_{i, j} =$ '<code>?</code>', that cell is empty.</p>

### 출력 

 <p>Print a single integer denoting the number of ways to finish Eva's painting, modulo $998\,244\,353$.</p>

