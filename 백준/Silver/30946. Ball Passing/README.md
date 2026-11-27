# [Silver I] Ball Passing - 30946 

[문제 링크](https://acmicpc.net/problem/30946) 

### 성능 요약

메모리: 2040 KB, 시간: 0 ms

### 분류

기하학, 그리디

### 제출 일자

2024년 02월 22일 14:57:14

### 문제 설명

<p>A group of students has just finished their math lesson and they're heading out for physical education. Their teacher has asked them to arrange themselves in a circle. After several minutes of busy moving around the court they have finally managed to position themselves so that they form a <em>strictly convex polygon</em>. They might not lie on the circle, but the teacher is happy to at least get some structure.</p>

<p>There is an even number of boys and an even number of girls in this group of $N$ students. They will practice ball passing in pairs, therefore the teacher has to pair them up. The teacher will pair boys among themselves and the same for girls.</p>

<p>The school administration has decided to address the decline in physical performance of their students. Therefore, they have implemented a quality measure for ball passing practice, which is the total distance traveled by the balls in a single round of ball passes between each pair. Help the teacher pair up the students in a way that will maximize this measure.</p>

### 입력 

 <p>The first line contains the number of students $N$. The second line contains a string $S$ of length $N$, which describes the students along the perimeter of the polygon with a character "<code>B</code>" for a boy and "<code>G</code>" for a girl. The following $N$ lines provide the locations of students with space-separated integer coordinates $X_i$ and $Y_i$ in the same order as they are described in the string $S$.</p>

### 출력 

 <p>Output the maximum ball passing distance that can be obtained by pairing up the students appropriately. The solution will be considered correct if the relative or absolute error compared to the official solution is within $10^{-6}$.</p>

