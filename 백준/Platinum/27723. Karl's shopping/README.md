# [Platinum IV] Karl's shopping - 27723 

[문제 링크](https://acmicpc.net/problem/27723) 

### 성능 요약

메모리: 12164 KB, 시간: 16 ms

### 분류

유량, 그래프

### 제출 일자

2026년 01월 06일 16:34:42

### 문제 설명

<p>Karl is going to spend his holiday in Nothingland. Since there is nothing there, he has to buy all supplies now. At the moment, he is waiting at the checkout counter with a shopping cart full of stuff.</p>

<p>Of course, he has a sufficient amount of money in his wallet. However, he prefers to use alternate means of payment if possible: luncheon vouchers, gift certificates, different types of coupons, etc. What makes the matter complicated is that the use of these items is often limited: e.g., luncheon vouchers can only be used to buy food, and gift certificates are often limited to a certain type of gifts.</p>

<p>You are given the number N of items in Karl’s shopping cart and their prices. You are also given the number M of vouchers in his wallet, together with the information on their allowed use.</p>

<p>When paying for his shopping, Karl may use vouchers for a larger sum than the cost of the things he is buying. It is also possible to split an item’s cost between multiple vouchers and use a voucher to pay for more than one item.</p>

<p>Compute the minimum amount of additional cash money Karl needs to pay for his shopping.</p>

### 입력 

 <p>The first line of input file contains an integer T specifying the number of test cases. T blocks follows, each block describes one test case. Each block is preceded by a blank line.</p>

<p>Each block starts with line containing two positive integers N (the number of items) and M (the number of vouchers). The second line contains N numbers A<sub>i</sub>, the i-th of them being the price of the i-th item in Karl’s shopping cart. The third line contains M numbers B<sub>i</sub>, the i-th of them being the cash value of the i-th voucher Karl has in his wallet. M lines follow. Each line consists of a number K<sub>i</sub> (the count of items such that you can pay for them using the i-th voucher) followed by K<sub>i</sub> numbers (the numbers of those items; items are numbered from 1 to N).</p>

### 출력 

 <p>For each test case output a single number specifying how much cash money Karl needs to pay for his shopping.</p>

