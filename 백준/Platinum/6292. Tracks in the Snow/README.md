# [Platinum V] Tracks in the Snow - 6292 

[문제 링크](https://acmicpc.net/problem/6292) 

### 성능 요약

메모리: 228784 KB, 시간: 780 ms

### 분류

0-1 너비 우선 탐색, 데이크스트라, 그래프, 최단 경로

### 제출 일자

2021년 11월 24일 22:29:10

### 문제 설명

<p>There is a rectangular meadow in a forest, having been covered with a blanket of fresh snow in the morning (left in the figure below).</p>

<p>Rabbits and foxes, who live in the forest, are crossing the meadow and leave their tracks in the snow. They always enter in the upper left corner and leave the meadow from the lower right corner. In between they can move back and forth, playing in the snow, even crossing their own tracks. At any time there is at most one animal on the meadow. No animal enters the meadow more than once. The movements of the animals can be described by dividing the meadow into quadratic cells. The animals never move diagonally in a single step and they never jump over a cell. When an animal enters a cell its tracks will cover all previous tracks left in this cell.</p>

<p>For example, first a rabbit crossed the meadow from top-left to bottom-right (middle in the figure). After that, a fox crossed, and now his tracks are partially covering the rabbit’s (right in the figure).</p>

<pre>........ RRR..... FFR.....
........ ..RRR... .FRRR...
........ ..R..... .FFFFF..
........ ..RRRR.R ..RRRFFR
........ .....RRR .....FFF</pre>

<p>You are given a map of the meadow at some time after indicating for each cell if there are any visible tracks and whether they were left by a rabbit or by a fox (right in the figure). You are interested in the local wildlife population. Write a program to determine the minimal possible number N of animals that must have crossed the meadow to leave the given pattern of tracks in the snow.</p>

### 입력 

 <p>The first line contains two integers H and W, the height and the width of the map of the meadow. H lines follow with exactly W characters on each: the map, where ‘.’ marks untouched snow, ‘R’ a spot where a rabbit’s track is the topmost one, and ‘F’ a spot where a fox’s track is the topmost one. There is at least one track on the meadow.</p>

### 출력 

 <p>The output should consist of a single integer: the minimal number N ≥ 1 of animals that could have left the tracks given in the input.</p>

