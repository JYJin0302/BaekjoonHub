# [Silver IV] Easy as ABC - 32076 

[문제 링크](https://acmicpc.net/problem/32076) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

브루트포싱, 구현, 문자열

### 제출 일자

2024년 10월 17일 11:14:02

### 문제 설명

<p>You are playing a word puzzle. The puzzle starts with a $3$ by $3$ grid, where each cell contains either the letter <code>A</code>, <code>B</code>, or <code>C</code>.</p>

<p>The goal of this puzzle is to find the lexicographically smallest possible word of length $3$. The word can be formed by choosing three different cells where the cell containing the first letter is adjacent to the cell containing the second letter, and the cell containing the second letter is adjacent to the cell containing the third letter.</p>

<p>Two cells are adjacent to each other if they share a border or a corner, as shown in the following illustration. Formally, if $(r, c)$ denotes the cell in the $r$<sup>th</sup> row and $c$<sup>th</sup> column, then cell $(r, c)$ is adjacent to cell $(r, c + 1)$, $(r - 1, c + 1)$, $(r - 1, c)$, $(r - 1, c - 1)$, $(r, c - 1)$, $(r + 1, c - 1)$, $(r + 1, c)$, and $(r + 1, c + 1)$.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 122px; height: 122px;"></p>

<p>Determine the lexicographically smallest possible word of length $3$ that you can find within the grid.</p>

<p>A string $s$ of length $n$ is lexicographically smaller than string $t$ of the same length if there exists an integer $1 ≤ i ≤ n$ such that $s_j = t_j$ for all $1 ≤ j < i$, and $s_i < t_i$ in alphabetical order. The following illustration shows some examples on some grids and their the lexicographically smallest possible word of length $3$ that you can find within the grids.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 691px; height: 122px;"></p>

### 입력 

 <p>Input consists of three lines, each containing three letters, representing the puzzle grid. Each letter in the grid can only be either <code>A</code>, <code>B</code>, or <code>C</code>.</p>

### 출력 

 <p>Output the lexicographically smallest possible word of length $3$ that you can find within the grid.</p>

