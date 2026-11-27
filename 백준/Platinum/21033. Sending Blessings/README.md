# [Platinum I] Sending Blessings - 21033 

[문제 링크](https://acmicpc.net/problem/21033) 

### 성능 요약

메모리: 46728 KB, 시간: 180 ms

### 분류

자료 구조, 구현, 최소 공통 조상, 세그먼트 트리, 희소 배열, 트리

### 제출 일자

2023년 05월 17일 16:16:52

### 문제 설명

<p>There are N cities connected by N bridges in the country of Sayagueaing. The cities and the bridges are numbered from 1 to N. The i<sup>th</sup> bridge connects city A<sub>i</sub> and city B<sub>i</sub> and can be passed by a total of C<sub>i</sub> people before the bridge collapses. It is guaranteed that any pair of cities are connected by a sequence of bridges. It is also guaranteed that any pair of cities are directly connected by at most one bridge.</p>

<p>At the start of every year, one of the N cities wants to send new year blessings to another one of the N cities. Specifically, we will consider the first Q years. At the start of the i<sup>th</sup> year, city U<sub>i</sub> wants to send new year blessings to city V<sub>i</sub>. To do so, the sender city sends as many residents as possible to the recipient city, one resident at a time. Each resident will go from city U<sub>i</sub> to city V<sub>i</sub> through one or more bridges. The president of Sayagueaing is wondering the number of residents that can reach the recipient city.</p>

<p>Note that at the end of every year, the conditions of the bridges are restored to their original state. In other words, all collapsed bridges will be rebuilt, and the i<sup>th</sup> bridge can be passed by a total of C<sub>i</sub> people.</p>

### 입력 

 <p>Input begins with a line containing two integers: N Q (3 ≤ N ≤ 100 000; 1 ≤ Q ≤ 100 000) representing the number of cities in the country of Sayagueaing and the number of years to be considered, respectively. The next N lines, each contains three integers: A<sub>i</sub> B<sub>i</sub> C<sub>i</sub> (1 ≤ A<sub>i</sub>, B<sub>i</sub> ≤ N; A<sub>i</sub> ≠ B<sub>i</sub>; 1 ≤ C<sub>i</sub> ≤ 100 000) representing the bridges in the country of Sayagueaing. It is guaranteed that any pair of cities are connected by a sequence of bridges. It is also guaranteed that any pair of cities are directly connected by at most one bridge. The next Q lines, each contains two integers: U<sub>i</sub> V<sub>i</sub> (1 ≤ U<sub>i</sub>, V<sub>i</sub> ≤ N; U<sub>i</sub> ≠ V<sub>i</sub>) representing new year blessings to be sent.</p>

### 출력 

 <p>For each year in the same order as input, output in a line an integer representing the number of residents that can reach the recipient city at the start of the year.</p>

