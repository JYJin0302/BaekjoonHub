# [Gold IV] 탈출 - 3055 

[문제 링크](https://acmicpc.net/problem/3055) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 그래프, 그래프 탐색, 격자 그래프

### 제출 일자

2020년 08월 15일 17:24:21

### 문제 설명

<p>The evil emperor Cactus has in his possession the Magic Keg and has flooded the Enchanted Forest! The Painter and the three little hedgehogs now have to return to the Beaver's den where they will be safe from the water as quickly as possible! </p>

<p>The map of the Enchanted Forest consists of R rows and C columns. Empty fields are represented by '.' characters, flooded fields by '*' and rocks by 'X'. Additionally, the Beaver's den is represented by 'D' and the Painter and the three little hedgehogs are shown as 'S'. </p>

<p>Every minute the Painter and the three little hedgehogs can move to 4 neighbouring fields (up, down, left or right). Every minute the flood expands as well so that all empty fields that have at least one common side with a flooded field become flooded as well. Neither water nor the Painter and the three little hedgehogs can pass through rocks. Naturally, the Painter and the three little hedgehogs cannot pass through flooded fields, and water cannot flood the Beaver's den.</p>

<p>Write a program that will, given a map of the Enchanted Forest, output the shortest time needed for the Painter and the three little hedgehogs to safely reach the Beaver's den.</p>

<p>Note: The Painter and the three little hedgehogs cannot move into a field that is about to be flooded (in the same minute). </p>

### 입력 

 <p>The first line of input will contain two integers, R and C, smaller than or equal to 50. </p>

<p>The following R lines will each contain C characters ('.', '*', 'X', 'D' or 'S'). The map will contain exactly one 'D' character and exactly one 'S' character. </p>

### 출력 

 <p>Output the shortest possible time needed for the Painter and the three little hedgehogs to safely reach the Beaver's den. If this is impossible output the word “KAKTUS” on a line by itself.</p>

