# [Gold II] 불켜기 - 11967 

[문제 링크](https://acmicpc.net/problem/11967) 

### 성능 요약

메모리: 2812 KB, 시간: 8 ms

### 분류

너비 우선 탐색, 그래프, 그래프 탐색

### 제출 일자

2021년 12월 01일 22:03:48

### 문제 설명

<p>Farmer John has recently built an enormous barn consisting of an \(N \times N\) grid of rooms (\(2 \leq N \leq 100\)), numbered from \((1,1)\) up to \((N,N)\). Being somewhat afraid of the dark, Bessie the cow wants to turn on the lights in as many rooms as possible.</p>

<p>Bessie starts in room \((1,1)\), the only room that is initially lit. In some rooms, she will find light switches that she can use to toggle the lights in other rooms; for example there might be a switch in room \((1,1)\) that toggles the lights in room \((1,2)\). Bessie can only travel through lit rooms, and she can only move from a room \((x,y)\) to its four adjacent neighbors \((x-1,y)\), \((x+1,y)\), \((x,y-1)\) and \((x,y+1)\) (or possibly fewer neighbors if this room is on the boundary of the grid).</p>

<p>Please determine the maximum number of rooms Bessie can illuminate.</p>

### 입력 

 <p>The first line of input contains integers \(N\) and \(M\) (\(1 \leq M \leq 20,000\)).</p>

<p>The next \(M\) lines each describe a single light switch with four integers \(x\), \(y\), \(a\), \(b\), that a switch in room \((x,y)\) can be used to toggle the lights in room \((a,b)\). Multiple switches may exist in any room, and multiple switches may toggle the lights of any room.</p>

### 출력 

 <p>A single line giving the maximum number of rooms Bessie can illuminate.</p>

