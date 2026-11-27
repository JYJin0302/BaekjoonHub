# [Silver II] Crochet Competition - 35218 

[문제 링크](https://acmicpc.net/problem/35218) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

많은 조건 분기, 구현

### 제출 일자

2026년 02월 03일 13:18:52

### 문제 설명

<p>The National Crochet Pattern Competition (NCPC) is an annual team-based event for crocheters of all skill levels, from beginner to expert. Teams design, write, and crochet original patterns within a time limit, which can range from minutes to a full week depending on the complexity---sometimes spanning weekends. Contestants may take breaks to eat, sleep, or go home, but the timer continues running.</p>

<p>NCPC has asked you to develop a system that calculates the total competition duration from the start and end times, provided with weekday, hour, and minute. The reported duration should be precise, correctly expressed in days, hours, and minutes, using as few components as necessary while minimizing the sum of the integer values.</p>

### 입력 

 <p>Input consists of two lines.</p>

<ul>
<li>The first line gives the competition's start time. </li>
<li>The second line gives the competition's end time.</li>
</ul>

<p>Times are formatted as "<code>Www HH:MM</code>", where</p>

<ul>
<li><code>Www</code> is the three-letter weekday abbreviation: <code>Mon</code>, <code>Tue</code>, <code>Wed</code>, <code>Thu</code>, <code>Fri</code>, <code>Sat</code>, or <code>Sun</code>. </li>
<li><code>HH</code> the two-digit hour, from $00$ to $23$.</li>
<li><code>MM</code> is the two-digits minutes, from $00$ to $59$.</li>
</ul>

<p>If the start and end times are identical, the competition lasts exactly one week.</p>

### 출력 

 <p>Output the competition duration in days, hours, and minutes, using the singular or plural form as appropriate (e.g., 1 day, 2 days). List the components in order -- days, hours, minutes -- separating three components with commas and two with "and"; omit any component with a value of zero.</p>

