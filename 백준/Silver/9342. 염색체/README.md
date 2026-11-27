# [Silver III] 염색체 - 9342 

[문제 링크](https://acmicpc.net/problem/9342) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

정규 표현식, 문자열

### 제출 일자

2024년 07월 18일 15:54:20

### 문제 설명

<p>At a biomedical research center, the technician must examine a string of chromosome to see if it matches a particular pattern. Each string consists of any uppercase alphabet (i.e., A, B, C, …, Z). Currently, the technician must find if the string exactly matches the following rules: </p>

<ul>
	<li>Starting with zero or exactly one alphabet from {A, B, C, D, E, F} </li>
	<li>Following by at least one or more of alphabet A </li>
	<li>Following by at least one or more alphabet F </li>
	<li>Following by at least one or more alphabet C </li>
	<li>Following by zero or exactly one alphabet from {A, B, C, D, E, F}</li>
</ul>

<p>You job is to write a program that performs this check </p>

### 입력 

 <p>First line of input is a number of test cases T ≤ 20, </p>

<p>Each test case is a line contains only uppercase alphabet without any whitespace and at most 200 alphabets.</p>

### 출력 

 <p>For each test case, display "Infected!" in one line if that string matches the pattern described above. Otherwise, output "Good" in one line.</p>

<p>Note: Do not output the ‘ " ’ symbol. It is used for clarification purpose. </p>

