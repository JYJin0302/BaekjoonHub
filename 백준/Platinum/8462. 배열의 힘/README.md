# [Platinum II] 배열의 힘 - 8462 

[문제 링크](https://acmicpc.net/problem/8462) 

### 성능 요약

메모리: 13756 KB, 시간: 332 ms

### 분류

Mo's, 오프라인 쿼리

### 제출 일자

2022년 01월 10일 23:04:39

### 문제 설명

<p>Dana jest tablica \(n\) liczb naturalnych \(a_1,a_2,a_3,\dots ,a_n\). Rozważmy fragment tej tablicy od \(l\)-tego do \(r\)-tego elementu: \(a_l,a_{l+1},\dots , a_r\). Oznaczmy przez \(K_s\) liczbę wystąpień liczby \(s\) w tym fragmencie. Potęgą fragmentu tablicy nazywamy sumę iloczynów \(K_s \cdot K_s \cdot s\) po wszystkich liczbach naturalnych \(s\). Oblicz potęgi podanych fragmentów.</p>

### 입력 

 <p>W pierwszym wierszu wejścia znajdują się dwie liczby całkowite \(n\) i \(t\) (1 ≤ \(n\), \(t\) ≤ 10<sup>5</sup>) oznaczające długość tablicy \(a\) oraz liczbę fragmentów, dla których należy obliczyć potęgi. Drugi wiersz zawiera \(n\) liczb naturalnych \(a_i\) (1 ≤ \(a_i\) ≤ 10<sup>6</sup>). Każdy z kolejnych \(t\) wierszy opisuje jednen fragment. Opis fragmentu składa się z dwóch liczb całkowitych \(l_i\), \(r_i\) (1 ≤ \(l_i\) ≤ \(r_i\) ≤ \(n\)), które oznaczają indeks jego lewego i prawego krańca.</p>

### 출력 

 <p>Na wyjściu należy wypisać \(t\) wierszy, w \(i\)-tym spośród nich powinna znaleźć się jedna liczba całkowita równa potędzie \(i\)-tego z podanych fragmentów.</p>

