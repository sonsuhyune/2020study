## 이미지 labeling하기 위한 tool 설치/실행

: DSC 팀프로젝트에서 각 이미지 별로 labeling을 할때 사용한 tool 설치법 정리

: https://github.com/tzutalin/labelImg

: window의 anaconda prompt에서 작성/설치했다

1. **가상환경 생성 후 실행**

   `conda activate {가상환경 이름}`

2. **내 가상환경의 path 확인**

   `conda env list`

3. **내 가상환경으로 cd**

   `cd {가상환경 path}`

4. `git clone https://github.com/tzutalin/labelImg`

5. **git clone한 파일에 들어가기**

   `cd labelImg`

6. `conda install pyqt=5`

7. `pyrcc5 -o libs/resources.py resources.qrc`

8. `conda install -c anaconda lxml`

   : 이걸 하지 않으면 9번 명령어를 쳤을때 lib.resoures가 없다고 에러가 뜬다.

9. **labeling하는 tool실행!**

   `python labelImg.py`

   ![image-20200122150442306](C:\Users\CSE_123\AppData\Roaming\Typora\typora-user-images\image-20200122150442306.png)

--> 그럼 이런 tool이 뜬다!