# [Platinum II] Easy Compare-and-Set - 20236 

[문제 링크](https://acmicpc.net/problem/20236) 

### 성능 요약

메모리: 19460 KB, 시간: 100 ms

### 분류

오일러 경로, 그래프

### 제출 일자

2023년 08월 11일 14:51:46

### 문제 설명

<p>Let us define "Compare-and-Set" operation for a global variable $v$. The operation checks if the variable is equal to $a$. If that's true, the variable value changes to $b$ and the operation succeeds. Otherwise, the variable doesn't change and the operation fails. Let us denote the operation as $\operatorname{CAS}(a,b)$.</p>

<p>Imagine that you are given a list of such operations $\operatorname{CAS}(a_1,b_1), \dots, \operatorname{CAS}(a_n,b_n)$. Also, you are given an initial value for the variable, $c$, and a list of wishes $w_1, \dots w_n$, where $w_i$ tells whether the operation $\operatorname{CAS}(a_i,b_i)$ should be successful. Your task is to determine the order of operations execution so that all the wishes are satisfied.</p>

### 입력 

 <p>The first line contains two integers $n$ and $c$ ($1 \le n \le 10^5$; $1 \le c \le 10^9$) --- the number of operations and the initial value of the variable.</p>

<p>Each of the next $n$ lines contains three integers $a_i, b_i, w_i$ ($1 \le a_i, b_i \le 10^9$; $0 \le w_i \le 1$), denoting $\operatorname{CAS}(a_i, b_i)$ operation that you wish to be successful if $w_i = 1$ and unsuccessful if $w_i = 0$. The operations are numbered from $1$ to $n$ in order of input.</p>

### 출력 

 <p>If no correct order of operations exists, output a single word "<code>No</code>".</p>

<p>Otherwise, output a word "<code>Yes</code>" followed by $n$ distinct integers $p_1, p_2, \ldots p_n$ ($1 \le p_i \le n$), meaning that operation $p_1$ should be executed first, then operation $p_2$, and so on. If there are several possible orders, output any of them.</p>

