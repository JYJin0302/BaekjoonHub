# [Diamond III] Beyond the Former Explorer - 33005 

[문제 링크](https://acmicpc.net/problem/33005) 

### 성능 요약

메모리: 43856 KB, 시간: 2220 ms

### 분류

애드 혹, 이분 탐색, 구현

### 제출 일자

2024년 12월 30일 14:16:20

### 문제 설명

<p>You are standing at the very center of a field, which is divided into a grid of cells running north-south and east-west. A great treasure is hidden somewhere within one of these cells.</p>

<p><em>John Belzoni</em>, a descendant of the famous treasure hunter <em>Giovanni Battista Belzoni</em>, actually discovered that treasure. Unfortunately enough, he died of heatstroke before successfully digging it out; he seems to have spent too long time wandering around the field.</p>

<p>John started his exploration from the central cell of the field where you stand now. All of his footprints leading to the treasure are left on the field, but you cannot identify the footprint on a cell until you reach there. The footprint on a cell indicates which of the four adjacent grid cells he proceeded to. It is known that John did not visit the same grid cell twice or more. You see a footprint on the central cell indicating that <strong>John’s first step was northward.</strong></p>

<p>There is exactly one treasure cell in the field, and you will recognize it only when you are on it.</p>

<p>A possible situation of the field is shown in Figure G.1. John’s footprints are depicted as arrows in the cells. The treasure cell is depicted as ‘<code>G</code>’. The shaded cell is where you initially stand.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 201px; height: 200px;"></p>

<p style="text-align: center;">Figure G.1. Possible situation</p>

<p>Your task is to find the treasure in a limited number of <em>steps</em>. In a single step, you decide to take one of the four directions north, west, south, or east, and proceed to the adjacent cell in that direction. When you move on to the cell, you may find either the treasure, John’s footprint, or nothing. You do not have to follow John’s footprints. Unlike John’s route, you may visit the same cell more than once. John’s footprints will remain the same regardless of your exploration.</p>

### 입력 

 Empty

### 출력 

 Empty

