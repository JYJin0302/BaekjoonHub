# [Gold II] Science Fiction - 20675 

[문제 링크](https://acmicpc.net/problem/20675) 

### 성능 요약

메모리: 2324 KB, 시간: 4 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2024년 10월 12일 13:09:34

### 문제 설명

<p>Arts and literature have always been influenced by science. This appears, for example, in Christopher Nolan movies. But, there is a scientist who is doing his research on a hypothesis based on fictional novels.</p>

<p>Dr. Khosro, a theoretical physicist, does research on parallel worlds with high-dimensions, inspired by Isaac Asimov’s novels. During his research, he needs a method of sorting in his imaginary high-dimension network of planets. In Dr. Khosro’s imaginary n-dimensional world, there are 2<sup>n</sup> planets and a wormhole network connecting them. The network is like an n-dimensional hypercube. The planets are numbered with non-negative integers less than 2<sup>n</sup>, and there is a wormhole from planet a to planet b if and only if the n-bit binary representations of a and b differ in exactly one bit-position. In Dr. Khosro’s model, there is a number written on each planet and we can swap the numbers of two planets only if there is a direct wormhole between them. You are given the numbers written on each planet, construct a valid sequence of swaps that makes the numbers sequence sorted from smallest to largest. Formally, if the number written on the planet number i (0 ⩽ i < 2<sup>n</sup>) is denoted by a<sub>i</sub>, you have to construct a sequence of valid pairwise swaps that makes the sequence a = ⟨a<sub>0</sub>, a<sub>1</sub>, ..., a<sub>2<sup>n</sup>−1</sub>⟩ in increasing order.</p>

### 입력 

 <p>The first line of input consists of n (1 ⩽ n ⩽ 10), the dimension of Dr. Khosro’s imaginary world. The next line contains 2<sup>n</sup> <strong>distinct</strong> integers, indicating a<sub>0</sub>, a<sub>1</sub>, ..., a<sub>2<sup>n</sup>−1</sub> (0 ⩽ a<sub>i</sub> ⩽ 10<sup>6</sup>).</p>

### 출력 

 <p>Print the numbers of your swaps in the first line. Your answer will be considered correct if this number is nonnegative and less than 12 000. Then in the following lines, print the sequence of swaps. In your solution, every swap must be between two planets with a direct wormhole between them.</p>

