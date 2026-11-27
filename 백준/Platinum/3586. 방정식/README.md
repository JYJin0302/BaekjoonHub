# [Platinum IV] 방정식 - 3586 

[문제 링크](https://acmicpc.net/problem/3586) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

많은 조건 분기, 자료 구조, 구현, 수학, 파싱, 스택, 문자열

### 제출 일자

2024년 01월 27일 18:58:40

### 문제 설명

<p>Your task is to solve an equation of the form f(x) = 0 where f(x) is written in postﬁx notation with numbers, operations +, -, *, /, and at most one occurrence of a variable x.</p>

<p>For example, f(x) for an equation (4x + 2)=2 = 0 is written as:</p>

<p>4 X * 2 + 2 /</p>

<p>The solution for f(x) = 0 is x = -1/2.</p>

### 입력 

 <p>The input file consists of a single line with at most 30 tokens separated by spaces. Each token is either:</p>

<ul>
	<li>a digit from 0 to 9;</li>
	<li>an operation +, -, *, or /;</li>
	<li>an uppercase letter X that denotes variable x.</li>
</ul>

<p>The input file contains a correct representation of f(x) in postfix notation where token X occurs at most once. There is no division by a constant zero in this equation, that is, there always exists a value of x, such that f(x) can be evaluated without division by zero.</p>

### 출력 

 <p>Write to the output file:</p>

<ul>
	<li>X = p/q if equation f(x) = 0 has a single solution that can be represented with a simple fraction p/q, where p and q are coprime integer numbers and q is positive.</li>
	<li>NONE if equation f(x) = 0 has no solution;</li>
	<li>MULTIPLE if equation f(x) = 0 has multiple solutions.</li>
</ul>

