# [Platinum III] spiral123 - 5264 

[문제 링크](https://acmicpc.net/problem/5264) 

### 성능 요약

메모리: 2236 KB, 시간: 4 ms

### 분류

백트래킹, 해 구성하기, 구현

### 제출 일자

2024년 05월 06일 18:22:08

### 문제 설명

<p>We shall name a square matrix as spiral123 if it has the following properties:</p>

<ul>
	<li>its elements are from the {0, 1, 2, 3} set;</li>
	<li>each row and column contains each of the values 1, 2 and 3, exactly once and all the other values are 0;</li>
	<li>starting from the upper-left corner going right, moving in spiral, the non-zero values will appear in the following order 1, 2, 3, 1, 2, 3, ... , 1, 2, 3.</li>
</ul>

<p style="text-align: center;"><img alt="" src="" style="width: 114px; height: 100px;"></p>

<p>For example a 5x5 spiral123 matrix is the following:</p>

<p style="text-align: center;"><img alt="" src="" style="width: 107px; height: 96px;"></p>

<p>For a given natural number n, you should generate a n x n spiral123 matrix.</p>

### 입력 

 <p>The input contains only one natural number n on the first line.</p>

### 출력 

 <p>If there is solution, output must contain n lines, each with n numbers separated with one space, representing the required matrix. If there is no solution, on the single line of the output file, the -1 value will be written.</p>

