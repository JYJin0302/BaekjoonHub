# [Platinum II] Find and Replace - 27558 

[문제 링크](https://acmicpc.net/problem/27558) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

애드 혹, 많은 조건 분기, 그래프

### 제출 일자

2025년 03월 29일 22:46:37

### 문제 설명

<p>Bessie is using the latest and greatest innovation in text-editing software, miV! She starts with an input string consisting solely of upper and lowercase English letters and wishes to transform it into some output string. With just one keystroke, miV allows her to replace all occurrences of one English letter $c_1$ in the string with another English letter $c_2$. For example, given the string <code>aAbBa</code>, if Bessie selects $c_1$ as 'a' and $c_2$ as 'B', the given string transforms into <code>BAbBB</code>.</p>

<p>Bessie is a busy cow, so for each of $T$ ($1\le T\le 10$) independent test cases, output the minimum number of keystrokes required to transform her input string into her desired output string.</p>

### 입력 

 <p>The first line contains $T$, the number of independent test cases.</p>

<p>The following $T$ pairs of lines contain an input and output string of equal length. All characters are upper or lowercase English letters (either A through Z or a through z). The sum of the lengths of all strings does not exceed $10^5$.</p>

### 출력 

 <p>For each test case, output the minimum number of keystrokes required to change the input string into the output string, or $-1$ if it is impossible to do so.</p>

