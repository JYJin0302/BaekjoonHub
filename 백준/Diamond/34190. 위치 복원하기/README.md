# [Diamond V] 위치 복원하기 - 34190 

[문제 링크](https://acmicpc.net/problem/34190) 

### 성능 요약

메모리: 13676 KB, 시간: 88 ms

### 분류

애드 혹

### 제출 일자

2025년 09월 01일 16:13:59

### 문제 설명

<p><strong>이 문제는 인터랙티브 문제입니다.</strong></p>

<p>수직선 상에 $N$개의 <strong>서로 다른</strong> 정수 좌표 $x_1, x_2, \cdots, x_N$이 존재한다. 여러분은 이 값을 알지 못하며, $x_1 = 0 < x_2$이고 모든 $x_i$가 $|x_i| \le 10^9$를 만족한다는 사실만 알고 있다.</p>

<p>채점기에 다음 질문을 $\lfloor\frac{3}{2}N\rfloor$번 이하로 하여 $x_1, x_2, \cdots, x_N$을 복원하자.</p>

<ul>
	<li><span style="color:#e74c3c;"><code>?</code></span> $i$ $j$: $x_i, x_j$에 대해 $|x_i - x_j|$를 질문한다.</li>
</ul>

### 입력 

 <p>첫 번째 줄에 테스트 케이스의 개수 $T$가 주어진다. $(1 \le T \le 500)$</p>

<p>각 테스트 케이스의 시작에 정수 좌표의 개수를 나타내는 정수 $N$이 주어진다. $(2 \le N \le 1\,000)$</p>

<p>모든 테스트 케이스에 대한 $N$의 총합은 $1\,000$을 넘지 않는다.</p>

### 출력 

 <p>여러분은 다음 두 가지 유형의 질문을 채점기에 할 수 있다.</p>

<ul>
	<li><span style="color:#e74c3c;"><code>?</code></span> $i$ $j$

	<ul>
		<li>$x_i, x_j$에 대해 $|x_i - x_j|$를 질문한다. $(1 \leq i < j \leq N$, $i, j$는 정수$)$</li>
		<li>이 유형의 질문은 최대 $\lfloor\frac{3}{2}N\rfloor$번 할 수 있다.</li>
	</ul>
	</li>
	<li><span style="color:#e74c3c;"><code>!</code></span> $x_1$ $x_2$ $\cdots$ $x_N$
	<ul>
		<li>$x_1, x_2, \cdots, x_N$이 정답인지 질문한다. $(|x_i| \le 10^9$, $x_i$는 정수$)$</li>
		<li>별도의 반환값은 없고, 출력이 정답과 불일치한다면 <span style="color:#dd4124;">틀렸습니다</span> 판정을 받는다.</li>
		<li>출력이 정답과 일치하며 남은 테스트 케이스가 있다면 다음 테스트 케이스의 인터랙션이 이어서 진행된다.</li>
		<li>출력이 정답과 일치하며 남은 테스트 케이스가 없다면 <span style="color:#009874;"><strong>맞았습니다!!</strong></span> 판정을 받는다.</li>
	</ul>
	</li>
</ul>

<p>모든 출력 이후에는 반드시 표준 출력 버퍼를 flush해야 한다. 언어 별로 표준 출력 버퍼를 flush하는 방법은 다음과 같다.</p>

<ul>
	<li>C: <code>fflush(stdout)</code></li>
	<li>C++: <code>std::cout << std::flush</code></li>
	<li>Java: <code>System.out.flush()</code></li>
	<li>Python: <code>sys.stdout.flush()</code></li>
</ul>

<p>기타 언어의 경우 각 언어의 documentation을 참조하자.</p>

<p>출력 형식을 지키지 않거나 첫 번째 유형의 질문을 $\lfloor\frac{3}{2}N\rfloor$번 초과로 한 경우에는 예상치 못한 채점 결과를 받을 수 있음에 유의하자.</p>

<p>모든 테스트 케이스를 해결한 뒤 프로그램은 즉시 종료되어야 한다.</p>

