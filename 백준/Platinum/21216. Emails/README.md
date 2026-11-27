# [Platinum II] Emails - 21216 

[문제 링크](https://acmicpc.net/problem/21216) 

### 성능 요약

메모리: 8096 KB, 시간: 40 ms

### 분류

애드 혹, 너비 우선 탐색, 그래프, 그래프 탐색

### 제출 일자

2023년 07월 27일 18:52:10

### 문제 설명

<p>Ariadna's blog is filled with delicious recipes and sensible advice for a healthy and balanced lifestyle. Unsurprisingly, it has thus gathered an impressive number of readers. This reader base is now stable, and Ariadna feels that it would be useful for them to interact more and form a tighter community, one that is not solely anchored to the blog.</p>

<p>Ariadna knows that some of the readers are already friends or acquaintances, and therefore have each other's email addresses. She thinks that a good start for developing the community would be for everyone to have everyone else's email address, so that everyone would be able to reach out to the entire group. Since she knows her blog's readers also greatly enjoy doing things in a "decentralized" fashion, she therefore devises the following protocol, to be started on day $D$:</p>

<ul>
	<li>Every day at 8am, everyone sends the current list of contacts in their address book to all of the contacts in their address book.</li>
	<li>Every day at 8pm, everyone updates their address book, adding any new received email addresses.</li>
</ul>

<p>If a person does not need to do any update at 8pm, then the process is said to have <em>converged</em> for this person, and she will no longer need to continue sending emails over the next days.</p>

<p>You are a skillful hacker and you have managed to get access to all of the blog readers' address books. You would like to surprise and impress Ariadna  by notifying her of whether or not the process she proposes will lead to everyone getting everyone else's address. Moreover, if the process is meant to succeed, you want to give her a good estimate of how many days it would take. More precisely, if the process succeeds, you can either give her:</p>

<ul>
	<li>the number $E$ of days (including the first day) elapsed until the last update takes place, or</li>
	<li>the number of days (including the first day) elapsed until the process has <em>converged</em> on everyone's side. Note that, according to Ariadna's definition, this is equal to $E$+1.</li>
</ul>

### 입력 

 <p>The first line of the input contains two integers $N$ and $M$, corresponding to the number of readers and respectively to the number of pairs of readers that initially have each other's email address. Readers are numbered from $1$ to $N$.</p>

<p>The $M$ following lines each contain two integers, $i$ and $j$, meaning that readers $i$ and $j$ initially have each other's email address. Note that this means that both reader $i$ has reader $j$'s address and reader $j$ has reader $i$'s address.  </p>

### 출력 

 <p>The output should contain a single integer equal to either:</p>

<ul>
	<li>$-1$ if the process does not lead to everyone eventually having everyone else's email address, or</li>
	<li>the estimated necessary number of days, otherwise. Note that this number may be equal to 0.</li>
</ul>

