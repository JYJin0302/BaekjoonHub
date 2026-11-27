# [Diamond II] 팀의 난이도 - 3611 

[문제 링크](https://acmicpc.net/problem/3611) 

### 성능 요약

메모리: 5252 KB, 시간: 20 ms

### 분류

이분 탐색, 유량, 그래프, 매개 변수 탐색, 최대 유량 최소 컷 정리

### 제출 일자

2026년 02월 10일 15:52:57

### 문제 설명

<p>John is a Chief Executive Oﬃcer at a privately owned medium size company. The owner of the company has decided to make his son Scott a manager in the company. John fears that the owner will ultimately give CEO position to Scott if he does well on his new manager position, so he decided to make Scott’s life as hard as possible by carefully selecting the team he is going to manage in the company.</p>

<p>John knows which pairs of his people work poorly in the same team. John introduced a hardness factor of a team — it is a number of pairs of people from this team who work poorly in the same team divided by the total number of people in the team. The larger is the hardness factor, the harder is this team to manage. John wants to ﬁnd a group of people in the company that are harderst to manage and make it Scott’s team. Please, help him.</p>

<p><img alt="" src="" style="height:154px; width:155px"></p>

<p>In the example on the picture the hardest team consists of people 1, 2, 4, and 5. Among 4 of them 5 pairs work poorly in the same team, thus hardness factor is equal to 5/4. If we add person number 3 to the team then hardness factor decreases to 6/5.</p>

### 입력 

 <p>The ﬁrst line of the input ﬁle contains two integer numbers n and m (1 ≤ n ≤ 100, 0 ≤ m ≤ 1000). Here n is a total number of people in the company (people are numbered from 1 to n), and m is the number of pairs of people who work poorly in the same team. Next m lines describe those pairs with two integer numbers a<sub>i</sub> and b<sub>i</sub> (1 ≤ a<sub>i</sub>, b<sub>i</sub> ≤ n, a<sub>i</sub> ≠ b<sub>i</sub>) on a line. The order of people in a pair is arbitrary and no pair is listed twice.</p>

### 출력 

 <p>Write to the output ﬁle an integer number k (1 ≤ k ≤ n) — the number of people in the hardest team, followed by k lines listing people from this team in ascending order. If there are multiple teams with the same hardness factor then write any one.</p>

