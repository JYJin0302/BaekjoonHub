# [Platinum V] 불끄기 - 1819 

[문제 링크](https://acmicpc.net/problem/1819) 

### 성능 요약

메모리: 2580 KB, 시간: 0 ms

### 분류

비트마스킹, 비트필드를 이용한 DP, 다이나믹 프로그래밍, 구현, 역추적

### 제출 일자

2024년 05월 01일 18:33:07

### 문제 설명

<p>The cows so much prefer to sleep in the dark. Every night, though, when they return to the barn, some of the L (3 <= L <= 50) lights are switched on. They know the location of the push button switches but, as is always the problem, they lack fingers. The buttons are arranged in a nice row, and the left most button (#1) toggles light #1; the next button to the right toggles light #2; and so on. ('Toggle' means change from off-to-on or on-to-off, depending on the current state of the switch.)</p>

<p>They do however have an unusual pitchfork with T (1 <= T <= 7) slots, each one of which might hold a tine that can push the switches. Some tines are present; some might be absent. By way of example, imagine a pitchfork with T=4 and a missing tine. This particular pitchfork has tines in the 1st, 2nd, and 4th positions, easily described as '1101'.</p>

<p>If the pitchfork is aimed at the leftmost switch, then lights #1, #2, and #4 are toggled (#3 isn't toggled since there is no tine there). If the pitchfork is aimed at switch #3, then lights #3, #4, and #6 are toggled. The pitchfork must be aimed so that all its tine slots touch switches; the fork cannot cross the end of the line of switches.</p>

<p>Given a list of lights that are on and a configuration for a pitchfork, determine a sequence of pitchfork presses that will toggle the lights until the minimum number of lights is lit.</p>

### 입력 

 <p>* Line 1: Two space-separated integers: L and T</p>

<p>* Line 2: A line with L characters (and no spaces), each of which is '0' or '1'. '1' means a light in that slot is lit; '0' means the light in that slot is not lit.</p>

<p>* Line 3: A line with T characters, each of which is '0' or '1' (no spaces are present). '1' means a tine is present on the pitchfork in that slot; '0' means otherwise.  The pitchfork can not be inverted.</p>

### 출력 

 <p>* Line 1: K, the number of positions at which the pitchfork was aimed.</p>

<p> </p>

