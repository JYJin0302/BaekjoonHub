# [Platinum II] 전함 - 5480 

[문제 링크](https://acmicpc.net/problem/5480) 

### 성능 요약

메모리: 6972 KB, 시간: 792 ms

### 분류

자료 구조, 오프라인 쿼리, 세그먼트 트리, 값 및 좌표 압축

### 제출 일자

2024년 01월 26일 12:32:42

### 문제 설명

<p>You are a member of the prestigious ICPC (Inter-Continental Protecting Corps) and fighting against the evil enemy. The battlefield is represented by an n × n grid. The coordinate of the leftmost and lowest point is (1,1) and that of the rightmost and highest point is (n,n). The enemy has a fleet of k battleships. Each battleship i is represented by a line segment whose length is greater than 0 and its endpoints are (x<sub>i</sub>,y<sub>i</sub>) and (x'<sub>i</sub>,y'<sub>i</sub>). Also, its weight is w<sub>i</sub>. You can fire a laser cannon l times to destroy battleships. Each time you can fire it either horizontally or vertically. If you shoot it vertically, the laser is represented by a line linking (a,1) and (a,n) and all the battleships which meet the line (including the endpoints) are destroyed. If you shoot it horizontally, the laser is represented by a line linking (1,a) and (n,a) and those which meet the line (including the endpoints) are destroyed. While you are a brave soldier, due to the inefficiency of bureaucracy, you are asked to report the heaviest battleship you just destroyed each time you shoot the laser cannon. </p>

<p>Consider the example in Figure 1. There are five battleships on a 5 × 5 grid. The weight of a battleship is written next to it. Assume that we first shoot the cannon vertically and the laser is a line linking (4,1) and (4,5). Then two battleships are destroyed: one with weight 4 and the other with weight 5, which is heavier. Therefore we report 5. Next we shoot the cannon horizontally and the laser is a line linking (1,4) and (5,4). Again two battleships are destroyed: one with weight 1 and the other with weight 2, which is heavier. We report 2. Note that the battleship with weight 4 is already destroyed at the first shooting. </p>

<p><img alt="" src="" style="height:199px; width:234px"></p>

<p>Figure 1. An example of battlefield with five battleships.</p>

<p>Given the locations of battleships and your shooting information, write a program which reports the heaviest battleship you destroyed each time you shoot the cannon. </p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with integers n,k, and l, the size of the grid, the number of battleships, and the number of times you can shoot the laser cannon, respectively, where 1 ≤ n ≤ 1,000,000,000 and 1 ≤ k,l ≤ 100,000. Each of the following k lines contains five integers x,y,x',y' and w separated by a space which represent the endpoints of a battleship (x,y) and (x'y') (1 ≤ x,y,x',y' ≤ n) and its weight 1 ≤ w ≤ 1,000,000. Also each of the following l lines contains two integers a and b where 1 ≤ a  n. Either b = 0 or b = 1. If b = 0, you shoot the cannon horizontally and the laser is represented by a line linking (1,a) and (n,a). If b = 1, you shoot it vertically and the laser is represented by a line linking (a,1) and (a,n).</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly l lines for each test case. Each line should contain an integer value, the weight of the heaviest battleship you destroyed by shooting the laser cannon. If you destroyed nothing, print 0.</p>

