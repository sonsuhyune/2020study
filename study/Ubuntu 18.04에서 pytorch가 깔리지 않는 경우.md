## Ubuntu 18.04에서 pytorch가 깔리지 않는 경우

https://dreamgonfly.github.io/2018/01/30/conda-pytorch.html

이 블로그의 설명을 따르면, 

1. 가상환경 만들고, activate한다

   

2. ```bash
   conda install -y pytorch torchvision -c pytorch
   ```

   이렇게 설치해준다

   

3. ```bash
    python -m ipykernel install --user --name pytorch --display-name "PyTorch"
   ```

   그리고, 이렇게 커널을 설정해주면 된다고 하지만 error가 뜬다.

   그렇다고 커널을 설정하지 않으면 jupyter notebook에서 torch를 사용할 수 없다

   (import torch를 하면 알 수 없는 모듈이라고 할 것이다)

   

   * **해결방법**
     : 에러가 뜨면 !

     ```bash
     conda install ipykernel
     ```

      : 위 명령어를 치고 다시 3번을 치면 아마 주피터가 사라졌을 것이다. 

        그럼 다시 

     ```bash
     conda install jupyter
     ```

      해서 설치하면 import torch가 된다.