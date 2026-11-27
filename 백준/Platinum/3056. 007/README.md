# [Platinum V] 007 - 3056 

[문제 링크](https://acmicpc.net/problem/3056) 

### 성능 요약

메모리: 19344 KB, 시간: 140 ms

### 분류

비트마스킹, 비트필드를 이용한 DP, 다이나믹 프로그래밍

### 제출 일자

2024년 10월 07일 18:01:22

### 문제 설명

<p>Everyone knows of the secret agent double-oh-seven, the popular Bond (James Bond). A lesser known fact is that he actually did not perform most of his missions by himself; they were instead done by his cousins, Jimmy Bonds. Bond (James Bond) has grown weary of having to distribute assign missions to Jimmy Bonds every time he gets new missions so he has asked you to help him out. </p>

<p>Every month Bond (James Bond) receives a list of missions. Using his detailed intelligence from past missions, for every mission and for every Jimmy Bond he calculates the probability of that particular mission being successfully completed by that particular Jimmy Bond. Your program should process that data and find the arrangement that will result in the greatest probability that all missions are completed successfully.</p>

<p>Note: the probability of all missions being completed successfully is equal to the product of the probabilities of the single missions being completed successfully. </p>

### 입력 

 <p>The first line will contain an integer N, the number of Jimmy Bonds and missions (1 ≤ N ≤ 20). </p>

<p>The following N lines will contain N integers between 0 and 100, inclusive. The j-th integer on the ith line is the probability that Jimmy Bond i would successfully complete mission j, given as a percentage.</p>

### 출력 

 <p>Output the maximum probability of Jimmy Bonds successfully completing all the missions, as a percentage. </p>

<p>Note: Outputs within ±0.000001 of the official solution will be accepted. </p>

