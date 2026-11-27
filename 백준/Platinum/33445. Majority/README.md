# [Platinum II] Majority - 33445 

[문제 링크](https://acmicpc.net/problem/33445) 

### 성능 요약

메모리: 2224 KB, 시간: 0 ms

### 분류

애드 혹, 해 구성하기, 분할 정복

### 제출 일자

2026년 01월 04일 16:19:44

### 문제 설명

<p>Little Cat learned Boolean circuits recently. Now he wants to construct a majority circuit.</p>

<p>A <em>circuit</em> over Boolean variables $x_1, \ldots, x_n$ is a directed acyclic graph where each node (logical gate) is either an input node labeled by a variable $x_i$, or an operation node labeled by a logical operation $\vee$ or $\wedge$. There are exactly $n$ input nodes, one for each of the input variables $x_1, \ldots, x_n$. Additionally, a single node is <strong>chosen</strong> as the output of the circuit.</p>

<p>Each node computes an output: the input nodes (labeled by a variable) output exactly the variable written on them, and nodes labeled by $\vee$ (respectively, $\wedge$) output the logical OR (respectively, AND) of all incoming nodes. Note that logical NOT nodes are <strong>forbidden</strong>. See the example and notes for better understanding.</p>

<p>The in-degree of an input node is $0$. The in-degree of an operation node is at least $1$, and can be arbitrarily large. The out-degrees are arbitrary (possibly $0$).</p>

<p>For convenience, there are two special constant nodes $T$ (true) and $F$ (false), which always output $1$ and $0$, respectively.</p>

<p>The majority circuit $\mathit{Maj}_n$ has $n$ inputs $x_1, \ldots, x_n$, and it outputs $1$ if at least half of inputs are $1$, and outputs $0$ otherwise. Formally, $\mathit{Maj}_n(x_1, \ldots, x_n) = \left[2 \sum_{i = 1}^n x_i \ge n\right]$.</p>

<p>Define the <em>depth</em> of a circuit as the length of the longest (directed) path in the circuit, that is, the number of edges of the longest path.</p>

<p>Could you help Little Cat to construct a majority circuit over $n$ inputs with depth at most $14$?</p>

### 입력 

 <p>The input contains one line with an integer $n$ ($2 \le n \le 64$) indicating the number of input nodes.</p>

### 출력 

 <p>The first line must contain an integer $m$ ($1 \le m \le 5 \cdot 10^4$) representing the number of nodes labeled by $\vee$ or $\wedge$, so there are $n + m + 2$ nodes in the circuit in total. The input nodes $x_1, \ldots, x_n$ are numbered by $1, \ldots, n$. The constant true node $T$ is numbered by $-1$, and the constant false node $F$ is numbered by $-2$.</p>

<p>A total of $m$ lines must follow. The $i$-th line must describe node $(n + i)$ in one of the following formats.</p>

<ul>
	<li>"<code>OR</code> $k_i$ $a_1$ $a_2$ $\ldots$ $a_{k_i}$" (without quotes): node $(n + i)$ computes the logical OR of nodes $a_j$ where $-2 \le a_j < n + i$ and $a_j \neq 0$ for all $1 \le j \le k_i$.</li>
	<li>"<code>AND</code> $k_i$ $a_1$ $a_2$ $\ldots$ $a_{k_i}$" (without quotes): node $(n + i)$ computes the logical AND of nodes $a_j$ where $-2 \le a_j < n + i$ and $a_j \neq 0$ for all $1 \le j \le k_i$.</li>
</ul>

<p>It is fine if $a_u = a_v$ for some $u \neq v$. You must guarantee that $\sum_{i = 1}^{m} k_i \le 2 \cdot 10^5$ and that the depth of the circuit does not exceed $14$.</p>

<p>The output of the circuit <strong>is chosen as</strong> the output of node $n + m$.</p>

<p>To check the circuit you construct, Little Cat will test your circuit for $1500$ rounds. In each round, Little Cat will generate an arbitrary input $x_1, \ldots, x_n$ (he won't say how exactly) and test your circuit with that input. You pass this round if your circuit outputs the majority of the input $x_1, \ldots, x_n$ correctly. You need to pass all the $1500$ rounds.</p>

