# [Gold II] The Great Spamway Strike - 6882 

[문제 링크](https://acmicpc.net/problem/6882) 

### 성능 요약

메모리: 2160 KB, 시간: 0 ms

### 분류

데이크스트라, 그래프, 최단 경로

### 제출 일자

2024년 10월 12일 13:38:48

### 문제 설명

<p>You may remember the Spamway messaging service. Spamway uses a pyramid scheme of zombie computers to solicit and receive orders for their fine products. However, Spamway has a problem – all its zombies have gone on strike for better RAM. Hence, Spamway has recruited replacement scab zombies so that they can continue doing business during the strike. These scab zombies are very disorganized and hence are not very good at networking.</p>

<p>Your job is to organize the scab zombies so that Spamway can solicit and receive product orders in the minimum amount of time. Specifically, you are to assign to each zombie a list of subordinates so that:</p>

<ol>
	<li>Each zombie except the head zombie has exactly one superior.</li>
	<li>Every zombie eventually reports to the head zombie.</li>
</ol>

<p>To initiate a round of ordering, the head zombie will simultaneously send a message to all of its subordinates requesting a list of purchase orders. A scab zombie, upon receiving such a message, will make a similar request of all of its subordinates. After receiving a reply from all of its subordinates, the scab zombie will combine the purchase lists contained therein with the list of purchase orders it received and send the combined purchase list to its superior.</p>

<p>So that you can organize the zombies, you need to know a few things:</p>

<ol>
	<li>A zombie can send any number of messages simultaneously.</li>
	<li>Every message takes 10 seconds to reach its destination (all data is highly compressed to achieve this spectacular efficiency).</li>
	<li>Spamway has one manager who is not on strike and who can act as the head zombie (the manager is the infamous computer ”localhost”).</li>
	<li>All zombies use cellular modems to communicate. However, because of poor coverage, not all zombies can talk to each other.</li>
	<li>Spamway is very frugal and will not use more than 100 zombies (including the manager acting as head zombie).</li>
	<li>So that the scab zombies cannot be identified and harmed (with a terrible virus) by the striking computers, all scab zombies are given a secret code name: Z0, Z1, Z2, Z3, ... and so on. Z0 is the head zombie.</li>
	<li>Scab zombies, due to their lack of training, take a certain amount of time to read a message once it has been received. Scab zombies can read many messages simultaneously, but they cannot act on the message before this reading is done. This lag time (called zombie zzz time) varies for each zombie, but is a non-negative integer number of seconds less than 1000. You can assume that zombie Z0 (the head zombie) has no lag time.</li>
</ol>

### 입력 

 <p>Input begins with an integer value n indicating the number of scab zombies that have been hired (not counting the manager acting as head zombie), 1 ≤ n ≤ 99. This integer is followed by n + 1 lines, each of which identifies the zombie zzz time for one particular zombie, followed by the number of zombies that can be reliably contacted and then a list of those zombies. The first line describes the head zombie, and the remaining n lines describe zombies Z1 through Zn, in that order.</p>

### 출력 

 <p>Output should consist of a single integer value indicating the total amount of time that is needed to send and receive the data for a single round of ordering. While there may be several possible zombie organizations, you are to find and report the time for the optimal one.</p>

