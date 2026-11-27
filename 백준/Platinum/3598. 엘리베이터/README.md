# [Platinum III] 엘리베이터 - 3598 

[문제 링크](https://acmicpc.net/problem/3598) 

### 성능 요약

메모리: 2940 KB, 시간: 16 ms

### 분류

데이크스트라, 그래프, 수학, 최단 경로

### 제출 일자

2025년 01월 21일 14:39:26

### 문제 설명

<p>Edward works as an engineer for Non-trivial Elevators: Engineering, Research and Construction (NEERC). His new task is to design a brand new elevator for a skyscraper with h floors.</p>

<p>Edward has an id´ee ﬁxe: he thinks that four buttons are enough to control the movement of the elevator. His last proposal suggests the following four buttons:</p>

<ul>
	<li>Move a floors up.</li>
	<li>Move b floors up.</li>
	<li>Move c floors up.</li>
	<li>Return to the ﬁrst floor.</li>
</ul>

<p>Initially, the elevator is on the ﬁrst floor. A passenger uses the ﬁrst three buttons to reach the floor she needs. If a passenger tries to move a, b or c floors up and there is no such floor (she attempts to move higher than the h-th floor), the elevator doesn’t move.</p>

<p>To prove his plan worthy, Edward wants to know how many floors are actually accessible from the flrst floor via his elevator. Help him calculate this number.</p>

### 입력 

 <p>The first line of the input file contains one integer h — the height of the skyscraper (1 ≤ h ≤ 10<sup>18</sup>)</p>

<p>The second line contains three integers a, b and c — the parameters of the buttons (1 ≤ a,b,c ≤ 100,000)</p>

### 출력 

 <p>Output one integer number — the number of floors that are reachable from the first floor.</p>

