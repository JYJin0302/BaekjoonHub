# [Platinum III] Superliczby w permutacji - 8443 

[문제 링크](https://acmicpc.net/problem/8443) 

### 성능 요약

메모리: 5972 KB, 시간: 16 ms

### 분류

이분 탐색, 다이나믹 프로그래밍, 가장 긴 증가하는 부분 수열 문제

### 제출 일자

2025년 01월 22일 14:18:53

### 문제 설명

<p>Permutacja <em>n</em>-elementowa jest ciągiem <em>n</em>-elementowym składającym się z różnych liczb ze zbioru 1, 2, ..., <em>n</em>. Przykładowo, ciąg 2, 1, 4, 5, 3 jest permutacją 5-elementową.</p>

<p>W permutacjach liczb będą interesować nas najdłuższe rosnące podciągi. W przykładowej permutacji mają one długość 3 i istnieją dokładnie dwa takie podciągi, a mianowicie 2, 4, 5 oraz 1, 4, 5.</p>

<p><em>Superliczbą</em> nazwiemy każdą liczbę, która należy do dowolnego z najdłuższych rosnących podciągów. W permutacji 2, 1, 4, 5, 3 superliczbami są 1, 2, 4, 5, zaś liczba 3 superliczbą nie jest.</p>

<p>Twoim zadaniem jest dla zadanej permutacji znaleźć wszystkie superliczby.</p>

<p>Napisz program, który:</p>

<ul>
	<li>wczyta permutację ze standardowego wejścia,</li>
	<li>znajdzie wszystkie superliczby,</li>
	<li>wypisze znalezione superliczby na standardowe wyjście.</li>
</ul>

### 입력 

 <p>Wejście składa się z dwóch wierszy. W pierwszym wierszu znajduję się jedna liczba <em>n</em>, 1 ≤ <em>n</em> ≤ 100000. W drugim wierszu znajduję się <em>n</em> liczb tworzących permutację <em>n</em>-elementową, pooddzielanych pojedynczymi odstępami.</p>

### 출력 

 <p>Wyjście powinno się składać z dwóch wierszy. W pierwszym wierszu powinna znaleźć się jedna liczba <em>m</em> - liczba superliczb w wejściowej permutacji. W drugim powinny znaleźć się superliczby pooddzielane pojedynczymi odstępami, wymienione w kolejności rosnącej.</p>

