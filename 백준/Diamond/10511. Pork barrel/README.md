# [Diamond IV] Pork barrel - 10511 

[문제 링크](https://acmicpc.net/problem/10511) 

### 성능 요약

메모리: 63124 KB, 시간: 2464 ms

### 분류

자료 구조, 분리 집합, 그래프, 최소 스패닝 트리, 퍼시스턴트 세그먼트 트리, 세그먼트 트리

### 제출 일자

2023년 08월 30일 18:17:43

### 문제 설명

<p>Winning the election was simpler than you expected: it was enough to promise to finally build a good quality, country-wide road infrastructure, of course without crippling the budget... Your happiness did not last long, however: it seems, that the citizens have found a way to actually hold you accountable for your promise!</p>

<p>There are n major cities in your country. The Ministry of Transport has prepared a detailed map, outlining</p>

### 입력 

 <p>The first line of input contains the number of test cases T. The descriptions of the test cases follow: </p>

<p>The first line of each test case contains integers n and m (1 ≤ n ≤ 1000; 0 ≤ m ≤ 100 000) – the number of cities in the country, and of possible direct connections, respectively.</p>

<p>Each of the following m lines contains three integers x, y, w (1 ≤ x ≠ y ≤ n; 1 ≤ w ≤ 1 000 000), denoting that the cities x and y can be connected by a bidirectional highway at cost w. There might be many ways to connect a single pair of cities.</p>

<p>The following line contains an integer q (1 ≤ q ≤ 1 000 000) – the number of rulings of the committees. Each of the following q lines contains two integers. The first of the lines contains the initial rulings l<sub>1</sub>, h<sub>1</sub>, given directly. The rest of the rulings are encoded. The numbers in the j-th of the lines for j > 1 are l<sub>j</sub> + c<sub>j−1</sub> and h<sub>j</sub> + c<sub>j−1</sub>, where l<sub>j</sub> and h<sub>j</sub> are the actual rulings and c<sub>j−1</sub> is the correct answer for the preceding rulings l<sub>j−1</sub> and h<sub>j−1</sub>. </p>

<p>All rulings satisfy 1 ≤ l<sub>j</sub> ≤ h<sub>j</sub> ≤ 1 000 000.</p>

### 출력 

 <p>For each test case, output q lines, one for each ruling. In the j-th of them, output the minimal cost c<sub>j</sub> of building a highway network which adheres to the committees’ constraints, and creates the maximum number of connected pairs of cities.</p>

