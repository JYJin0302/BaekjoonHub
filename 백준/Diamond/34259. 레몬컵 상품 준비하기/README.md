# [Diamond V] 레몬컵 상품 준비하기 - 34259 

[문제 링크](https://acmicpc.net/problem/34259) 

### 성능 요약

메모리: 20964 KB, 시간: 0 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리

### 제출 일자

2025년 09월 07일 15:39:29

### 문제 설명

<p>레몬컵 운영진은 대회 상품을 준비하려 한다. 상품의 종류는 총 $N$개이며, 각 종류는 $1$번부터 $N$번까지 번호가 매겨져 있다. 처음에는 모든 상품의 개수가 $0$이다.</p>

<p>재원이는 이 상품들을 이용해 <strong>선물 묶음</strong>을 만들고자 한다. 하나의 선물 묶음은 <strong>연속한 번호의 상품을 $\mathbf{2}$개 이상</strong> 포함해야 하며, 각 상품은 정확히 $\mathbf{1}$<strong>개씩</strong> 사용한다.</p>

<p>다음과 같은 두 가지 쿼리가 주어진다.</p>

<ul>
<li><span style="color:#e74c3c;"><code>1 l r k</code></span>: $l, l+1, \dots, r$번 상품을 각각 $k$개씩 구매한다. 단, $k < 0$이면 해당 상품들을 각각 $|k|$개씩 폐기하였다는 뜻이다.</li>
<li><span style="color:#e74c3c;"><code>2 l r</code></span>: $l, l+1, \dots, r$번 상품을 모두 사용하여 만들 수 있는 <strong>선물 묶음</strong>의 최소 개수를 출력한다. 이때 $l, l+1, \dots, r$번 상품만을 사용해야 한다. 만약 모든 상품을 사용해서 선물 묶음을 만들 수 없다면 <span style="color:#e74c3c;"><code>-1</code></span>을 출력한다.</li>
</ul>

<p>$2$번 쿼리가 주어질 때마다 정답을 출력하라.</p>

### 입력 

 <p>입력은 다음과 같은 형식으로 주어진다.</p>

<blockquote>
<p>$N \ Q$</p>

<p>$\text{query}_1$</p>

<p>$\text{query}_2$</p>

<p>$\vdots$</p>

<p>$\text{query}_Q$</p>
</blockquote>

<p>각각의 $\text{query}_i$ ($1 \le i \le Q$)는 다음 두 형식 중 하나이다.</p>

<blockquote>
<p>$1 \ l_i \ r_i \ k_i$</p>
</blockquote>

<blockquote>
<p>$2 \ l_i \ r_i$</p>
</blockquote>

### 출력 

 <p>$2$번 쿼리가 주어질 때마다 정답을 출력한다.</p>

