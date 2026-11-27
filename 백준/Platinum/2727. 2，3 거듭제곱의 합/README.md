# [Platinum V] 2,3 거듭제곱의 합 - 2727 

[문제 링크](https://acmicpc.net/problem/2727) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

해 구성하기, 그리디, 수학

### 제출 일자

2022년 03월 09일 23:48:35

### 문제 설명

<p>Every positive integer N can be written in at least one way as a sum of terms of the form (2<sup>a</sup>)(3<sup>b</sup>) where no term in the sum exactly divides any other term in the sum. For example: </p>

<ul>
	<li>1 = (2<sup>0</sup>)(3<sup>0</sup>)</li>
	<li>7 = (2<sup>2</sup>)(3<sup>0</sup>) + (2<sup>0</sup>)(3<sup>1</sup>)</li>
	<li>31 = (2<sup>4</sup>)(3<sup>0</sup>) + (2<sup>0</sup>)(3<sup>2</sup>) + (2<sup>1</sup>)(3<sup>1</sup>) = (2<sup>2</sup>)(3<sup>0</sup>) + (2<sup>0</sup>)(3<sup>3</sup>)</li>
</ul>

<p>Note from the example of 31 that the representation is not unique. </p>

<p>Write a program which takes as input a positive integer N and outputs a representation of N as a sum of terms of the form (2<sup>a</sup>)(3<sup>b</sup>). </p>

### 입력 

 <p>The first line of input contains a single integer C, (1 ≤ C ≤ 1000) which is the number of datasets that follow. </p>

<p>Each dataset consists of a single line of input containing a single integer N, (1 ≤ N < 2<sup>31</sup>), which is the number to be represented as a sum of terms of the form (2<sup>a</sup>)(3<sup>b</sup>). </p>

### 출력 

 <p>For each dataset, the output will be a single line consisting of: The dataset number, a single space, the number of terms in your sum as a decimal integer followed by a single space followed by representations of the terms in the form [<2 exponent>,<3 exponent>] with terms separated by a single space. <2 exponent> is the power of 2 in the term and <3 exponent> is the power of 3 in the term. </p>

