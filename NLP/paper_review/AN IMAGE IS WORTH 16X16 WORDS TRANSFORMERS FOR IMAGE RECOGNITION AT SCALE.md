## AN IMAGE IS WORTH 16X16 WORDS: TRANSFORMERS FOR IMAGE RECOGNITION AT SCALE

##### Under review as a conference paper at ICLR 2021

(Abstract-Intro부분만 정리)



- NLP에서 transformer와 같은 self-attention based architectures 사용이 매우 효과적이었다.

- 하지만 비전분야에서는 convolutional architecture이 여전히 dominant하다

   (attention을 적용하고자 한 연구가 있었지만, 이는 이론적으로는 효과적이었으나 mordern hardware에 효과적으로 적용되지 못했다. 그래서 large-scale의 image recognition에서는 여전히 ResNet과 같은 클래식한 모델이 SOTA이다.)



- 본 논문에서는 transformer는 바로 image에 적용하는 experiments를 진행
  - 이미지를 **patch**로 자르고 embedding을 거쳐 transformer의 입력으로
  - 각 patch= NLP에서 token
  - image classification task로 학습 - supervised fashion
  - 이렇게 학습시킨 모델은 mid-size의 dataset(such as ImageNet)으로 train시켰을때 비슷한 크기의 ResNet과 비교했을때 더 좋은 accuracy를 보임
  - transformer는 CNN과는 달리 inductive biases가 부족하기 때문에, 적은 양의 data로 학습하였을땐 generalize가 되지 않는다.
  - 본 논문에서 많은양의 dataset으로 학습시키면 위의 문제였던 inductive bias 문제가 해결됨을 보였다.
  - transformer를 충분한 양으로 pretraining을 하면 좋은 결과를 보임
  - 