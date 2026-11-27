# [Platinum III] Join two kingdoms - 9534 

[문제 링크](https://acmicpc.net/problem/9534) 

### 성능 요약

메모리: 15012 KB, 시간: 48 ms

### 분류

이분 탐색, 깊이 우선 탐색, 다이나믹 프로그래밍, 자료 구조, 그래프, 그래프 탐색, 세그먼트 트리, 트리, 트리DP, 두 포인터

### 제출 일자

2025년 02월 18일 21:15:48

### 문제 설명

<p>The kingdoms of Nlogonia and Quadradonia fought a long and terrible war that historians have come to call Almost Completely Meaningless (ACM) because nobody can now remember why it started. When the ACM war finally ended, the two kingdoms decided to strengthen their bonds in order to avoid more bloodshed, and for this reason they consulted the International Consortium for the Prevention of Conflicts (ICPC). The ICPC recommended building a single road to connect a city in Nlogonia with a city in Quadradonia, thus allowing commercial and cultural exchange between the two.</p>

<p>Nlogonia and Quadradonia have N and Q cities respectively. The road system of each kingdom consists of a set of bidirectional roads that join pairs of different cities in the same kingdom, such that there is a unique path (i.e. sequence of consecutive roads) that one can take to go from any city in a kingdom to any other city in the same kingdom. The “size” of such a road system is defined as the maximum number of roads that one must take in order to travel between any pair of cities.</p>

<p>Because the ICPC did not specify which two cities should be connected by the new road joining the two kingdoms, the citizens are now worried that the size of the combined road system might be too large. In order to prevent a second ACM war, you would like to convince them that this is not the case, and to this end you need to calculate the expected size of the resulting road system assuming that all possible roads between the two kingdoms are equally likely to be built.</p>

### 입력 

 <p>The first line contains two integers N and Q representing the number of cities in each of the two kingdoms (1 ≤ N, Q ≤ 4 × 10<sup>4</sup>). Cities in Nlogonia are identified with different integers from 1 to N, while cities in Quadradonia are identified with different integers from 1 to Q. Each of the next N − 1 lines describes a road in Nlogonia with two distinct integers A and B indicating that the road connects city A with city B (1 ≤ A, B ≤ N). Each of the next Q−1 lines describes a road in Quadradonia with two distinct integers C and D indicating that the road connects city C with city D (1 ≤ C, D ≤ Q). The road system of each kingdom is such that there is exactly one path between each pair of cities in the kingdom.</p>

### 출력 

 <p>Output a line with a rational number representing the expected size of the road system after the two kingdoms have been joined, considering that all possible roads connecting them are equally likely to be built. The result must be output as a rational number with exactly three digits after the decimal point, rounded if necessary.</p>

