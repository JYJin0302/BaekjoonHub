# [Diamond IV] Headline Heat - 32484 

[문제 링크](https://acmicpc.net/problem/32484) 

### 성능 요약

메모리: 247460 KB, 시간: 220 ms

### 분류

아호-코라식, 자료 구조, 무작위화, 문자열, 트리, 트라이

### 제출 일자

2026년 01월 06일 15:46:47

### 문제 설명

<p>The German ICPC scene is widely considered one of the most competitive. At least, that's what we tell our students. Countless rivalries form a complex web of envy, despair, glory, and triumph woven around and manifested in the unrelenting echoes of two scoreboards -- Winter Contest and GCPC. While generations of participants tend to forget the grudges of their predecessors, we coaches, acting as timeless beacons of continuity, preserve these petty conflicts between long forgotten teams. Striving for perfect balance, we express our dedication to our coaching duties in a furious outcry on social media against every unfair news article. That is, a coach gets mad if a news article is published that contains a rival university name more often than their own. </p>

<p>To smoothen the waves of conflict in this ocean of rage, a newly appointed authority is tasked with proofreading media coverage of GCPC and Winter Contest to prevent uneven coverage.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with the number of universities $n$, rivalries $m$, and articles $k$. ($1\leq n,m,k\leq 10^5$)</li>
	<li>$n$ lines containing the name of a university $p_i$.</li>
	<li>$m$ lines containing two integers $u,v$, meaning that universities $u$ and $v$ are rivals. ($1\leq u,v \leq n, u\neq v$)</li>
	<li>$k$ lines containing a news article $t_i$.</li>
</ul>

<p>If a university $u$ is a rival of university $v$, then $v$ is also a rival of $u$. Moreover, there are no duplicate rivalries.</p>

<p>Names and articles are strings of lowercase Latin letters and spaces. The first and last character of a name or article are never a space. Names can overlap and be contained in other names.</p>

<p>The summed length of all names and articles is at most $10^6$, i.e. $\sum_{i=1}^{n} |p_i| + \sum_{i=1}^{k} |t_i| \leq 10^6$.</p>

### 출력 

 <p>For each article, output "<code>no</code>" if it will draw the wrath of at least one coach and "<code>yes</code>" otherwise.</p>

