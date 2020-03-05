## Hierarchical Multi-Task Learning model 에 대한 정리

참고한 자료: https://towardsdatascience.com/hmtl-multi-task-learning-for-solving-nlp-tasks-cfae39b3d6e1



* simple task에 대한 training을 먼저 하고, 그 지식을 좀 더 comlpicated한 task에 대해 training할때 사용한다.
* 이 모델은 SOTA를 달성했었다.



#### Background

* NLP에서 많은 task들이 있다 그들을 결합하면 더 좋은 성능을 낼 수 있다는 paper들 또한 많다.

* 하지만 모든 NLP task들이 연관되어 있는 것이 아니기때문에, 서로 도움을 줄 수 있는 task를 선택하는 것이 중요하다.

* HMTL model는 4가지의 task에 집중

  - NER

  - EMD-**Entity Mention Detection** 

    : NER의 확정버전으로, name이 아닌 경우여도 실제 entity와 연관된 mention을 identify하는 것이다.

  - CR-**Coreference Resolution** 

    : 같은 entity들의 metion을 grouping하는

  - RE

* 아래와 같은 예시 sentence가 있을 때

  “*When we were in Spain, my mom taught me how to drive with a car. She also explained how to fuel it*”

  ![img](https://miro.medium.com/max/1290/1*VY01fJkQCzMlNHy3-6Ks0w.png)

  

#### The HMTL Model

- **hierarchical model**

  : 초기에는 NER같으 simple task를 training하고, 그 결과를 다음 task를 training할 때 사용한다.

- 각 task는 세가지 component를 가진다

  - Word Embedding
  - Encode
  - Task-specific layer

- model의 base는 아래의 3가지 모델을 사용하여 **각  input sentence를 vector로 표현**하는 것이다.

  - GloVe
  - ELMo
  - Character-level word embeddings

- 각 task는 dedicated encoder(그 task에 맞는 word embedding을 생성하는 multi-layer로 구성된)로 학습된다

  : bidirectional하다

- encoder의 출력은 앞/뒤 네트워크의 마지막 layer와 연결

- encoder의 입력은 base word representation+ previous task의 encoder output

  

![img](https://miro.medium.com/max/1460/0*ars4YAQeLi9w0WXg.png)