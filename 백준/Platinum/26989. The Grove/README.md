# [Platinum III] The Grove - 26989 

[문제 링크](https://acmicpc.net/problem/26989) 

### 성능 요약

메모리: 2220 KB, 시간: 0 ms

### 분류

애드 혹, 너비 우선 탐색, 비트마스킹, 기하학, 그래프, 그래프 탐색

### 제출 일자

2024년 04월 06일 18:16:07

### 문제 설명

<p>The pasture contains a small, contiguous grove of trees that has no 'holes' in the middle of the it. Bessie wonders: how far is it to walk around that grove and get back to my starting position? She's just sure there is a way to do it by going from her start location to successive locations by walking horizontally, vertically, or diagonally and counting each move as a single step. Just looking at it, she doesn't think you could pass 'through' the grove on a tricky diagonal. Your job is to calculate the minimum number of steps she must take.</p>

<p>Happily, Bessie lives on a simple world where the pasture is represented by a grid with R rows and C columns (1 ≤ R ≤ 50, 1 ≤ C ≤ 50). Here's a typical example where '.' is pasture (which Bessie may traverse), 'X' is the grove of trees, '*' represents Bessie's start and end position, and '+' marks one shortest path she can walk to circumnavigate the grove (i.e., the answer):</p>

<pre>...+...
..+X+..
.+XXX+.
..+XXX+
..+X..+
...+++*</pre>

<p>The path shown is not the only possible shortest path; Bessie might have taken a diagonal step from her start position and achieved a similar length solution. Bessie is happy that she's starting 'outside' the grove instead of in a sort of 'harbor' that could complicate finding the best path.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: R and C</li>
	<li>Lines 2..R+1: Line i+1 describes row i with C characters (with no spaces between them).</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: The single line contains a single integer which is the smallest number of steps required to circumnavigate the grove.</li>
</ul>

