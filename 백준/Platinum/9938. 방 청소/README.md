# [Platinum II] 방 청소 - 9938 

[문제 링크](https://acmicpc.net/problem/9938) 

### 성능 요약

메모리: 3256 KB, 시간: 96 ms

### 분류

자료 구조, 분리 집합

### 제출 일자

2020년 10월 12일 01:02:14

### 문제 설명

<p>Mirko has N items (labeled with numbers from 1 to N) and L drawers (labeled with numbers from 1 to L). All items are currently scattered throughout his room, so he decided to clean them up. Each drawer can contain one item, and in order to make it easier for Mirko to find them later, he has determined in advance exactly two drawers (A<sub>i</sub> and B<sub>i</sub>) for each item i. </p>

<p>Mirko stores the items in order from 1 to N using the first rule he can apply: </p>

<ol>
	<li>If the drawer A<sub>i</sub> is empty, he stores the item i in that drawer </li>
	<li>If the drawer B<sub>i</sub> is empty, he stores the item i in that drawer </li>
	<li>Try to move the item from A<sub>i</sub> to its other drawer; if that one's filled too, try moving that item to its other drawer, and so on until you either succeed or get back to a previously seen drawer. In case of success, store the item i in the drawer A<sub>i</sub>. In case of failure, continue to next rule. </li>
	<li>Try moving the item from B<sub>i</sub> to its other drawer; if that one's filled too, try moving that item to its other drawer, and so on until you either succeed or get back to a previously seen drawer. In case of success, store the item i in the drawer B<sub>i</sub>. In case of failure, continue to next rule. </li>
	<li>Give up and throw away the item i. </li>
</ol>

<p>For given pairs of drawers for each item, determine which items will be stored and which will be thrown away. </p>

### 입력 

 <p>The first line of input consists of two integers, N and L (1 ≤ N, L ≤ 300 000), the number of items and the number of drawers. </p>

<p>Each of the following N lines contains two integers: A<sub>i</sub> and B<sub>i</sub> (1 ≤ A<sub>i</sub> and B<sub>i</sub> ≤ L), pair of drawers corresponding to the item i. The numbers A<sub>i</sub> and B<sub>i</sub> will be different. </p>

### 출력 

 <p>For each item, respectively, output where it ends up. </p>

<p>In case the item is stored successfully, output "LADICA" (without quotes, Croatian word for drawer). </p>

<p>In case the item is thrown away, output "SMECE" (without quotes, Croatian word for trash).</p>

