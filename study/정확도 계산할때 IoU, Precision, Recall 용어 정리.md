### 정확도 계산할때 IoU, Precision, Recall

참고 : https://hoya012.github.io/blog/Tutorials-of-Object-Detection-Using-Deep-Learning-how-to-measure-performance-of-object-detection/



- **IoU (Intersection Over Union)**

  : 모델이 예측한 결과와 GT(정답)--> 이 두 Box 간의 교집합과 합집합을 통해 IoU를 측정

<img src="https://hoya012.github.io/assets/img/object_detection_fourth/fig1.PNG" alt="img" style="zoom:50%;" />

​       : 이 IoU가 threshold를 넘으면 정답이라고 생각. 



- **Precision** - **예측된 결과가 얼마나 정확한지**

  : classification에서 자주 보이는

  <img src="https://hoya012.github.io/assets/img/object_detection_fourth/fig3.PNG" alt="img" style="zoom:80%;" />

  - TP

    : 실제 Positive를 Positive로 예측한 경우 (잘한거)

  - FP

    : 실제는 Negative인데 Positive로 예측한 경우 (잘못한거)

  : 즉, Precision값을 높으려면 모델이 Box를 잘 예측해서 **FP를 줄여야함**



- **Recall - 얼마나 잘 예측했는지**

  <img src="https://hoya012.github.io/assets/img/object_detection_fourth/fig4.PNG" alt="img" style="zoom:80%;" />

: positive를 주었을 때 얼마나 잘 Positive로 예측하는지

: Recall을 높이기 위해선 모델 입장에서는 되도록 Box를 많이 쳐서 정답을 맞혀서 FN을 줄여야 함



