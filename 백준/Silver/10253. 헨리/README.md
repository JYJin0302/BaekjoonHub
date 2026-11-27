# [Silver I] 헨리 - 10253 

[문제 링크](https://acmicpc.net/problem/10253) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

유클리드 호제법, 구현, 수학, 정수론

### 제출 일자

2022년 01월 29일 22:10:08

### 문제 설명

<p>Henry, a 10 year old boy, has just learned about the concept of fractions today from his math teacher Ahmes. Henry liked so much to play with fractions, and all of a sudden found it funny to represent a fraction by the sum of different fractions. Henry has tried many fractions, and discovered that all fractions he tried can be represented by a sum of distinct unit fractions. A unit fraction is a fraction whose numerator is 1. For example, \(\frac{4}{23}\) can be represented as \(\frac{1}{6} + \frac{1}{138}\). </p>

<p>Henry told his discovery to Ahmes. Ahmes was so happy about the little boy’s brilliant discovery, and named such a representation of a fraction a Henry representation. That is, a Henry representation of fraction \(\frac{a}{b}\) is a series of distinct unit fractions that sum up exactly to \(\frac{a}{b}\). Henry and Ahmes continued studying Henry representations. At last they found that every fraction that is smaller than 1 indeed has a Henry representation and may have many different ones: for example, \(\frac{5}{7} = \frac{1}{2} + \frac{1}{5} + \frac{1}{70} = \frac{1}{2}+\frac{1}{6} + \frac{1}{21} = \frac{1}{2} + \frac{1}{7} + \frac{1}{14}\). Also, notice by definition that \(\frac{2}{3} = \frac{1}{3} + \frac{1}{3}\) is not a Henry representation because that contains two equal unit fractions \(\frac{1}{3}\). </p>

<p>Ahmes and Henry also found an easy procedure to find a Henry representation of a given fraction, described as follows: given a fraction \(\frac{a}{b}\) where \(a\) and \(b\) are positive integers with \(a < b\), choose the largest unit fraction \(\frac{1}{x_1}\) such that \(\frac{1}{x_1} \le \frac{a}{b}\). Then, subtract \(\frac{1}{x_1}\) from \(\frac{a}{b}\), and repeat the process for the remainder: choose the largest unit fraction \(\frac{1}{x_2}\) such that \(\frac{1}{x_2} \le \frac{a}{b} - \frac{1}{x_1}\). Repeat again until there is no remainder. This procedure will result in a series of unit fractions \(\frac{1}{x_1}, \frac{1}{x_2}, \frac{1}{x_3}, \dots\) that sum up to the given fraction \(\frac{a}{b}\). Ahmes and Henry proved that this procedure always terminates for any input fraction \(\frac{a}{b}\) with a finite number of distinct unit fractions, that is, a Henry representation. </p>

<p>Ahmes and Henry want to have their algorithm implemented by you. Given a fraction \(\frac{a}{b}\), you are to write a computer program that prints out the denominator of the last fraction in the resulting Henry representation of their algorithm. For example, if \(\frac{a}{b} = \frac{5}{7}\), then your program must print out 70 since the algorithm will terminate with a Henry representation \(\frac{5}{7} = \frac{1}{2} + \frac{1}{5} + \frac{1}{70}\).</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case consists of a line containing two integers \(a\) and \(b\) ( 1 ≤ \(a\) < \(b\) ≤ 10,000 ) that are relatively prime, representing the input fraction \(\frac{a}{b}\). Note that if \(\frac{1}{x_1},\frac{1}{x_2},\frac{1}{x_3},\cdots,\frac{1}{x_m}\) are the unit fractions produced by Ahmes and Henry’s algorithm in order for the input \(\frac{a}{b}\), then you can assume that  \(bx_1x_2 \cdots x_{m-1} < 2^{31}\) .</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain an integer representing the denominator of the last fraction in the resulting Henry representation of Ahmes and Henry’s algorithm for the input fraction \(\frac{a}{b}\)</p>

