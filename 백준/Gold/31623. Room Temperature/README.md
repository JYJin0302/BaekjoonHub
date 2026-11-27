# [Gold II] Room Temperature - 31623 

[문제 링크](https://acmicpc.net/problem/31623) 

### 성능 요약

메모리: 5928 KB, 시간: 92 ms

### 분류

그리디, 정렬

### 제출 일자

2025년 07월 14일 19:20:16

### 문제 설명

<p>President K is taking on the role of adjusting the room temperature of the officers’ room. He wants to make the officers as comfortable as possible.</p>

<p>Now there are $N$ officers in the room. Each officer is numbered from $1$ to $N$, and the appropriate temperature for officers $i$ ($1 ≤ i ≤ N$) is $A_i$ degrees when (s)he is not wearing jackets. For each officer, the appropriate temperature drops by $T$ degrees every time (s)he wears a jacket. In other words, when the officer $i$ is wearing $k$ jackets, her/his appropriate temperature is $A_i − kT$ degrees.</p>

<p>When the room temperature is $x$ degrees and the appropriate temperature of a certain officer is $y$ degrees, the <strong>discomfort index</strong> of the officer is expressed as $|x − y|$. Note that $|t|$ represents the absolute value of $t$. Each officer wears the appropriate number of jackets of $0$ or more to minimize discomfort index, depending on the room temperature.</p>

<p>Here, president K decided to call the maximum discomfort index among all officers as <strong>room’s unpleasantness</strong>, and set the room temperature so that the room’s unpleasantness was minimized. Note that the room temperature must be an integer.</p>

<p>Write a program which, given information about the officers and the appropriate temperature, calculates the minimum room’s unpleasantness.</p>

### 입력 

 <p>Read the following data from the standard input.</p>

<blockquote>
<p>$N$ $T$</p>

<p>$A_1$ $A_2$ $\cdots$ $A_N$</p>
</blockquote>

### 출력 

 <p>Write one line to the standard output. The output should contain the minimum room’s unpleasantness.</p>

