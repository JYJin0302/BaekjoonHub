# [Bronze II] 펫 - 1362 

[문제 링크](https://acmicpc.net/problem/1362) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현, 시뮬레이션

### 제출 일자

2022년 12월 19일 23:27:40

### 문제 설명

<p>My young cousin, Jo, has a virtual pet toy. It is a funny looking ‘animal’ that has either a smiley face if it is happy or a sad face if it is sad. If it should die, it ‘lies down’.</p>

<p>The pet has an optimum weight. If its actual weight is more than half but less than twice its optimum weight then the pet is happy. If its weight drops to 0 or less, it dies. Other than that, the pet is sad.</p>

<p>Jo can interact with the pet in two ways: give it food or make it exercise. To make the pet exercise, Jo has to enter a number to say how many minutes of exercise are to be done then press the ‘E’ button on the game console. To feed the pet, Jo again enters a number, this time the amount of food units given, and presses the ‘F’ button. The console can only accept a number between 1 and 999.</p>

<p>Both activities cause the pet to change weight. For every minute of exercise done, the pet loses one unit of body weight. For every unit of food eaten, the pet puts on one unit of body weight. After each activity, the pet’s state is displayed. Once the pet is dead it ignores all future attempts to feed or exercise it. This problem gets you to mimic Jo’s pet game.</p>

### 입력 

 <p>Input consists of a number of scenarios. Each starts with a line containing two numbers, o and w. o is the optimum weight of the pet, w is its actual weight at the start of the scenario (10 ≤ o, w ≤ 1000). Input ends with a line containing ‘0 0’—this line should not be processed.</p>

<p>Subsequent lines of each scenario contain actions by Jo. Each action starts with the letter of the button pressed, ‘E’ or ‘F’, followed by a space then a number, n (1 ≤ n ≤ 999). The last action line will be ‘# 0’. This line terminates the scenario and should not be processed.</p>

### 출력 

 <p>Output will be the scenario number followed by a space, then the state of the pet (see below) once all actions are completed.</p>

<ul>
	<li>For a happy pet, display ‘:-)’.</li>
	<li>For a sad pet, display ‘:-(’.</li>
	<li>For a dead pet, display ‘RIP’.</li>
</ul>

