## Attention mechanism in NLP. From seq2seq + attention to BERT

### 출처

: [https://lovit.github.io/machine%20learning/2019/03/17/attention_in_nlp/](https://lovit.github.io/machine learning/2019/03/17/attention_in_nlp/)

: 위의 사이트의 내용을 정리+추가

----------------------------

- Attention mechanism도 단어 임베딩만큼 중요한 발전

- Seq2Seq의 context vector를 개선하기 위해 attention mechanism이 제안 됨

  - context vector의 문제점

    : 인코더에서 context vector로 압축하는 과정에서 sequence의 일부가 손실될 수 있다.

------------------

### WHY Attention?

- n-gram을 이용하는 전통적인 통계기반 언어모델은 단어의 종류가 조금만 늘어도 여러종류의 n-gram을 기억해야했다 

  - 모델의 크기가 매우 커지고, 단어의 의미 정보를 쉽게 표현하기 어려웠음
  - WordNet과 같은 외부 지식을 쌓아야만 했음

- Word2Vec은 NLM의 성능은 유지하면서 학습 속도는 빠르게 만들었고, 쉽게 **단어 임베딩을 이용**할 수 있도록 했음

- python package "Gensim" 덕분에 파이썬을 이용하는 분석가들이 쉽게 LDA와 Word2Vec 이용

- Attention도 단어 임베딩만큼이나 자연어처리에 중요한 역할

- Attention 과정을 통해 얻을 수 있는 attention weight matrix를 이용하여 모델의 작동방식 시각화 가능

  -  모델의 안정성 점검, 모델의 원인을 찾을 수 있음
  - 이전보다 쉽게 복잡한 모델을 해석 가능

- 최근에는 ,

  **self-Attention을 이용하는 Transformer**가 번역의 성능을 향상시켜주었고, 이를 이용하는 **BERT**는 왠만한 자연어처리 과업들의 기록을 단 하나의 단일 모델로 갈아치웠다.



### Attention in seq2seq

- 하나의 input sequence에 대한 output sequence를 만들기 위해 제안됨

- Seq2Seq =/= sequential labeling

  - sequential labeling

    : input sequence [x1,x2,…,xn]의 각 xi에 해당하는 output sequence [y1,y2,…,yn]를 출력

    : input sequence와 output sequence 의 길이가 같음

- seq2seq가 풀고자 했던 문제 : **번역**

  - input sequence의 x1:n 의 의미와 같은 의미를 지닌 output sequence y1:m을 만드는 것
  - xi, yi 간의 관계를 학습하는 것이 아님!
  - input sequence와 output sequence의 길이가 다를 수 있음

- 아래 그림

  : input sequence [A, B, C] 에 대하여 output sequence [W, X, Y, Z] 를 출력하는 **sequence to sequence model** 

  ![img](https://lovit.github.io/assets/figures/seq2seq.png)

  : 서로 언어가 다르기 때문에 Encoder RNN과 Decoder RNN을 따로 두었음

  - **Encoder**

    : input (source) sentence 의 언어적 지식을 학습하는

  - **Decoder**

  ​       :  output (target) sentence 의 언어적 지식을 학습하는

- Seq2Seq가 학습하는 기준
  $$
  maximize∑Pθ(y1:m|x1:n)
  $$
  : **x1:n과 y1:m의 상관성을 최대화** 하는 것

  : input sequence 의 정보를 하나의 **context vector C** 에 저장

  : C - Encoder RNN 의 마지막 hidden state vector

  **: Decoder RNN** 

  - 고정된 context vector C와 현재까지 생성된 단어열 ya:i-1을 이용하는 Language Model (sentence generator)

  
  $$
  P(y1:m|x1:n)=
  ∏
  i
  P
  (
  y
  i
  |
  y
  1
  :
  i
  −
  1
  ,
  c
  )
   
   
  $$

  - 이 구조만으로도 번역 성능은 향상됨 --> Word embedding 정보를 이용했기 때문에

  - n-grams를 이용하는 기존의 statistical machine translation보다 작은 크기의 모델 안에 **단어간의 semantic정보**가 포함되어 있기 때문에

    

- 하나의 문장에 대한 정보를 하나의 context vector C로 표현하는 것이 충분하지 않다는 문제가 제기됨
  - Decoder RNN이 문장을 만들때 각 단어가 필요한 정보는 다 다름
  - 하지만, Seq2Seq는 매 time step에 동일한 context vector C를 사용함
  - 대신에 x1,x2,…,xn 에 해당하는 **encoder RNN 의 hidden state vectors h1,h2,…,hn 의 조합으로** yi 마다 다르게 조합하여 이용하는 방법을 제안 --> **Attention**
- 아래의 그림처럼 decoder RNN 이 yi 를 선택할 때 encoder RNN 의 hj 를 얼만큼 이용할지를 **aij** 로 정의

<img src="https://lovit.github.io/assets/figures/seq2seq_with_attention.png" alt="img" style="zoom: 50%;" />

- Weight는



