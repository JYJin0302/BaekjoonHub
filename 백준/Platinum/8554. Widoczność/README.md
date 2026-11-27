# [Platinum III] Widoczność - 8554 

[문제 링크](https://acmicpc.net/problem/8554) 

### 성능 요약

메모리: 3572 KB, 시간: 12 ms

### 분류

이분 탐색, 조합론, 자료 구조, 수학, 스택

### 제출 일자

2026년 01월 03일 15:33:19

### 문제 설명

<p>Dany jest ciąg liczb całkowitych <em>x</em><sub>1</sub>, <em>x</em><sub>2</sub>, ..., <em>x<sub>n</sub></em>. Powiemy, że dwa elementy <em>x<sub>i</sub></em> i <em>x<sub>j</sub></em> (dla 1 ≤ <em>i</em> < <em>j</em> ≤ <em>n</em>) <i>widzą się bezpośrednio</i> nawzajem, jeśli każdy z elementów <em>x</em><sub><em>i</em>+1</sub>, ..., <em>x</em><sub><em>j</em>-1</sub> jest mniejszy od min(<em>x<sub>i</sub></em>, <em>x<sub>j</sub></em>). W szczególności każde dwa kolejne elementy w ciągu widzą się bezpośrednio nawzajem. Powiemy, że dwa elementy <em>x<sub>i</sub></em> i <em>x<sub>j</sub></em> (dla 1 ≤ <em>i</em> < <em>j</em> ≤ <em>n</em>) widzą się <i>pośrednio nawzajem</i>, jeżeli:</p>

<ul>
	<li>widzą się bezpośrednio nawzajem, lub</li>
	<li>istnieje takie <em>k</em>, <em>i</em> < <em>k</em> < <em>j</em>, że <em>x<sub>i</sub></em> i <em>x<sub>k</sub></em> widzą się bezpośrednio nawzajem, oraz <em>x<sub>k</sub></em> i <em>x<sub>j</sub></em> widzą się bezpośrednio nawzajem.</li>
</ul>

<p>Zadanie polega na obliczeniu dla danego ciągu <em>x</em><sub>1</sub>, <em>x</em><sub>2</sub>, ..., <em>x<sub>n</sub></em> liczby wszystkich takich par (<em>i</em>, <em>j</em>), że 1 ≤ <em>i</em> < <em>j</em> ≤ <em>n</em> oraz elementy <em>x<sub>i</sub></em> i <em>x<sub>j</sub></em> widzą się <i>pośrednio</i> nawzajem.</p>

### 입력 

 <p>W pierwszym wierszu zapisana jest jedna liczba całkowita <em>n</em> (1 ≤ <em>n</em> ≤ 40 000). W kolejnych wierszach zapisane są kolejne elementy ciągu, po jednym w wierszu. Elementy ciągu to liczby całkowite z zakresu od -1 000 000 do 1 000 000.</p>

### 출력 

 <p>Program powinien wypisać jeden wiersz, zawierający jedną liczbę całkowitą - liczbę takich par (<em>i</em>, <em>j</em>), że 1 ≤ <em>i</em> < <em>j</em> ≤ <em>n</em> oraz elementy <em>x<sub>i</sub></em> i <em>x<sub>j</sub></em> widzą się <i>pośrednio</i> nawzajem.</p>

