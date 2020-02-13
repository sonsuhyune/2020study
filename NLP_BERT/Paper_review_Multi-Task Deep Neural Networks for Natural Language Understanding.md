## Multi-Task Deep Neural Networks for Natural Language Understanding

- 아래 사이트를 참고하여 작성하였습니다.

  https://y-rok.github.io/nlp/2019/05/20/mt-dnn.html#3-model-architecture--training 

-----------------

### MT-DNN

  : BERT에 **Multi-task learning**(GLUE의 9개의 Task 활용)을 수행하여 성능 개선한 모델

  : 다양한 Task의 Supervised Dataset을 모두 사용하여 대용량 데이터 학습

  : Multi-task learning을 통해 특정 Task에 Overfitting되지 않도록 Regularization

  : [8개의 GLUE Task, Domain Adaptation] 에서 State-of-the-Art 성능

​    (Fine tuning 데이터가 적을 때에도 Classification정확도가 꽤 높음)

  : **BERT보다 더 높은 성능**



#### 자연어에서 Language representation

- Word or Sentence의 Vector Representation을 생성하는 방식 2가지

  **1) Language Model Pre-Training**

  ​    : Unlabeled dataset을 활용한 방법

  ​    : 문장에서 특정 단어를 맞추는 방식으로 <u>Unsupervised Learning</u>

  ​    : ELMo, BERT

  **2)** **Multi-task learning**

  ​    : 여러 Task의 Labeled Dataset을 활용하여 1개의 모델 <u>Supervised Learning</u>

  ​    : 어떤 Task에서의 학습효과가 다른 Task의 성능에 영향을 미칠 것이라는 가정



#### Multi-task learning

- Supervised Task를 1개의 모델을 통해 학습

  : GLUE의 9개 Task 활용

- Multi-Task Learning의 이점

  1. 대용량 Supervised Dataset을 활용하여 학습가능

     : Supervised Dataset은 Task에 따라 데이터가 적을 경우, 성능이 상당히 저하되지만, Multi-task learning 시 이러한 데이터를 모두 합쳐서 활용 가능

  2. 모델이 특정 Task에 Overfitting되지 않도록 Regularization 효과를 줄 수 있음



#### GLUE Task

- Single Sentence Classification

  : 하나의 문장이 Input으로 주어졌을 때, Class를 분류하는 Task

  : CoLA - 문장이 문법적으로 맞는지 아닌지 (True/False)  

  : SST-2 - 영화 Review 문장의 감정 분류 (Positive/Negative)

- Text Similarity

  : 문장 쌍이 주어졌을 때, 점수를 예측하는 Regression Task

  : STS-B = 문장간의 의미적 유사도를 점수로 예측

- Pairwise Text Classification

  : 문장 쌍이 주어졌을 때, 문장의 관계를 분류하는 Task

  : RTE, MNLI - 문장간의 의미적 관계를 3가지로 분류

  ​                        (Entailment, Contradiction, Neutral)

  : QQP, MRPC - 문장간의 의미가 같은지 아닌지 

  ​                        (True, False)

- Relevance Ranking

  : 질문 문장과 지문이 주어졌을때, 지문 중 정답이 있는 문장을 Ranking을 통해 찾는 Task

  : QNLI-질문, 지문 중 한 문장이 쌍으로 주어졌을 때 해당 지문 문장에 질문의 답이 있는지

  * **MT-DNN**에서는 이를 **Rank**방식으로

    : 모든 지문 문장에 정답이 있을 가능성을 측정하여 그 값이 가장 높은 지문문장만을 True로 분류하는 방식

 

