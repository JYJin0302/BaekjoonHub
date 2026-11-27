# [Bronze III] 이교수님의 시험 - 10874 

[문제 링크](https://acmicpc.net/problem/10874) 

### 성능 요약

메모리: 2016 KB, 시간: 0 ms

### 분류

구현

### 제출 일자

2021년 01월 05일 11:33:24

### 문제 설명

<p>Dr. L is a professor at University of Computer Programming Contest (UCPC). His courses are famous for the final exam, which is a multiple choice test. There are ten problems in the test and students have to select the best possible answer from the five choices. This is why students at UCPC love to take his courses. However, the problems are usually tough and students can hardly get full marks in the exam. </p>

<p>This semester, an amazing thing happened; in one of his courses, the correct answers of the exam problems have formed a certain pattern! The correct answer of the j-th problem was ((j − 1) mod 5) + 1, where mod denotes the remainder operation. For example, the correct answer of the first problem was ((1 − 1) mod 5) + 1 = 1, and the correct answer of the eighth problem was ((8 − 1) mod 5) + 1 = 3, etc. Note that the 10 problems are numbered from 1 to 10, and the 5 choices of the problems are numbered from 1 to 5.</p>

<p>It is, however, not amazing that the students at UCPC are brilliant enough to reveal this pattern during the examination time. After solving first few problems in the exam (which are relatively easy), a lot of students have discovered the above formula and could answer the other hard problems without actually solving them. This is definitely cheating, so Dr. L decided to retest the students who got a perfect score, with a new different set of exam problems (and of course, without any kind of pattern of the answers).</p>

<p>Given answer sheets of N students, write a program that computes the list of students who should retake the exam.</p>

### 입력 

 <p>The first line contains one integer N (1 ≤ N ≤ 100), which denotes the number of students who took the exam. Each of the following N lines contain ten integers between 1 and 5; the j-th number in the i-th line denotes the choice made by the i-th student for the j-th exam problem (1 ≤ i ≤ N, 1 ≤ j ≤ 10). The numbers in the same line of the input are separated by a single space.</p>

### 출력 

 <p>Print the number of the students who should retake the exam, sorted in ascending order. Each student number must be on a separate line.</p>

