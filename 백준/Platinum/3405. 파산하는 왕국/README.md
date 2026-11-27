# [Platinum V] 파산하는 왕국 - 3405 

[문제 링크](https://acmicpc.net/problem/3405) 

### 성능 요약

메모리: 2688 KB, 시간: 1220 ms

### 분류

비트마스킹, 비트필드를 이용한 DP, 다이나믹 프로그래밍, 그래프

### 제출 일자

2023년 08월 17일 19:10:47

### 문제 설명

<p>Several kingdoms got into serious financial troubles. For many years, they have been secretly borrowing more and more money from each other. Now, with their liabilities exposed, the crash is inevitable...</p>

<p>There are n kingdoms. For each pair (A, B) of kingdoms, the amount of gold that kingdom A owes to kingdom B is expressed by an integer number d<sub>AB</sub> (we assume that d<sub>BA</sub> = −d<sub>AB</sub>). If a kingdom has negative balance (has to pay more than it can receive), it may bankrupt. Bankruptcy removes all liabilities, both positive and negative, as if the kingdom ceased to exist. The next kingdom may then bankrupt, and so on, until all remaining kingdoms are financially stable.</p>

<p>Depending on who falls first, different scenarios may occur—in particular, sometimes only one kingdom might remain. Determine, for every kingdom, whether it can become the only survivor.</p>

### 입력 

 <p>The first line of the input contains the number of test cases T. The descriptions of the test cases follow:</p>

<p>The description of each test case starts with a line containing the number of the kingdoms n, 1 ≤ n ≤ 20. Then n lines follow, each containing n space-separated numbers. The j-th number in the i-th line is the number d<sub>ij</sub> of gold coins that the i-th kingdom owes to the j-th one. You may assume that d<sub>ii</sub> = 0 and d<sub>ij</sub> = −d<sub>ji</sub> for every 1 ≤ i, j ≤ n. Also, |d<sub>ij</sub>| ≤ 10<sup>6</sup> for all possible i, j.</p>

### 출력 

 <p>Print the answers to the test cases in the order in which they appear in the input. For each test case, print a single line containing the indices of the kingdoms that can become the sole survivors, in increasing order. If there are no such kingdoms, print a single number 0</p>

