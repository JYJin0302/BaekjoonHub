# [Platinum II] 복도 뚫기 - 9373 

[문제 링크](https://acmicpc.net/problem/9373) 

### 성능 요약

메모리: 18576 KB, 시간: 964 ms

### 분류

자료 구조, 분리 집합, 기하학, 그래프, 최소 스패닝 트리

### 제출 일자

2021년 06월 12일 23:32:07

### 문제 설명

<p>A long and straight corridor is ﬁtted with a number of sensors. Each sensor has a certain range within which it can detect objects or persons. If a part of an object is within the sensor’s range, an alarm will go off. Otherwise, nothing will happen.</p>

<p>Ethan needs to traverse this corridor in order to do some spy stuff at the other end. The question is, can he pass through the corridor without being detected? Can he ﬁt so easily that he can bring some equipment along, or does he have to wear some tight clothing? Or can he perhaps sent a robot through instead?</p>

<p>We model the corridor as being two-dimensional (we ignore the height), bounded by two straight lines. Each sensor is located inside the corridor or on a wall. Their scopes are well in between the two ends of the corridor. We model the person or robot going through as a circle. Given the layout, what is the maximum radius this circle can have so that it is possible to negotiate the corridor without being detected?</p>

<p><img alt="" src="" style="height:247px; width:418px"></p>

<p>A visual representation of the samples.</p>

<p> </p>

### 입력 

 <p>On the ﬁrst line one positive number: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>one line with a single integer w (1 ≤ w ≤ 100 000): the width of the corridor. The two walls are given by the lines x = 0 and x = w.</li>
	<li>one line with a single integer n (0 ≤ n ≤ 1 000): the number of sensors in the corridor.</li>
	<li>n lines with three space-separated integers x, y and r (0 ≤ x ≤ w, -100 000 ≤ y ≤ 100 000 and 1 ≤ r ≤ 100 000): the location and the range of each sensor, respectively.</li>
</ul>

<p>The two ends of the corridor are at y = -∞ and y = +∞, or in less technical terms, they are far beyond the scope of all the sensors.</p>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>one line with one ﬂoating point number: the radius of the largest circular object (or person) that could pass through the corridor without being detected, assuming the object can (be) move(d) with absolute precision. If nothing could possibly get through, the output should be zero. The number should be accurate up to 10<sup>-6</sup> absolute precision.</li>
</ul>

