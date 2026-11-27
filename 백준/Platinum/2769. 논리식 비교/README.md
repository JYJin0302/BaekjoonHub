# [Platinum I] 논리식 비교 - 2769 

[문제 링크](https://acmicpc.net/problem/2769) 

### 성능 요약

메모리: 2040 KB, 시간: 4 ms

### 분류

브루트포싱, 구현, 파싱, 문자열

### 제출 일자

2024년 07월 29일 15:07:56

### 문제 설명

<p>At the University of Kentucky, they build a lot of high-performance computer hardware and software, often using one supercomputer to design the next. One of the most fundamental computer design problems is logic optimization: making sure that the optimized logic still computes the same function as the original design.</p>

<p>For this problem, your program will be given two logic expressions to compare for logical equivalence.</p>

### 입력 

 <p>The first line of the input consists of a positive integer n, which is the number of datasets (lines) that follow. Each dataset consists of a single line containing the two input expressions to be tested. The input expressions consist of any of 26 variables named a-z, the binary operators |, &, ^, (OR, AND and XOR respectively), the unary ~ (NOT), and parenthesis. The expressions should be evaluated ignoring all other characters and with operator precedence as in the C language (parenthesis, ~, &, ^, |). The two expressions will be input in sequence and it is up to your program to determine where one expression ends and the next begins.</p>

<p>Most logic manipulation programs would convert each expression into a normal form and check if the two normalized expressions are identical. Fortunately for you, each expression will consist of no more than 100 operations using no more than 10 different variables. For that many cases, you can test for equivalence by simply evaluating the two input expressions for all possible inputs and comparing the results.</p>

### 출력 

 <p>For each data set, print:</p>

<p>Data set N: Equivalent</p>

<p>if the expressions produce the same result, or:</p>

<p>Data set N: Different</p>

<p>if they produce different results. Of course N should be replaced by the data set number.</p>

