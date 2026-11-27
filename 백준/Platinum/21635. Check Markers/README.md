# [Platinum III] Check Markers - 21635 

[문제 링크](https://acmicpc.net/problem/21635) 

### 성능 요약

메모리: 5152 KB, 시간: 40 ms

### 분류

그리디, 홀의 결혼 정리

### 제출 일자

2025년 12월 30일 13:59:12

### 문제 설명

<p>Alexander Markovich should start his lecture in five minutes, but at this moment he is just entering the university! He would be just in time unless it wasn't that the lecture had been scheduled in that huge room where lots of spent markers are all around. Now Alexander Markovich should find at least two markers of different colors that are not completely spent yet.</p>

<p>University professors use markers of $n$ different colors, and they are all in a single pile initially. We know that among the markers of color $i$ there are $a_i$ spent and $b_i$ good (that can still be used for writing) markers in the pile. It is impossible to distinguish whether a marker is spent or good by its appearance. In order to find two good markers of different colors, Alexander Markovich will repeat the following procedure:</p>

<ol>
	<li>he takes two markers of different colors from the pile;</li>
	<li>then he simultaneously checks whether each of these markers can be used for writing;</li>
	<li>if both markers are good, Alexander Markovich takes them and starts the lecture;</li>
	<li>otherwise, if at least one of the markers is spent, he throws both markers to trash and returns to step 1.</li>
</ol>

<p>Alexander Markovich chooses a pair of markers arbitrarily. Is it possible that he never finds two good markers of different colors, i. e. at some iteration of step 1 there are no two markers of different colors left in the pile?</p>

<p>You are to solve the problem for $t$ test cases.</p>

### 입력 

 <p>The first line contains a single integer $t$ ($1 \le t \le 2 \cdot 10^5$) --- the number of test cases.</p>

<p>Each of the test cases is described in three lines. The first line contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$) --- the number of different colors of markers.</p>

<p>The second line of each test case contains  $n$ integers $a_1$, $a_2$, \ldots, $a_n$ ($0 \le a_i \le 10^9$) --- the number of spent markers of each color.</p>

<p>The third line of each test case contains $n$ integers $b_1$, $b_2$, \ldots, $b_n$ ($0 \le b_i \le 10^9$) --- the number of good markers of each color.</p>

<p>It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.</p>

### 출력 

 <p>For each test case print "<code>YES</code>" in a separate line if it is possible that Alexander Markovich never finds two good markers of different colors, otherwise print "<code>NO</code>".</p>

