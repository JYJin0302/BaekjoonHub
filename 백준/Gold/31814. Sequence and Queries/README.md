# [Gold III] Sequence and Queries - 31814 

[문제 링크](https://acmicpc.net/problem/31814) 

### 성능 요약

메모리: 101780 KB, 시간: 252 ms

### 분류

조합론, 다이나믹 프로그래밍, 수학

### 제출 일자

2024년 05월 13일 16:01:53

### 문제 설명

<p>길이가 $n$인 수열 $(s_1,s_2,\ldots ,s_n)$이 주어진다. 함수 $f$는 다음과 같이 정의된다.</p>

<p>\[f(i,j,k) =\begin{cases}1&\text{if } s_{i+t}\leq s_{j+t}\text{ for all } 0\leq t<k\\ 0&\text{otherwise}\end{cases}\]</p>

<p>$\sum_{i=1}^{n}\sum_{j=1}^{n}\sum_{k=1}^{\min(n-i+1,n-j+1)}f(i,j,k)$의 값을 출력하라.</p>

### 입력 

 <p>첫 번째 줄에 수열의 길이를 나타내는 정수 $n$이 주어진다.</p>

<p>두 번째 줄에 $n$개의 정수 $s_1,s_2,\ldots ,s_n$이 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>$\sum_{i=1}^{n}\sum_{j=1}^{n}\sum_{k=1}^{\min(n-i+1,n-j+1)}f(i,j,k)$의 값을 출력한다.</p>

