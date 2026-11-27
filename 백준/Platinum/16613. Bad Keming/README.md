# [Platinum IV] Bad Keming - 16613 

[문제 링크](https://acmicpc.net/problem/16613) 

### 성능 요약

메모리: 13224 KB, 시간: 64 ms

### 분류

KMP, 문자열

### 제출 일자

2024년 07월 24일 14:53:48

### 문제 설명

<p>You and your fellow teammates have just founded a startup to sell nameplates to programmers. After having carefully researched your target market, you have determined that it is best to use a monospace font.</p>

<p>Your very first client has asked you to print the source string S onto a nameplate. Unfortunately, you have set up your laser printer incorrectly and have accidentally printed a space before the first character, after the last character and between every character of the string.</p>

<p>Your client is expecting this nameplate very soon (in 5 hours, to be precise), so you do not have time to reconfigure your printer or to find a new plate. To salvage your current plate, you have decided to use the printer to fill in each space with a single character, such that the longest possible prefix of the source string S appears as a substring of your plate. A substring is a contiguous subsequence of characters.</p>

<p>For example, say you intended to print <code>ENDED</code>. Instead, your printer printed <code>_E_N_D_E_D_</code> (using _ to indicate a space), which you could fill as <code>JEJNJDJENDE</code>. This string contains <code>ENDE</code>, which is a prefix of S with length 4. This is the best you can do.</p>

<p>As a second example, consider the string <code>ERROR</code>. This would be printed as <code>_E_R_R_O_R_</code>, which you could fill as <code>JEJRERRORRJ</code>. In this case, the entire source string <code>ERROR</code> is a substring of the final plate.</p>

<p>What is the length of the longest prefix of the source string that you can print on the nameplate?</p>

### 입력 

 <p>The input consists of a single line containing the string S. The string contains only uppercase letters and consists of at least 1 and at most 2 000 000 characters.</p>

### 출력 

 <p>Display the length of the longest prefix of S that you can print on the nameplate.</p>

