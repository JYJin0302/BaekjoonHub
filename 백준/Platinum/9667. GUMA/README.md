# [Platinum III] GUMA - 9667 

[문제 링크](https://acmicpc.net/problem/9667) 

### 성능 요약

메모리: 2808 KB, 시간: 56 ms

### 분류

포함 배제의 원리, 수학, 정수론

### 제출 일자

2025년 02월 15일 00:37:34

### 문제 설명

<p>A factory called Gumi-Gumi is dedicated to making tires. Their carving machine is responsible for carving fillisters into the tire. The tire has N vertical fillisters which divide the rubber into N+1 vertical parts. Horizontal cuts are made on each vertical part so that all parts comprising the vertical part are of equal size. The machine can make fillisters on one or more not necessarily continuous vertical sections in one cut, but it can only cut in a straight line. </p>

<p>An example of a tire cutting strategy, corresponding to the sample test. </p>

<p style="text-align: center;"><img alt="" src="" style="width: 388px; height: 275px;"></p>

<p>The topmost and the lowest lines represent a full horizontal cut, whereas the first and the last vertical lines are the ends of the tire. </p>

<p>You are given the shape of the tire. Your task is to calculate the minimal possible number of cuts necessary in order to obtain such shape. </p>

### 입력 

 <p>The first line of input contains the integer N (1 ≤ N ≤ 100 000). </p>

<p>Each of the following N+1 lines contains an integer a<sub>i</sub> (1 ≤ a<sub>i</sub> ≤ 100 000), representing the number of parts which the i<sup>th</sup> vertical section should consist of. </p>

### 출력 

 <p>The first and only line of output must consist of the minimal number of cuts required. </p>

