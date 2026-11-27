# [Diamond IV] RotationAlmostSort - 19815 

[문제 링크](https://acmicpc.net/problem/19815) 

### 성능 요약

메모리: 2532 KB, 시간: 0 ms

### 분류

애드 혹

### 제출 일자

2026년 01월 07일 19:31:28

### 문제 설명

<p>A robot can execute a sequence of commands in an $n \times n$ square filled with numbers. The only type of command the robot can execute is:</p>

<p style="text-align: center;"><code>[cell 1] > [cell 2] ? [cell 3]</code></p>

<p>Such command has the following effect: if the number in cell 1 is greater than the number in cell 2, then rotate counterclockwise a $2 \times 2$ square whose upper left corner is cell 3.</p>

<p>Each cell is described with a letter denoting its column and a digit denoting its row, concatenated without a space. The columns are marked from left to right staring with <code>a</code>, the rows are marked from top to bottom starting with 1.</p>

<p>If one of the cells in one of the commands doesn't fit into the $n \times n$ square, or if cell 3 is located in the bottommost row or the rightmost column, then the robot becomes broken.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 334px; height: 82px;"></p>

<p style="text-align: center;">An example of a single command execution. The condition is true ($9 > 1$), therefore the rotation is made.</p>

<p>After the execution of the entire program, the bottommost $n-2$ rows are written down concatenated in the order from top to bottom (the 3-rd row, the 4-th row, $\ldots$, the $n$-th row). The resulting sequence consisting of $n\cdot(n-2)$ numbers must be non-decreasing.</p>

<p>You are given an integer $n$. Output a program containing only commands of the described type, such that when a robot executes this program on any initial square with numbers, it doesn't become broken and makes the square satisfy the desired state.</p>

### 입력 

 <p>The first line contains a positive integer $n$ ($2 \le n \le 9$) --- the size of the square with numbers.</p>

### 출력 

 <p>Output a correct program. It must contain no more than $100\,000$ commands. Follow the output format shown in the example.</p>

