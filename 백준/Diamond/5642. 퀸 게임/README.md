# [Diamond IV] 퀸 게임 - 5642 

[문제 링크](https://acmicpc.net/problem/5642) 

### 성능 요약

메모리: 3100 KB, 시간: 8 ms

### 분류

게임 이론, 런타임 전의 전처리, 스프라그–그런디 정리

### 제출 일자

2023년 02월 01일 14:34:50

### 문제 설명

<p>Queen game is played in a chessboard of size R rows and C columns. Rows are numbered from 1 to R and columns are numbered from 1 to C. The topmost square is in row 1 and column 1. The game is a 2 player game. Initially there are N queens placed in various squares of the chessboard. In his turn, the player picks a queen and moves it either towards the top vertically, or towards the left horizontally or towards the top-left diagonally and the queen should always stay on the board. When the queen reaches square (1, 1) it is removed from the board. The player who gives the last move wins. Each square is big enough to accommodate infinite number of queens. The players give their moves by turns. You are given the size of the chessboard and the initial positions of the N queens. Assuming that both of the players play perfectly your task is to determine who will win this game. </p>

### 입력 

 <p>First line of the input contains T the number of test cases. Each test case starts with a line containing 3 integers R(1≤R≤25), C(1≤C≤10<sup>15</sup>) and N(1≤N≤1000). Each of the next N lines contains the positions of N queens. The position is denoted by two integers. The first integer is the row number and the second integer is the column numbers. </p>

### 출력 

 <p>For each test case output “YES” if the first player has a winning strategy and “NO” otherwise. </p>

<p> </p>

