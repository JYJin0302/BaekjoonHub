# [Gold IV] 팬케이크 뒤집기 - 2759 

[문제 링크](https://acmicpc.net/problem/2759) 

### 성능 요약

메모리: 1984 KB, 시간: 0 ms

### 분류

해 구성하기, 그리디

### 제출 일자

2020년 08월 30일 17:03:51

### 문제 설명

<p>We start with a stack n of pancakes of distinct sizes. The problemis to convert the stack to one in which the pancakes are in size order with the smallest on the top and the largest on the bottom. To do this, we are allowed to flip the top k pancakes over as a unit (so the k-th pancake is now on top and the pancake previously on top is now in the k-th position). </p>

<p>For example:</p>

<p style="text-align: center;"><img alt="" src="" style="width: 575px; height: 118px;"></p>

<p>This problem is to write a program, which finds a sequence of at most max(0, 2n – 3) flips, which converts a given stack of pancakes to a sorted stack.</p>

### 입력 

 <p>Each line of the input gives a separate data set as a sequence of numbers separated by spaces. The first number on each line gives the number, N, of pancakes in the data set. The input ends when Nis 0 (zero) with no other data on the line. The remainder of the data set are the numbers 1 through N in some order giving the initial pancake stack. The numbers indicate the relative sizes of the pancakes. N will be, at most, 30. </p>

### 출력 

 <p>For each data set, the output is a single-space separated sequence of numbers on a line. The first number on each line, K, gives the number of flips required to sort the pancakes. This number is followed by a sequence of K numbers, each of which gives the number of pancakes to flip on the corresponding sorting step. There may be several correct solutions for some datasets. For instance 3 3 2 3 is also a solution to the first problem below. </p>

