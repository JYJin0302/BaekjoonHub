# [Gold II] Nunchucks Shop - 20245 

[문제 링크](https://acmicpc.net/problem/20245) 

### 성능 요약

메모리: 2044 KB, 시간: 0 ms

### 분류

조합론, 수학

### 제출 일자

2023년 08월 11일 18:33:39

### 문제 설명

<p>Nathan owns a shop that sells souvenir nunchucks with unique design. Nunchucks is a traditional martial arts weapon consisting of two sticks connected with a chain. In Nathan's design, each stick is inlayed with $n$ gemstones arranged in a row. These gemstones are either quartz or onyx, and they create a nice black-and-white pattern. For aesthetics reasons, Nathan sells only nunchucks with exactly $k$ onyxes on both sticks in total. For example, here is one of the possible designs for $n=4$ and $k=5$.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 404px; height: 44px;"></p>

<p>Recently Nathan decided that it will be good to be able to sell nunchucks with every possible design. But that will require him to have nunchucks with all possible designs in the storage, and the number of possible designs is huge! </p>

<p>Thus, Nathan decided to compromise. He will have a number of sticks in his storage. When a customer orders some design, Nathan will take two sticks from the storage and combine them with a chain. Sticks are symmetrical, and Nathan can connect the chain to any end of the stick. For example, if $n=3$ and $k=2$, and Nathan has these sticks in the storage:</p>

<p style="text-align: center;"><img alt="" src="" style="width: 565px; height: 66px;"></p>

<p>Then he can make nunchucks of any possible design. For example, if the customer asks for nunchucks of this design:</p>

<p style="text-align: center;"><img alt="" src="" style="width: 254px; height: 35px;"></p>

<p>Then Nathan can make it from sticks 1 and 3.</p>

<p>Now Nathan wonders: what is the minimum number of sticks he should have in the storage to be able to make nunchucks of any possible design? Help him find this number.</p>

### 입력 

 <p>The input contains two integers $n$ and $k$ ($1\le n\le 50$; $0\le k\le 2\cdot n$).</p>

### 출력 

 <p>Output one integer: the minimum number of sticks Nathan should have in the storage.</p>

