# [Platinum V] Contact Tracing - 25225 

[문제 링크](https://acmicpc.net/problem/25225) 

### 성능 요약

메모리: 2632 KB, 시간: 0 ms

### 분류

애드 혹, 그래프, 그래프 탐색

### 제출 일자

2025년 11월 04일 14:21:29

### 문제 설명

<p>A novel infectious disease has started spreading through the population. You are tasked with figuring out who might be infected in order to get them to quarantine. The behavior of the disease among members of the population is as follows:</p>

<ul>
	<li>When a person comes into contact with someone who is infectious, they may (but do not always) catch the disease. If they catch the disease, they are not infectious for the rest of that day, so they will not spread it to other people they come into contact with that day.</li>
	<li>When a person catches the disease, they are infectious starting the day after they caught the disease.</li>
	<li>Starting two days after they caught the disease, they are symptomatic; as a result, they will quarantine themselves and not come into contact with any other people from then on.</li>
</ul>

<p>You know that on day $0$, a single Patient Zero (of unknown identity) caught the disease. On day $1$, they were infectious and potentially came into contact with people, potentially infecting those people. On day $2$, Patient Zero became symptomatic and therefore stopped coming into contact with other people, but any people who were infected on day $1$ could potentially spread the disease to the people they come into contact with.</p>

<p>Today is day $k$, and it is the end of the day. You have access to a list of all pairs of people who came into contact with each other on each day, including today. If you can identify all people who could be infectious but not symptomatic tomorrow (because they caught the disease today) and tell them to quarantine, you can halt the outbreak, because all people who are symptomatic tomorrow will quarantine themselves anyway. What is the minimum number of people you need to tell to quarantine to be sure that you halt the outbreak?</p>

### 입력 

 <p>The first line of input contains three integers $n$ ($1 \leq n \leq 1\,000$), $k$ ($1 \leq k \leq 10$), and $c$ ($0 \leq c \leq 1\,000$), where $n$ is the number of people, $k$ is the number of days since Patient Zero became infected, and $c$ is the number of contacts that occurred between people.</p>

<p>Each of the next $c$ lines contains three space-separated integers $a$, $b$ ($1 \leq a < b \leq n$), and $d$ ($1 \leq d \leq k$), denoting that people $a$ and $b$ came into contact with each other on day $d$. All of these $c$ lines will be distinct. There will be at least one person with no contacts after day 1.</p>

### 출력 

 <p>Output a line with a single integer $x$ denoting the minimum number of people you must tell to quarantine beginning on day $k+1$. Then, output $x$ lines listing the people who must quarantine, one per line, in ascending order.</p>

