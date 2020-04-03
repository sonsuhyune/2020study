## MobilePill: Accurate Pill Image Classification via Deep Learning on Mobile 논문 정리

#### abstract

- mobile을 통해 알약 정보를 제공
- mobile을 통해 찍은 알약 이미지를 분류하는 문제
- 분류하기 위해 hybrid CNN model 사용
- 같은 모양의 알약 이미지에서 다른 properties를 classify하는 접근법 (모델)



#### introduction



- the ranking based recognition system

  : 실제 알약을 Top-n pills과의 유사성으로

-  CNN 활용

  : 알약의 문자를 인식하는 모듈 도입

  (기존의 OCR - character을 검출하는데 제한된 성능)

- 알약 인식 관련 work 에 대한 설명 --> pill image의 limitation에 대한 설명

- pill들의 시작적인 homogeneity는 정확하게 pill을 검출하는데에 방해가 된다

  --> 그래서,

  ​      1. **ranking based recognitioin system 을 이용해서 Top-n pills에 대한 유사도** 

  ​      2. **CNN을 통해 알약의 식별문자를 인식하는 모듈 추가**

        -  위 두가지 방법으로 정확도를 높이겠다



-------------------------------------------------------------------------------

###  Limitation and Solutions

- major limitation

  : 알약의 양면에서 나온 size, shape, color, and imprint 등을 고려한다면 정확한 알약 matching이 가능

- 두가지 type의 이미지 set으로 match시켜야한다.

  : 여기서 두 type-consumer image, reference image

- 실제 사용자가 찍은 이미지는 주변 환경에 영향을 받는다. 



#### A. Image Feature Classification

- 각 feature의 classification에서는 consumer image에서의 difference로 인한 문제가 있다.
  - 사용자 이미지에서 illumination, shading, and background 의 영향으로 image에서 pill의 색이 바뀔 수 있다.
  - pill의 shape에 기초한 classification의 경우 사용자의 이미지에서  circle과 polygon와 같이 유사한 모양을 구분하기 힘들 수 있다.
- 이런 데이터의 변화들 때문에 정확한 classification을 위한 CNN 제안 
  - trained augmented reference image data



#### B. Characters Recognition

- 알약의 문자로 classify하기 위한 OCR 제안
- pill character data를 기반으로 한 RNN 제안



#### C. Lack of Sample Images

- 각 알약마다 다양한 사용자 이미지를 구하기 힘들어서 --> 각 알약별 40개의 sample image 만들어서 training 시킴
- CNN은 이렇게 만들어낸 argument image로 training 시킬때 충분했다.
- argument Image: image rotation 기반 (image를 10도씩 회전해서 36개 image얻음)



#### D. Limtation in Pill Preprocessing

- RAG, binary thresholding에서 생성된 이미지에서 **character**(surface와 character간의 boundary를 구분하기 위해)추출





----------------------------------------



### System Overview

: 크게 3가지 stage

1. data processing

   :  알약 사진을 찍고 이미지 quality를 높이기 위해 RAG thresholds, smoothing, and sharpening filter techniques 사용

   : 이렇게 하면 고화질의 사진이 됨

2. 1단계에서 적절한 image와 shape 정보를 받은 후

   image를 classify하고 prediction score로 pill image의 label을 generate

   (여기서 prediction score: shape 마다의 CNN model - 5개를 통해)

   - 그래서, 5개의 training set(reference img, real img) 필요

   - training set 만들때 알약 shape 별로 rotation기반으로 augmentation imgae 생성해서

3. hyprid decision 단계에서 Random Forest Model을 사용한다.

   - 이 단계는 알약의 이름을 present하는 단계이다.
   - 여기서 model은 다양한 input data(전처리에서 수집한 shape, label number)를 사용하여 color, OCR, dosage forms, and break marks information를 추가한다.
   - 여기서 label number: 



------------------------------------------



### Evaluation

- 총 5개의 dataset이 CNN 기반 접근법 접근법을 평가하는데 사용됨
- 두가지 experiments
  - a classification rate test in terms of CNN & hybrid models.