# [Platinum II] 돌연변이 - 10256 

[문제 링크](https://acmicpc.net/problem/10256) 

### 성능 요약

메모리: 30532 KB, 시간: 800 ms

### 분류

아호-코라식, 자료 구조, 문자열, 트리, 트라이

### 제출 일자

2024년 01월 17일 14:33:19

### 문제 설명

<p>The human DNA sequence can be considered as a long string made up with four letters, A, G, T, and C. It is known that some diseases are related to a marker, a short substring of the DNA sequence. If your DNA contains it, then it is likely that you have a higher probability of suffering from those diseases. </p>

<p>Sometimes it is not enough to find markers from your DNA sequences. Mutation can change the marker. That is, the marker can be divided into three parts and the middle one can be reversed. Note that the first or the third one can be an empty string. For example, if the marker is AGGT, considering the mutation, there can be six cases: GAGT, GGAT, TGGA, AGGT, ATGG, and AGTG. </p>

<p>Given your DNA sequence and the marker, write a program which computes the number of occurrences of the marker or its mutations. For example, if your DNA sequence is ATGGAT and the marker is AGGT again, the answer is 3 as it includes ATGG, TGGA, and GGAT. </p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with integers n and m, the length of your DNA sequence and that of the marker, respectively, where 1 ≤ n ≤ 1, 000, 000 and 1 ≤ m ≤ 100. The second line of each test case contains your DNA sequence. The third line of each test case contains the marker. All the strings are made up with four letters, A, G, T, and C. </p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain an integer which is the number of occurrences of the marker and its mutated strings in your DNA sequence. If there is no such occurrence, print 0. </p>

