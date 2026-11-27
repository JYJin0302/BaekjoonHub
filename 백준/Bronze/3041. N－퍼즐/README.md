# [Bronze I] N-퍼즐 - 3041 

[문제 링크](https://acmicpc.net/problem/3041) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현

### 제출 일자

2024년 10월 08일 13:51:54

### 문제 설명

<p>N-puzzle is a puzzle that goes by many names and has many variants. In this problem we will use the 15-puzzle. It consists of a 4-by-4 grid of sliding squares where one square is missing. The squares are labeled with uppercase letters 'A' through 'O', with the desired layout as follows: </p>

<table class="table table-bordered" style="width:100px">
	<tbody>
		<tr>
			<td>A</td>
			<td>B</td>
			<td>C</td>
			<td>D</td>
		</tr>
		<tr>
			<td>E</td>
			<td>F</td>
			<td>G</td>
			<td>H</td>
		</tr>
		<tr>
			<td>I</td>
			<td>J</td>
			<td>K</td>
			<td>L</td>
		</tr>
		<tr>
			<td>M</td>
			<td>N</td>
			<td>O</td>
			<td>.</td>
		</tr>
	</tbody>
</table>


<p>It can be useful (for example, when solving the puzzle using a computer) to define the "scatter" of a puzzle as the sum of distances between each square's current position and its position in the desired layout. The distance between two squares is their Manhattan distance (the absolute value of the sum of differences between the two rows and the two columns). </p>

<p>Write a program that calculates the scatter of the given puzzle. </p>

### 입력 

 <p>Four lines of input contain four characters each, representing the state of the puzzle. </p>

<p> </p>

### 출력 

 <p>Output the scatter of the puzzle on a single line. </p>

<p> </p>

