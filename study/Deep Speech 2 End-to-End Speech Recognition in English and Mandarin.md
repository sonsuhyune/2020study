## Deep Speech 2: End-to-End Speech Recognition in English and Mandarin



- 주요 기능: End to End learning

- speech recognition의 가장 큰 challenge는 speech와 acoustics의 다양성

  그래서, 현대의 ASR( automatic speech recognition )은 complex feature extraction, acoustic models, language and pronunciation models, speaker adaptation와 같은 복잡한 component들로 구성된다. 그래서 새로운 언어에 대한 ASR개발은 매우 어려웠다.

- 이 논문에서는

  사용자의 기대를 충족하기 위해  single engine이 인간과 유사한 능력을 갖추어야 한다고 주장함. 그래서, 아주 작은 modification만으로 다양한 application을 handle할 수 있게 하고, 새로운 language를 dramatic한 change없이 학습할 수 있게한다. --> 이 논문에서는 이것들을 달성하여 중국어와 영어 test에서 인간의 능력보다 뛰어나게 했음. 

- Deep Speech 2(DS2)는 End to End 딥러닝 시스템이기때문에 the model architecture, large labeled training datasets, and computational scale 이 세가지 핵심 component에 집중해서 

- 전체적인 논문은 이 세가지를 어떻게 했는지에 대한!

- 오디오에서 speech transcription을 예측하기 위해 CTC(Connectionist Temporal Classification) loss function함수를 이용하여 학습

- 이 논문에서는 기존의 연구보다 더 좋은 prediction을 하는 network를 find했을 뿐 만 아니라 accuracy에서 큰 loss없이 production 환경에 setting될 수 있는 recurrent model instance도 find했다.

- model architecture을 찾는것뿐 만 아니라, 기존의 speech recognition system에서 train하는 data보다 더 많은 dataset을 create할 수 있는 data capturing pipeline을 explain하고 있다.

  training 중에 data를 증가시키기 위해 data synthesis 사용

- 공개된 test set을 이용해서 test했고, 그 결과를 이전에 이 저자들이 만든 end to end system과 비교
- 이 연구의 목표: 특정 benchmark에서 뿐만 아니라 여러 시나리오에서 모두 인간 수준의 performance가 나오도록
- 그래서, 비교를 하기위해서 인간의 performance도 측정했다.
- 또 공개 benchmark외에도 real-world product 시나리오에서도 좋은 성능을 보임



### Model Architecture

- 수천 시간의 labeled speech data를 이용해서 train하려면 model도 매우 커야한다.

- bidirectional recurrent layers과  convolutional layers들을 포함하여 총 11개의 layer로 구성되어 있는 model

- 최적화: Batch Normalization (for RNN), novel optimization(SortaGrad) 사용

  

![](https://media.arxiv-vanity.com/render-output/2434449/x1.png)



- 사용한 데이터

  ![image-20200416174825491](/home/miruware/.config/Typora/typora-user-images/image-20200416174825491.png)

: 영어 경우 

: 원래 dataset은 noisy도 많은 raw data였다. 이런 raw data는 hours의 편차가 커서 (= 어떤건 몇분, 어떤건 몇 시간짜리 ) 이 논문에서는 training set을 만드는 alignment, segmentation, filtering pipeline을 만들어서 training set 구축



영어면 영어 data 싹 다 training

중국어면 중국어 싹 다 training



결과

-영어에 가장 좋은 모델:  11 layers with 3 layers of 2D convolution, 7 bidirectional recurrent layers, a fully-connected output layer along with Batch Normalization.

-Read Speech : high signal

![image-20200416180649910](/home/miruware/.config/Typora/typora-user-images/image-20200416180649910.png)

WSJ, LibriSpeech : 사용한 corpus

DS1: 이 저자들이 이전에 한 model



-Accented speech: 여러 악센트로 읽은 

![image-20200416181430768](/home/miruware/.config/Typora/typora-user-images/image-20200416181430768.png)



-noisy speech

![image-20200416181651861](/home/miruware/.config/Typora/typora-user-images/image-20200416181651861.png)

eval clean: noise-free

eval real: real noisy environment에서 collect된 data

eval sim: clean에 noisy를 넣은 것