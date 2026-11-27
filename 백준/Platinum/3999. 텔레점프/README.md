# [Platinum I] 텔레점프 - 3999 

[문제 링크](https://acmicpc.net/problem/3999) 

### 성능 요약

메모리: 2160 KB, 시간: 16 ms

### 분류

애드 혹, 많은 조건 분기, 해 구성하기

### 제출 일자

2026년 02월 26일 15:53:54

### 문제 설명

<p>John, Jill and Jeremy are planning their vacation trip. They would like to visit all planets in their planetary system. They are planning to use Telejump teleport system which was recently installed at all planets. There are n planets in the planetary system, numbered from 0 to n − 1. John, Jill and Jeremy are planning to start their journey from planet 0 and can ﬁnish it at any planet.</p>

<p>Telejump uses three types of tickets for their system. Ticket of the ﬁrst type allows to travel from planet x to planet x + 1 (when x + 1 ≤ n − 1) or to planet x − 1 (when x − 1 ≥ 0). Ticket of the second type allows to travel from planet x to planet x + 2 (when x + 2 ≤ n − 1) or to planet x − 2 (when x − 2 ≥ 0). Finally, ticket of the third type allows to travel from planet x to planet x + 3 (when x + 3 ≤ n − 1) or to planet x − 3 (when x − 3 ≥ 0).</p>

<p>Friends have bought a tickets of the ﬁrst type, b tickets of the second type and c tickets of the third type. Tickets are quite expensive, so they have bought the minimal number of tickets they need to visit all planets: a + b + c = n − 1. However, all three of friends collect used Telejump tickets, so they have bought at least 3 tickets of each type (yes, you can deduce from these facts that n ≥ 10).</p>

<p>Now they would like to plan their trip.</p>

<p>Help John, Jill and Jeremy to choose in which order they should visit planets, so that they could visit each planet by using their tickets.</p>

### 입력 

 <p>The input ﬁle contains several test cases. The ﬁrst line of the input ﬁle contains t — the number of test cases (1 ≤ t ≤ 20).</p>

<p>Each of the following t lines contains three integers each: a<sub>i</sub>, b<sub>i</sub> and c<sub>i</sub> (3 ≤ a<sub>i</sub>, b<sub>i</sub>, c<sub>i</sub> ≤ 5000). For such test case n<sub>i</sub> is equal to a<sub>i</sub> + b<sub>i</sub> + c<sub>i</sub> + 1.</p>

### 출력 

 <p>Output one line for each test case in the input. Each line must contain n<sub>i</sub> integers separated by spaces: planet numbers in the order friends should visit them to use their tickets.</p>

<p>If there are several solutions, output any one. It is guaranteed that for each test case from the input ﬁle solution always exists.</p>

