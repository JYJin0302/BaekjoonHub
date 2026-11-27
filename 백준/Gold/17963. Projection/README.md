# [Gold I] Projection - 17963 

[문제 링크](https://acmicpc.net/problem/17963) 

### 성능 요약

메모리: 20860 KB, 시간: 204 ms

### 분류

해 구성하기, 구현

### 제출 일자

2023년 08월 04일 13:09:53

### 문제 설명

<p style="text-align: center;"><img alt="" src="" style="width: 231px; height: 192px;"></p>

<p>Everybody knows that you are a TensorFlow fan. Therefore, you’ve been challenged to recreate the TensorFlow logo from two projections.</p>

<p>Consider that you have a 3D volume, n×m×h, and two projections (two matrices with dimensions n×m and n × h with elements 0 and 1). You are asked to compute a possible sets of cubes that must be placed inside the 3D volume such that the 3D object created with the cubes throws the shadows specified by the projection-matrices, when the light comes from left and front. If it is not possible, just print −1. If it is possible you must find exactly two sets, one with the <strong>maximum</strong> amount of cubes and one with the <strong>minimum</strong> amount. You can assume there is no gravitation (the cubes are located inside the 3D volume exactly where they are placed, without requiring any support). We assume that 1 represents shadow and 0 represents light.</p>

<p>If there are multiple such solutions, you must output the minimum lexicographic one. One solution A is lexicographically smaller than another solution b if the first number that differs between the two solutions is smaller in a than in b.</p>

<p>For example, solution [(0, 0, 0),(1, 1, 1)] is smaller than [(1, 1, 1),(0, 0, 0)].</p>

### 입력 

 <p>The first line contains three integers separated by a single space n, m, h (1 ≤ n, m, h ≤ 100) — the volume dimensions.</p>

<p>Each of the next n lines contains m characters, each being either 1 or 0 representing either a shadow area (1) or a light area (0), describing the projection from the light in the front.</p>

<p>Each of the next n lines contains h characters, with the same format as above, describing the projection from the light on the left.</p>

### 출력 

 <p>The output should contain on the first line one number, either −1 if there is no solution or k<sub>max</sub> representing the maximum number of cubes we can assign in the volume that will generate the two projections given in the input.</p>

<p>The next k<sub>max</sub> lines should contain triplets of numbers x, y, z (0 ≤ x < n, 0 ≤ y < m, 0 ≤ z < h) representing the cubes chosen in the lexicographically smallest solution with maximum number of cubes.</p>

<p>Then, only if there is a solution, one more line follows containing k<sub>min</sub>, the minimum number of cubes we can assign in the volume that will generate the two projections given in the input.</p>

<p>After that, the next k<sub>min</sub> lines should contain triplets of numbers x, y, z (0 ≤ x < n, 0 ≤ y < m, 0 ≤ z < h) representing the cubes in the lexicographically smallest solution with minimum number of cubes.</p>

