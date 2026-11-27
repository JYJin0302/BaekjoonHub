# [Diamond IV] Učiteljica - 32535 

[문제 링크](https://acmicpc.net/problem/32535) 

### 성능 요약

메모리: 63412 KB, 시간: 2004 ms

### 분류

자료 구조, 포함 배제의 원리, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리, 스위핑

### 제출 일자

2025년 07월 04일 16:31:41

### 문제 설명

<p>In the best school in Varaždin, there was an excellent computer science teacher known for her interesting and unusual ideas. Her name was Lana, and she often gave her students impossible or unsolvable problem. Each student only needed to solve 1 problem during the school year to pass the class with an excellent grade. Students who did not solve any tasks by the end of the year would have to repeat the grade. On the last day of school, she wrote an extremely difficult problem on the board, which went as follows:</p>

<p>Imagine you have a sequence of numbers of length $N$, and you can remove some elements from the beginning or the end (or both). How many ways can you perform such deletions so that after the deletion, there must be at least $1$ number that appears exactly once, at least $1$ number that appears exactly twice, . . ., and at least $1$ number that appears exactly $K$ times.</p>

<p>A student named Fran, who had not solved any problems so far, quickly said, "I know how to solve this problem." Teacher Lana did not believe Fran and told him, "Write the code in the next 30 minutes, and then I’ll believe you. If you don’t, you’ll have to repeat the grade." Fran doesn’t know how to code, so he urgently asked for your help to write the code to solve this task. In his hurry, he forgot to explain his idea for solving the task. Write a code that takes as input the numbers $N$ and $K$, the sequence of $N$ elements, and solve Lana’s question to help Fran.</p>

### 입력 

 <p>In the first line, there are $2$ positive integers $N$ ($1 ≤ N ≤ 10^5$) and $K$ ($1 ≤ K ≤ 4$) from the task description.</p>

<p>In the second line, there are $N$ positive integers $a_i$ ($1 ≤ a_i ≤ N$), the numbers from the task description.</p>

### 출력 

 <p>In the first line, print a whole number, the number of distinct deletions such that the conditions from the task hold. Two deletions are different if there is an index that is not deleted in one, but deleted in the other.</p>

