# [Diamond V] Matrix Calculator - 3874 

[문제 링크](https://acmicpc.net/problem/3874) 

### 성능 요약

메모리: 2436 KB, 시간: 16 ms

### 분류

구현, 파싱, 문자열

### 제출 일자

2024년 07월 30일 16:08:37

### 문제 설명

<p>Dr. Jimbo, an applied mathematician, needs to calculate matrices all day for solving his own problems. In his laboratory, he uses an excellent application program for manipulating matrix expressions, however, he cannot use it outside his laboratory because the software consumes much of resources. He wants to manipulate matrices outside, so he needs a small program similar to the excellent application for his handheld computer.</p>

<p>Your job is to provide him a program that computes expressions of matrices.</p>

<p>Expressions of matrices are described in a simple language. Its syntax is shown in Table J.1. Note that even a space and a newline have meaningful roles in the syntax.</p>

<p>Table J.1: Syntax in BNF (a newline is denoted by <code>NL</code>)</p>

<pre>program            ::= assignment | program assignment
assignment         ::= var "=" expr "." NL
var                ::= "A" | "B" | "C" | "D" | "E" | "F" | "G" | "H"
                     | "I" | "J" | "K" | "L" | "M" | "N" | "O" | "P"
                     | "Q" | "R" | "S" | "T" | "U" | "V" | "W" | "X"
                     | "Y" | "Z"
expr               ::= term | expr "+" term | expr "-" term
term               ::= factor | term "*" factor
factor             ::= primary | "-" factor
primary            ::= inum | var | matrix | "(" expr ")"
                     | indexed-primary | transposed-primary
indexed-primary    ::= primary "(" expr "," expr ")"
transposed-primary ::= primary "’"
matrix             ::= "[" row-seq "]"
row-seq            ::= row | row-seq ";" row
row                ::= expr | row " " expr
inum               ::= digit | inum digit
digit              ::= "0" | "1" | "2" | "3" | "4"
                     | "5" | "6" | "7" | "8" | "9"</pre>

<p>The start symbol of this syntax is <code>program</code> that is defined as a sequence of <code>assignments</code> in Table J.1. Each <code>assignment</code> has a variable on the left hand side of an equal symbol (“<code>=</code>”) and an expression of matrices on the right hand side followed by a period and a newline (<code>NL</code>). It denotes an assignment of the value of the expression to the variable. The variable (<code>var</code> in Table J.1) is indicated by an uppercase Roman letter. The value of the expression (<code>expr</code>) is a matrix or a scalar, whose elements are integers. Here, a scalar integer and a 1 × 1 matrix whose only element is the same integer can be used interchangeably.</p>

<p>An expression is one or more terms connected by “<code>+</code>” or “<code>-</code>” symbols. A term is one or more factors connected by “<code>*</code>” symbol. These operators (“<code>+</code>”, “<code>-</code>”, “<code>*</code>”) are left associative.</p>

<p>A factor is either a primary expression (<code>primary</code>) or a “<code>-</code>” symbol followed by a factor. This unary operator “<code>-</code>” is right associative.</p>

<p>The meaning of operators are the same as those in the ordinary arithmetic on matrices: Denoting matrices by <code>A</code> and <code>B</code>, <code>A + B</code>, <code>A − B</code>, <code>A * B</code>, and <code>−A</code> are defined as the matrix sum, difference, product, and negation. The sizes of <span style="font-family:monospace">A</span> and <span style="font-family:monospace">B</span> should be the same for addition and subtraction. The number of columns of <span style="font-family:monospace">A</span> and the number of rows of <span style="font-family:monospace">B</span> should be the same for multiplication.</p>

<p>Note that all the operators <code>+</code>, <code>−</code>, <code>*</code> and unary − represent computations of addition, subtraction, multiplication and negation modulo <code>M</code> = 2<sup>15</sup> = 32768, respectively. Thus all the values are nonnegative integers between 0 and 32767, inclusive. For example, the result of an expression 2 − 3 should be 32767, instead of −1.</p>

<p><code>inum</code> is a non-negative decimal integer less than <code>M</code>.</p>

<p><code>var</code> represents the matrix that is assigned to the variable <code>var</code> in the most recent preceding assignment statement of the same variable.</p>

<p><code>matrix</code> represents a mathematical matrix similar to a 2-dimensional array whose elements are integers. It is denoted by a <code>row-seq</code> with a pair of enclosing square brackets. <code>row-seq</code> represents a sequence of <code>row</code>s, adjacent two of which are separated by a semicolon. <code>row</code> represents a sequence of expressions, adjacent two of which are separated by a space character.</p>

<p>For example, <code>[1 2 3;4 5 6]</code> represents a matrix \(\begin{pmatrix}  1&2&3  \\  4&5&6  \end{pmatrix}\). The first row has three integers separated by two space characters, i.e. “1 2 3”. The second row has three integers, i.e. “4 5 6”. Here, the <code>row-seq</code> consists of the two rows separated by a semicolon. The matrix is denoted by the <code>row-seq</code> with a pair of square brackets.</p>

<p>Note that elements of a row may be matrices again. Thus the nested representation of a matrix may appear. The number of rows of the value of each expression of a <code>row</code> should be the same, and the number of columns of the value of each <code>row</code> of a <code>row-seq</code> should be the same.</p>

<p>For example, a matrix represented by <code>[[1 2 3;4 5 6] [7 8;9 10] [11;12];13 14 15 16 17 18]</code> is \(\begin{pmatrix} 1&2&3&7&8&11 \\ 4&5&6&9&10&12 \\ 13&14&15&16&17&18 \end{pmatrix}\). The sizes of matrices should be consistent, as mentioned above, in order to form a well-formed matrix as the result. For example, <code>[[1 2;3 4] [5;6;7];6 7 8]</code> is not consistent since the first row “<code>[1 2;3 4] [5;6;7]</code>” has two matrices (2 × 2 and 3 × 1) whose numbers of rows are different. <code>[1 2;3 4 5]</code> is not consistent since the number of columns of two rows are different.</p>

<p>The multiplication of 1 × 1 matrix and m × n matrix is well-defined for arbitrary m > 0 and n > 0, since a 1 × 1 matrices can be regarded as a scalar integer. For example, <code>2*[1 2;3 4]</code> and <code>[1 2;3 4]*3</code> represent the products of a scalar and a matrix \(2 * \begin{pmatrix} 1&2 \\ 3&4 \end{pmatrix} = \begin{pmatrix} 2&4 \\ 6&8 \end{pmatrix}\) and \(\begin{pmatrix} 1&2 \\ 3&4 \end{pmatrix} * 3 = \begin{pmatrix} 3&6 \\ 9&12 \end{pmatrix}\). <code>[2]*[1 2;3 4]</code> and <code>[1 2;3 4]*[3]</code> are also well-defined similarly. An indexed-primary is a primary expression followed by two expressions as indices. The first index is 1 × k integer matrix denoted by (i<sub>1</sub> i<sub>2</sub> ··· i<sub>k</sub>), and the second index is 1 × <sub>ℓ</sub> integer matrix denoted by (j<sub>1</sub> j<sub>2</sub> ··· j<sub>ℓ</sub>). The two indices specify the submatrix extracted from the matrix which is the value of the preceding primary expression. The size of the submatrix is k× and whose (a, b)-element is the (i<sub>a</sub>, j<sub>b</sub>)-element of the value of the preceding primary expression. The way of indexing is one-origin, i.e., the first element is indexed by 1.</p>

<p>For example, the value of <code>([1 2;3 4]+[3 0;0 2])([1],[2])</code> is equal to 2, since the value of its primary expression is a matrix <code>[4 2;3 6]</code>, and the first index <code>[1]</code> and the second <code>[2]</code> indicate the (1, 2)-element of the matrix. The same integer may appear twice or more in an index matrix, e.g., the first index matrix of an expression <code>[1 2;3 4]([2 1 1],[2 1])</code> is <code>[2 1 1]</code>, which has two 1’s. Its value is \(\begin{pmatrix} 4&3 \\ 2&1 \\ 2&1 \end{pmatrix}\).</p>

<p>A <code>transposed-primary</code> is a primary expression followed by a single quote symbol (“<code>’</code>”), which indicates the transpose operation. The transposed matrix of an m × n matrix A = (a<sub>ij</sub>) (i = 1,...,m and j = 1,...,n) is the n × m matrix B = (b<sub>ij</sub>) (i = 1,...,n and j = 1,...,m), where b<sub>ij</sub> = a<sub>ji</sub>. For example, the value of <code>[1 2;3 4]’</code> is \(\begin{pmatrix} 1&3 \\ 2&4 \end{pmatrix}\).</p>

### 입력 

 <p>The input consists of multiple datasets, followed by a line containing a zero. Each dataset has the following format.</p>

<pre>n
program</pre>

<p>n is a positive integer, which is followed by a program that is a sequence of single or multiple lines each of which is an assignment statement whose syntax is defined in Table J.1. n indicates the number of the assignment statements in the program. All the values of <code>var</code>s are undefined at the beginning of a program.</p>

<p>You can assume the following:</p>

<ul>
	<li>1 ≤ n ≤ 10,</li>
	<li>the number of characters in a line does not exceed 80 (excluding a newline),</li>
	<li>there are no syntax errors and semantic errors (e.g., reference of undefined <code>var</code>),</li>
	<li>the number of rows of matrices appearing in the computations does not exceed 100, and</li>
	<li>the number of columns of matrices appearing in the computations does not exceed 100.</li>
</ul>

### 출력 

 <p>For each dataset, the value of the expression of each assignment statement of the program should be printed in the same order. All the values should be printed as non-negative integers less than <code>M</code>.</p>

<p>When the value is an m × n matrix A = (a<sub>ij</sub>) (i = 1,...,m and j = 1,...,n), m lines should be printed. In the k-th line (1 ≤ k ≤ m), integers of the k-th row, i.e., a<sub>k1</sub>,...,a<sub>kn</sub>, should be printed separated by a space.</p>

<p>After the last value of a dataset is printed, a line containing five minus symbols ’-----’ should be printed for human readability.</p>

<p>The output should not contain any other extra characters.</p>

