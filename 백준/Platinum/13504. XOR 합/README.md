# [Platinum III] XOR 합 - 13504 

[문제 링크](https://acmicpc.net/problem/13504) 

### 성능 요약

메모리: 50600 KB, 시간: 3220 ms

### 분류

자료 구조, 누적 합, 트리, 트라이

### 제출 일자

2023년 02월 28일 19:40:04

### 문제 설명

<p>Given an array of N numbers, we wish to choose a contiguous sub-sequence of the array, so that the bitwise XOR of all chosen numbers is maximum. Bitwise XOR is defined as follows: every bit in the answer is obtained by applying XOR logic on the corresponding bits of the set of numbers. For example 7, 8 and 5 are XORed as follows,</p>

<p>Numbers in binary:  0111  1000  0101  -----  1010</p>

<p>So the answer is 10 (in decimal). The same answer can be obtained in C/C++/Java by using the XOR operator as 7^8^5.</p>

### 입력 

 <p>The first line contains the number of test cases T. The first line of each test-case contains one integer, N (size of the array). The next N lines of each test-case contain integers denoting the elements of the array.</p>

<p>Constraints:</p>

<ul>
	<li>1 ≤ T ≤ 10</li>
	<li>1 ≤ N ≤ 100, 000</li>
	<li>All input integers will be non-negative and fit into 32 bit signed integer.</li>
</ul>

### 출력 

 <p>For each test case, output a single line containing the maximum sum that can be obtained.</p>

