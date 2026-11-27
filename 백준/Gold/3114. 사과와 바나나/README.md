# [Gold II] 사과와 바나나 - 3114 

[문제 링크](https://acmicpc.net/problem/3114) 

### 성능 요약

메모리: 45932 KB, 시간: 220 ms

### 분류

다이나믹 프로그래밍, 누적 합

### 제출 일자

2020년 08월 31일 21:36:39

### 문제 설명

<p>Inhabitants of neighbouring villages (call the villages A and B) cannot settle their border dispute. The disputed area is rectangular, composed of R×C unit cells of land. Every cell has either some number of apple trees or some number of banana trees growing in it. </p>

<p>A foreign counsellor has been asked to mediate in order to settle the dispute. He has decided that a bulldozer will pass through the area and destroy all trees in the cells it goes through. The bulldozer will start in the upper-left corner of the area and always move one cell down, right or diagonally down-right. </p>

<p>The bulldozer stops when it reaches the lower-right corner. </p>

<p>The village A will get the land below the bulldozer's path, while village B will get the land above it. Note that it is possible for one of the villages to receive no land at all. </p>

<p>The counsellor noticed that people in village A prefer apples, while people in village B prefer bananas. So he decided to choose the bulldozer's path so that the sum of the numbers of apple trees below its path and banana trees above its path is the largest possible. </p>

<p>Write a program that calculates this largest possible sum. </p>

### 입력 

 <p>The first line contains the integers R and C (2 ≤ R, C ≤ 1500), the dimensions of the area. </p>

<p>Each of the following R lines contains C descriptions of a cell of land. Each such description consists of the letter 'A' (apples) or 'B' (bananas) and the number of such trees in the cell. Each cell contains between 1 and 99 trees. </p>

### 출력 

 <p>Output the largest possible sum as described above. </p>

<p> </p>

