# [Bronze I] 마술사 이민혁 - 3023 

[문제 링크](https://acmicpc.net/problem/3023) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

구현, 문자열

### 제출 일자

2024년 10월 15일 20:22:46

### 문제 설명

<p>The well-known magician Al'Dimi Kartimi needs a program to help him design the back side of his cards. </p>

<p>Al'Dimi first draws the upper left quarter of the card, mirrors it horizontally onto the upper right quarter and then vertically mirrors the entire upper half onto the lower half. </p>

<p>After the mirroring, Al'Dimi also adds a small error (changes the appearance of one square) to help him determine which card it is (to cheat, if you will).</p>

<p>Help Al'Dimi by writing a program that, given the design of the upper left quarter and the location of the error, draws the entire back side. </p>

<p>Here are three examples of Al'Dimi's cards (the error is shaded gray): </p>

<table class="table table-bordered td-center">
	<tbody>
		<tr>
			<td><code>###.##.###<br>
			##########<br>
			.########.<br>
			..######..<br>
			####<span style="background-color:#bdc3c7;">.</span>#####<br>
			##########<br>
			..######..<br>
			.########.<br>
			##########<br>
			###.##.###</code></td>
			<td><code>#.#..#.#<br>
			#.####.#<br>
			#.####.#<br>
			........<br>
			.#.##.#.<br>
			.#.##.#.<br>
			........<br>
			#.####.#<br>
			#.####.#<br>
			#.#.<span style="background-color:#bdc3c7;">#</span>#.#</code></td>
			<td><code><span style="background-color:#bdc3c7;">.</span>#.##.##<br>
			#.#..#.#<br>
			........<br>
			..#..#..<br>
			..#..#..<br>
			........<br>
			#.#..#.#<br>
			##.##.##</code></td>
		</tr>
	</tbody>
</table>

### 입력 

 <p>The first line of input contains two integers, R and C (1 ≤ R, C ≤ 50), the number of rows and columns in the upper left quarter of the card. </p>

<p>Each of the R following lines contains C characters '.' or '#', the design of the upper left quarter. </p>

<p>The next line contains two integers, A and B (1 ≤ A ≤ 2R, 1 ≤ B ≤ 2C), the row and column of the error. </p>

### 출력 

 <p>Output 2R rows, each containing 2C characters, the design of the back side.</p>

