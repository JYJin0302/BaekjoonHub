# [Diamond V] 피보나치 단어 - 4206 

[문제 링크](https://acmicpc.net/problem/4206) 

### 성능 요약

메모리: 41388 KB, 시간: 36 ms

### 분류

다이나믹 프로그래밍, KMP, 문자열

### 제출 일자

2026년 02월 14일 22:51:48

### 문제 설명

<p>The Fibonacci word sequence of bit strings is deﬁned as:</p>

<p><img alt="" src="" style="height:76px; width:291px"></p>

<p>Here + denotes concatenation of strings. The ﬁrst few elements are:</p>

<table class="table table-bordered table-condensed" style="width:50%">
	<thead>
		<tr>
			<td style="width:5%">n</td>
			<td style="width:45%">F(n)</td>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>0</td>
			<td>0</td>
		</tr>
		<tr>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td>2</td>
			<td>10</td>
		</tr>
		<tr>
			<td>3</td>
			<td>101</td>
		</tr>
		<tr>
			<td>4</td>
			<td>10110</td>
		</tr>
		<tr>
			<td>5</td>
			<td>10110101</td>
		</tr>
		<tr>
			<td>6</td>
			<td>1011010110110</td>
		</tr>
		<tr>
			<td>7</td>
			<td>101101011011010110101</td>
		</tr>
		<tr>
			<td>8</td>
			<td>1011010110110101101011011010110110</td>
		</tr>
		<tr>
			<td>9</td>
			<td>1011010110110101101011011010110110101101011011010110101</td>
		</tr>
	</tbody>
</table>

<p>Given a bit pattern p and a number n, how often does p occur in F(n)?</p>

### 입력 

 <p>The ﬁrst line of each test case contains the integer n (0 ≤ n ≤ 100). The second line contains the bit pattern p. The pattern p is nonempty and has a length of at most 100 000 characters.</p>

### 출력 

 <p>For each test case, display its case number followed by the number of occurrences of the bit pattern p in F(n). Occurrences may overlap. The number of occurrences will be less than 2<sup>63</sup>.</p>

