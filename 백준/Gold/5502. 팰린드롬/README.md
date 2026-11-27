# [Gold III] 팰린드롬 - 5502 

[문제 링크](https://acmicpc.net/problem/5502) 

### 성능 요약

메모리: 99720 KB, 시간: 148 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2021년 05월 27일 22:05:14

### 문제 설명

<p>A palindrome is a symmetrical string, that is, a string read identically from left to right as well as from right to left. You are to write a program which, given a string, determines the minimal number of characters to be inserted into the string in order to obtain a palindrome.</p>

<p>As an example, by inserting 2 characters, the string "Ab3bd" can be transformed into a palindrome ("dAb3bAd" or "Adb3bdA"). However, inserting fewer than 2 characters does not produce a palindrome.</p>

### 입력 

 <p>The first line contains one integer: the length of the input string N, 3 ≤ N ≤ 5000. The second line contains one string with length N. The string is formed from uppercase letters from ‘A’ to ‘Z’, lowercase letters from ‘a’ to ‘z’ and digits from ‘0’ to ‘9’. Uppercase and lowercase letters are to be considered distinct.</p>

### 출력 

 <p>The first line contains one integer, which is the desired minimal number.</p>

