# [Diamond V] High-Tech Detective - 21934 

[문제 링크](https://acmicpc.net/problem/21934) 

### 성능 요약

메모리: 2352 KB, 시간: 188 ms

### 분류

많은 조건 분기, 조합론, 다이나믹 프로그래밍, 수학

### 제출 일자

2025년 10월 28일 12:24:33

### 문제 설명

<p>The problem set document for the Yokohama Chinatown Gluttony Contest was kept in a safe at the headquarters of the Kanagawa Gourmendies Foundation. It was considered to be quite secure, but, in the morning of the very day of the contest, the executive director of the foundation found that the document was missing!</p>

<p>The director checked that the document was in the safe when she left the headquarters in the evening of the day before. To open the door of the headquarters office, a valid ID card has to be touched on the reader inside or outside of the door. As the door and its lock are not broken, the thief should have used a valid ID card.</p>

<p>Normally, all the entries and exits through the door are recorded with the ID. The system, however, has been compromised somehow, and some of the recorded ID’s are lost.</p>

<p>It is sure that nobody was in the office when the director left, but, many persons visited the office since then to prepare the contest materials. It is sure that the same ID card was used only once for entry and then once for exit.</p>

<p>The director is planning inquiries to grasp all the visits during the night. You are asked to write a program that calculates the number of possible combinations of ID’s to fill the lost parts of the records.</p>

### 입력 

 <p>The input consists of a single test case of the following format.</p>

<pre>n
c<sub>1</sub> x<sub>1</sub>
.
.
.
c<sub>2n</sub> x<sub>2n</sub></pre>

<p>The first line contains an integer n (1 ≤ n ≤ 5000), representing the number of visitors during the night. Each visitor has a unique ID numbered from 1 to n. The following 2n lines provide (incomplete) entry and exit records in chronological order. The i-th line (1 ≤ i ≤ 2n) contains a character c<sub>i</sub> and an integer x<sub>i</sub> (0 ≤ x<sub>i</sub> ≤ n). Here, c<sub>i</sub> denotes the type of the event, where c<sub>i</sub> = <code>I</code> and <code>O</code> indicate some visitor entered and exited the office, respectively. x<sub>i</sub> denotes the visitor ID, where x<sub>i</sub> ≥ 1 indicates the ID of the visitor is x<sub>i</sub>, and x<sub>i</sub> = 0 indicates the ID is lost. At least one of them is 0. It is guaranteed that there is at least one consistent way to fill the lost ID(s) in the records.</p>

### 출력 

 <p>Output a single integer in a line which is the number of the consistent ways to fill the lost ID(s) modulo 10<sup>9</sup> + 7.</p>

