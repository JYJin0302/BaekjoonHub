# [Gold I] 곱하기 게임 - 2062 

[문제 링크](https://acmicpc.net/problem/2062) 

### 성능 요약

메모리: 2732 KB, 시간: 8 ms

### 분류

자료 구조, 게임 이론, 우선순위 큐

### 제출 일자

2024년 04월 14일 21:40:45

### 문제 설명

<p>Nils and Mikael are intergalaxial ﬁghters. Now they are competing for the planet Tellus. The size of this small and unimportant planet is 1 < X < 10000 gobs. The problem is that their pockets only have room for one gob, so they have to reduce the size of the planet. They have available 1 ≤ K ≤ 6 FACTOR-weapons characterized by numbers F<sub>1</sub>, F<sub>2</sub>, . . . , F<sub>k</sub>, all less than 0.9. As is commonly known, a FACTOR-weapon will blow off part of the planet, thus reducing the planet to a fraction of its size, given by the characteristic. Thus, with e.g. F<sub>1</sub> = 0.5 an application of the ﬁrst weapon will half the size of the planet. The ﬁghter who reduces the size to less than, or equal to, 1 gob can take the planet home with him. They take turns attacking the planet with any weapon. If Nils starts, who will win the planet? Assume that both Nils and Mikael are omniscient and always make a winning move if there is one.</p>

<p>Technical note: To ease the problem of rounding errors, there will be no edge cases where an inﬁnitesimal perturbation of the input values would cause a different answer.</p>

### 입력 

 <p>The ﬁrst line of input is N ≤ 100, the number of test cases. Each of the next N lines consists of X, K and then the K numbers F<sub>1</sub>, F<sub>2</sub>, . . . , F<sub>k</sub>, having no more than 6 decimals</p>

### 출력 

 <p>For each test case, produce one line of output with the name of the winner (either Nils or Mikael).</p>

