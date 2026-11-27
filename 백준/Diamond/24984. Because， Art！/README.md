# [Diamond V] Because, Art! - 24984 

[문제 링크](https://acmicpc.net/problem/24984) 

### 성능 요약

메모리: 32632 KB, 시간: 96 ms

### 분류

고속 푸리에 변환, 그리디, 수학

### 제출 일자

2025년 10월 09일 00:10:19

### 문제 설명

<p>Leo is a designer. He has a collection of N fonts and N colors, each of them having an integer grade that indicates how much beautiful it is. A negative grade indicates that the font or color is “ugly”.</p>

<p>Based on that, Leo invented a new way of measuring the beauty of any text. If a text has a font of grade F<sub>i</sub> and a color of grade C<sub>j</sub>, then the beauty of the text is the product F<sub>i</sub> × C<sub>j</sub>. Note that when both the font and the color are ugly, the resulting text is beautiful, because, Art!</p>

<p>Leo has to present to his boss k beautiful text designs. The boss said to him that the texts must be really different from each other. With this in mind, Leo decided to select a distinct font and a distinct color for each text in such a way that the sum of the beauties of the k formed texts is maximum. For his pride, he also wants to know the minimum possible sum of the beauties of k texts made of distinct fonts and colors.</p>

<p>But there is a problem! Leo forgot how many designs the boss asked for, so he needs to find the answer for each integer k between 1 and N.</p>

### 입력 

 <p>The first line contains an integer N (1 ≤ N ≤ 10<sup>5</sup>) indicating the number of fonts and colors. The second line contains N integers F<sub>1</sub>, F<sub>2</sub>, . . . , F<sub>N</sub> (−10<sup>4</sup> ≤ F<sub>i</sub> ≤ 10<sup>4</sup> for i = 1, 2, . . . , N), representing the grades of the fonts. The third line contains N integers C<sub>1</sub>, C<sub>2</sub>, . . . , C<sub>N</sub> (−10<sup>4</sup> ≤ C<sub>i</sub> ≤ 10<sup>4</sup> for i = 1, 2, . . . , N), denoting the grades of the colors.</p>

### 출력 

 <p>Output N lines, such that the k-th line contains two integers indicating respectively the minimum and maximum sum of beauties if the boss asks for k texts.</p>

