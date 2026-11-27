# [Platinum V] snöflinga - 34329 

[문제 링크](https://acmicpc.net/problem/34329) 

### 성능 요약

메모리: 54612 KB, 시간: 904 ms

### 분류

분할 정복, 구현, 재귀

### 제출 일자

2025년 09월 13일 15:11:10

### 문제 설명

<p>진호는 하늘에서 내려온 눈송이 하나를 확대해서 관찰했다.</p>

<p>눈송이 하나에는 수많은 눈 결정이 들어있고, 확대를 해도 축소를 해도 같은 패턴을 가지고 있었다.</p>

<p>크기 1의 패턴은 5개의 결정이 밑변이고 가운데 한 칸이 비어 있도록 삼각형 모양을 하고 있다.</p>

<pre style="width: fit-content; margin: 0 auto; font-size: 0.8em; padding: 10px; border: 1px solid #ccc; background-color: #f9f9f9;">  *
 * *
*****
</pre>

<p>크기를 확대하면 각 변을 3등분 했을 때 가운데에서 계속해서 삼각형이 보이는 패턴을 하고 있다.</p>

<pre style="width: fit-content; margin: 0 auto; font-size: 0.8em; padding: 10px; border: 1px solid #ccc; background-color: #f9f9f9;">      *
     * *
*****   *****
</pre>
<p></p>
<pre style="width: fit-content; margin: 0 auto; font-size: 0.8em; padding: 10px; border: 1px solid #ccc; background-color: #f9f9f9;">                  *
                 * *
            *****   *****
             *         *
      *       *       *       *
     * *     *         *     * *
*****   *****           *****   *****
</pre>
<p></p>
<pre style="width: fit-content; margin: 0 auto; font-size: 0.8em; padding: 10px; border: 1px solid #ccc; background-color: #f9f9f9;">                                                      *
                                                     * *
                                                *****   *****
                                                 *         *
                                          *       *       *       *
                                         * *     *         *     * *
                                    *****   *****           *****   *****
                                     *                                 *
                                      *                               *
                                     *                                 *
                                    *****                           *****
                                         *                         *
                  *                       *                       *                       *
                 * *                     *                         *                     * *
            *****   *****           *****                           *****           *****   *****
             *         *             *                                 *             *         *
      *       *       *       *       *                               *       *       *       *       *
     * *     *         *     * *     *                                 *     * *     *         *     * *
*****   *****           *****   *****                                   *****   *****           *****   *****

</pre>

<p style="text-align: center;">눈송이의 일부분을 확대했을 때의 예시</p>

<p style="text-align: center;"><img alt="" src=""></p>

<p style="text-align: center;">크기 1부터 4까지 눈송이의 모양</p>

<p>확대한 크기 N이 주어질 때, 주어지는 크기의 눈송이를 출력해보자.</p>

### 입력 

 <p>첫째 줄에 눈송이의 크기를 나타내는 정수 $N$ $(1 \le N \le 8)$ 이 주어진다.</p>

### 출력 

 <p>주어진 크기의 눈송이를 출력한다.</p>

<p>출력하는 각 줄의 마지막 <strong>*</strong> 문자 이후에는 <strong>개행을 제외한 아무 문자도 출력하지 않는다</strong>.</p>

