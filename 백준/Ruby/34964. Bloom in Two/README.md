# [Ruby V] Bloom in Two - 34964 

[문제 링크](https://acmicpc.net/problem/34964) 

### 성능 요약

메모리: 5928 KB, 시간: 112 ms

### 분류

애드 혹, 자료 구조, 스택

### 제출 일자

2025년 12월 28일 18:18:08

### 문제 설명

<p>정원사인 당신은 두 방향으로 피는 새로운 꽃 품종을 개발하여 이를 여러분의 정원에 전시하고자 한다. 정원은 $N\times N$ 크기의 격자로 볼 수 있으며, 왼쪽 밑 칸이 $(1,1)$, 오른쪽 밑 칸이 $(N, 1)$, 오른쪽 위 칸이 $(N,N)$에 위치해 있다.</p>

<p>당신이 개발한 꽃은 상하좌우 네 방향 중에서, 서로 직각을 이루는 두 방향으로 피어난다.</p>

<p>정원에는 $N$개의 화분이 서로 다른 $N$개의 칸에 위치해 있으며, 모든 행과 열에는 정확히 하나의 화분이 존재한다. 당신은 $N$개의 화분 위에 꽃을 적당한 방향으로 심어 조화로운 정원을 만들고자 한다. 다음 조건을 만족하는 정원을 <strong>조화로운 정원</strong>이라고 한다.</p>

<ul>
<li>화분이 놓이지 않은 임의의 칸 $(i,j)$에 대해 이 위치에서 상, 하, 좌, 우로 보았을 때 이 위치를 바라보는 꽃이 적어도 하나 존재해야 한다.</li>
</ul>

<p style="text-align: center;"><img alt="" src="" style="height: 300px; width: 300px;">    <img alt="" src="" style="height: 300px; width: 300px;"></p>

<p>예를 들어, 왼쪽 그림과 같은 배치에서는 꽃이 모든 칸을 바라보고 있기 때문에 조화롭지만, 오른쪽 그림과 같은 배치에서는 $(3,3)$의 칸을 바라보고 있는 꽃이 없기 때문에 조화롭지 않다.</p>

<p><strong>조화로운 정원</strong>을 이룰 수 있도록 꽃의 방향을 정하여라.</p>

### 입력 

 <p>첫째 줄에 정원의 크기 $N$이 주어진다.</p>

<p>둘째 줄에 $N$개의 정수 $P_i$가 공백으로 구분되어 주어진다. 이는 $i$번째 화분이 $(i,P_i)$에 있음을 나타낸다.</p>

### 출력 

 <p>정원을 조화롭게 만들 수 있으면 첫째 줄에 <span style="color:#e74c3c;"><code>YES</code></span>를 출력하고, 아니면 <span style="color:#e74c3c;"><code>NO</code></span>를 출력한다.</p>

<p>정원을 조화롭게 만들 수 있는 경우 이어서 둘째 줄에 길이 $N$의 문자열 $S$를 출력한다. $S$의 $i$번째 문자는 다음과 같이 <code><span style="color:#e74c3c;">Q</span></code>, <span style="color:#e74c3c;"><code>E</code></span>, <code><span style="color:#e74c3c;">Z</span></code>, <span style="color:#e74c3c;"><code>C</code></span> 중 하나로, $i$번째 화분에 심을 꽃의 방향을 의미해야 한다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/6d8ed2cb-617d-4b66-b3e1-cc47b2b5df66/-/preview/" style="height: 109px; width: 300px;"></p>

