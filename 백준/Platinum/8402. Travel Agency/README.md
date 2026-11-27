# [Platinum I] Travel Agency - 8402 

[문제 링크](https://acmicpc.net/problem/8402) 

### 성능 요약

메모리: 2808 KB, 시간: 4 ms

### 분류

유량, 그래프, 최대 유량 최소 컷 정리

### 제출 일자

2026년 01월 31일 21:35:39

### 문제 설명

<p>The inhabitants of Byteland have recently begun to travel more often than ever before. Enterprising ByteMan has had an idea of opening a travel agency. In the first day <em>n</em> customers came to the agency (we label them with integers ranging from 1 to <em>n</em>) and each of them would like to go to a trip. Unfortunately, every customer has his requirements.</p>

<p>Your task is to help ByteMan in choosing the customers who should go to the trip so that ByteMan's profit is maximized.</p>

<p>Each customer told ByteMan what value has the trip for him/her. Let <em>x<sub>i</sub></em> be the value of the trip for the <em>i</em>-th customer (-1 000 000 ≤ <em>x<sub>i</sub></em> ≤ 1 000 000). If <em>x<sub>i</sub></em> ≥ 0, then this customer pays <em>x<sub>i</sub></em> debillars for the trip, and if <em>x<sub>i</sub></em> < 0, then ByteMan has to pay the <em>i</em>-th customer -<em>x<sub>i</sub></em> debillars if this customer goes to the trip.</p>

<p>Apart from financial requirements, customers also have social requirements. The <em>i</em>-th customer has <em>k<sub>i</sub></em> (0 ≤ <em>k<sub>i</sub></em> ≤ <em>n</em> - 1) such requirements; the <em>j</em>-th requirement of the <em>i</em>-th customer is represented by a pair of integers (a<sub>ij</sub>, <em>b<sub>ij</sub></em>), (1 ≤ <em>a<sub>ij</sub></em> ≤ <em>n</em>, <em>a<sub>ij</sub></em> ≠ i, 1 ≤ <em>b<sub>ij</sub></em> ≤ 1 000 000). This requirement means that if the <em>i</em>-th customer goes to the trip, then the <em>a<sub>ij</sub></em>-th customer also has to go to the trip or the cost of the trip for the <em>i</em>-th customer has to be lowered by <em>b<sub>ij</sub></em> debillars (it might happen in such way that for some customers the cost of the trip will decrease from positive to negative and ByteMan will have to pay some debillars to such customers, so they will go to the trip not having some of their social requirements satisfied).</p>

<p>Help ByteMan in choosing the customers who should go to the trip so that ByteMan's profit is maximized (the number of customers who can be taken to the trip is not bounded).</p>

### 입력 

 <p>In the first line there is exactly one integer <em>n</em> (1 ≤ <em>n</em> ≤ 1 000), denoting the number of customers of the travel agency. The next <em>n</em> lines describe the customers. In the <em>i</em> + 1-th line (1 ≤ <em>i</em> ≤ <em>n</em>) there are integers <em>x<sub>i</sub></em> (-1 000 000 ≤ <em>x<sub>i</sub></em> ≤ 1 000 000) and <em>k<sub>i</sub></em> (0 ≤ <em>k<sub>i</sub></em> ≤ <em>n</em> - 1), and after them <em>k<sub>i</sub></em> pairs of integers (a<sub>ij</sub>, <em>b<sub>ij</sub></em>) (1 ≤ <em>a<sub>ij</sub></em> ≤ <em>n</em>, <em>a<sub>ij</sub></em> ≠ i, 1 ≤ <em>b<sub>ij</sub></em> ≤ 1 000 000) - all numbers in the line are separated by single spaces. You may assume that every customer has at most one social requirement concerning any other customer.</p>

### 출력 

 <p>In the first line of any output file there should be exactly one integer <em>k</em> (0 ≤ <em>k</em> ≤ <em>n</em>) - the number of customers, who should be taken to the trip by ByteMan. If the number <em>k</em> is positive, then the second line should contain <em>k</em> integers, separated by single spaces and denoting the numbers of customers who should be taken to the trip. If there are many optimal solutions, the output file should contain one of them. The numbers of customers can be given in any order.</p>

