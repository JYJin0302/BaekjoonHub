# [Platinum IV] 디버그 - 3057 

[문제 링크](https://acmicpc.net/problem/3057) 

### 성능 요약

메모리: 3548 KB, 시간: 3224 ms

### 분류

비트 집합, 다이나믹 프로그래밍, 해싱

### 제출 일자

2024년 10월 08일 11:24:15

### 문제 설명

<p>While debugging a program Mirko noticed that a bug in the program may be linked with the existence of so called square killers in the program memory. The program memory is a matrix composed of R rows and C columns consisting only of zeroes and ones. A square killer is a square submatrix in memory, consisting of more than one character, that, when rotated 180 degrees looks exactly the same. For example, the following matrix contains 3 square killers: </p>

<p><img alt="" src="" style="height:107px; width:674px"></p>

<p>Mirko is wondering if there is a connection between the size of the largest square killer and the bug in the program. Help Mirko by writing a program that, given the layout of the memory, outputs the size of the largest square killer. The size of the square killer is the number of rows (or columns) that the killer consists of. In the example above the killer sizes are 2, 2 and 3, respectively.</p>

### 입력 

 <p>The first will contain two integers, R and C, smaller than or equal to 300. </p>

<p>The next R lines will each contain C characters ('0' or '1') with no spaces. </p>

### 출력 

 <p>Output the size of the largest killer on a single line, or output -1 if there are no square killers. </p>

<p> </p>

