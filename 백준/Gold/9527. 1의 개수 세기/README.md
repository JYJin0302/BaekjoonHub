# [Gold II] 1의 개수 세기 - 9527 

[문제 링크](https://acmicpc.net/problem/9527) 

### 성능 요약

메모리: 2016 KB, 시간: 0 ms

### 분류

비트마스킹, 수학, 누적 합

### 제출 일자

2021년 02월 18일 14:00:44

### 문제 설명

<p>Carl is right now the happiest child in the world: he has just learned this morning what the binary  system is. He learned, for instance, that the binary representation of a positive integer k is a string a<sub>n</sub>a<sub>n−1</sub> · · · a<sub>1</sub>a<sub>0</sub> where each ai is a binary digit 0 or 1, starting with a<sub>n</sub> = 1, and such that \(k = \sum_{i=0} ^{n} {a_i \times 2^i}\). It is really nice to see him turning decimal numbers into binary numbers, and then adding and even multiplying them.</p>

<p>Caesar is Carl’s older brother, and he just can’t stand to see his little brother so happy. So he has prepared a challenge: “Look Carl, I have an easy question for you: I will give you two integers A and B, and you have to tell me how many 1’s there are in the binary representation of all the integers from A to B, inclusive. Get ready”. Carl agreed to the challenge. After a few minutes, he came back with a list of the binary representation of all the integers from 1 to 100. “Caesar, I’m ready”. Caesar smiled and said: “Well, let me see, I choose A = 10<sup>15</sup> and B = 10<sup>16</sup>. Your list will not be useful”.</p>

<p>Carl hates loosing to his brother so he needs a better solution fast. Can you help him?</p>

### 입력 

 <p>A single line that contains two integers A and B (1 ≤ A ≤ B ≤ 10<sup>16</sup>).</p>

### 출력 

 <p>Output a line with an integer representing the total number of digits 1 in the binary representation of all the integers from A to B, inclusive.</p>

