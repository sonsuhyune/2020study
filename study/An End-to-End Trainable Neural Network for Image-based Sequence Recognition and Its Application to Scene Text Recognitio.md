### An End-to-End Trainable Neural Network for Image-based Sequence Recognition and Its Application to Scene Text Recognition


- 크게 4가지 특성

  1)  end-to-end trainable model 이다

  2) arbitrary한 길이의sequence들을 character segmentation과 horizontal scale normalization없이도 Handle할 수 있다.

  3) 사전에 정의된 lexicon에만 국한되는 것이 아니라 lexicon-free, lexicon-based text recognition task 모두 가능

  4) 모델크기가 작지만 성능이 좋아서 real-world application에 적합하다.

  

- 이 논문에서 제안하는 모델 **: CRNN**

  - combination of DCNN and RNN
    

- s**equence-like objects에서 CRNN**이 기존의 CNN과 다른 advantage

  1) words, instance와 같은 sequence label을 바로 학습할 수 있다. 

     (characters와 같은 detail한 annotation 필요없이)

  2) hand-craft features나 preprocessing step이 필요없이도 image data에서  informative
  representations을 학습하는 property를 갖고 있다. (DCNN과 같은)

  3) sequence label를 produce할 수 있는 RNN의 property를 가지고 있다.

  4) sequence object의 길이에 제한되지 않으며 단지 training과 test에서 높은 normalization을 필요로 한다.

  5) word recognition에서 높은 성능

  6) standard DCNN model보다 적은 parameter를 가지고 있다

  

- 네트워크 구조

  <img src="https://miro.medium.com/max/1074/1*crbk9-rmAuVadOd8lw1EbA.png" style="zoom:67%;" />



- Convolution Layer --> Recurrent Layer --> Transcription Layer

  - **Convolution Layer**

    : input image에서 automatic하게 feature sequence를 뽑아낸다.

  - **Recurrent Layer**

    : convolution layer의 output인 feature sequence의 각 frame에 대해서 prediction을 위한 layer

  - **Transcription Layer**

    : recurrent Layer에서 frame마다 predict한 것을 translate하는 Layer

  --> 전체 architecture는 하나의 loss function!!



- CRNN을 pytorch로 구현한 github

  : https://github.com/sonsuhyune/crnn.pytorch