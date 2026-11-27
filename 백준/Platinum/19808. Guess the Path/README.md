# [Platinum II] Guess the Path - 19808 

[문제 링크](https://acmicpc.net/problem/19808) 

### 성능 요약

메모리: 13824 KB, 시간: 248 ms

### 분류

이분 탐색, 분할 정복

### 제출 일자

2026년 01월 07일 19:31:07

### 문제 설명

<p>You are going to take part in robot programming contest. You will have to launch robots to a special field that has detectors at some cells. The jury has chosen one of the shortest paths on the field and you have to find it.</p>

<p>The field is a grid rectangle with $m$ rows and $n$ columns. Let us denote the cell at the $i$-th row and the $j$-th column as $(i, j)$ ($1 \le i \le m$, $1 \le j \le n$). Every path that the robot can be launched along must start at the top-left cell of the grid which has coordinates $(1, 1)$, pass some cells of the field, and end at the bottom-right cell which has coordinates $(m, n)$.</p>

<p>In one step the robot can move one cell down, or one cell to the right. Therefore if the robot is at the cell $(i, j)$, it can move to the cell $(i + 1, j)$ or to the cell $(i, j + 1)$. The robot cannot move outside of the field. The path of the robot consists of $m + n - 2$ steps, so it moves from the cell $(1, 1)$ to the cell $(m, n)$ visiting some other cells.</p>

<p>The jury has chosen one of the possible robot paths. This path is not known to participants. Each cell that belongs to the path chosen by the jury has special detector installed in it. When the robot enters the cell with the detector, the detector reports that the cell was visited.</p>

<p>The participant can launch the robot along any allowed path from $(1, 1)$ to $(m, n)$. After every launch the jury tells the participant which cells that have detectors installed have reported that the cell was visited. Your task is to launch the robot at most $10$ times, and find out the path that the judges have chosen.</p>

### 입력 

 Empty

### 출력 

 Empty

