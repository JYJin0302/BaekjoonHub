# [Platinum IV] Last Hit (Small) - 12228 

[문제 링크](https://acmicpc.net/problem/12228) 

### 성능 요약

메모리: 2416 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2022년 10월 07일 13:47:05

### 문제 설명

<p>Diana needs your help maximizing her gold while playing her favorite game. She is often faced with a scenario where she is standing close to her tower and is facing <strong>N</strong> monsters. When that happens, Diana and the tower take turns shooting the monsters, and she goes first. During her turn, Diana <em>may</em> choose a monster to shoot at (this means Diana may choose to skip a turn). During its turn, the tower shoots the monster closest to it. Diana and the tower can not shoot dead monsters.</p>

<p>If Diana shoots at a monster, its hit points are reduced by <strong>P</strong>. If the tower shoots at a monster, its hit points are reduced by <strong>Q</strong>. If a monster's hit points are reduced below 1, it is killed. The i<sup>th</sup> monster starts with <strong>H</strong><strong><sub>i</sub></strong> hit points. Diana is awarded <strong>G</strong><strong><sub>i</sub></strong> gold if her shot kills the i<sup>th</sup> monster, but none if the tower's shot kills it. What is the maximum amount of gold Diana can obtain?</p>

### 입력 

 <p>The first line of the input gives the number of test cases, <strong>T</strong>. <strong>T</strong> test cases follow. Each case begins with one line containing three space-separated integers representing <strong>P</strong>, <strong>Q</strong> and <strong>N</strong>. <strong>N</strong> lines then follow, with the i<sup>th</sup> line containing two space-separated integers representing <strong>H</strong><strong><sub>i</sub></strong> and <strong>G</strong><strong><sub>i</sub></strong>.</p>

<p>The monsters are given in the order of their distance from the tower. In other words, the tower will shoot at the i<sup>th</sup> monster only if all monsters < i are dead.</p>

<p>Limits</p>

<ul>
	<li>1 ≤ <strong>T</strong> ≤ 100</li>
	<li>20 ≤ <strong>P</strong> ≤ 200</li>
	<li>20 ≤ <strong>Q</strong> ≤ 200</li>
	<li>1 ≤ <strong>H</strong><strong><sub>i</sub></strong> ≤ 200</li>
	<li>0 ≤ <strong>G</strong><strong><sub>i</sub></strong> ≤ 10<sup>6</sup></li>
	<li><span style="line-height:1.6em">1 ≤ </span><strong style="line-height:1.6em">N</strong><span style="line-height:1.6em"> ≤ 4</span></li>
</ul>

### 출력 

 <p>For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the maximum amount of gold that Diana can obtain.</p>

<p> </p>

