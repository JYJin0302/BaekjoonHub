# [Diamond I] Security Fence - 25783 

[문제 링크](https://acmicpc.net/problem/25783) 

### 성능 요약

메모리: 25684 KB, 시간: 2012 ms

### 분류

이분 탐색, 회전하는 캘리퍼스, 기하학, 반평면 교집합

### 제출 일자

2025년 02월 10일 17:05:43

### 문제 설명

<p><img alt="" src="" style="width: 305px; height: 176px; float: right;">You are the last vestige of hope in a world overrun by penguins. You are going to set up a sonic noise emitter array to keep the deranged beasts away from your camp. You have the perfect location to do so. There is already a fence set up to help keep out the beasts while building your weapon. The fence has been constructed by joining a series of rods embedded in the ground with straight sections of reinforced titanium sheets. Luckily the fence’s interior angles between the sheets of titanium are each less than 180 degrees. You cannot adjust the location of the fence’s rods or the titanium sheets, but the fence’s current location should hopefully suffice for the task at hand.</p>

<p>To complete the sonic noise emitter array, you need to build two towers and there is a minimum distance required between these two towers. You don’t want the penguins to interfere in your construction. To utilize the fence as much as possible, the towers need to be as far from the titanium sheets as possible while inside the fenced area.</p>

<p>Given the location of the rods of the fence and the minimum distance required between the two towers, determine the maximum possible distance the towers can be from their closest titanium sheets.</p>

### 입력 

 <p>The first input line contains two integers, N and D (3 ≤ N ≤ 10<sup>5</sup> and 1 ≤ D ≤ 10<sup>6</sup>), representing the number of rods that comprise the fence and the minimum distance required between the two towers. Each of the following N lines contains two integers, the ith of which are x<sub>i</sub> and y<sub>i</sub> (-10<sup>7</sup> ≤ x<sub>i</sub> ≤ 10<sup>7</sup> and -10<sup>7</sup> ≤ y<sub>i</sub> ≤ 10<sup>7</sup>) representing the x and y coordinate of the i th fence rod. The rod locations are given in a clockwise order. It is guaranteed that both towers can exist in the interior of the fenced region.</p>

### 출력 

 <p>Print on a single line by itself a single positive number: the furthest possible distance between the closest titanium sheet and towers. Answers within 10<sup>-6</sup> absolute or relative of the expected answers will be considered correct.</p>

