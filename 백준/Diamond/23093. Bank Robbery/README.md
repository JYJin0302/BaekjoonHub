# [Diamond III] Bank Robbery - 23093 

[문제 링크](https://acmicpc.net/problem/23093) 

### 성능 요약

메모리: 13708 KB, 시간: 72 ms

### 분류

애드 혹, 해 구성하기, 게임 이론, 구현, 비둘기집 원리, 트리

### 제출 일자

2023년 11월 23일 16:26:44

### 문제 설명

<p>Each day, robbers plan to rob exactly one bank in a region. Due to undercover informers’ work, the detectives get to know which particular bank is being targeted by the robbers on each day just before 6 AM. The presence of a single detective in a bank is enough to deter the robbers, so the detectives want to plan their positions intelligently. Robbing is planned to happen during the daylight after 8 AM, when the banks open, and is always successful when there is no detective in the bank. Unfortunately, though, the number of detectives is not very big so there may not be enough of them to keep the banks safe. To ensure they are effective, there can be at most one detective in any bank at any time. A detective can leave a bank and travel to another bank only between 6 AM and 8 AM.</p>

<p>Given enough days, any detective would be able to move from any of the banks to any other via the 2-hour transits. Due to the travel restrictions (mainly time), they are not able to move freely but are restricted to move only between banks that are close to each other. The region is quite specific because there is a minimum number of bank pairs that are close that conform to the above restrictions. Additionally, no bank is close to exactly two other banks.</p>

<p>Now, there is a quest for a computer simulation: determining if the robbers can succeed in at least one robbery during one year. The simulation is run against the preprogrammed judge as a kind of computer game, with strong consequences in real life. In the game, the attacker represents the robbers, the defender manages the detectives.</p>

<p>In the beginning, the simulation is given the system of connections between close banks and the number of detectives available. Then, the simulation chooses whether it plays as an attacker or as a defender. The judge automatically adopts the opposite role. Next, the defender places the given number of detectives in banks according to its own choice.</p>

<p>Next, the game proceeds in turns. In one turn, the attacker announces a bank and then the defender moves each detective over at most one connection. The defender’s aim is to choose the movements in such a way the announced bank is occupied by a detective at the end of the turn. If there is no detective in the announced bank after all movements in the turn, the attacker immediately wins the game. Otherwise, the defender defends the turn and the next turn ensues. If the defender can successfully defend for one year (365 turns), they win the game. During the game, the location of each detective is known to both the attacker and the defender.</p>

<p>The goal of the simulation you have to write is to choose a role smartly so that you are able to win the game.</p>

### 입력 

 <p>The first input line contains values B and D (4 ≤ B ≤ 100, 0 ≤ D ≤ B), the number of banks and the number of detectives. The banks are labeled by integers 0, 1, . . . , B−1. Each of the next B − 1 lines contains a pair of integers b<sub>i</sub> and c<sub>i</sub> (0 ≤ b<sub>i</sub>, c<sub>i</sub> ≤ B − 1) representing a connection between two close banks b<sub>i</sub> and c<sub>i</sub>.</p>

### 출력 

 <p>After reading the input, if you choose to attack, then prints a line with string <code>ATTACK</code>. Otherwise, print a line with string <code>DEFEND</code> and on the next line it print D different indices, in arbitrary order, of all the banks where a detective is initially located. The remainder of the exchange happens interactively.</p>

