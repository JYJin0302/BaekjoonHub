# [Gold I] 제단 - 5626 

[문제 링크](https://acmicpc.net/problem/5626) 

### 성능 요약

메모리: 2020 KB, 시간: 116 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2021년 12월 04일 08:35:26

### 문제 설명

<p>Some people like to pretend that they are a pharaoh. Or a dolphin. Luka is one such person.</p>

<p>He has built a relief consisting of a long line of N columns with nonnegative integer heights. The heights of all columns were initially zero. The relief was build in steps, where in each step Luka would select a contiguous subsequence of columns with equal heights and raise all columns in the subsequence, except the first and last column, by one.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 574px; height: 93px;"></p>

<p>Hundreds of years have passed, and some of the columns have been stolen. Luka's great-great-...-great-grandson is trying to determine the number of possible reliefs that could have been built by Luka such that the remaining columns' heights match the original relief.</p>

### 입력 

 <p>The first line of input contains the positive integer N (1 ≤ N ≤ 10 000), the number of columns in Luka's relief.</p>

<p>The second line of input contains N space-separated integers h<sub>i</sub> (-1 ≤ h<sub>i</sub> ≤ 10 000), the column heights. A height of -1 represents a stolen column.</p>

### 출력 

 <p>The first and only line of output must contain the required number of possible reliefs modulo 1 000 000 007.</p>

