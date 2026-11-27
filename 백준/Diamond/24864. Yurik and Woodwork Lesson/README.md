# [Diamond V] Yurik and Woodwork Lesson - 24864 

[문제 링크](https://acmicpc.net/problem/24864) 

### 성능 요약

메모리: 4388 KB, 시간: 0 ms

### 분류

조합론, 수학

### 제출 일자

2026년 01월 22일 14:49:57

### 문제 설명

<p>Today Yurik got up early in the morning with a great joy because, according to the schedule, the first lesson in school is a woodwork lesson. It is the favorite Yurik's lesson because he usually ignores teacher and plays board games with his friends at the back of the classroom in this lesson. But he was disappointed when it turned out that the test would take place today.</p>

<p>At the beginning of the lesson the teacher handed out wooden boards of size $N \times M$ to each student, including Yurik. Using lines drawn in pencil, the board is divided into $N$ rows and $M$ columns in such way that it consists of $N \cdot M$ square cells of size $1 \times 1$.</p>

<p>The test is to cut out some cells from the the board using a jigsaw in such way that the the resulting part of the board is <em>nice</em>.</p>

<p>The board is called <em>nice</em> if the following five conditions are satisfied:</p>

<ol>
	<li>The upper-left cell of the board wasn't cut away.</li>
	<li>The lower-right cell of the board wasn't cut away.</li>
	<li>The resulting board is a connected area of cells. It means that every cell can be reached from any other cell using some number of steps. In one step we can move to the adjacent cell to the left, right, top or bottom.</li>
	<li>For each row of the resulting board the following condition is satisfied: all cells in this row that weren't cut from the board, form a continuous horizontal segment of cells.</li>
	<li>For each column of the resulting board the following condition is satisfied: all cells in this column that weren't cut from the board, form a continuous vertical segment of cells.</li>
</ol>

<p>Every board that doesn't satisfy at least one of these conditions is called <em>ugly</em>. Images below illustrate examples of nice and ugly boards. The upper-left and lower-right cells are painted grey.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 403px; height: 92px;"></p>

<p style="text-align: center;">Examples of nice boards of size $3 \times 4$</p>

<p style="text-align: center;"><img alt="" src="" style="width: 403px; height: 90px;"></p>

<p style="text-align: center;">Examples of ugly boards of size $3 \times 4$</p>

<p>Since Yurik never listens to his teacher and love mathematics, instead of doing the test, he wonders how many different nice boards can be obtained from the original board by cutting away some, possibly zero, number of cells? Two boards are considered different if sets of cut away cells are different.</p>

<p>Please, help Yurik to answer this question.</p>

### 입력 

 <p>The only input line contains two integers $N$ and $M$ --- dimensions of the original board ($1 \le N, M \le 10^5$).</p>

### 출력 

 <p>Print a single integer --- the number of different nice boards that Yurik can obtain by cutting away some cells from the original board.</p>

<p>As the answer can be very large, you should print it modulo $998\,244\,353$.</p>

