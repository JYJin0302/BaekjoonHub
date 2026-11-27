# [Platinum II] KryptoLocker Ate my Homework - 16531 

[문제 링크](https://acmicpc.net/problem/16531) 

### 성능 요약

메모리: 87644 KB, 시간: 176 ms

### 분류

비트마스킹, 해 구성하기, 재귀, 정렬

### 제출 일자

2026년 01월 08일 16:17:41

### 문제 설명

<p>Your friend’s computer was infected by KryptoLocker last night. KryptoLocker is a ransomware that encrypts user’s data making it unusable until a ransom is paid to the person behind the attack.</p>

<p>Luckily your friend noticed there was something weird happening and was able to stop the malicious process before all data was lost. Unfortunately it didn’t happen in time to save the homework he had just finished.</p>

<p>“The dog ate my homework” never really worked as an excuse for most teachers and probably things won’t be different with “KryptoLocker encrypted my homework”.</p>

<p>But not all hope is lost. For this homework each student was assigned an array of integer numbers v<sub>1</sub> ≤ v<sub>2</sub> ≤ · · · ≤ v<sub>N</sub>. Then, each student had to generate a list of 2<sup>N</sup> numbers, containing the sums of the elements in each possible subsequence of the array. KryptoLocker only corrupted the first line of the file containing your friend’s answer and this was the line where the array was written. So, all sums are still known and that should be enough to recover the array.</p>

<p>Can you help your friend save his homework?</p>

### 입력 

 <p>The first line contains an integer N (1 ≤ N ≤ 18) indicating the number of elements in the array assigned to your friend. Each of the next 2<sup>N</sup> lines contains an integer S (−10<sup>9</sup> ≤ S ≤ 10<sup>9</sup>) representing the sum of the elements in a subsequence of the array. The sums of all possible subsequences appear in the input, in no particular order. There is at least one array whose sums are the values given.</p>

### 출력 

 <p>Output each different array that may have been assigned to your friend, one array per line, with the lines lexicographically sorted. Two arrays are considered different if, and only if, they contain different elements in at least one position.</p>

