# [Silver I] 보드 점프 - 3372 

[문제 링크](https://acmicpc.net/problem/3372) 

### 성능 요약

메모리: 29340 KB, 시간: 84 ms

### 분류

임의 정밀도 및 큰 수 연산, 다이나믹 프로그래밍

### 제출 일자

2020년 10월 27일 17:16:41

### 문제 설명

<p>An n × n game board is populated with integers, one nonnegative integer per square. The goal is to jump along any legitimate path from the upper left corner to the lower right corner of the board. The integer in any one square dictates how large a step away from that location must be. If the step size would advance travel off the game board, then a step in that particular direction is forbidden. All steps must be either to the right or toward the bottom. Note that a 0 is a dead end which prevents any further progress.</p>

<p>Consider the 4 × 4 board shown in Figure 1, where the solid circle identifies the start position and the dashed circle identifies the target. Figure 2 shows the three legitimate paths from the start to the target, with the irrelevant numbers in each removed.</p>

<table class="table table-bordered td-center">
	<tbody>
		<tr>
			<td><img alt="" src="" style="width: 98px; height: 96px;"></td>
			<td><img alt="" src="" style="width: 320px; height: 96px;"></td>
		</tr>
		<tr>
			<td>Figure 1</td>
			<td>Figure 2</td>
		</tr>
	</tbody>
</table>

<p>Your task is to write a program that determines the number of legitimate paths from the upper left corner to the lower right corner.</p>

### 입력 

 <p>The input contains a first line with a single positive integer n, 4 ≤ n ≤ 100, which is the number of rows in this board. This is followed by n rows of data. Each row contains n integers, each one from the range 0…9.</p>

### 출력 

 <p>The output should consist of a single line containing a single integer, which is the number of legitimate paths from the upper left corner to the lower right corner.</p>

<p>It is guaranteed that all inputs will lead to a number of legitimate paths that can be written with no more than 100 digits.</p>

