# [Platinum III] Warehouse Store - 8234 

[문제 링크](https://acmicpc.net/problem/8234) 

### 성능 요약

메모리: 29040 KB, 시간: 260 ms

### 분류

자료 구조, 그리디, 우선순위 큐, 집합과 맵

### 제출 일자

2026년 01월 04일 14:28:50

### 문제 설명

<p>Byteasar runs a bricks and mortar warehouse store. This season's best seller, which accounts for majority of the store's revenue, is the laminate flooring. Unfortunately, it happens quite often that a customer makes an order that cannot be fulfilled, because there are not enough planks in the warehouse. To prevent losing customers, Byteasar has decided to minimize the number of such events.</p>

<p>To this end he has come up with a work schedule for the following n days. He has analyzed the contracts with the floors' producers and based on those he has determined a sequence a<sub>1</sub>,a<sub>2</sub>,…,a<sub>n</sub>. The number a<sub>i</sub> denotes that a<sub>i</sub> packages of planks are going to delivered to the warehouse in the morning of the i-th day.</p>

<p>Byteasar has also made a sheet of orders made by wholesalers, and based on those has determined another sequence b<sub>1</sub>,b<sub>2</sub>,…,b<sub>n</sub>. The number b<sub>i </sub>denotes that at noon of the i-th day a customer is going to make an order for b<sub>i</sub> packages of planks. If Byteasar decides to fulfill the customer's order, he will have to supply him with this many packages. If there are not enough packages in the warehouse when the order is made, Byteasar has to deny the order. If, on the other hand, there is a sufficient number of packages, Byteasar can decide whether he is going to accept the order or not.</p>

<p>Based on these data, Byteasar wants to determine which orders he should accept so that the total number of orders he denies (by choice or by necessity) is minimized. We assume that initially, in the early morning of the first day, the warehouse is empty.</p>

### 입력 

 <p>In the first line of the standard input there is an integer n (1 ≤ n ≤ 250,000). In the second line there is a sequence of integers a<sub>1</sub>,a<sub>2</sub>,…,a<sub>n</sub> (0 ≤ a<sub>i</sub> ≤ 10<sup>9</sup>). In the third line there is a sequence of integers b<sub>1</sub>,b<sub>2</sub>,…,b<sub>n</sub> (0 ≤ b<sub>i</sub> ≤ 10<sup>9</sup>). The numbers in the second and third line are separated by single spaces.</p>

<p>In tests worth 50% of the points the condition n ≤ 1,000 holds in addition.</p>

### 출력 

 <p>In the first line of the standard output your program should print an integer k  denoting the maximum number of orders that Byteasar can accept. In the second line an increasing sequence of k numbers should be printed, separated by single spaces. Those should be the numbers of customers whose orders should be accepted to that end. If no order can be accepted, the second line should be empty. The customers are numbered from 1 to n according to when they make their orders. If there is more than one correct answer, your program should pick one arbitrarily.</p>

<p> </p>

