# [Diamond IV] Smart Thief - 16575 

[문제 링크](https://acmicpc.net/problem/16575) 

### 성능 요약

메모리: 64264 KB, 시간: 56 ms

### 분류

오일러 경로, 그래프, 무작위화

### 제출 일자

2023년 08월 07일 19:02:42

### 문제 설명

<p>Ayu managed to steal Budi’s treasure box and ready to uncover any secret Budi hides. Unfortunately, the treasure box has some security system to prevent any unauthorized person (e.g., Ayu) from opening it.</p>

<p>To unlock the treasure box, Ayu has to input a correct PIN (Personal Identification Number) of length N, which of course, she doesn’t have. Ayu has no choice other than trying all possible PIN combinations. However, Ayu notices that this security system has an interesting (old) mechanism.</p>

<p>When you enter an N digits PIN, it is evaluated automatically and promptly, i.e. you don’t need to push some “enter” button to confirm the PIN. Whenever your entered PIN is wrong, it removes the oldest (first) digit and shifts all the remaining to the left, thus, you only need to enter one more (last) digit to make it N length again.</p>

<p>For example, let N = 4. If we input 204320435, then we actually test 6 PINs (with 5 different PINs):</p>

<ul>
	<li>[2043]20435, tested PIN = 2043</li>
	<li>2[0432]0435, tested PIN = 0432</li>
	<li>20[4320]435, tested PIN = 4320</li>
	<li>204[3204]35, tested PIN = 3204</li>
	<li>2043[2043]5, tested PIN = 2043</li>
	<li>20432[0435], tested PIN = 0435</li>
</ul>

<p>Notice that 2043 is tested twice in this example.</p>

<p>As a CS student, Ayu knows that finding the correct PIN by trying all possible combinations can be very time-consuming, but alas, there’s no other way. Ayu decides that she wants to test at least K different PINs on the first day. Your task is to help Ayu by simply giving her the string S which contains at least K different PINs. Ayu doesn’t care which PIN she’s going to test (so long at least there are K different PINs) or whether any PIN is tested more than once in S, but string S needs to be as short as possible. If there is more than one possible string for S, you can output any of them.</p>

<p>Note that, as this system is quite old, there are only M available digits ranging from 0 to 9.</p>

### 입력 

 <p>Input begins with a line containing three integers: N M K (1 ≤ N ≤ 100000, 1 ≤ M ≤ 10, 1 ≤ K ≤ min(M<sup>N</sup> , 100000)), representing the PIN length, the number of available digits, and the minimum number of PINs to be tested, respectively. The next line contains M integers: A<sub>i</sub> (0 ≤ A<sub>i</sub> ≤ 9), representing the available digits. You may assume all A<sub>i</sub> are distinct. You may also assume that the values of N, M, and K are chosen such that the answer contains no longer than 100000 digits.</p>

### 출력 

 <p>Output in a line the shortest string which contains at least K different PINs as its substring. If there is more than one such string, you can output any of them.</p>

