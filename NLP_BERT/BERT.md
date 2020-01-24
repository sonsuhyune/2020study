## NLP_BERT

이 폴더는 2018년 구글에서 공개한 인공지능 언어모델 BERT를 공부하기 위해 스스로 공부하며 정리한 파일들이다.

### BERT를 공부하는 이유

: 성능 평가에서 인간보다 더 높은 정확도를 보이며 NLP AI의 딥러닝 모델

: 기존의 단반향 사전학습의 모델과는 달리 task를 양방향으로 사전학습하는 모델

: 교육없이 양방향으로 사전 학습하는 첫 시스템

: 교육없음= bert는 보통의 text corpus 만을 이용해 training이 되기때문에 막대한 양의 보통 text data 언어로 이용 가능하다는 장점을 가짐

: BERT의 자세한 부분은 추후에 논문을 분석해서 추가로 올릴 예정이다



### 공부한 순서

1. RNN
2. Seq2Seq
3. Attention
4. transformer 
5. BERT

: 이렇게 정한 이유는, 일단 BERT는 Transformer를 기반으로 한다.

: Transformer는 Seq2Seq의 한계*(인코더에서 압축하는 과정에서 sequence의 일부가 손실)*를 보정하기 위해 Attention을 이용하여 인코더-디코더를 만든 것이다.

: 그래서 transformer를 이해하기 위해서는 Seq2Seq, Attention에 대한 이해가 필수였다.

: 또, Seq2Seq는 인코더 디코더의 구조로, 그 내부는 RNN architecture를 가진다. 이전에 RNN에 대해 공부한 적이 있었지만 다시 복습하는 개념으로 함께 정리했다. 

: 4번까지 공부 완료한 후에는 김동화의 Transformer&Bert 동영상(<https://www.youtube.com/watch?v=xhY7m8QVKjo>)으로 Transformer부분을 정리하고, Bert를 미리 한번 훑어봤다. 



#### 참고 (2020.01.23 기준)

<https://wikidocs.net/book/2155> : 위키독스-딥러닝을 이용한 자연어 처리 입문

: 완전 강추!! 설명도 엄청 자세하고, 동영상 강의(https://www.youtube.com/watch?v=xhY7m8QVKjo)도 있어 기본적인 딥러닝 지식만 있다면 따라가는 건 어렵지 않다!

<http://www.aitimes.kr/news/articleView.html?idxno=13117>

<https://www.youtube.com/watch?v=xhY7m8QVKjo>

: 위의 위키독스로 이론을 보고 이 동영상을 통해 transformer부분을 정리해보면 좋을 것 같다.