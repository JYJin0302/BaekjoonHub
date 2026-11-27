# [Diamond IV] Keys and Locks Boolean Logic - 20242 

[문제 링크](https://acmicpc.net/problem/20242) 

### 성능 요약

메모리: 2036 KB, 시간: 4 ms

### 분류

비트마스킹, 해 구성하기, 자료 구조, 파싱, 희소 배열, 문자열

### 제출 일자

2023년 08월 12일 18:50:22

### 문제 설명

<p>Karen and her friends play in a music band in Karen's garage. She has complicated thoughts on which subsets of the band should be allowed to enter the garage. She designed a boolean formula $F$ in which each variable denotes the presence of a certain band member. She wants a group of people to be able to enter the garage if and only if $F$ is true.</p>

<p>You are asked to create a system of wires and locks that will fulfill the formula $F$. Each band member will receive a key that opens all the locks that are denoted by their letter.</p>

<p>For example, suppose that $F = a \lor (b \land c)$ and band members $a$ and $b$ are present. Then they should be able to enter the garage with their keys because $true \lor (true \land false) = true$.</p>

<p>A band member doesn't have to use their key to open all the locks possible. For example, suppose that $F = a \oplus b$. Then band member $a$ alone should be able to enter the garage because $true \oplus false = true$. But if both $a$ and $b$ come to the garage, they can just disregard $b$'s key and open the garage using $a$'s one. However, $true \oplus true = false$, so this formula $F$ is not fulfillable.</p>

<p>The system must be a rectangular grid of size at most $50 \times 50$ containing horizontal wires '<code>-</code>', vertical wires '<code>|</code>', wire connections '<code>+</code>', and locks. The upper leftmost and the upper rightmost cells of the grid must contain wire connections that will be attached to the doors of the garage. The garage doors stay closed as long as there is a path between these two connections via wires and locked locks.</p>

<p>You are to design such a system corresponding to the given formula $F$, or to state that there is no such system.</p>

### 입력 

 <p>The input contains a non-empty boolean formula $F$.</p>

<p>The formula can contain letters <code>a</code>, ..., <code>h</code> denoting the presence of band members, operators "<code>and</code>", "<code>or</code>", "<code>not</code>", and parentheses. The length of the formula does not exceed 2020. The "<code>not</code>" operator has the highest priority. The "<code>and</code>" operator has higher priority than the "<code>or</code>" operator. There are single spaces around each "<code>and</code>", around each "<code>or</code>", and after each "<code>not</code>". There are no spaces other than those.</p>

### 출력 

 <p>If it is impossible to design the desired system, print one line "<code>IMPOSSIBLE</code>".</p>

<p>Otherwise, output a rectangular grid of characters --- the system corresponding to formula $F$. The system can only contain spaces, '<code>-</code>', '<code>|</code>', '<code>+</code>', and letters corresponding to the band members that are mentioned in the input.</p>

<p>The upper leftmost and the upper rightmost cells should be wire connections. The width of the grid should be between 2 and 50, inclusive, the height of the grid should be between 1 and 50, inclusive.</p>

<p>Character '<code>-</code>' must be used for a wire if and only if it connects something on the left and something on the right with empty cells below and above. Similarly, '<code>|</code>' must be used for a wire if and only if it connects something below and something above with empty cells on the left and on the right.</p>

