#### Shape and Text Imprint Recognition of Pill Image Taken with a Smartphone 논문 정리

-----------------------------------------

논문: http://s-space.snu.ac.kr/bitstream/10371/137361/1/000000146053.pdf



- 본 논문에서 제안하는 것

  : 스마트폰으로 촬영된 알약 영상에서 글자와 형상 인식

  - 알약 영역을 특정하기 위해 Saliency Map 이용한 뒤, 빛/그림자 제거 --> 알약 영역 획득
  - 위에서 획득한 영역에서 Zernike Moment를 통해 형상정보를 얻음
  - Gaussian Filter, Gradient Filter, Binarization을 통해 글자박스 추출 --> CNN을 통해 OCR



- 전체 시스템 개요
  - 알약 주변부 획득 --> 그림자/빛 효과 제거 --> 배경과의 색상 차이 및 Canny Edge를 이용하여 알약 영역을 추출 --> Zernike Moment를 이용해 형상 정보 획득 --> Gradient filter를 이용해 글자부를 강조 --> 글자의 Bounding Box 획득 --> 글자 읽음 --> 모양 정보 + 글자 정보 종합하여 알약 인식



1. 알약 주변부 획득

   : 영상 사이즈를 줄인 뒤, Saliency Map 적용

   : Saliency Map

       - 배경과 구분되는 경향을 수치화하여 나타내는

   : 영상을 이진화하여 알약 주변부 영역 획득

2. 알약 영역 획득

   : RGB로 표현된 알약을 HSV 색상공간으로 변경 --> 어두운 공간과 밝은 공간이 V값에 의해 결정됨

3. 형상 정보 획득

   : 총 14가지의 모양을 정의 한 후 앞서 찾아진 알약 영역이 어떤 모양에 속하는지 분류 ( Zernike Moment) 적용

4. **글자부 획득**

   : 앞서 획득한 알약 영역 이미지에서 이미지의 밝기 조절 --> Gaussian Filter 적용

   1) 알약 영역 이미지를 흑백으로

   2) Intensity Adjustment 수행

   ​    : 글자 각인 영역의 밝기 차가 뚜렷하지 않은 경우를 보완하기 위해

   3) Gaussian Filter 이용하여 노이즈 제거

   ​    : 글자 영역을 선명하게 하기위해 조정했던 것들이 알약의 울퉁불퉁한 표면들도 함께 강조될 수 있기때문에

   ​    : 표면에서의 밝기 차이 < 글자 영역의 밝기 차이 이므로 Gaussian Filter 이용하여 제거

   4) Gradient 방법 사용하여 글자의 획을 뚜렷하게

   ​    : 각인 글자처럼 배경과 글자의 색이 구분되지 않아도 경계를 추출할 수 있음

   5) 히스토그램에 기반한 Otsu Threashold를 적용하여 영상 이진화, 노이즈 제거

5. **글자 학습 및 인식**

   - 기존의 OCR 사용 X

     : 기존의 경우는 배경과 글자의 색이 흑백일 경우만 가능하기 때문

   - CNN Deep Learning 사용

   - 글자: 영문 26, 숫자 10 총 39자

   - 각 글자별 3000개 데이터로 학습

![](/home/miruware/Desktop/new_2020study/NLP/paper_review/img/cnn_network.png)

 

​       - 이렇게 학습된 OCR network를 글자부박스를 추출한 뒤 적용시켜서 글자를 인식하게끔