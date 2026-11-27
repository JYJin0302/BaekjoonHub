# [Diamond V] Lost Logic - 13956 

[문제 링크](https://acmicpc.net/problem/13956) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

2-SAT, 애드 혹, 해 구성하기, 그래프, 강한 연결 요소

### 제출 일자

2023년 09월 01일 19:12:29

### 문제 설명

<p>Gustav is reading about 2-satisfiability, a well known problem of assigning truth values to boolean variables in order to satisfy a list of constraints — simple logical formulas involving two variables each.</p>

<p>We are using n variables x<sub>1</sub>, x<sub>2</sub>, . . . , x<sub>n</sub> that can take on values 0 (false) and 1 (true). A constraint is a formula of the form a → b where both a and b are possibly negated variables. As usual, → denotes logical implication: a → b is 0 only when a is 1 and b is 0. The negation of variable a is denoted by !a.</p>

<p>Given an assignment of values to variables, we say that the constraint is satisfied if it evaluates to 1. Gustav has constructed a list of constraints and correctly concluded that there are exactly three different assignments of values to variables that satisfy all the constraints. Gustav has wrote down all three assignments but has, unfortunately, lost the list of constraints.</p>

<p>Given three assignments of n values to variables, find any list consisting of at most 500 constrains such that the three given assignments are the only assignments that satisfy all the constraints.</p>

### 입력 

 <p>The first line contains an integer n (2 ≤ n ≤ 50) — the number of variables. Three lines follow, each describing one assignment. The k-th line contains n space-separated integers v<sub>1</sub><sup>k</sup> , v<sub>2</sub><sup>k</sup> , . . . , v<sub>n</sub><sup>k </sup>, where each v<sub>i</sub><sup>k</sup> is either 0 or 1 and denotes the value of the variable x<sub>i</sub> in the k-th assignment. All three assignments will be different.</p>

### 출력 

 <p>If there is no solution output a single line containing the integer −1.</p>

<p>Otherwise, the first line should contain an integer m where 1 ≤ m ≤ 500 — the number of constraints in your solution. The k-th of the following m lines should contain the k-th constraint. Each constraint should be a string constructed according to the following rules:</p>

<ul>
	<li>A variable is a string of the form “xi” where i is an integer between 1 and n inclusive written without leading zeros.</li>
	<li>A literal is a string consisting of a variable possibly preceded by the “!” character.</li>
	<li>A constraint is a string of the form “a -> b” where both a and b are literals. The implication sign consists of the “minus” character and the “greater-than” character and there is a single space character both before and after the implication sign.</li>
</ul>

