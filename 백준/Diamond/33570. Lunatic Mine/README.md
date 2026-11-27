# [Diamond II] Lunatic Mine - 33570 

[문제 링크](https://acmicpc.net/problem/33570) 

### 성능 요약

메모리: 13748 KB, 시간: 648 ms

### 분류

애드 혹, 해 구성하기, 휴리스틱, 구현

### 제출 일자

2025년 09월 23일 11:39:27

### 문제 설명

<p style="text-align:center">이 문제는 <strong>비적응적 인터랙티브</strong> 문제입니다.</p>

<hr>
<h1 style="text-align:center"><span style="color:#f1c40f">🌙 </span><strong><span style="color:#f1c40f">Lunatic</span> <span style="color:#9b59b6">Mine </span></strong><span style="color:#9b59b6">⛏</span></h1>

<hr>
<blockquote>
<p>달의 광산 한복판에서 돌을 캐면서 끝없는 도전 과제를 깨는 초특급 광산 시뮬레이터! 이건 그저 <span style="color:#3498db"><strong>광(鑛)부</strong></span>의 꿈이 아닙니다! 당신은 이제 단단한 바위 속에서 반짝이는 돌을 캐며, 도전 과제 10개를 노리는 진정한 <span style="color:#e74c3c"><strong>광(狂)부</strong></span>가 될 수 있습니다!</p>

<p>입구에서 곡괭이를 휘두르면, 지하 깊숙이 숨겨진 돌이 빛을 발합니다. 하지만 조심하세요, 이건 단순히 돌을 깨부수는 일이 아닙니다! 돌 속에 숨겨진 재치 있는(?) 사건들이 당신을 기다리고 있습니다. 어떤 돌은 돈을 주고, 어떤 돌은 강화석을 주고, 어떤 돌은… 글쎄, 아무것도 안 줍니다. 웃기지 않나요?</p>

<p>곡괭이 강화를 통해 <strong><span style="color:#9b59b6">우주</span> <span style="color:#2ecc71">최</span><span style="color:#f1c40f">강</span> <span style="color:#2ecc71">채</span><span style="color:#f1c40f">광</span> <span style="color:#e74c3c">능력</span></strong>을 얻고 싶으신가요? 도전 과제 10개를 모두 달성해서 <strong>끝판왕</strong>이 되고 싶으신가요?</p>

<p>그렇다면 이 게임이야말로 당신을 위한 것입니다. 웃음과 헛수고가 가득한 광산 모험, 지금 바로 곡괭이를 들고 뛰어드세요!</p>

<hr>
<p>- <strong>Lunatic Mine</strong> 광고</p>
</blockquote>

<hr>
<h1 style="text-align:center"><strong>목차</strong></h1>

<ul>
<li><a href="#game">제 1장. 게임 시스템</a></li>
<li><a href="#random">제 2장. 랜덤 시스템과 인벤토리 & 장착 시스템</a></li>
<li><a href="#smelt">제 3장. 제련 시스템</a></li>
<li><a href="#enchant">제 4장. 마법 부여 시스템</a></li>
<li><a href="#rank_up">제 5장. 합성 & 마법 승급 시스템</a></li>
<li><a href="#bless">제 6장. 축복 시스템</a></li>
<li><a href="#mine">제 7장. 채광 시스템</a></li>
<li><a href="#achievement">최종장. 업적 시스템</a></li>
</ul>

<hr>
<h1 id="game" style="text-align:center"><strong>🎮 제 1장. 게임 시스템 🎮</strong></h1>

<p><strong>Lunatic Mine</strong> 게임에는 두 종류의 재화가 있습니다! 루나🌙와 강화석💎이죠! 루나는 이 게임에서 통용되는 화폐라고 보아도 무방합니다. 반면에 강화석은 여러분의 곡괭이⛏를 좀 더 강화하기 위해 필요한 재화입니다. 강화할 곡괭이가 어떻게 되어 있는지 한번 살펴보시죠! 편의상 $2^{63} - 1$의 값을 $\text{INF}$로 정의하겠습니다.</p>

<ul>
<li>곡괭이 능력치 ⛏
<ul>
<li>마법 등급 🔮
<ul>
<li>$0$ 이상 $4$ 이하의 정수로 표현됩니다.
<ul>
<li>이 정수는 마법 등급을 의미합니다.</li>
</ul>
</li>
<li>마법 시스템<sup><a href="#enchant">[🪄]</a></sup><sup><a href="#rank_up">[🔮]</a></sup>의 등급을 의미합니다.</li>
<li>보통 마법 등급이 높으면 좋은 마법이 뜰 확률이 높습니다.</li>
<li>마법 등급은 5가지로 <strong>일반</strong>, <span style="color:#f39c12"><strong>레어</strong></span>, <span style="color:#9b59b6"><strong>에픽</strong></span>, <span style="color:#3498db"><strong>유니크</strong></span>, <span style="color:#e74c3c"><strong>레전드리</strong></span> 순으로 높은 등급입니다.</li>
<li>각각 0번, 1번, 2번, 3번, 4번 마법 등급으로 부르기도 합니다.</li>
</ul>
</li>
<li>마법 🪄
<ul>
<li>$0$ 이상 $18$ 이하의 정수 $1$개와 $-25$ 이상 $4\,000$ 이하의 정수 $1$개로 표현됩니다.
<ul>
<li>첫 번째 정수는 마법 아이디, 두 번째 정수는 마법의 세부 수치를 의미합니다.</li>
</ul>
</li>
<li>마법은 곡괭이의 각종 능력치를 좋게 만들어줍니다.</li>
<li>한 곡괭이에는 3개의 마법이 부여되며 각각 0번, 1번, 2번 마법 슬롯이라 부릅니다.</li>
<li>영향을 주는 능력치의 종류가 같은 마법끼리는 0번, 1번, 2번 마법 슬롯 순서대로 능력치를 바꾸기 때문에 같은 마법의 구성이더라도 순서가 다르면 최종 능력치가 다를 수 있습니다.
<ul>
<li>다음과 같은 상황에서 2번 마법 슬롯은 고려하지 않는다고 가정합니다.</li>
<li>0번 마법 슬롯은 $A$ 수치를 $2$만큼 올려주고, 1번 마법 슬롯이 $A$ 수치를 $2$배 올려준다면 최종 적용 수치는 $(A+2) \times 2$입니다.</li>
<li>0번 마법 슬롯은 $A$ 수치를 $2$배 올려주고, 1번 마법 슬롯이 $A$ 수치를 $2$만큼 올려준다면 최종 적용 수치는 $A \times 2 + 2$입니다.</li>
</ul>
</li>
</ul>
</li>
<li>제련 레벨 🔨
<ul>
<li>$0$ 이상 $30$ 이하의 정수로 표현됩니다.
<ul>
<li>이 정수는 제련 레벨을 의미합니다.</li>
</ul>
</li>
<li>제련 시스템<sup><a href="#smelt">[🔨]</a></sup>의 레벨을 의미합니다.</li>
<li>보통 제련 레벨이 높으면 곡괭이 능력치가 좋습니다.</li>
</ul>
</li>
<li>최종 레벨 ⚒️
<ul>
<li>$0$ 이상 $39$ 이하의 정수로 표현됩니다.
<ul>
<li>이 정수는 최종 레벨을 의미합니다.</li>
</ul>
</li>
<li>최종 레벨은 제련 레벨에서 마법에 의한 레벨까지 추가한 레벨입니다.</li>
<li>채광 시 마법 시스템<sup><a href="#enchant">[🪄]</a></sup><sup><a href="#rank_up">[🔮]</a></sup>에 의해 증가할 수 있는 능력치입니다.</li>
</ul>
</li>
<li>최소 루나 🌙
<ul>
<li>$1$ 이상 $\text{INF}$ 이하의 정수로 표현됩니다.
<ul>
<li>이 정수는 최소 루나를 의미합니다.</li>
</ul>
</li>
<li>채광 시스템<sup><a href="#mine">[⛏]</a></sup>에서 루나를 최소로 얼마나 얻을 수 있는지에 기여합니다.</li>
<li>제련 시스템<sup><a href="#smelt">[🔨]</a></sup>에서 제공하는 능력치입니다.</li>
<li>축복 시스템<sup><a href="#bless">[🙏]</a></sup>에서 제공하는 능력치입니다.</li>
<li>채광 시 마법 시스템<sup><a href="#enchant">[🪄]</a></sup><sup><a href="#rank_up">[🔮]</a></sup>에 의해 증가할 수 있는 능력치입니다.</li>
</ul>
</li>
<li>최대 루나 🌕
<ul>
<li>$100$ 이상 $\text{INF}$ 이하의 정수로 표현됩니다.
<ul>
<li>이 정수는 최대 루나를 의미합니다.</li>
</ul>
</li>
<li>채광 시스템<sup><a href="#mine">[⛏]</a></sup>에서 루나를 최대로 얼마나 얻을 수 있는지에 기여합니다.</li>
<li>제련 시스템<sup><a href="#smelt">[🔨]</a></sup>에서 제공하는 능력치입니다.</li>
<li>축복 시스템<sup><a href="#bless">[🙏]</a></sup>에서 제공하는 능력치입니다.</li>
<li>채광 시 마법 시스템<sup><a href="#enchant">[🪄]</a></sup><sup><a href="#rank_up">[🔮]</a></sup>에 의해 증가할 수 있는 능력치입니다.</li>
</ul>
</li>
<li>달빛 ✨
<ul>
<li>$0$ 이상 $\text{INF}$ 이하의 정수로 표현됩니다.
<ul>
<li>이 정수는 달빛을 의미합니다.</li>
</ul>
</li>
<li>채광 시스템<sup><a href="#mine">[⛏]</a></sup>에서 루나를 얼마나 얻을 수 있는지에 기여합니다.</li>
<li>제련 시스템<sup><a href="#smelt">[🔨]</a></sup>에서 제공하는 능력치입니다.</li>
<li>축복 시스템<sup><a href="#bless">[🙏]</a></sup>에서 제공하는 능력치입니다.</li>
<li>채광 시 마법 시스템<sup><a href="#enchant">[🪄]</a></sup><sup><a href="#rank_up">[🔮]</a></sup>에 의해 증가할 수 있는 능력치입니다.</li>
</ul>
</li>
<li>배율 🔥
<ul>
<li>$100$ 이상 $\text{INF}$ 이하의 정수로 표현됩니다.
<ul>
<li>이 정수는 배율을 의미합니다.</li>
</ul>
</li>
<li>채광 시스템<sup><a href="#mine">[⛏]</a></sup>에서 루나를 얼마나 얻을 수 있는지에 기여합니다.</li>
<li>축복 시스템<sup><a href="#bless">[🙏]</a></sup>에서 제공하는 능력치입니다.</li>
<li>채광 시 마법 시스템<sup><a href="#enchant">[🪄]</a></sup><sup><a href="#rank_up">[🔮]</a></sup>에 의해 증가할 수 있는 능력치입니다.</li>
</ul>
</li>
<li>강화석 드랍률 💎
<ul>
<li>길이가 $5$인 정수형 배열로 표현됩니다.
<ul>
<li>각 원소는 $0$ 이상 $\text{INF}$ 이하의 정수입니다.
<ul>
<li>$0$번째 원소는 <strong>일반 강화석 드랍률</strong>을 의미합니다.</li>
<li>$1$번째 원소는 <span style="color:#f39c12"><strong>레어 강화석 드랍률</strong></span>을 의미합니다.</li>
<li>$2$번째 원소는 <span style="color:#9b59b6"><strong>에픽 강화석 드랍률</strong></span>을 의미합니다.</li>
<li>$3$번째 원소는 <span style="color:#3498db"><strong>유니크 강화석 드랍률</strong></span>을 의미합니다.</li>
<li>$4$번째 원소는 <span style="color:#e74c3c"><strong>레전드리 강화석 드랍률</strong></span>을 의미합니다.</li>
</ul>
</li>
<li>이 정수형 배열은 강화석 드랍률을 의미합니다.</li>
</ul>
</li>
<li>채광 시스템<sup><a href="#mine">[⛏]</a></sup>에서 강화석을 얻을 수 있는 확률에 기여합니다.</li>
<li>제련 시스템<sup><a href="#smelt">[🔨]</a></sup>에서 제공하는 능력치입니다.</li>
<li>축복 시스템<sup><a href="#bless">[🙏]</a></sup>에서 제공하는 능력치입니다.</li>
<li>채광 시 마법 시스템<sup><a href="#enchant">[🪄]</a></sup><sup><a href="#rank_up">[🔮]</a></sup>에 의해 증가할 수 있는 능력치입니다.</li>
</ul>
</li>
<li>행운 🍀
<ul>
<li>$1$ 이상 $16$ 이하의 정수로 표현됩니다.
<ul>
<li>이 정수는 행운을 의미합니다.</li>
</ul>
</li>
<li>채광 시스템<sup><a href="#mine">[⛏]</a></sup>에서 강화석을 얼마나 얻을 수 있는지에 기여합니다.</li>
<li>채광 시 마법 시스템<sup><a href="#enchant">[🪄]</a></sup><sup><a href="#rank_up">[🔮]</a></sup>에 의해 증가할 수 있는 능력치입니다.</li>
</ul>
</li>
<li>할인 🆓
<ul>
<li>$25$ 이상 $100$ 이하의 정수로 표현됩니다.
<ul>
<li>이 정수는 할인을 의미합니다.</li>
</ul>
</li>
<li>제련 시스템<sup><a href="#smelt">[🔨]</a></sup>에서 제련 비용 감소에 기여합니다.</li>
<li>마법 시스템<sup><a href="#enchant">[🪄]</a></sup><sup><a href="#rank_up">[🔮]</a></sup>에 의해 감소할 수 있는 능력치입니다.</li>
</ul>
</li>
</ul>
</li>
</ul>

<p>여러분은 강화한 곡괭이로 채광을 할 수 있습니다. 채광하면 곡괭이 강화 상태에 따라서 루나와 강화석을 얻을 수 있습니다. 채광으로 얻은 재화로 곡괭이 강화에 다시 투자해 지속적으로 곡괭이 능력치를 올리는 것이 가능하죠. 곡괭이로 가능한 행동은 총 6가지입니다. 여러분은 명령어를 통해 아래 행동을 취할 수 있습니다.</p>

<ul>
<li>채광 (<code><span style="color:#e74c3c">mine</span></code>)

<ul>
<li>여러분이 가장 많이 하게 될 행동입니다.
<ul>
<li><iframe allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen="" frameborder="0" height="315" referrerpolicy="strict-origin-when-cross-origin" src="https://www.youtube.com/embed/p-3e0EkvIEM?si=hEMrUBP7HMxP-v1V" title="YouTube video player" width="560"></iframe></li>
</ul>
</li>
<li>해당 행동으로, <strong>장착한</strong> 곡괭이의 능력에 따라 루나와 강화석을 얻을 수 있습니다.</li>
</ul>
</li>
<li>장착 (<span style="color:#e74c3c"><code>equip</code></span>)
<ul>
<li>이 게임에서는 곡괭이가 세 개입니다. 곡괭이가 세 개! 그 세 개의 곡괭이 중 원하는 곡괭이를 장착할 수 있는 명령어입니다.</li>
<li>곡괭이는 0번, 1번, 2번 곡괭이가 있습니다.</li>
</ul>
</li>
<li>제련 (<span style="color:#e74c3c"><code>smelt</code></span>)
<ul>
<li>루나를 소모하여, <strong>장착한</strong> 곡괭이의 제련 레벨을 올릴 수 있습니다.</li>
</ul>
</li>
<li>합성 (<span style="color:#e74c3c"><code>craft</code></span>)
<ul>
<li>루나와 강화석을 소모하여, 더 좋은 강화석을 제작할 수 있습니다.</li>
</ul>
</li>
<li>마법 승급 (<span style="color:#e74c3c"><code>rank_up</code></span>)
<ul>
<li>강화석을 소모하여, <strong>장착한</strong> 곡괭이의 마법 등급을 올릴 수 있습니다.</li>
</ul>
</li>
<li>마법 부여 (<span style="color:#e74c3c"><code>enchant</code></span>)
<ul>
<li>루나를 소모하여, <strong>장착한</strong> 곡괭이에 마법을 부여할 수 있습니다.</li>
</ul>
</li>
</ul>

<p>좋습니다. 그러면 시스템 흐름을 요약해 봅시다.</p>

<ul>
<li>게임 흐름
<ul>
<li>채광을 통해 루나와 강화석을 얻습니다.</li>
<li>합성을 통해 더 좋은 강화석을 얻습니다.</li>
<li>제련, 마법 승급, 마법 부여를 통해 곡괭이를 강화합니다.</li>
<li><img alt="" src="" style="width:500px;height:397px"></li>
</ul>
</li>
</ul>

<p>이제 세부적인 사항에 대해서 살펴봅시다.</p>

<hr>
<h1 id="random" style="text-align:center"><strong>👜 제 2장. 랜덤 시스템과 인벤토리 & 장착 시스템 👜</strong></h1>

<p>이 게임에서는 유사 난수 생성기를 활용합니다. 따라서 시드와 명령어 순서만 알고 있다면, 항상 같은 결과를 얻을 수 있습니다!</p>

<ul>
<li>랜덤 함수
<ul>
<li>시드
<ul>
<li>$0$ 이상 $2^{32}$ 미만의 정수이며 $S_0$으로 정의합니다.</li>
</ul>
</li>
<li>rand()
<ul>
<li>유사 난수 생성기 함수이며, 선형 합동 생성기를 활용합니다.</li>
<li>rand() 함수를 $i$번째로 호출하면 $S_{n + 1} = (aS_n + c) \bmod m$식에 따라 $S_i$를 반환합니다.</li>
<li>$S_0$은 위에서 언급한 시드입니다.</li>
<li>이때 $a = 1\,664\,525$ , $c = 1\,013\,904\,223$ , $m = 2^{32}$ 입니다.</li>
</ul>
</li>
<li>randInt($l$, $r$)
<ul>
<li>$l$ 이상 $r$ 이하의 정수를 반환하는 함수입니다.</li>
<li>randInt($l$, $r$)를 호출하면 $l +(($rand()$\times (r-l+1)) \div m$ 의 <strong>몫</strong>$)$을 반환합니다.</li>
</ul>
</li>
<li>chance($p$)
<ul>
<li>$p$% 확률로 True를 반환하는 함수입니다.</li>
<li>chance($p$)를 호출하면 randInt($1$, $100$) $\le p$의 논리 연산 결과를 반환합니다.</li>
</ul>
</li>
<li>choice($\text{arr}$)
<ul>
<li>배열 $\text{arr}$에 있는 임의의 원소 하나를 반환하는 함수입니다.</li>
<li>choice($\text{arr}$)을 호출하면 배열 $\text{arr}$의 randInt($0$, $\text{arr}$의 길이 $-\ 1$)번째 원소를 반환합니다.
<ul>
<li>원소가 $N$개인 배열은 첫 번째 원소가 $0$번째이고, 마지막 원소가 $N - 1$번째 원소입니다.</li>
</ul>
</li>
</ul>
</li>
<li>명령어
<ul>
<li><strong>랜덤 함수를 호출하는 명령어는 제공하지 않습니다.</strong></li>
</ul>
</li>
</ul>
</li>
<li>인벤토리
<ul>
<li>인벤토리를 통해 곡괭이 3개, 루나, 강화석, 축복 강화석을 보유할 수 있습니다.
<ul>
<li>곡괭이는 모든 곡괭이 능력치의 집합으로 표현됩니다.
<ul>
<li>곡괭이 능력치는 게임 시스템<sup><a href="#game">[🎮]</a></sup> 설명란에서 정의했음을 유의하세요.</li>
</ul>
</li>
<li>루나는 $0$ 이상 $\text{INF}$ 이하의 정수로 표현됩니다.</li>
<li>강화석은 길이가 $5$인 정수형 배열로 표현됩니다.
<ul>
<li>각 원소는 $0$ 이상 $\text{INF}$ 이하의 정수입니다.
<ul>
<li>$0$번째 원소는 <strong>일반 강화석 개수</strong>를 의미합니다.</li>
<li>$1$번째 원소는 <span style="color:#f39c12"><strong>레어 강화석 개수</strong></span>를 의미합니다.</li>
<li>$2$번째 원소는 <span style="color:#9b59b6"><strong>에픽 강화석 개수</strong></span>를 의미합니다.</li>
<li>$3$번째 원소는 <span style="color:#3498db"><strong>유니크 강화석 개수</strong></span>를 의미합니다.</li>
<li>$4$번째 원소는 <span style="color:#e74c3c"><strong>레전드리 강화석 개수</strong></span>를 의미합니다.</li>
</ul>
</li>
<li>5종류의 강화석은 등급 순서대로 0번, 1번, 2번, 3번, 4번 등급 강화석으로 부르기도 합니다.</li>
</ul>
</li>
<li>축복 강화석 개수는 $0$ 이상 $\text{INF}$ 이하의 정수로 표현됩니다.</li>
</ul>
</li>
<li><strong>게임 시작 시</strong>
<ul>
<li>초기 곡괭이 3개와 1000 루나, <strong>일반 강화석</strong> 20개가 지급됩니다.</li>
<li>축복 강화석, <span style="color:#f39c12"><strong>레어 강화석</strong></span>, <span style="color:#9b59b6"><strong>에픽 강화석</strong></span>, <span style="color:#3498db"><strong>유니크 강화석</strong></span>, <span style="color:#e74c3c"><strong>레전드리 강화석</strong></span>은 0개입니다.</li>
<li>초기 곡괭이의 능력치는 다음과 같습니다.
<ul>
<li>제련 레벨 : $0$</li>
<li>마법 등급 : <strong>일반</strong></li>
<li>마법 : 0번, 1번, 2번 마법 슬롯 모두 0번 마법이 부여된 상태</li>
<li>최소 루나 : $1$</li>
<li>최대 루나 : $100$</li>
<li>달빛 : $0$</li>
<li>배율 : $100$</li>
<li>강화석 드랍률 : 모든 등급 $0$(%)</li>
<li>행운 : $1$</li>
<li>할인 : $100$</li>
</ul>
</li>
</ul>
</li>
<li>명령어
<ul>
<li><strong>인벤토리를 열람하는 명령어는 제공하지 않습니다.</strong></li>
</ul>
</li>
</ul>
</li>
<li>장착
<ul>
<li>원하는 곡괭이를 장착합니다.</li>
<li><strong>장착한</strong> 곡괭이로만 채광할 수 있습니다.</li>
<li><strong>장착한</strong> 곡괭이에만 제련, 마법 승급, 마법 부여를 할 수 있습니다.</li>
<li><strong>게임은 0번 곡괭이를 <strong>장착한</strong> 상태에서 시작합니다.</strong></li>
<li>명령어
		<ul style="list-style-type:square">
<li><span style="color:#e74c3c"><code>equip</code></span> <span style="color:#e74c3c">$x$</span> : $x$번째 곡괭이를 장착합니다.</li>
<li>$x$는 $0$ 이상 $2$ 이하의 정수이어야 합니다.</li>
<li>반환값
<ul>
<li><span style="color:#e74c3c"><code>1</code></span> : 장착에 성공한 경우 반환합니다.</li>
</ul>
</li>
</ul>
</li>
</ul>
</li>
</ul>

<p>이제 여러분은 이 게임을 즐길 준비가 된 겁니다! 한번 강화 시스템들도 하나씩 알아보죠. 다음은 제련 시스템<sup><a href="#smelt">[🔨]</a></sup>입니다!</p>

<hr>
<h1 id="smelt" style="text-align:center">🔨 <strong>제 3장. 제련 시스템 </strong>🔨</h1>

<ul>
<li>
	<p>제련</p>

	<table class="table table-bordered td-center th-center">
<thead>
<tr>
<th>강화 전</th>
<th>강화 후</th>
<th>비용</th>
<th>성공 확률</th>
<th>최소 루나</th>
<th>최대 루나</th>
<th>일반 강화석 드랍률</th>
<th>달빛</th>
<th>레어 강화석 드랍률</th>
<th>에픽 강화석 드랍률</th>
<th>유니크 강화석 드랍률</th>
</tr>
</thead>
<tbody>
<tr>
<td>-</td>
<td>0레벨</td>
<td>-</td>
<td>-</td>
<td>1</td>
<td>100</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>0 레벨</td>
<td>1 레벨</td>
<td>1000 루나</td>
<td>100.00%</td>
<td>100</td>
<td>200</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>1 레벨</td>
<td>2 레벨</td>
<td>2000 루나</td>
<td>95.00%</td>
<td>200</td>
<td>400</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>2 레벨</td>
<td>3 레벨</td>
<td>3000 루나</td>
<td>90.00%</td>
<td>300</td>
<td>600</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>3 레벨</td>
<td>4 레벨</td>
<td>4000 루나</td>
<td>85.00%</td>
<td>400</td>
<td>800</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>4 레벨</td>
<td>5 레벨</td>
<td>5000 루나</td>
<td>80.00%</td>
<td>500</td>
<td>1000</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>5 레벨</td>
<td>6 레벨</td>
<td>6000 루나</td>
<td>80.00%</td>
<td>600</td>
<td>1200</td>
<td>1%</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>6 레벨</td>
<td>7 레벨</td>
<td>7000 루나</td>
<td>80.00%</td>
<td>700</td>
<td>1400</td>
<td>2%</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>7 레벨</td>
<td>8 레벨</td>
<td>8000 루나</td>
<td>80.00%</td>
<td>800</td>
<td>1600</td>
<td>3%</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>8 레벨</td>
<td>9 레벨</td>
<td>9000 루나</td>
<td>80.00%</td>
<td>900</td>
<td>1800</td>
<td>4%</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>9 레벨</td>
<td>10 레벨</td>
<td>10000 루나</td>
<td>80.00%</td>
<td>1000</td>
<td>2000</td>
<td>5%</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>10 레벨</td>
<td>11 레벨</td>
<td>11000 루나</td>
<td>70.00%</td>
<td>1200</td>
<td>2400</td>
<td>7%</td>
<td>100</td>
<td>-</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>11 레벨</td>
<td>12 레벨</td>
<td>12000 루나</td>
<td>60.00%</td>
<td>1500</td>
<td>3000</td>
<td>9%</td>
<td>200</td>
<td>-</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>12 레벨</td>
<td>13 레벨</td>
<td>13000 루나</td>
<td>50.00%</td>
<td>1900</td>
<td>3800</td>
<td>11%</td>
<td>300</td>
<td>-</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>13 레벨</td>
<td>14 레벨</td>
<td>14000 루나</td>
<td>40.00%</td>
<td>2400</td>
<td>4800</td>
<td>13%</td>
<td>400</td>
<td>-</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>14 레벨</td>
<td>15 레벨</td>
<td>15000 루나</td>
<td>30.00%</td>
<td>3000</td>
<td>6000</td>
<td>15%</td>
<td>500</td>
<td>-</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>15 레벨</td>
<td>16 레벨</td>
<td>20000 루나</td>
<td>30.00%</td>
<td>3500</td>
<td>7000</td>
<td>16%</td>
<td>700</td>
<td>1%</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>16 레벨</td>
<td>17 레벨</td>
<td>22500 루나</td>
<td>30.00%</td>
<td>4000</td>
<td>8000</td>
<td>17%</td>
<td>900</td>
<td>2%</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>17 레벨</td>
<td>18 레벨</td>
<td>25000 루나</td>
<td>30.00%</td>
<td>4500</td>
<td>9000</td>
<td>18%</td>
<td>1100</td>
<td>3%</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>18 레벨</td>
<td>19 레벨</td>
<td>27500 루나</td>
<td>30.00%</td>
<td>5000</td>
<td>10000</td>
<td>19%</td>
<td>1300</td>
<td>4%</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>19 레벨</td>
<td>20 레벨</td>
<td>30000 루나</td>
<td>30.00%</td>
<td>5500</td>
<td>11000</td>
<td>20%</td>
<td>1500</td>
<td>5%</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>20 레벨</td>
<td>21 레벨</td>
<td>35000 루나</td>
<td>25.00%</td>
<td>7000</td>
<td>14000</td>
<td>22%</td>
<td>2000</td>
<td>7%</td>
<td>1%</td>
<td>-</td>
</tr>
<tr>
<td>21 레벨</td>
<td>22 레벨</td>
<td>40000 루나</td>
<td>20.00%</td>
<td>8000</td>
<td>16000</td>
<td>24%</td>
<td>2500</td>
<td>9%</td>
<td>2%</td>
<td>-</td>
</tr>
<tr>
<td>22 레벨</td>
<td>23 레벨</td>
<td>45000 루나</td>
<td>15.00%</td>
<td>9000</td>
<td>18000</td>
<td>26%</td>
<td>3000</td>
<td>11%</td>
<td>3%</td>
<td>-</td>
</tr>
<tr>
<td>23 레벨</td>
<td>24 레벨</td>
<td>50000 루나</td>
<td>10.00%</td>
<td>10000</td>
<td>20000</td>
<td>28%</td>
<td>3500</td>
<td>13%</td>
<td>4%</td>
<td>-</td>
</tr>
<tr>
<td>24 레벨</td>
<td>25 레벨</td>
<td>60000 루나</td>
<td>5.00%</td>
<td>11000</td>
<td>20000</td>
<td>30%</td>
<td>4000</td>
<td>15%</td>
<td>5%</td>
<td>-</td>
</tr>
<tr>
<td>25 레벨</td>
<td>26 레벨</td>
<td>70000 루나</td>
<td>5.00%</td>
<td>13000</td>
<td>20000</td>
<td>34%</td>
<td>5000</td>
<td>18%</td>
<td>7%</td>
<td>-</td>
</tr>
<tr>
<td>26 레벨</td>
<td>27 레벨</td>
<td>80000 루나</td>
<td>4.00%</td>
<td>15000</td>
<td>20000</td>
<td>38%</td>
<td>6000</td>
<td>21%</td>
<td>9%</td>
<td>-</td>
</tr>
<tr>
<td>27 레벨</td>
<td>28 레벨</td>
<td>90000 루나</td>
<td>3.00%</td>
<td>17000</td>
<td>20000</td>
<td>42%</td>
<td>7000</td>
<td>24%</td>
<td>11%</td>
<td>-</td>
</tr>
<tr>
<td>28 레벨</td>
<td>29 레벨</td>
<td>100000 루나</td>
<td>2.00%</td>
<td>19000</td>
<td>20000</td>
<td>46%</td>
<td>8000</td>
<td>27%</td>
<td>13%</td>
<td>-</td>
</tr>
<tr>
<td>29 레벨</td>
<td>30 레벨</td>
<td>200000 루나</td>
<td>1.00%</td>
<td>20000</td>
<td>20000</td>
<td>50%</td>
<td>10000</td>
<td>30%</td>
<td>15%</td>
<td>-</td>
</tr>
<tr>
<td>-</td>
<td>31 레벨</td>
<td>-</td>
<td>-</td>
<td>22000</td>
<td>22000</td>
<td>55%</td>
<td>12000</td>
<td>35%</td>
<td>18%</td>
<td>-</td>
</tr>
<tr>
<td>-</td>
<td>32 레벨</td>
<td>-</td>
<td>-</td>
<td>24000</td>
<td>24000</td>
<td>60%</td>
<td>14000</td>
<td>40%</td>
<td>21%</td>
<td>-</td>
</tr>
<tr>
<td>-</td>
<td>33 레벨</td>
<td>-</td>
<td>-</td>
<td>26000</td>
<td>26000</td>
<td>65%</td>
<td>16000</td>
<td>45%</td>
<td>24%</td>
<td>-</td>
</tr>
<tr>
<td>-</td>
<td>34 레벨</td>
<td>-</td>
<td>-</td>
<td>29000</td>
<td>29000</td>
<td>75%</td>
<td>19000</td>
<td>52%</td>
<td>28%</td>
<td>-</td>
</tr>
<tr>
<td>-</td>
<td>35 레벨</td>
<td>-</td>
<td>-</td>
<td>32000</td>
<td>32000</td>
<td>85%</td>
<td>22000</td>
<td>59%</td>
<td>32%</td>
<td>-</td>
</tr>
<tr>
<td>-</td>
<td>36 레벨</td>
<td>-</td>
<td>-</td>
<td>35000</td>
<td>35000</td>
<td>95%</td>
<td>25000</td>
<td>66%</td>
<td>36%</td>
<td>-</td>
</tr>
<tr>
<td>-</td>
<td>37 레벨</td>
<td>-</td>
<td>-</td>
<td>40000</td>
<td>40000</td>
<td>100%</td>
<td>30000</td>
<td>76%</td>
<td>40%</td>
<td>-</td>
</tr>
<tr>
<td>-</td>
<td>38 레벨</td>
<td>-</td>
<td>-</td>
<td>45000</td>
<td>45000</td>
<td>200%</td>
<td>35000</td>
<td>86%</td>
<td>45%</td>
<td>-</td>
</tr>
<tr>
<td>-</td>
<td>39 레벨</td>
<td>-</td>
<td>-</td>
<td>50000</td>
<td>50000</td>
<td>400%</td>
<td>50000</td>
<td>100%</td>
<td>50%</td>
<td>25%</td>
</tr>
</tbody>
</table>

<ul>
<li><code>-</code> 로 표시된 칸은, 해당 레벨에서는 해당 능력치가 제공되지 않는다는 의미입니다.</li>
<li>위 표를 참고하여, 곡괭이의 레벨에 따른 성공 확률, 제련 비용, 제련 후의 곡괭이 능력치를 알 수 있습니다.
<ul>
<li>제련하기 위한 비용은 위 표를 따르나, <strong>마법에 의해 비용이 감소할 수도 있습니다.</strong></li>
<li>해당 내용은 마법 시스템<sup><a href="#enchant">[🪄]</a></sup><sup><a href="#rank_up">[🔮]</a></sup>, 채광 시스템<sup><a href="#mine">[⛏]</a></sup>에서 정의하고 있으니 마법 시스템<sup><a href="#enchant">[🪄]</a></sup><sup><a href="#rank_up">[🔮]</a></sup>, 채광 시스템<sup><a href="#mine">[⛏]</a></sup> 부분을 참고해 주세요.</li>
</ul>
</li>
<li>제련 레벨은 최대 30레벨까지 존재하며, <strong>최종 레벨</strong>은 최대 39레벨까지 존재합니다. 즉, 제련으로 올릴 수 있는 레벨은 30레벨이 최대입니다.</li>
<li>성공 여부에 따라 결과가 2가지 존재합니다.
<ul>
<li>실패할 경우, 레벨이 유지됩니다.</li>
<li>성공할 경우, 레벨이 $1$ 상승합니다.</li>
</ul>
</li>
<li>명령어
<ul>
<li><span style="color:#e74c3c"><code>smelt</code></span> : <strong>장착한</strong> 곡괭이의 제련 레벨 올리기를 시도합니다.</li>
<li>반환값이 <span style="color:#e74c3c"><code>-1</code></span>이 아닐 때, 현재 레벨에서 다음 레벨로 올라갈 확률이 $p$%라면 chance($p$)를 한 번 호출합니다.</li>
<li>반환값
<ul>
<li><span style="color:#e74c3c"><code>-1</code></span> : 제련하기 위한 루나가 부족하거나 제련 레벨이 최대 레벨에 도달한 경우 반환합니다.</li>
<li><span style="color:#e74c3c"><code>0</code></span> : 제련에 실패한 경우 반환합니다. 즉, chance($p$) 값이 False인 경우입니다.</li>
<li><span style="color:#e74c3c"><code>1</code></span> : 제련에 성공한 경우 반환합니다. 즉, chance($p$) 값이 True인 경우입니다.</li>
</ul>
</li>
</ul>
</li>
</ul>
</li>
</ul>

<p>곡괭이의 기본 능력치를 담당하는 제련 시스템<sup><a href="#smelt">[🔨]</a></sup>입니다. 제련 레벨은 높을수록 무조건 좋습니다! 아마도요?</p>

<hr>
<h1 id="enchant" style="text-align:center">🪄 <strong>제 4장. 마법 부여 시스템 </strong>🪄</h1>

<ul>
<li>
	<p>마법 부여</p>

	<table class="table table-bordered td-center th-center">
<thead>
<tr>
<th>표기 이름 →</th>
<th>달빛+ (1)</th>
<th>달빛% (2)</th>
<th>달빛의 기운 (3)</th>
<th>최소치+ (4)</th>
<th>최소치% (5)</th>
<th>최소치의 기운 (6)</th>
</tr>
</thead>
<tbody>
<tr>
<th>효과 설명 →</th>
<th>달빛 증가</th>
<th>달빛 증가</th>
<th>달빛 3배 증가</th>
<th>최소 루나 증가</th>
<th>최소 루나 증가</th>
<th>최소 루나 3배 증가</th>
</tr>
<tr>
<th>일반</th>
<td>(+) 1~100</td>
<td>-</td>
<td>-</td>
<td>(+) 1~100</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<th><span style="color:#f39c12">레어</span></th>
<td>(+) 1~300</td>
<td>(%) 10~50</td>
<td>-</td>
<td>(+) 1~400</td>
<td>(%) 10~50</td>
<td>-</td>
</tr>
<tr>
<th><span style="color:#9b59b6">에픽</span></th>
<td>(+) 1~500</td>
<td>(%) 10~100</td>
<td>-</td>
<td>(+) 1~800</td>
<td>(%) 10~100</td>
<td>-</td>
</tr>
<tr>
<th><span style="color:#3498db">유니크</span></th>
<td>(+) 500~700</td>
<td>(%) 100~150</td>
<td>(%) 200</td>
<td>(+) 800~1200</td>
<td>(%) 100~150</td>
<td>(%) 200</td>
</tr>
<tr>
<th><span style="color:#e74c3c">레전드리</span></th>
<td>(+) 700~1500</td>
<td>(%) 150~200</td>
<td>(%) 200</td>
<td>(+) 1200~2000</td>
<td>(%) 150~200</td>
<td>(%) 200</td>
</tr>
<tr>
				<td colspan="7" style="text-align:center"> </td>
</tr>
<tr>
<th>표기 이름 →</th>
<th>최대치+ (7)</th>
<th>최대치% (8)</th>
<th>최대치의 기운 (9)</th>
<th>배율+ (10)</th>
<th>배율% (11)</th>
<th>배율의 기운 (12)</th>
</tr>
<tr>
<th>효과 설명 →</th>
<th>최대 루나 증가</th>
<th>최대 루나 증가</th>
<th>최대 루나 3배 증가</th>
<th>배율 증가</th>
<th>배율 증가</th>
<th>배율 3배 증가</th>
</tr>
<tr>
<th>일반</th>
<td>(+) 2~200</td>
<td>-</td>
<td>-</td>
<td>(+) 1~5</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<th><span style="color:#f39c12">레어</span></th>
<td>(+) 200~800</td>
<td>(%) 10~50</td>
<td>-</td>
<td>(+) 5~10</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<th><span style="color:#9b59b6">에픽</span></th>
<td>(+) 800~1600</td>
<td>(%) 50~100</td>
<td>-</td>
<td>(+) 10~25</td>
<td>(%) 1~10</td>
<td>-</td>
</tr>
<tr>
<th><span style="color:#3498db">유니크</span></th>
<td>(+) 1600~2400</td>
<td>(%) 100~150</td>
<td>(%) 200</td>
<td>(+) 25~50</td>
<td>(%) 10~50</td>
<td>(%) 200</td>
</tr>
<tr>
<th><span style="color:#e74c3c">레전드리</span></th>
<td>(+) 2400~4000</td>
<td>(%) 150~200</td>
<td>(%) 200</td>
<td>(+) 50~100</td>
<td>(%) 50~100</td>
<td>(%) 200</td>
</tr>
<tr>
				<td colspan="7" style="text-align:center"> </td>
</tr>
<tr>
<th>표기 이름 →</th>
<th>드랍률 (13)</th>
<th>행운 (14)</th>
<th>강화석의 기운 (15)</th>
<th>레벨 (16)</th>
<th>할인 (17)</th>
<th>루나의 기운 (18)</th>
</tr>
<tr>
<th>효과 설명 →</th>
<th>특정 강화석 드랍률 증가</th>
<th>얻는 강화석 개수 증가</th>
<th>모든 강화석 드랍률 3배 증가</th>
<th>레벨 증가</th>
<th>할인 적용</th>
<th>최종 루나 3배 증가</th>
</tr>
<tr>
<th>일반</th>
<td>(+) 1~5 [<strong>일반 강화석</strong>만]</td>
<td>(+) 1</td>
<td>-</td>
<td>-</td>
<td>(+) -5</td>
<td>-</td>
</tr>
<tr>
<th><span style="color:#f39c12">레어</span></th>
<td>(+) 5~10 [<strong>일반 강화석</strong>만]</td>
<td>(+) 2</td>
<td>-</td>
<td>-</td>
<td>(+) -10</td>
<td>-</td>
</tr>
<tr>
<th><span style="color:#9b59b6">에픽</span></th>
<td>(+) 5~10 [<span style="color:#f39c12"><strong>레어 강화석</strong></span>만]</td>
<td>(+) 3</td>
<td>-</td>
<td>(+) 1</td>
<td>(+) -15</td>
<td>-</td>
</tr>
<tr>
<th><span style="color:#3498db">유니크</span></th>
<td>(+) 10~20 [<span style="color:#f39c12"><strong>레어 강화석</strong></span>만]</td>
<td>(+) 4</td>
<td>(%) 200</td>
<td>(+) 2</td>
<td>(+) -20</td>
<td>(%) 200</td>
</tr>
<tr>
<th><span style="color:#e74c3c">레전드리</span></th>
<td>(+) 20~25 [<span style="color:#9b59b6"><strong>에픽 강화석</strong></span>만]</td>
<td>(+) 5</td>
<td>(%) 200</td>
<td>(+) 3</td>
<td>(+) -25</td>
<td>(%) 200</td>
</tr>
</tbody>
</table>

<ul>
<li><code>-</code> 로 표시된 칸은, 해당 마법 등급에서는 해당 마법이 나오지 않는다는 의미입니다.</li>
<li><strong>마법은 곡괭이의 기본 능력치를 변경하지 않습니다. 채광 시스템<sup><a href="#mine">[⛏]</a></sup>의 계산식에서만 영향을 주는 것에 유의하세요.</strong></li>
<li>표기 이름 옆의 소괄호 안 정수는("<code><span style="background-color:#ecf0f1">달빛+ <strong><span style="color:#e74c3c">(1)</span></strong></span></code>", "<code><span style="background-color:#ecf0f1">배율% <strong><span style="color:#e74c3c">(11)</span></strong></span></code>")은 마법의 고유한 아이디입니다. 이 아이디로 어떤 종류의 마법인지 알 수 있습니다.
<ul>
<li><strong>0번 마법은 아무 능력 없음으로 정의합니다. 또한 0번 마법은 마법 부여 시에 나타나지 않습니다.</strong></li>
<li>$i$번 마법이 채광 시스템<sup><a href="#mine">[⛏]</a></sup>에서 영향을 주는 능력치 값을 $x_i$라 정의합니다.</li>
</ul>
</li>
<li>마법 등급별 세부 수치 옆의 소괄호 안 기호는("<code><span style="background-color:#ecf0f1"><strong><span style="color:#e74c3c">(+)</span></strong> 2~200</span></code>", "<code><span style="background-color:#ecf0f1"><strong><span style="color:#e74c3c">(%)</span></strong> 1~10</span></code>")은, 해당 마법이 어떻게 계산되는가를 나타내는 연산 기호입니다.
<ul>
<li>세부 수치로 결정된 값을 정수 $y$라 정의합니다.
<ul>
<li>만약 세부 수치가 <strong>범위 형태</strong>일 때 세부 수치의 최솟값을 $y_{\min}$, 최댓값을 $y_{\max}$라 하면, $y=$ randInt($y_{\min}$, $y_{\max}$)입니다.</li>
<li>만약 세부 수치가 범위 형태가 아니고 <strong>단일 수치</strong>라면, $y$는 해당 수치값입니다.</li>
</ul>
</li>
<li>연산 기호
<ul>
<li><code>+</code> : $x_i=x_i+y$</li>
<li><code>%</code> : $x_i= x_i + ( (x_i \times y) \div 100$ 의 <strong>몫</strong>$)$</li>
<li>13, 15번 마법처럼 $x_i$가 정수가 아닌 정수형 배열일 수도 있습니다. 15번의 경우는 모든 $x_i[j]$에 대해 다음과 같이 연산합니다.
<ul>
<li><code>+</code> : $x_i[j]=x_i[j]+y$</li>
<li><code>%</code> : $x_i[j]= x_i[j] + ( (x_i[j] \times y) \div 100$ 의 <strong>몫</strong>$)$</li>
</ul>
</li>
<li>13번의 경우는 15번과 비슷하지만, 특정 $j$에 대해서만 연산합니다.
<ul>
<li>곡괭이 마법 등급이 <strong>일반</strong>, <span style="color:#f39c12"><strong>레어</strong></span> 등급인 경우 $j=0$인 경우에 대해서만 $x_i[j]$를 계산합니다.</li>
<li>곡괭이 마법 등급이 <span style="color:#9b59b6"><strong>에픽</strong></span>, <span style="color:#3498db"><strong>유니크</strong></span> 등급인 경우 $j=1$인 경우에 대해서만 $x_i[j]$를 계산합니다.</li>
<li>곡괭이 마법 등급이 <span style="color:#e74c3c"><strong>레전드리</strong></span> 등급인 경우 $j=2$인 경우에 대해서만 $x_i[j]$를 계산합니다.</li>
</ul>
</li>
</ul>
</li>
</ul>
</li>
<li>마법 부여 방식은 다음과 같습니다.
<ul>
<li><strong>장착한</strong> 곡괭이의 마법 등급에서 나올 수 있는 마법 아이디를 오름차순 상태로 정렬한 상태의 배열을 $\text{magic}$이라 정의합니다.</li>
<li>다음 과정을 0번, 1번, 2번 마법 슬롯 순서대로 진행합니다.
<ul>
<li>choice($\text{magic}$)에서 나온 값을 해당 마법 슬롯의 마법 아이디로 합니다.
<ul>
<li>마법 부여가 이루어지면 기존 마법 슬롯에 있던 마법은 사라집니다.</li>
<li><strong>즉, 마법 부여를 통해 기존 마법을 새 마법으로 덮어쓰게 되며 되돌릴 수 없으니 주의해 주세요.</strong></li>
</ul>
</li>
<li>해당 마법 아이디의 세부 수치가 <strong>범위 형태</strong>일 때 위에서 언급한 $y=$ randInt($y_{\min}$, $y_{\max}$)를 시행합니다.</li>
</ul>
</li>
</ul>
</li>
<li>마법 아이디에 대응하는 곡괭이 능력치 종류는 다음과 같습니다.
<ul>
<li>0번 : 없음</li>
<li>1, 2, 3번 : 달빛</li>
<li>4, 5, 6번 : 최소 루나</li>
<li>7, 8, 9번 : 최대 루나</li>
<li>10, 11, 12번 : 배율</li>
<li>13, 15번 : 강화석 드랍률</li>
<li>14번 : 행운</li>
<li>16번 : 레벨</li>
<li>17번 : 할인</li>
<li>18번 : 최종 루나
<ul>
<li>최종 루나는 채광 시스템<sup><a href="#mine">[⛏]</a></sup>에서 정의하고 있으니 채광 시스템<sup><a href="#mine">[⛏]</a></sup> 부분을 참고해 주세요.</li>
</ul>
</li>
</ul>
</li>
<li><strong>장착한</strong> 곡괭이의 마법 등급에 따라 마법 부여 비용이 다릅니다.
<ul>
<li><strong>일반</strong> : 1000 루나</li>
<li><strong><span style="color:#f39c12">레어</span></strong> : 3000 루나</li>
<li><strong><span style="color:#9b59b6">에픽</span></strong> : 8000 루나</li>
<li><strong><span style="color:#3498db">유니크</span></strong> : 15000 루나</li>
<li><span style="color:#e74c3c"><strong>레전드리</strong></span> : 50000 루나</li>
</ul>
</li>
<li>명령어
<ul>
<li><span style="color:#e74c3c"><code>enchant</code></span> : <strong>장착한</strong> 곡괭이에 마법 3개를 부여합니다.</li>
<li>반환값
<ul>
<li><span style="color:#e74c3c"><code>-1</code></span> : 마법 부여를 하기 위한 루나가 부족한 경우 반환합니다.</li>
<li><span style="color:#e74c3c"><code>1</code></span> : 마법 부여에 성공한 경우 다음과 같은 형태로 반환합니다.
				<div style="background:#eee;border:1px solid #ccc;padding:5px 10px"><code>1</code> <code><magic slot 0 id></code> : 0번 마법 슬롯의 마법 아이디 <code><magic slot 0 data></code> : 0번 마법 슬롯의 $y$값 <code><magic slot 1 id></code> : 1번 마법 슬롯의 마법 아이디 <code><magic slot 1 data></code> : 1번 마법 슬롯의 $y$값 <code><magic slot 2 id></code> : 2번 마법 슬롯의 마법 아이디 <code><magic slot 2 data></code> : 2번 마법 슬롯의 $y$값</div>

<ul>
<li>
					<p>$y$값은 항상 $-25$ 이상 $4\,000$ 이하의 정수로 주어집니다.</p>
</li>
</ul>
</li>
</ul>
</li>
</ul>
</li>
</ul>
</li>
</ul>

<p>마법 시스템<sup><a href="#enchant">[🪄]</a></sup><sup><a href="#rank_up">[🔮]</a></sup>을 통해 곡괭이를 더 강화할 수 있습니다! 제련 시스템<sup><a href="#smelt">[🔨]</a></sup>과 마법 시스템<sup><a href="#enchant">[🪄]</a></sup><sup><a href="#rank_up">[🔮]</a></sup>은 서로 영향을 줄 수 있으니 한번 마법 종류를 꼼꼼하게 읽어보는 것을 추천합니다.</p>

<hr>
<h1 id="rank_up" style="text-align:center"><strong>💎 제 5장. 합성 & 마법 승급 시스템 </strong>🔮</h1>

<ul>
<li>합성
<ul>
<li>$r-1$번 등급 강화석 2개와 루나를 소모하여 $r$번 등급 강화석 1개를 제작합니다. 이를 $r$번 등급 강화석 합성이라고 정의합니다.</li>
<li>합성하고자 하는 강화석의 등급에 따라 합성 비용이 다릅니다.
<ul>
<li><strong>일반</strong> : 합성을 통해 제작할 수 없음.</li>
<li><span style="color:#f39c12"><strong>레어</strong></span> : 1250 루나</li>
<li><span style="color:#9b59b6"><strong>에픽</strong></span> : 2500 루나</li>
<li><span style="color:#3498db"><strong>유니크</strong></span> : 5000 루나</li>
<li><span style="color:#e74c3c"><strong>레전드리</strong></span> : 10000 루나</li>
</ul>
</li>
<li>명령어
		<ul style="list-style-type:square">
<li><span style="color:#e74c3c"><code>craft</code></span> <span style="color:#e74c3c">$r$</span> : $r$번 등급 강화석을 합성합니다.</li>
<li>$r$은 $1$ 이상 $4$ 이하의 정수이어야 합니다.</li>
<li>각 정수에 대응하는 등급은 다음과 같습니다.
<ul>
<li>$1$은 <span style="color:#f39c12"><strong>레어 강화석</strong></span>입니다.</li>
<li>$2$는 <span style="color:#9b59b6"><strong>에픽 강화석</strong></span>입니다.</li>
<li>$3$은 <span style="color:#3498db"><strong>유니크 강화석</strong></span>입니다.</li>
<li>$4$는 <span style="color:#e74c3c"><strong>레전드리 강화석</strong></span>입니다.</li>
</ul>
</li>
<li>반환값
<ul>
<li><span style="color:#e74c3c"><code>-1</code></span> : 합성을 하기 위한 이전 등급의 강화석 또는 루나가 부족한 경우 반환합니다.</li>
<li><span style="color:#e74c3c"><code>1</code></span> : 합성에 성공한 경우 반환합니다.</li>
</ul>
</li>
</ul>
</li>
</ul>
</li>
<li>마법 승급
<ul>
<li>강화석을 소모해 <strong>장착한</strong> 곡괭이의 마법 등급을 한 단계 올립니다.</li>
<li>목표 등급 강화석 1개를 소모합니다.
<ul>
<li>예를 들어 <strong>일반 등급 곡괭이</strong>를 <span style="color:#f39c12"><strong>레어 등급 곡괭이</strong></span>로 승급시키기 위해서 <span style="color:#f39c12"><strong>레어 강화석</strong></span> 1개를 소모합니다.</li>
</ul>
</li>
<li>목표로 하는 마법 등급마다 성공 확률이 존재합니다.
<ul>
<li><strong>일반</strong> : 마법 승급을 통해 도달할 수 없음.</li>
<li><span style="color:#f39c12"><strong>레어</strong></span> : 16%</li>
<li><span style="color:#9b59b6"><strong>에픽</strong></span> : 9%</li>
<li><span style="color:#3498db"><strong>유니크</strong></span> : 4%</li>
<li><span style="color:#e74c3c"><strong>레전드리</strong></span> : 1%</li>
</ul>
</li>
<li>성공 여부에 따라 결과가 2가지 존재합니다.
<ul>
<li>성공할 경우, 마법 등급이 한 단계 상승합니다. <strong>그리고 0번, 1번, 2번 마법 슬롯이 0번 마법으로 대체됩니다.</strong></li>
<li>실패할 경우, 축복 강화석을 얻습니다.
<ul>
<li>축복 강화석은 축복 시스템<sup><a href="#bless">[🙏]</a></sup>에서 정의하고 있으니 축복 시스템<sup><a href="#bless">[🙏]</a></sup> 부분을 참고해 주세요.</li>
</ul>
</li>
</ul>
</li>
<li>명령어
<ul>
<li><span style="color:#e74c3c"><code>rank_up</code></span> : <strong>장착한</strong> 곡괭이의 마법 승급을 시도합니다.</li>
<li>반환값이 <span style="color:#e74c3c"><code>-1</code></span>이 아닐 때 현재 마법 등급에서 승급할 확률이 $p$%라면 chance($p$)를 한 번 호출합니다.</li>
<li>반환값
<ul>
<li><span style="color:#e74c3c"><code>-1</code></span> : 목표 등급 강화석이 부족하거나, <strong>장착한</strong> 곡괭이의 마법 등급이 <span style="color:#e74c3c"><strong>레전드리</strong></span>일 경우 반환합니다.</li>
<li><span style="color:#e74c3c"><code>0</code></span> : 마법 승급에 실패한 경우 반환합니다. 즉, chance($p$) 값이 False인 경우입니다.</li>
<li><span style="color:#e74c3c"><code>1</code></span> : 마법 승급에 성공한 경우 반환합니다. 즉, chance($p$) 값이 True인 경우입니다.</li>
</ul>
</li>
</ul>
</li>
</ul>
</li>
</ul>

<p>합성 시스템<sup><a href="#rank_up">[💎]</a></sup>과 마법 승급 시스템<sup><a href="#rank_up">[🔮]</a></sup>은 마법 부여 시스템<sup><a href="#enchant">[🪄]</a></sup>을 더 강력하게 만들어주는 시스템입니다. 강력한 마법을 얻고 싶다면 해당 시스템을 숙지해 두는 게 좋겠네요!</p>

<hr>
<h1 id="bless" style="text-align:center"><strong>🙏 제 6장. 축복 시스템 🙏</strong></h1>

<ul>
<li>
	<p>축복</p>

	<table class="table table-bordered td-center th-center">
<thead>
<tr>
<th>레벨</th>
<th>최소 루나 증가</th>
<th>최대 루나 증가</th>
<th>달빛 증가</th>
<th>일반 강화석 드랍률 증가</th>
<th>배율 증가</th>
</tr>
</thead>
<tbody>
<tr>
<td>0 레벨</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
<td>-</td>
</tr>
<tr>
<td>1 레벨</td>
<td>(+) 100</td>
<td>(+) 200</td>
<td>(+) 100</td>
<td>(+) 1%</td>
<td>-</td>
</tr>
<tr>
<td>2 레벨</td>
<td>(+) 200</td>
<td>(+) 400</td>
<td>(+) 200</td>
<td>(+) 2%</td>
<td>-</td>
</tr>
<tr>
<td>3 레벨</td>
<td>(+) 300</td>
<td>(+) 600</td>
<td>(+) 300</td>
<td>(+) 3%</td>
<td>-</td>
</tr>
<tr>
<td>4 레벨</td>
<td>(+) 400</td>
<td>(+) 800</td>
<td>(+) 400</td>
<td>(+) 4%</td>
<td>-</td>
</tr>
<tr>
<td>5 레벨</td>
<td>(+) 500</td>
<td>(+) 1000</td>
<td>(+) 500</td>
<td>(+) 5%</td>
<td>-</td>
</tr>
<tr>
<td>6 레벨</td>
<td>(+) 600</td>
<td>(+) 1200</td>
<td>(+) 600</td>
<td>(+) 6%</td>
<td>-</td>
</tr>
<tr>
<td>7 레벨</td>
<td>(+) 700</td>
<td>(+) 1400</td>
<td>(+) 700</td>
<td>(+) 7%</td>
<td>-</td>
</tr>
<tr>
<td>8 레벨</td>
<td>(+) 800</td>
<td>(+) 1600</td>
<td>(+) 800</td>
<td>(+) 8%</td>
<td>-</td>
</tr>
<tr>
<td>9 레벨</td>
<td>(+) 900</td>
<td>(+) 1800</td>
<td>(+) 900</td>
<td>(+) 9%</td>
<td>-</td>
</tr>
<tr>
<td>10 레벨</td>
<td>(+) 1000</td>
<td>(+) 2000</td>
<td>(+) 1000</td>
<td>(+) 10%</td>
<td>-</td>
</tr>
<tr>
<td>11 레벨</td>
<td>(+) 1100</td>
<td>(+) 2200</td>
<td>(+) 1100</td>
<td>(+) 11%</td>
<td>-</td>
</tr>
<tr>
<td>12 레벨</td>
<td>(+) 1200</td>
<td>(+) 2400</td>
<td>(+) 1200</td>
<td>(+) 12%</td>
<td>-</td>
</tr>
<tr>
<td>13 레벨</td>
<td>(+) 1300</td>
<td>(+) 2600</td>
<td>(+) 1300</td>
<td>(+) 13%</td>
<td>-</td>
</tr>
<tr>
<td>14 레벨</td>
<td>(+) 1400</td>
<td>(+) 2800</td>
<td>(+) 1400</td>
<td>(+) 14%</td>
<td>-</td>
</tr>
<tr>
<td>15 레벨</td>
<td>(+) 1500</td>
<td>(+) 3000</td>
<td>(+) 1500</td>
<td>(+) 15%</td>
<td>-</td>
</tr>
<tr>
<td>16 레벨</td>
<td>(+) 1600</td>
<td>(+) 3200</td>
<td>(+) 1600</td>
<td>(+) 16%</td>
<td>-</td>
</tr>
<tr>
<td>17 레벨</td>
<td>(+) 1700</td>
<td>(+) 3400</td>
<td>(+) 1700</td>
<td>(+) 17%</td>
<td>-</td>
</tr>
<tr>
<td>18 레벨</td>
<td>(+) 1800</td>
<td>(+) 3600</td>
<td>(+) 1800</td>
<td>(+) 18%</td>
<td>-</td>
</tr>
<tr>
<td>19 레벨</td>
<td>(+) 1900</td>
<td>(+) 3800</td>
<td>(+) 1900</td>
<td>(+) 19%</td>
<td>-</td>
</tr>
<tr>
<td>20 레벨</td>
<td>(+) 2000</td>
<td>(+) 4000</td>
<td>(+) 2000</td>
<td>(+) 20%</td>
<td>-</td>
</tr>
<tr>
<td>$b$ 레벨</td>
<td>(+) 2000</td>
<td>(+) 4000</td>
<td>(+) 2000</td>
<td>(+) 20%</td>
<td>(+) ($b$ - 20)%</td>
</tr>
</tbody>
</table>

<ul>
<li><code>-</code> 로 표시된 칸은, 해당 축복 레벨에서는 해당 능력치가 제공되지 않는다는 의미입니다.</li>
<li>위 표를 참고하여, 축복 레벨에 의해 얻는 능력치를 알 수 있습니다.
<ul>
<li><strong>축복으로 얻은 능력치는 채광 시스템<sup><a href="#mine">[⛏]</a></sup>의 계산식에서만 영향을 줍니다. 축복은 곡괭이의 능력치가 아님에 유의하세요.</strong></li>
<li>위 표에서 $b$는 $21$ 이상 $\text{INF}$ 이하의 정수입니다.</li>
</ul>
</li>
<li>축복 강화석을 일정량 보유 시, 즉시 축복 강화석이 일정량 소모되고 축복 레벨이 $1$ 상승합니다.
<ul>
<li>현재 축복 레벨이 $n$일 때, 레벨 상승을 위해 $n+1$개의 축복 강화석이 필요합니다. ($n$은 $0$ 이상 $\text{INF}$ 미만의 정수)</li>
</ul>
</li>
<li><strong>마법 승급에 실패할 때, 목표로 하는 곡괭이의 마법 등급에 따라 일정량의 축복 강화석을 얻습니다.</strong>
<ul>
<li><strong>일반</strong> : 마법 승급을 통해 도달할 수 없음.</li>
<li><span style="color:#f39c12"><strong>레어</strong></span> : 1개</li>
<li><span style="color:#9b59b6"><strong>에픽</strong></span> : 2개</li>
<li><span style="color:#3498db"><strong>유니크</strong></span> : 4개</li>
<li><span style="color:#e74c3c"><strong>레전드리</strong></span> : 8개</li>
</ul>
</li>
<li>명령어
<ul>
<li><strong>축복 시스템<sup><a href="#bless">[🙏]</a></sup>을 열람하는 명령어는 제공하지 않습니다.</strong></li>
</ul>
</li>
</ul>
</li>
</ul>

<p>축복은 곡괭이의 연이은 마법 승급 실패의 고통을 덜어주는 시스템입니다. 정말 갓겜이죠?</p>

<hr>
<h1 id="mine" style="text-align:center"><strong><span style="color:#9b59b6">⛏ </span>제 7장. 채광 시스템 <span style="color:#9b59b6">⛏</span></strong></h1>

<ul>
<li>채광
<ul>
<li>축복 레벨 그리고 <strong>장착한</strong> 곡괭이의 제련 레벨과 마법 상태에 따라 얻게 되는 루나와 강화석의 양이 달라집니다.</li>
<li>채광 프로세스 : 해당 과정은 작성된 순서대로 이루어지며, <strong>rand() 호출 순서에 따라 결과가 달라질 수 있음에 유의하세요.</strong>
<ul>
<li>얻을 재화 계산에 필요한 값들을 구합니다.
<ul>
<li>최종 레벨을 계산합니다.
<ul>
<li><strong>장착한</strong> 곡괭이의 0, 1, 2번 마법 슬롯 중 16번 마법이 존재한다면 해당 수치에 맞게 레벨을 상승시킵니다.</li>
<li>즉, 레벨 마법을 적용합니다.</li>
</ul>
</li>
<li>제련 능력치를 불러옵니다.
<ul>
<li><strong>장착한</strong> 곡괭이의 최종 레벨에 알맞은 능력치를 불러옵니다.</li>
<li>이를 기본 최소 루나, 기본 최대 루나, 기본 달빛, 기본 강화석 드랍률이라 정의합니다.</li>
</ul>
</li>
<li>축복 능력치를 불러옵니다.
<ul>
<li>현재 축복 레벨에 맞는 능력치를 불러옵니다.</li>
<li>이를 축복 최소 루나, 축복 최대 루나, 축복 달빛, 축복 강화석 드랍률, 축복 배율이라 정의합니다.</li>
</ul>
</li>
<li>최종 배율은 다음과 같이 계산됩니다.
<ul>
<li>최종 배율 = (100 + 축복 배율) ← 마법 적용</li>
<li>해당 수치에 영향을 주는 마법은 10, 11, 12번 마법입니다.</li>
</ul>
</li>
<li>최종 달빛은 다음과 같이 계산됩니다.
<ul>
<li>최종 달빛 = (기본 달빛 + 축복 달빛) ← 마법 적용</li>
<li>해당 수치에 영향을 주는 마법은 1, 2, 3번 마법입니다.</li>
</ul>
</li>
<li>최종 최소 루나는 다음과 같이 계산됩니다.
<ul>
<li>최종 최소 루나 = ((((기본 최소 루나 + 축복 최소 루나) ← 마법 적용) + 최종 달빛) $\times$ 최종 배율) $\div$ 100 의 <strong>몫</strong></li>
<li>해당 수치에 영향을 주는 마법은 4, 5, 6번 마법입니다.</li>
</ul>
</li>
<li>최종 최대 루나는 다음과 같이 계산됩니다.
<ul>
<li>최종 최대 루나 = ((((기본 최대 루나 + 축복 최대 루나) ← 마법 적용) + 최종 달빛) $\times$ 최종 배율) $\div$ 100 의 <strong>몫</strong></li>
<li>해당 수치에 영향을 주는 마법은 7, 8, 9번 마법입니다.</li>
</ul>
</li>
<li>최종 강화석 드랍률은 다음과 같이 계산됩니다.
<ul>
<li>최종 강화석 드랍률 = (기본 강화석 드랍률 + 축복 강화석 드랍률) ← 마법 적용</li>
<li>강화석 등급별로 독립적으로 계산됩니다.</li>
<li>해당 수치에 영향을 주는 마법은 13, 15번 마법입니다.</li>
</ul>
</li>
<li>최종 행운은 다음과 같이 계산됩니다.
<ul>
<li>최종 행운 = (1) ← 마법 적용</li>
<li>해당 수치에 영향을 주는 마법은 14번 마법입니다.</li>
</ul>
</li>
<li>최종 할인은 다음과 같이 계산됩니다.
<ul>
<li>최종 할인 = (100) ← 마법 적용</li>
<li>해당 수치에 영향을 주는 마법은 17번 마법입니다.</li>
<li>이 수치는 채광 시스템<sup><a href="#mine">[⛏]</a></sup>에서 사용되지 않고, 제련 시스템<sup><a href="#smelt">[🔨]</a></sup>에서 사용됩니다.</li>
<li>제련 시 ‘(본래 제련 시 드는 비용) $\times$ (최종 할인) $\div$ 100 의 <strong>몫</strong>’이 최종 제련 비용이 됩니다.</li>
</ul>
</li>
</ul>
</li>
<li>최종 루나는 다음과 같이 계산됩니다.
<ul>
<li>randInt(최종 최소 루나, $\max$(최종 최소 루나, 최종 최대 루나))의 값</li>
</ul>
</li>
<li>다음 값이 채광을 통해 획득하는 루나의 수 입니다.
<ul>
<li>획득하는 루나 = (최종 루나) ← 마법 적용</li>
<li>해당 수치에 영향을 주는 마법은 18번 마법입니다.</li>
</ul>
</li>
<li>다음 값이 획득하는 강화석의 개수입니다.
<ul>
<li><strong>일반</strong>, <span style="color:#f39c12"><strong>레어</strong></span>, <span style="color:#9b59b6"><strong>에픽</strong></span>, <span style="color:#3498db"><strong>유니크</strong></span>, <span style="color:#e74c3c"><strong>레전드리</strong></span> 순서로 진행됩니다.
<ul>
<li>해당 등급 최종 강화석 드랍률이 100(%) 이상이라면 100(%) 당 강화석 1개를 확정적으로 지급합니다. 이를 <strong>확정적으로 얻는 해당 등급의 강화석</strong>이라 정의합니다.</li>
<li>강화석 드랍률을 100으로 나눈 나머지를 $d_i$로 정의합니다. 이를 <strong>확률적으로 얻는 해당 등급의 강화석</strong>이라 정의합니다.</li>
<li>chance($d_i$)가 True면 강화석을 1개 얻습니다.
<ul>
<li>$d_i$가 $0$이어도 호출됨을 유의하세요.
<ul>
</ul>
</li>
</ul>
</li>
<li>획득하는 해당 등급의 강화석 개수 = ((확정적으로 얻는 해당 등급의 강화석의 개수) $+$ (확률적으로 얻는 해당 등급의 강화석의 개수)) $\times$ (최종 행운)</li>
</ul>
</li>
</ul>
</li>
</ul>
</li>
<li>명령어
<ul>
<li><span style="color:#e74c3c"><code>mine</code></span> : <strong>장착한</strong> 곡괭이로 채광합니다.</li>
<li>반환값 :
<ul>
<li><span style="color:#e74c3c"><code>1</code></span> : 채광에 성공한 경우, 다음 한 줄에 길이가 $6$인 정수형 배열을 추가로 반환합니다.
<ul>
<li>배열은 채광으로 획득한 [루나, <strong>일반 강화석의 개수</strong>, <span style="color:#f39c12"><strong>레어 강화석의 개수</strong></span>, <span style="color:#9b59b6"><strong>에픽 강화석의 개수</strong></span>, <span style="color:#3498db"><strong>유니크 강화석의 개수</strong></span>, <span style="color:#e74c3c"><strong>레전드리 강화석의 개수</strong></span>]로 구성됩니다.</li>
<li>각 원소는 $0$ 이상 $\text{INF}$ 이하의 정수입니다.</li>
<li>각 원소는 공백으로 구분되어 주어집니다.</li>
</ul>
</li>
</ul>
</li>
</ul>
</li>
</ul>
</li>
</ul>

<p>강화한 곡괭이로 채광하는 과정입니다. 꽤 복잡하지만 제련 레벨, 축복 레벨, 마법 등급이 높을수록 더 많은 재화를 얻는다고 보면 됩니다!</p>

<hr>
<h1 id="achievement" style="text-align:center"><strong>🏆 최종장. 업적 시스템 🏆</strong></h1>

<ul>
<li>
	<p>업적</p>

	<table class="table table-bordered td-center th-center">
<thead>
<tr>
<th>업적 번호</th>
<th>업적 이름</th>
<th>달성 조건</th>
</tr>
</thead>
<tbody>
<tr>
<td>1</td>
<td>제로부터 시작하는 <strong>Lunatic Mine</strong></td>
<td>정확히 $0$ 루나 보유</td>
</tr>
<tr>
<td>2</td>
<td>끝이야?</td>
<td>제련 레벨이 $30$ 레벨인 곡괭이 보유</td>
</tr>
<tr>
<td>3</td>
<td>레전설</td>
<td><span style="color:#e74c3c"><strong>레전드리 등급 곡괭이</strong></span> 보유</td>
</tr>
<tr>
<td>4</td>
<td>양자 곡괭이</td>
<td>(최종 최대 루나 - 최종 최소 루나) 값이 $100\,000$ 이상인 곡괭이 보유</td>
</tr>
<tr>
<td>5</td>
<td>역전 곡괭이</td>
<td>(최종 최대 루나 - 최종 최소 루나) 값이 $0$ 미만인 곡괭이 보유</td>
</tr>
<tr>
<td>6</td>
<td>오버플로우</td>
<td>아무 등급의 강화석 드랍률이 $100%$ 초과인 곡괭이 보유</td>
</tr>
<tr>
<td>7</td>
<td>전설의 광부의 전설</td>
<td><span style="color:#e74c3c"><strong>레전드리 등급 곡괭이</strong></span> $3$개 보유</td>
</tr>
<tr>
<td>8</td>
<td>만수루</td>
<td>$100\,000\,000$ 루나 이상 보유</td>
</tr>
<tr>
<td>9</td>
<td>광(狂)부</td>
<td>모든 곡괭이 최종 레벨 합산 $100$ 이상 달성</td>
</tr>
<tr>
<td>10</td>
<td>진짜로 끝이야.</td>
<td>최종 레벨이 $39$ 레벨인 곡괭이 보유</td>
</tr>
</tbody>
</table>

<ul>
<li><strong>Lunatic Mine</strong> 게임에는 총 10개의 도전과제가 존재합니다.</li>
<li>1개의 행동을 완료할 때마다 도전과제 달성 여부를 확인합니다.</li>
<li>각각의 도전과제는 한번 달성하면, 이후에 조건을 만족시키지 못하더라도 달성한 것으로 유지됩니다.</li>
<li>명령어
<ul>
<li><strong>업적 시스템<sup><a href="#achievement">[🏆]</a></sup>을 열람하는 명령어는 제공하지 않습니다.</strong></li>
</ul>
</li>
</ul>
</li>
<li>게임 종료
<ul>
<li>명령어
<ul>
<li><span style="color:#e74c3c"><code>exit</code></span> : <strong>Lunatic Mine</strong> 게임을 종료합니다. 😢</li>
</ul>
</li>
</ul>
</li>
<li>채점
<ul>
<li>여러분은 이 게임을 플레이해서 엔딩을 보셔야 합니다!</li>
<li>엔딩의 조건은 다음과 같습니다.
<ul>
<li>채점 데이터 273개에 대해 각각 해당 조건을 만족시켜야 합니다.
<ul>
<li>게임 종료를 제외한 명령어 사용 횟수가 $20\,000$번 이하이어야 합니다.</li>
<li><strong>마지막 명령어는 게임 종료 명령어이어야 합니다.</strong></li>
<li>게임 종료 명령어를 입력했을 때, 10개의 업적이 모두 달성되어 있어야 합니다.</li>
</ul>
</li>
<li>각 채점 데이터에서 시드가 주어집니다. 273개의 시드는 아래의 제한 설명란을 참고해 주세요.</li>
</ul>
</li>
<li>엔딩을 보신다면 이 문제에서 <span class="result-ac-text"> </span>를 받을 수 있습니다. 한번 광질을 하러 가볼까요?</li>
</ul>
</li>
</ul>

<hr>
<h1 style="text-align:center"><strong>📝 세 줄 요약 📝</strong></h1>

<ul>
<li>이 문제는 해당 게임을 플레이하는 프로그램을 작성하는 문제입니다.</li>
<li>장착 명령어로 곡괭이를 장착하고, 채광 명령어로 재화를 얻고, 제련, 마법 부여, 마법 승급, 합성 명령어로 곡괭이를 강화합니다.</li>
<li>입력으로는 시드가 주어지며, 주어진 모든 273개의 데이터에 대해 10개의 업적을 모두 달성하면 <span class="result-ac-text"> </span>를 받습니다.</li>
</ul>

### 입력 

 <p>첫 번째 줄에 시드 $S_0$가 주어집니다. $(0 \le S_0 \lt 2^{32})$</p>

### 출력 

 <p>다음을 표준 출력 스트림(stdout)으로 한 줄에 출력하여 $20\,000$번까지 명령어를 사용할 수 있습니다.</p>

<ul>
<li><span style="color:#e74c3c;"><code>mine</code></span> : <strong>장착한</strong> 곡괭이로 채광합니다.</li>
<li><span style="color:#e74c3c;"><code>equip</code> $x$</span> : $x$번 곡괭이를 장착합니다. $(0 \le x \le 2)$</li>
<li><span style="color:#e74c3c;"><code>smelt</code></span> : <strong>장착한</strong> 곡괭이의 제련 레벨 올리기를 시도합니다.</li>
<li><span style="color:#e74c3c;"><code>craft</code> $r$</span> : $r$번 등급 강화석을 합성합니다. $(1 \le r \le 4)$</li>
<li><span style="color:#e74c3c;"><code>rank_up</code></span> : <strong>장착한</strong> 곡괭이의 마법 승급을 시도합니다.</li>
<li><span style="color:#e74c3c;"><code>enchant</code></span> : <strong>장착한</strong> 곡괭이에 마법 3개를 부여합니다.</li>
</ul>

<p>명령어를 출력한 뒤, 여러분은 인터랙터에게서 다음과 같은 결과를 알 수 있습니다.</p>

<ul>
<li><span style="color:#e74c3c;"><code>mine</code></span> : 첫 번째 줄에 명령어 결과가 출력됩니다. 채광에 성공한 경우에 한해서 추가로 1개 줄에 걸쳐 채광 결과가 출력됩니다.

<ul>
<li><span style="color:#e74c3c;"><code>1</code></span> : 채광에 성공한 경우

<ul>
<li>다음 1개의 줄이 추가로 출력됩니다.
<ul>
<li><span style="color:#e74c3c;"><code><luna> <normal_upgrade_stone> <rare_upgrade_stone> <epic_upgrade_stone> <unique_upgrade_stone> <legendary_upgrade_stone></code></span></li>
<li>위의 모든 값은 $0$ 이상 $\text{INF}$ 이하의 정수로 주어집니다.</li>
</ul>
</li>
</ul>
</li>
</ul>
</li>
<li><span style="color:#e74c3c;"><code>equip</code> $x$</span> : 첫 번째 줄에 명령어 결과가 출력됩니다.
<ul>
<li><span style="color:#e74c3c;"><code>1</code></span> : 장착에 성공한 경우</li>
</ul>
</li>
<li><span style="color:#e74c3c;"><code>smelt</code></span> : 첫 번째 줄에 명령어 결과가 출력됩니다.
<ul>
<li><span style="color:#e74c3c;"><code>-1</code></span> : 제련하기 위한 루나가 부족하거나 제련 레벨이 최대 레벨에 도달한 경우</li>
<li><span style="color:#e74c3c;"><code>0</code></span> : 제련에 실패한 경우</li>
<li><span style="color:#e74c3c;"><code>1</code></span> : 제련에 성공한 경우</li>
</ul>
</li>
<li><span style="color:#e74c3c;"><code>craft</code> $r$</span> : 첫 번째 줄에 명령어 결과가 출력됩니다.
<ul>
<li><span style="color:#e74c3c;"><code>-1</code></span> : 합성을 하기 위한 이전 등급의 강화석 또는 루나가 부족한 경우</li>
<li><span style="color:#e74c3c;"><code>1</code></span> : 합성에 성공한 경우</li>
</ul>
</li>
<li><span style="color:#e74c3c;"><code>rank_up</code></span> : 첫 번째 줄에 명령어 결과가 출력됩니다.
<ul>
<li><span style="color:#e74c3c;"><code>-1</code></span> : 목표 등급 강화석이 부족하거나, <strong>장착한</strong> 곡괭이의 마법 등급이 <span style="color:#e74c3c;"><strong>레전드리</strong></span>일 경우</li>
<li><span style="color:#e74c3c;"><code>0</code></span> : 승급에 실패한 경우</li>
<li><span style="color:#e74c3c;"><code>1</code></span> : 승급에 성공한 경우</li>
</ul>
</li>
<li><span style="color:#e74c3c;"><code>enchant</code></span> : 첫 번째 줄에 명령어 결과가 출력됩니다. 마법 부여에 성공한 경우에 한해서 추가로 6개 줄에 걸쳐 마법 부여의 결과가 출력됩니다.
<ul>
<li><span style="color:#e74c3c;"><code>-1</code></span> : 마법 부여를 하기 위한 루나가 부족한 경우</li>
<li><span style="color:#e74c3c;"><code>1</code></span> : 마법 부여에 성공한 경우
<ul>
<li>다음 6개의 줄이 추가로 출력됩니다.
<ul>
<li><span style="color:#e74c3c;"><code><magic slot 0 id></code></span></li>
<li><span style="color:#e74c3c;"><code><magic slot 0 data></code></span></li>
<li><span style="color:#e74c3c;"><code><magic slot 1 id></code></span></li>
<li><span style="color:#e74c3c;"><code><magic slot 1 data></code></span></li>
<li><span style="color:#e74c3c;"><code><magic slot 2 id></code></span></li>
<li><span style="color:#e74c3c;"><code><magic slot 2 data></code></span></li>
</ul>
</li>
</ul>
</li>
<li><code><span style="color:#e74c3c;"><magic slot 0 id></span></code>, <code><span style="color:#e74c3c;"><magic slot 1 id></span></code>, <code><span style="color:#e74c3c;"><magic slot 2 id></span></code>는 $1$ 이상 $18$ 이하의 정수로 주어집니다.</li>
<li><code><span style="color:#e74c3c;"><magic slot 0 data></span></code>, <code><span style="color:#e74c3c;"><magic slot 1 data></span></code>, <code><span style="color:#e74c3c;"><magic slot 2 data></span></code>는 $-25$ 이상 $4\,000$ 이하의 정수로 주어집니다.</li>
</ul>
</li>
</ul>

<p>만약 게임을 종료하고 싶다면 다음과 같이 출력합니다.</p>

<ul>
<li><span style="color:#e74c3c;"><code>exit</code></span>를 한 줄에 출력합니다.</li>
<li>출력을 마친 직후 프로그램을 종료합니다.</li>
</ul>

<p>다음과 같은 경우에는 <span class="result-wa-text"> </span>를 받습니다.</p>

<ul>
<li>게임 종료를 제외한 명령어 사용 횟수가 $20\,000$번을 초과한 경우</li>
<li>다음 예시와 같이 명령어 사용 중에 유효한 범위 내의 정수를 출력하지 않는 경우
<ul>
<li><span style="color:#e74c3c;"><code>equip</code> $x$</span> 명령어에서 $x = 3$인 경우</li>
<li><span style="color:#e74c3c;"><code>craft</code> $r$</span> 명령어에서 $r = 0$인 경우</li>
</ul>
</li>
</ul>

<p>다음과 같은 경우에는 예상하지 못한 채점 결과를 받을 수 있습니다.</p>

<ul>
<li>어떤 출력 직후 출력 버퍼를 비우지 않은 경우</li>
<li>출력 형식을 어기는 경우</li>
<li>정답 출력을 마친 직후 프로그램을 종료하지 않은 경우</li>
</ul>

