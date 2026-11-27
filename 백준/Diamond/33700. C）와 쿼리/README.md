# [Diamond V] C)와 쿼리 - 33700 

[문제 링크](https://acmicpc.net/problem/33700) 

### 성능 요약

메모리: 9320 KB, 시간: 136 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 누적 합, 세그먼트 트리

### 제출 일자

2025년 03월 30일 14:49:39

### 문제 설명

<p>UDPC만을 손꼽아 기다리던 포닉스는 어느새 어디를 봐도 알파벳 U, D, P, C가 보이는 수준에 이르렀다. 그중에서도, 알파벳 <span style="color:#e74c3c;"><code>C</code></span>, <span style="color:#e74c3c;"><code>U</code></span>와 괄호 <span style="color:#e74c3c;"><code>(</code></span> , <span style="color:#e74c3c;"><code>)</code></span>는 굉장히 유사한 모양을 띠기 때문에 구별하기가 매우 힘들어졌다.</p>

<p>다행인 점은, 알파벳 <span style="color:#e74c3c;"><code>C</code></span>와 <span style="color:#e74c3c;"><code>U</code></span>를 돌려 마치 괄호처럼 사용할 수 있다는 점이다. <span style="color:#e74c3c;"><code>C</code></span>는 그 모습 그대로 여는 괄호 <span style="color:#e74c3c;"><code>(</code></span> 로 사용하거나, 어느 방향으로든 90도씩 두 번을 돌려 닫는 괄호 <span style="color:#e74c3c;"><code>)</code></span> 로 사용할 수 있다. <span style="color:#e74c3c;"><code>U</code></span>는 시계 방향으로 90도를 회전하면 여는 괄호 <span style="color:#e74c3c;"><code>(</code></span> , 반시계 방향으로 90도를 회전하면 닫는 괄호 <span style="color:#e74c3c;"><code>)</code></span> 로 사용할 수 있다.</p>

<p>포닉스는 UDPC를 기다리느라 지쳤기 때문에 알파벳을 최소한으로 돌리고 싶다. 구체적으로, 짝수 길이의 <span style="color:#e74c3c;"><code>C</code></span>와 <span style="color:#e74c3c;"><code>U</code></span>로 이루어진 문자열 $S$가 주어지면, 알파벳 중 하나를 골라 어느 방향으로든 90도씩 회전해 올바른 괄호 문자열을 만들기 위해 필요한 최소 회전 횟수를 구해야 한다.</p>

<p>그러나 이 문제가 너무 쉽다고 생각한 달구는 포닉스에게 다음과 같은 $Q$번의 질문을 던졌다.</p>

<ul>
	<li>$x$: $S_x$가 <span style="color:#e74c3c;"><code>C</code></span>라면 <span style="color:#e74c3c;"><code>U</code></span>로, <span style="color:#e74c3c;"><code>U</code></span>라면 <span style="color:#e74c3c;"><code>C</code></span>로 바꾼 후 $S$를 올바른 괄호 문자열로 만들기 위해 필요한 최소 회전 횟수를 구하여라. $S_x$는 $S$의 $x$번째 문자를 의미한다.</li>
</ul>

<p>포닉스는 이 $Q$번의 질문에 모두 올바르게 대답하지 못한다면 2025 UDPC에 참가하지 못할 것이다. 포닉스가 2025 UDPC에 무사히 참가할 수 있도록 도와주자.</p>

### 입력 

 <p>첫째 줄에 문자열의 길이 $N$과 질문의 개수 $Q$가 공백으로 구분되어 주어진다. $N$은 항상 짝수임이 보장된다. $(2\le N \le 200\, 000; 1 \le Q \le 200\, 000)$</p>

<p>둘째 줄에 길이가 $N$인 문자열 $S$가 주어진다. $S$는 알파벳 <span style="color:#e74c3c;"><code>C</code></span>, <span style="color:#e74c3c;"><code>U</code></span>로만 이루어짐이 보장된다.</p>

<p>셋째 줄부터 $Q$개의 줄에 걸쳐 달구가 던진 질문 $x$가 주어진다. $(1\le x\le N)$ 문자열에 가해진 수정은 질문 이후에도 유지된다.</p>

### 출력 

 <p>첫째 줄에 입력으로 주어진 $S$에 대해 이를 올바른 괄호 문자열으로 만들기 위해 필요한 최소 회전 횟수를 출력한다.</p>

<p>둘째 줄부터 $Q$개의 줄에 걸쳐 각 작업 후 바뀐 문자열을 올바른 괄호 문자열로 만들기 위해 필요한 최소 회전 횟수를 순서대로 출력한다.</p>

