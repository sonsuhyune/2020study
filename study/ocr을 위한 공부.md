## OCR을 어떻게 할지..

- text recognition을 사용할지, 글자 하나하나를 detect(object detection)으로 할지
- 참고 자료
  - https://hoya012.github.io/blog/Tutorials-of-Object-Detection-Using-Deep-Learning-what-is-object-detection/



------------------------------------------

- **object detection이란**

  : Object Detection은 Image Classification task에 사물의 위치를 Bounding Box로 예측하는 Regression task가 추가된 문제

  : 한 이미지에 여러 class의 객체가 동시에 존재할 수 있는 상황을 가정

  ```
  Object Detection = Multi-labeled Classification + Bounding Box Regression
  ```

  ![object detection](https://hoya012.github.io/assets/img/object_detection_second/fig1_detection_milestones.PNG)



- **R-CNN**

  : Object Detection에 CNN을 적용한 첫 논문

  : Selective Search와 CNN을 결합한 방법론
     - selective search란

  ​      : 영상의 계층적 구조를 활용하여 영역을 탐색하고 그룹화하는 과정을 반복하며 객체의 위치를 proposal 하는

  <img src="https://hoya012.github.io/assets/img/object_detection_first/fig7_selective_search.PNG" style="zoom:50%;" />

  : input image를 selective search를 통해 region을 proposal하고 proposal된 region을 CNN의 고정 입력 사이즈로 변환하고, 각 region마다 classification을 하는 방식

  : + proposal된 region에서 실제 object의 위치와 가까워지도록 보정하는 regression(사물의 위치를 Bounding Box로 예측하는)도 수행함



- Deep learning을 이용한 Object detection은 크게 두가지

  1) 1-Stage Object Detector

  2) 2-Stage Object Detector

- **2-Stage Object Detector**

  : Region Proposal(R-CNN과 같이 영역을 찾는) 과 그 영역을 classification하는 Detection이 순차적으로 수행하는
  
  : 1-Stage 보다 느리지만 더 정확하다!
  
  : R-CNN계열의 모델들
  
  ![](https://hoya012.github.io/assets/img/object_detection_second/fig5_2stage.PNG)

- **1-Stage Object Detector**

  : 위의 두 과정을 한번에 수행하는

  : SSD, YOLO 등

  : 2-stage에 비해 빠르지만 부정확하다

  ![img](https://hoya012.github.io/assets/img/object_detection_second/fig6_1stage.PNG)

  



- Object detection의 성능

  : 정확도가 높다는 것 = 정답과 유사한 Bounding Box를 예측(Regression)하면서 동시에 Box 안의 object의 class를 잘 예측(Classification)한다는 것

  : 보톤 논문에서는 class를 예측하지 못하면 실패로 간주

  : <u>Class를 올바르게 예측하였을 때의 Bounding Box의 정확도를 기준으로 정확도를 측정</u>

  : 보통 논문에서 사용되는 benchmark는 VOC07, VOC12, COCO - dataset

  

  

