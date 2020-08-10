## STRUCTBERT: INCORPORATING LANGUAGE STRUCTURES INTO PRE-TRAINING FOR DEEP LANGUAGE UNDERSTANDING

* BERT model에서 pretraining시 **language structure**도 포함하여 학습하게 하는 방식으로  bert를 extend한 model
* GLUE Leaderboard에서 3위인 model



### Abstract

* 2가지 auxiliary task로 pretraining(전체적인 pretrain방식은 bert와 비슷하지만 structure를 학습하는 방식으로)

  * to make the most of the sequential order of words and sentences, which leverage language structures at the word and sentence levels, respectively.

    

 ### 1. Introduction

* BERT와 같은 기존의 모델을 언급하면서, 이러한 모델은 underlying language structure들을 활용하지 못한다고 말함.

* 그래서, 이 paper에서 제안하는 structbert는 두가지 새로운 linearization strategies를 제안하여 language structure에 대한 학습이 pretraining시에 일어나도록 한다.
* Specifically, 기존의 masking strategy에서 structbert는 bert를 확장하여 **language structure 정보**를 활용하게 했다.
  * 여기서 language structure: word-level ordering , sentence-level ordering
* 새로운 두가지 **structural objective**로 pretraining을 해여 모델을 강화시켰다.
  * 두가지 structural objective : inner-sentence structure, inter-sentence structure
  * 이를 통해, pretraining 과정동안 linguistic(어학적) aspects들이 captured된다.



* structural pretraining동안, structbert는 contextualized representation에서 word간의 dependency를 encode한다. 



### 2. StructBERT Model Pre-training

* bert와 동일한 구조 - multiLayer bidirectional Transformer network

  * single text sentence나 pair of text sentence가 주어졌을때, 각 token에 대한 contextualized vector representation을 학습. 각 input token은  word, position,text segment를 기반으로 represent된다.

    (=input encoding 또한, bert와 동일하다는 뜻 같다)

    

* bert는 model을 pretrain할때 두가지의 unsupervised learning을 사용
  * 여기서 두가지의 unsupervised learning : Masked LM, next sentence prediction

* **structbert**는 
  * word masking을 한 후, 일정 개수의 token을 shuffling하고 right order를 predict하게 하는 방식의 pretraining을 추가함으로써 masked LM task의 ability를 amplify(증폭)시킴
  * sentence간의 relation을 더 잘 이해하기 위해, sentence들을 random하게 swap 후, next/previous sentence를 예측하게함 
  * 이렇게 함으로써, model은 모든 sentence에서 미세한 word structure를 capture할 뿐 만 아니라 적절하게 bidirectional하게 inter-sentence structure를 모델링할 수 있다.



### 2.1 Input Representation

* input representation

  : bert와 동일한 형태-[CLS] s1 [SEP] s2 [SEP]

  : text들은 wordpiece에 의해 subword unit으로 tokenized

  : 그 후, (bert와 동일하게) positional encoding, segment encoding



### 2.2 Transformer Encoder

: input representation에서 contextual information을 encode하기 위해 Transformer Encoder 사용
$$
H^l = Transformer_l(H^{l-1})
$$
: 여기서, l은 layer



### 2.3 Pre-training Objectives

: pretrain two auxiliary objectives

  1) word structural objective - mainly for the single sentence task

  2) sentence structural objective - mainly for the sentence-pair task

* 위의 두 objectives를 original masked LM objective와 함께 pretrain



![Pre-training-objective](https://baekyeongmin.github.io/images/StructBERT/pre_training_task.jpg)





#### 2.3.1 Word Structural Objective

: 원래 bert의 pretraining 방식인 Masked token을 예측하는 task + shuffled token을 제대로 예측하는 task
$$
arg\ \underset{\theta }max \sum log\  P(pos_1 = t_1, pos_2 = t_2,...,pos_k = t_K|t_1,t_2,...,t_K,\theta)
$$
: K는 shuffled subsequence의 length

: K가 커질수록 모델은 더 많은 부분을 예측하게된다. 이 paper에서는 trigram(K=3)을 사용

​		* 이유: language reconstructability와 model의 robustness(강건한 모델)를 위해

* 전체적인 과정

  : unmasked token들 중에서 3개의 word를 shuffle(순서대로) 

  : transformer encoder를 통과한 output vector는 origin token을 예측하기 위해 **softmax classifier**로 fed

  : **(원래 bert의) masked LM과 위의 Onjective는 동일한 모델로 동시학습되고, weight도 동일하게 학습된다.**



#### 2.3.2 Sentence Structural Objective

: 기존의 bert는 next sentence prediction

: 이 paper는 이를 확장하여 next, previous sentence prediction 둘 다

: 두 문장 S1,S2가 input으로 들어오면, S2가 S1의 next인지, previous인지, (다른 document의) random한 sentence인지 예측한다. 

: S1에 대해서 1/3은 next sentence로, 1/3은 previous sentence로, 1/3은 random sentence로 S2를 sampling

: 이 두 문장은 하나의 input sentence(사실상 SEP로 구분되는) 로 encoder로 input

: model output에서 [CLS] token에 대한 hidden state를 가져와서 softmax classifier로 feed





### 3. Experiments

: 대부분 SOTA-현재 GLUE leaderboard에서 3위

![glue result](https://baekyeongmin.github.io/images/StructBERT/glue.jpg)

