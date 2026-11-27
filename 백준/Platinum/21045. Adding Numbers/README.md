# [Platinum II] Adding Numbers - 21045 

[문제 링크](https://acmicpc.net/problem/21045) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

많은 조건 분기, 다이나믹 프로그래밍, 수학, 누적 합

### 제출 일자

2022년 02월 04일 23:41:09

### 문제 설명

<p>Samouel has an array <em>A</em> of <em>N</em> integers indexed from 1 to <em>N</em>. Initially, all of the integers are 0. His friend, Gregor also has an array <em>B</em> of <em>N</em> integers indexed from 1 to <em>N</em>.</p>

<p>Samouel wants to modify his array such that his array becomes equal to Gregor's. To achieve that, Samouel can apply the following operation: choose two consecutive indices <em>i</em> and <em>i</em> + 1 (1 ≤ <em>i</em> < <em>N</em>) and do either the following:</p>

<ul>
	<li>Increment <em>A<sub>i</sub></em> by 1 and increment <em>A</em><sub><em>i</em>+1</sub> by 2, or</li>
	<li>Increment <em>A<sub>i</sub></em> by 2 and increment <em>A</em><sub><em>i</em>+1</sub> by 1.</li>
</ul>

<p>Determine whether it is possible for Samouel to achieve his goal.</p>

### 입력 

 <p>The first line contains one integer: <em>N</em> (1 ≤ <em>N</em> ≤ 100) in a line denoting the length of both array <em>A</em> and <em>B</em>. The second line contains <em>N</em> integers: <em>B</em><sub>1</sub>, <em>B</em><sub>2</sub>, ..., <em>B<sub>N</sub></em> (0 ≤ <em>B<sub>i</sub></em> ≤ 50,000) in a line denoting the value of array <em>B</em>.</p>

### 출력 

 <p>Output “YES" in a line if it is possible for Samouel to achieve his goal, or "NO" otherwise.</p>

