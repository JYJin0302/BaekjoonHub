# [Platinum III] 이중 연결 리스트 - 3045 

[문제 링크](https://acmicpc.net/problem/3045) 

### 성능 요약

메모리: 14200 KB, 시간: 68 ms

### 분류

자료 구조, 연결 리스트, 가장 긴 증가하는 부분 수열 문제, 역추적

### 제출 일자

2024년 10월 08일 16:16:36

### 문제 설명

<p>Mirko received a birthday present from his aunt in the US – a brand-new doubly-linked list (an example of which is shown in the figure below). The list contains N nodes numbered 1 through N. Two types of moves can be done on the list: </p>

<p>A) Move node X in front of node Y. </p>

<p>B) Move node X after node Y. </p>

<p style="text-align: center;"><img alt="" src="" style="width: 518px; height: 55px;"></p>

<p style="text-align: center;">An example of a list with 6 nodes. </p>

<p style="text-align: center;"><img alt="" src="" style="width: 518px; height: 54px;"></p>

<p style="text-align: center;">The list after the move "A 1 4". </p>

<p style="text-align: center;"><img alt="" src="" style="width: 518px; height: 55px;"></p>

<p style="text-align: center;">The list after another move, "B 3 5". </p>

<p>Mirko played with his new toy for hours, writing down each move on a piece of paper so that he can reconstruct the list's initial state (nodes 1 through N in order from left to right). </p>

<p>When he decided to reconstruct the list, Mirko was astonished to find that there is no easy way to invert the moves and restore the list's initial state. Mirko cannot know where node X was prior to each move, only where it ended up. </p>

<p>Seeing how Mirko is still recovering from the shock, write a program that finds a minimal sequence of moves that restored the list's initial state from Mirko's logs.</p>

### 입력 

 <p>The first line of input contains two integers N and K (2 ≤ N ≤ 500 000, 0 ≤ M ≤ 100 000), the number of nodes and the number of moves made by Mirko. </p>

<p>Each of the next M rows contains a description of a single move made by Mirko – the type of move ('A' or 'B') and two integers X and Y. </p>

### 출력 

 <p>Output the minimum number of moves (call this number K) on the first line. </p>

<p>Each of the next K lines should contain a description of a single move in the same format as in the input. </p>

<p>Note: The sequence need not be unique.</p>

