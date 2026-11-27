# [Diamond IV] 힝스파티 - 35314 

[문제 링크](https://acmicpc.net/problem/35314) 

### 성능 요약

메모리: 24824 KB, 시간: 916 ms

### 분류

이분 매칭, 그래프, 격자 그래프

### 제출 일자

2026년 02월 22일 15:46:40

### 문제 설명

<p>힝스 격자는 $N$행 $M$열로 이루어져 있고 각 칸에 <code><span style="color:#e74c3c;">^</span></code> 또는 <span style="color:#e74c3c;"><code>-</code></span> 가 적혀 있는 격자이다. 힝스 격자의 힝스력은 가로 혹은 세로로 연속된 세 칸이 차례로 <code><span style="color:#e74c3c;">-^-</span></code> 로 나타나는 총 횟수로 정의된다.</p>

<p>현재 격자의 어떤 칸에는 <code><span style="color:#e74c3c;">^</span></code> 또는 <span style="color:#e74c3c;"><code>-</code></span> 가 채워져 있고 다른 칸들은 모두 비어 있는 상태이다. 남은 빈칸을 <code><span style="color:#e74c3c;">^</span></code> 또는 <code><span style="color:#e74c3c;">-</span></code>로 적당히 채웠을 때 가능한 최대 힝스력을 구해보자.</p>

### 입력 

 <p>첫째 줄에 격자의 행과 열의 크기를 나타내는 두 정수 $N$, $M$이 주어진다. $(1\leq N,M \leq 150)$</p>

<p>다음 $N$줄에 걸쳐 격자의 정보를 나타내는 길이 $M$의 문자열이 주어진다. $i+1$번째 줄의 $j$번째 문자는 $i$행 $j$열의 상태를 나타내며 <span style="color:#e74c3c;"><code>.</code></span>일 시 빈칸을, 그렇지 않다면 그 칸에 적혀있는 문자를 나타낸다.</p>

### 출력 

 <p>남은 빈칸을 <code><span style="color:#e74c3c;">^</span></code> 또는 <code><span style="color:#e74c3c;">-</span></code>로 적당히 채웠을 때 가능한 최대 힝스력을 출력한다.</p>

