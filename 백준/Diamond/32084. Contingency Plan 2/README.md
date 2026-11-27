# [Diamond IV] Contingency Plan 2 - 32084 

[문제 링크](https://acmicpc.net/problem/32084) 

### 성능 요약

메모리: 13204 KB, 시간: 52 ms

### 분류

이분 매칭, 방향 비순환 그래프, 자료 구조, 분리 집합, 그래프, 위상 정렬

### 제출 일자

2024년 10월 23일 21:47:07

### 문제 설명

<p>You are working as a manager in The ICPC Company. In the company building, there are $N$ computers (numbered from $1$ to $N$). There are $N - 1$ cables, numbered from $1$ to $N - 1$, that connect all the computers into a single network. Cable $i$ connects computer $U_i$ and $V_i$. Each cable can be set into emergency mode, where cable $i$ only transfers data from computer $U_i$ to computer $V_i$, but not the other way around. During a disaster, it is mandatory for all cables to be in emergency mode.</p>

<p>Through your research, you discover a new way to determine the vulnerability of a network. You want to add zero or more new cables to the current network such that it is <strong>not vulnerable</strong> during a disaster. Your network is not vulnerable if and only if there is <strong>exactly one</strong> permutation of $1$ to $N$ such that $u$ appears before $v$ in the permutation for all cables that connect computer $u$ and $v$. In other words, it should have exactly one topological order.</p>

<p>The following illustration shows examples of not vulnerable networks and vulnerable networks.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 576px; height: 60px;"></p>

<p>For the not vulnerable networks, the only permutation that satisfies the requirement for the networks on the left and on the right are $[1, 2, 3]$ and $[3, 1, 2]$, respectively. Meanwhile, for the vulnerable networks, there are $2$ permutations that satisfy the requirement for the network on the left: $[1, 2, 3]$ and $[3, 1, 2]$; while there is no permutation that satisfies the requirement for the network on the right.</p>

<p>You are interested in the minimum number of new cables that should be added to the current network such that it is not vulnerable during a disaster. Furthermore, you want to know, which pairs of computers should be connected by using the minimum number of cables. If there are several ways to connect, you can connect in any way of your choice. Under the given constraints, it can be proven that there exists a way to make the network not vulnerable.</p>

### 입력 

 <p>The first line consists of an integer $N$ ($2 ≤ N ≤ 100\, 000$).</p>

<p>Each of the next $N - 1$ lines consists of two integers $U_i$ $V_i$ ($1 ≤ U_i , V_i ≤ N$). The input edges form a tree.</p>

### 출력 

 <p>The first line consists of an integer, representing the minimum number of new cables that should be added to the current network such that it is no longer vulnerable during a disaster. Denote this number as $K$ and the new cables are numbered from $1$ to $K$.</p>

<p>If $K$ is not $0$, then output $K$ lines. Each of the next $K$ lines consists of two integers $A_i$ $B_i$, representing the computers that are connected by the new cable $i$. During a disaster, new cable $i$ only transfers data from computer $A_i$ to computer $B_i$, but not the other way around. If there exist several solutions, you can output any of them.</p>

