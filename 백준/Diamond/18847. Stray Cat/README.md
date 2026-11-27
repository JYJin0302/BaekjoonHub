# [Diamond II] Stray Cat - 18847 

[문제 링크](https://acmicpc.net/problem/18847) 

### 성능 요약

메모리: 23464 KB, 시간: 2828 ms

### 분류

애드 혹, 많은 조건 분기, 그래프, 그래프 탐색

### 제출 일자

2024년 07월 26일 15:58:05

### 문제 설명

<p>Anthony is an ant living in JOI City. There are N towns in JOI City, numbered from 0 to N −1. Anthony lives in the town 0. There are M roads, numbered from 0 to M − 1. The road i (0 ≤ i ≤ M − 1) connects the town U<sub>i</sub> and the town V<sub>i</sub>, and it is possible to pass through it in both directions. Different roads connect different pairs of towns. It is possible to travel from any town to any other town by passing through several roads.</p>

<p>Catherine is a cat who is a friend of Anthony. She is planning to visit JOI City, but she does not know the information of the roads and she often strays. Anthony decided to put marks on the roads in advance. There are A types for marks, numbered from 0 to A − 1.</p>

<p>Now Catherine arrived at a town in JOI City. Whenever she is in a town other than the town 0, she does the following:</p>

<p>For each type of marks, she can count the number of roads of that type going from her current town, except for the road which she passed lastly (if such a road exists).</p>

<p>After that, she chooses a road to pass. Note that <strong>except for the road which she passed lastly, she can distinguish the road only by types of marks</strong>. Choosing roads suitably, she wants to arrive at the town 0 without taking much time. More precisely, the minimum number of roads to pass to travel from her first town to the town 0 is d, she wants to arrive at the town 0 by choosing roads at most d + B times.</p>

<p>Write a program which, given the information of the roads, implements Anthony’s strategy to put marks on the roads, and a program which implements Catherine’s strategy to choose roads.</p>

### 입력 

 Empty

### 출력 

 Empty

