# [Silver III] 마라톤 틱택토 - 3024 

[문제 링크](https://acmicpc.net/problem/3024) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

브루트포싱, 구현

### 제출 일자

2024년 10월 15일 20:27:53

### 문제 설명

<p>Albert, Barbara, Casper, Dinko, Eustahije are starting a marathon game of tic-tac-toe, played on an N×N board. </p>

<p>Initially, all squares on the board are empty and players take turns writing the first letter of their name into any of the empty squares (because the players are elite, no two players have the same first letter). </p>

<p>The game ends when some player places 3 of his or her letters consecutively in a row, column or diagonally. That player is declared the winner. </p>

<p>Write a program that, given the state of the board, determines if the game is over and who won if it is. </p>

### 입력 

 <p>The first line of input contains the integer N (1 ≤ N ≤ 30), the size of the board. </p>

<p>The following N lines contain N characters each. The characters will be uppercase letters of the English alphabet or '.' (if the square is empty). </p>

<p>The input data will be such that there is at most one winner. </p>

### 출력 

 <p>If the game is over, output the first letter of the winner's name. If not, output "ongoing" (even if the board is full). </p>

