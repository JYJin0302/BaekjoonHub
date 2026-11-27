# [Diamond I] 북극여우는 괄호를 뒤집어 - 29162 

[문제 링크](https://acmicpc.net/problem/29162) 

### 성능 요약

메모리: 111528 KB, 시간: 468 ms

### 분류

스플레이 트리, 트리

### 제출 일자

2023년 11월 20일 00:47:34

### 문제 설명

<p style="text-align: center;"><img alt="" src="" style="width: 30%;"></p>

<p>극지 연구소에서 연구 중인 협이는 저번에 북극곰이 괄호를 찢는다는 특성을 알아낸 후 괄호로 여러가지 실험을 하고 있었다. 연구를 하다가 잠깐 쉬고 온 협이는 실험 중이던 괄호가 바뀐 것을 알아차렸다. 범인을 찾기 위해 CCTV를 찾아본 결과 북극여우가 괄호들을 뒤집었다는 사실을 알아냈다. 북극에 사는 동물의 새로운 특성에 신이 난 협이는 북극여우가 어떤 습성을 가지고 있는지 관찰하려 한다. 올바른 괄호 쌍의 개수와 북극여우와 관계가 있을 것이라 생각한 협이는 관찰 결과를 통해 올바른 괄호 쌍이 몇 개 있는지 세어보려 한다.</p>

<p>올바른 괄호 쌍의 개수는 연속된 “<span style="color:#e74c3c;"><code>()</code></span>”인 쌍 하나를 지우고 남은 문자열을 붙이는 연산을 재귀적으로 진행했을 때, “<span style="color:#e74c3c;"><code>()</code></span>”인 쌍을 최대로 제거하는 횟수가 올바른 괄호쌍의 개수이다.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 50%;"></p>

<p style="text-align: center;"><img alt="" src="" style="width: 50%;"></p>

<p style="text-align: center;"><img alt="" src="" style="width: 50%;"></p>

<p>문자열 $S$가 주어질 때, 북극여우는 다음 $3$가지 행동을 할 수 있다. $l$, $r$이 주어졌을 때, $l \le i \le r$인 $i$에 대해서</p>

<ul>
	<li>$1$ $l$ $r$: 모든 $i$에 대해 $s_i$가 ‘<span style="color:#e74c3c;"><code>(</code></span>’ 이면 ‘<span style="color:#e74c3c;"><code>)</code></span>’으로, ‘<span style="color:#e74c3c;"><code>)</code></span>’이면 ‘<span style="color:#e74c3c;"><code>(</code></span>’ 로 바꾼다.</li>
	<li>$2$ $l$ $r$: 모든 $i$에 대해 문자 $s_i$의 위치를 $s_{r+l-i}$으로 옮긴다.</li>
	<li>$3$ $l$ $r$: 부분 문자열 $s_l, s_{l + 1}, \cdots, s_r$을 $180$도만큼 회전시킨다.</li>
</ul>

<p>그리고 협이는 북극여우가 행동하는 중에, 임의의 구간 $[l,r]$에 대하여 올바른 괄호 쌍의 개수를 질문할 수 있다.</p>

<ul>
	<li>$4$ $l$ $r$: 부분 문자열 $s_l, s_{l + 1}, \cdots, s_r$에서 올바른 괄호 쌍의 개수를 알려준다.</li>
</ul>

<p>위 네 개의 질의를 순서대로 처리하며 올바른 괄호 쌍의 개수가 몇 개인지 알려주자.</p>

### 입력 

 <p>첫 줄에 괄호 문자열 $S$의 길이 $N$과 질의의 개수 $Q$가 공백으로 구분되어 주어진다. $(1 \leq N= \lvert S \rvert \leq 1\,000\,000;$ $1 \leq Q \leq 20\,000)$</p>

<p>둘째 줄에 길이가 $N$이고 ‘<span style="color:#e74c3c;"><code>(</code></span>’ 또는 ‘<span style="color:#e74c3c;"><code>)</code></span>’로 이루어진 공백 없는 문자열 $S$가 주어진다.</p>

<p>셋째 줄부터 $Q$개의 줄에 걸쳐 질의의 정보 $t$, $l$, $r$가 공백으로 구분되어 주어진다. $(1 \leq t \leq 4;$ $1 \leq l \leq r \leq N)$</p>

<p>$4$번 질의는 하나 이상 주어지며, 입력으로 주어지는 수는 모두 정수이다.</p>

### 출력 

 <p>$4$번 질의에 대한 답을 한 줄에 하나씩 순서대로 출력한다.</p>

