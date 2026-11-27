# [Platinum III] K-Shaped Figures - 26873 

[문제 링크](https://acmicpc.net/problem/26873) 

### 성능 요약

메모리: 2176 KB, 시간: 172 ms

### 분류

각도 정렬, 브루트포싱, 조합론, 기하학, 수학, 정렬

### 제출 일자

2023년 07월 16일 19:19:39

### 문제 설명

<p>Let's say that three segments on a plane form a <em>K-shaped figure</em> if:</p>

<ul>
	<li>two of them share a common endpoint;</li>
	<li>this common endpoint lies strictly inside the third segment;</li>
	<li>these two segments are located on the same side with respect to the third one;</li>
	<li>all three segments are pairwise not collinear.</li>
</ul>

<table class="table table-bordered td-center">
	<tbody>
		<tr>
			<td><img alt="" src="" style="width: 74px; height: 110px;"></td>
			<td><img alt="" src="" style="width: 74px; height: 110px;"></td>
			<td><img alt="" src="" style="width: 74px; height: 110px;"></td>
			<td><img alt="" src="" style="width: 74px; height: 110px;"></td>
			<td><img alt="" src="" style="width: 74px; height: 110px;"></td>
			<td><img alt="" src="" style="width: 74px; height: 110px;"></td>
			<td><img alt="" src="" style="width: 74px; height: 110px;"></td>
		</tr>
		<tr>
			<td>$\{AB,CD,CE\}$</td>
			<td>$\{AB,CD,CE\}$</td>
			<td>$\{AB,CD,CE\}$</td>
			<td>$\{AB,CD,CE\}$</td>
			<td>$\{AB,CD,CE\}$</td>
			<td>$\{AB,CD,EF\}$</td>
			<td>$\{AB,AC,AD\}$</td>
		</tr>
		<tr>
			<td colspan="3">Valid K-shaped figures</td>
			<td colspan="4">Invalid K-shaped figures</td>
		</tr>
	</tbody>
</table>

<p>You are given a collection of $n$ segments on the plane. Find the number of triples of segments from this collection that form a K-shaped figure.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 3333$). The description of the test cases follows.</p>

<p>The first line of each test case contains a single integer $n$ --- the number of segments ($3 \le n \le 1000$).</p>

<p>The $i$-th of the following $n$ lines contains four integers $x_{i,1}$, $y_{i,1}$, $x_{i,2}$, $y_{i,2}$ --- the coordinates of endpoints of the $i$-th segment ($-10^6 \le x_{i,1}, y_{i,1}, x_{i,2}, y_{i,2} \le 10^6$). All segments have positive lengths. Some segments may coincide.</p>

<p>It is guaranteed that the sum of $n$ over all test cases does not exceed $10^4$.</p>

### 출력 

 <p>For each test case, print a single integer --- the number of triples of segments that form a K-shaped figure.</p>

