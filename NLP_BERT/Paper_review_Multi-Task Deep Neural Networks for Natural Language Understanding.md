## Multi-Task Deep Neural Networks for Natural Language Understanding

- 2019년 MS에서 발표한 논문인, MT-DNN 논문 리뷰 겸 정리

- 아래 사이트를 참고하여 작성하였습니다.

  https://y-rok.github.io/nlp/2019/05/20/mt-dnn.html#3-model-architecture--training 

-----------------

### MT-DNN

  : BERT에 **Multi-task learning**(GLUE의 9개의 Task 활용)을 수행하여 성능 개선한 모델

  : 다양한 Task의 Supervised Dataset을 모두 사용하여 대용량 데이터 학습

  : Multi-task learning을 통해 특정 Task에 Overfitting되지 않도록 Regularization 

   --> Domain adaptation

  : [8개의 GLUE Task, Domain Adaptation] 에서 State-of-the-Art 성능

​    (Fine tuning시, 데이터가 적을 때에도 Classification정확도가 꽤 높음)

  : **BERT보다 더 높은 성능**

  : SNLI, SciTail dataset을 사용하여 MT-DNN에서 학습된 representation이 pre-trained BERT model보다   

   **domain adaptation**을 더 잘 수행한다.



### 1. Introduction

#### 자연어에서 Language representation

- Word or Sentence의 Vector Representation을 생성하는 방식 2가지

  **1) Language Model Pre-Training**

  ​    : Unlabeled dataset을 활용한 방법

  ​    : 문장에서 특정 단어를 맞추는 방식으로 <u>Unsupervised Learning</u>

  ​    : ELMo, BERT

  **2)** **Multi-task learning**

  ​    : 여러 Task의 Labeled Dataset을 활용하여 1개의 모델 <u>Supervised Learning</u>

  ​    : 어떤 Task에서의 학습효과가 다른 Task의 성능에 영향을 미칠 것이라는 가정

   <u>--> MT-DNN에서는 이 두가지 방식을 combine하여 사용했다.</u>



#### Multi-task learning

  : 이전 task에서 배운 지식이 새로운 task를 학습할때 도움을 주는 인간 학습 활동에서 영감을 얻음

  : 한 task에서 학습한 지식이 다른 task에 유익하게 하기 위해 **multiple task를 동시에 학습**

  : 그래서, 최근에는 <u>DNN에 이러한 Multi task learning을 적용</u>시키는 것에 관심 多    

- 관심이 많아진 이유 2가지

  1. supervised learning은 많은 양의 task-specific한 labeled data가 필요하다. (Supervised Dataset은 Task에 따라 데이터가 적을 경우, 성능이 상당히 저하된다.)

     하지만 이 데이터들도 항상 이용할 수 있는 건 아님

     --> MTL은 연관되어 있는 **task들의 supervised data를 효과적으로 활용할 수 있는 방법**을 제공

  2. 모델이 특정 **Task에 Overfitting되지 않도록 Regularization 효과**를 줄 수 있음



#### language model pretraining

  : 많은 양의 unlabeled data를 활용하여 보편적인 language representation을 배우는데 효과적

  : BERT, ELMo, GPT 같은 model

  : unsupervised objective를 이용하여 text data를 train한 model

  : ex) BERT - multi layer bidirectional Transformer를 기반으로, MLM과 NSP task를 위해 훈련된다

  : 특정 NLU Task를 하려면, 각 task 별로 fine-tuning을 진행

​    각 task specific한 layer를 추가적으로 붙여서 task specific한 training data로 fine tuning을 진행



#### MTL, Language model pretraining

  : MTL과 LMP는 상호 보완적인 기술

  : 이 둘을 combine하여 다양한 NLU task

  : 이를 위해, **BERT를 shared text encoding layer로 사용**

  : 둘을 합치 모델 layer - Figure 1

![img](https://y-rok.github.io/assets/img/Untitled-5daa626f-1b42-4f5b-818e-eb6bbe294093.png)

  : BERT 모델처럼 MT-DNN은 fine-tuning을 통해 특정 task에 적용할 수 있다

  : MT-DNN은 BERT와는 달리, pretraining할때 MTL을 사용하였다.



### 2. Tasks

#### GLUE Task

: 총 9개의 NLU task 중 8개에 대한 SOTA - 82.7%로 올렸고, BERT보다 2.2%정도 더 높음

- **Single Sentence Classification**

  : 하나의 문장이 Input으로 주어졌을 때, Class를 분류하는 Task

  : <u>CoLA</u> - 문장이 문법적으로 맞는지 아닌지 (True/False)  

  : <u>SST-2</u> - 영화 Review 문장의 감정 분류 (Positive/Negative)

- **Text Similarity**

  : 문장 쌍이 주어졌을 때, 점수를 예측하는 Regression Task

  : <u>STS-B</u> = 문장간의 의미적 유사도를 점수로 예측

- **Pairwise Text Classification**

  : 문장 쌍이 주어졌을 때, 문장의 관계를 분류하는 Task

  : <u>RTE</u>, <u>MNLI</u> - 문장간의 의미적 관계를 3가지로 분류

  ​                        (Entailment, Contradiction, Neutral)

  : <u>QQP</u>, <u>MRPC</u> - 문장간의 의미가 같은지 아닌지 

  ​                        (True, False)

- **Relevance Ranking**

  : 질문 문장과 지문이 주어졌을때, 지문 중 정답이 있는 문장을 Ranking을 통해 찾는 Task

  : <u>QNLI</u>-질문, 지문 중 한 문장이 쌍으로 주어졌을 때 해당 지문 문장에 질문의 답이 있는지

  * **MT-DNN**에서는 이를 **Rank**방식으로

    : 모든 지문 문장에 정답이 있을 가능성을 측정하여 그 값이 가장 높은 지문문장만을 True로 분류하는 방식

 

### 3. The Proposed MT-DNN Model

![img](https://y-rok.github.io/assets/img/Untitled-5daa626f-1b42-4f5b-818e-eb6bbe294093.png)

-  **Lower layer** 

  : Shared layer

  : 모든 task가 share하는 layer

  - **Lexicon Encoder**

    : input X을 embedding vector의 sequence로 나타내는 layer

  - **Transformer encoder**

    : self attention을 통해 각 word에 대한 contextual information을 capture

    : **shared contextual embedding vector**를 만드는 layer

     (이 vector는 multi-task object에 의해 훈련된 <u>shared semantic representation</u>이다.)

  

- **top layer**

  : task specific한 output을 represent하는 layer



#### 이제 각 layer에 대해 더 자세히 

- **Lexicon Encoder**

  - input X : 길이가 m인 token들의 sequence ([CLS],[SEP],[SEP] token 포함하고 있는)

  - X를 각 token에 대해 input embedding, segment(token) embedding, positional encoding 한 후,

    embedding vector의 sequence로 나타내는 layer



- **Transformer Encoder**
  
  - lexicon Encoder에서 나온 input representation vector를 contextual embedding vector C의 sequence로 map
  
  - mapping하기 위해 multi layer bidirectional Transformer encoder를 사용
  
  - **<u>contextual embedding vector = task들 간의 shared representation</u>** 
  
  - BERT는 pretraining을 통해 representation을 학습하지만, **MT-DNN은 pretraining+mtl로 representation을 학습**
  
    

- **Single-Sentence Classification Output**

  - x=token [CLS]의 contextual embedding

  ​         = input sentence X의 semantic representation을 볼 수 있는

  - SST-2의 경우, X가 class c에 labeled 일 확률은 softmax를 통해

    ![1_func](/img/1_func.PNG)



- **Text Similarity Output**

  - STS-B task : 문장간의 의미적 유사도를 점수로 예측

  - x= token [CLS]의 contextual embedding

      = input sentence pair(X1,X2)의 semantic representation을 볼 수 있는

    ![](img\2_func.PNG)



- Pairwisw Text Classification Output
  - edxxxgvcxs