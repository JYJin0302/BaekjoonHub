# [Diamond V] Best Subsequence - 18448 

[문제 링크](https://acmicpc.net/problem/18448) 

### 성능 요약

메모리: 12512 KB, 시간: 156 ms

### 분류

자료 구조, 그리디, 매개 변수 탐색, 세그먼트 트리

### 제출 일자

2025년 04월 18일 17:00:08

### 문제 설명

<p>You have an array w<sub>1</sub>, w<sub>2</sub>, . . . , w<sub>n</sub> of length n.</p>

<p>You need to choose a subsequence of k elements. Let their indices be 1 ≤ i<sub>1</sub> < i<sub>2</sub> < . . . < i<sub>k</sub> ≤ n.</p>

<p>Your goal is to find the minimum possible value of</p>

<p style="text-align: center;">max ((w<sub>i<sub>1</sub></sub> + w<sub>i<sub>2</sub></sub>),(w<sub>i<sub>2</sub></sub> + w<sub>i<sub>3</sub></sub>), . . . ,(w<sub>i<sub>k−1</sub></sub> + w<sub>i<sub>k</sub></sub>),(w<sub>i<sub>k</sub></sub> + w<sub>i<sub>1</sub></sub>))</p>

<p>among all such subsequences.</p>

### 입력 

 <p>The first line of input contains two integers n and k: the number of elements in the array w and the length of subsequence (3 ≤ k ≤ n ≤ 200 000).</p>

<p>The second line contains n space-separated integers w<sub>1</sub>, w<sub>2</sub>, . . . , w<sub>n</sub> (1 ≤ w<sub>i</sub> ≤ 10<sup>9</sup>).</p>

### 출력 

 <p>Print one integer: the minimum possible value of</p>

<p style="text-align: center;">max ((w<sub>i<sub>1</sub></sub> + w<sub>i<sub>2</sub></sub>),(w<sub>i<sub>2</sub></sub> + w<sub>i<sub>3</sub></sub>), . . . ,(w<sub>i<sub>k−1</sub></sub> + w<sub>i<sub>k</sub></sub>),(w<sub>i<sub>k</sub></sub> + w<sub>i<sub>1</sub></sub>))</p>

<p>among all subsequences of length k.</p>

