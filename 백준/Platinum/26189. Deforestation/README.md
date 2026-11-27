# [Platinum V] Deforestation - 26189 

[문제 링크](https://acmicpc.net/problem/26189) 

### 성능 요약

메모리: 21484 KB, 시간: 48 ms

### 분류

다이나믹 프로그래밍, 그리디, 정렬, 트리, 트리DP

### 제출 일자

2023년 04월 06일 12:01:11

### 문제 설명

<p>You want to remove a big tree from your property, but it's too big for you to carry all at once. How many pieces do you have to cut it into if the maximum weight you can carry is $W$?</p>
<p>The tree has a single trunk connected to the ground and can split out into multiple branches. All of those branches can branch out further etc. So each segment of the tree is a continuous mass of wood, which may or may not split out into multiple branches.</p>
<p>You can make cuts at any point on the tree; start, end, or anywhere in the middle of any segment. You can consider branching as an arbitrarily small part of the tree, i.e. you can cut immediately before or after a branch splits off without increasing the weight of the base branch, but it will affect whether the child branches are cut off as a single piece or just one branch is cut off separately. </p>

### 입력 

 <p>The first line of the input will contain $W$, your carrying capacity.
The next line will continue with the description of the first tree segment; its trunk.</p>
<p>A tree segment description is defined recursively. The first line contains two numbers $M$, weight of the segment, and $N$, number of branches coming out of the segment at its end. This is followed by $N$ tree segment descriptions, describing each one of the branches.</p>

### 출력 

 <p>Output one number, the number of pieces you have to cut the tree into.</p>

