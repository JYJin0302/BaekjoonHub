# [Diamond IV] 유성 - 8217 

[문제 링크](https://acmicpc.net/problem/8217) 

### 성능 요약

메모리: 56460 KB, 시간: 2364 ms

### 분류

이분 탐색, 차분 배열 트릭, 자료 구조, 병렬 이분 탐색, 세그먼트 트리

### 제출 일자

2022년 12월 01일 15:37:26

### 문제 설명

<p>Byteotian Interstellar Union (BIU) has recently discovered a new planet in a nearby galaxy. The planet is unsuitable for colonisation due to strange meteor showers, which on the other hand make it an exceptionally interesting object of study.</p>

<p>The member states of BIU have already placed space stations close to the planet's orbit. The stations' goal is to take samples of the rocks flying by. The BIU Commission has partitioned the orbit into m sectors, numbered from 1 to m, where the sectors 1 and m are adjacent. In each sector there is a single space station, belonging to one of the n member states.</p>

<p>Each state has declared a number of meteor samples it intends to gather before the mission ends. Your task is to determine, for each state, when it can stop taking samples, based on the meteor shower predictions for the years to come.</p>

### 입력 

 <p>The first line of the standard input gives two integers, n and m (1 ≤ n,m ≤ 300,000), separated by a single space, that denote, respectively, the number of BIU member states and the number of sectors the orbit has been partitioned into.</p>

<p>In the second line there are m integers o<sub>i</sub> (1 ≤ o<sub>i</sub> ≤ n), separated by single spaces, that denote the states owning stations in successive sectors.</p>

<p>In the third line there are n integers p<sub>i</sub> (1 ≤ p<sub>i</sub> ≤ 10<sup>9</sup>), separated by single spaces, that denote the numbers of meteor samples that the successive states intend to gather.</p>

<p>In the fourth line there is a single integer k (1 ≤ k ≤ 300,000) that denotes the number of meteor showers predictions. The following  lines specify the (predicted) meteor showers chronologically. The i-th of these lines holds three integers  l<sub>i</sub>, r<sub>i</sub>, a<sub>i</sub> (separated by single spaces), which denote that a meteor shower is expected in sectors l<sub>i</sub>,l<sub>i+1</sub>,…,r<sub>i</sub>  (if l<sub>i</sub> ≤ r<sub>i</sub>) or sectors l<sub>i</sub>,l<sub>i+1</sub>,…,m,1,…,r<sub>i</sub> (if l<sub>i</sub> > r<sub>i</sub>), which should provide each station in those sectors with a<sub>i</sub> meteor samples (1 ≤ a<sub>i</sub> ≤ 10<sup>9</sup>).</p>

<p>In tests worth at least 20% of the points it additionally holds that n,m,k ≤ 1,000.</p>

### 출력 

 <p>Your program should print n lines on the standard output. The i-th of them should contain a single integer w<sub>i</sub>, denoting the number of shower after which the stations belonging to the i-th state are expected to gather at least p<sub>i</sub> samples, or the word NIE (Polish for no) if that state is not expected to gather enough samples in the foreseeable future.</p>

