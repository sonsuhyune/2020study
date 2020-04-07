### conda 가상환경에 필요한 모듈 설치법 정리

1. torchtext

   ```
   conda install -c pytorch torchtext
   ```

   : 이렇게 해도 안됨

2. sentencepiece

   ```
   conda install -c powerai sentencepiece
   ```

   ```
   conda install -c roccqqck sentencepiece
   ```

   : pytorch랑 충돌이 일어남..!

   

   

3. pytorch

   ```
   conda install -y -c peterjc123 pytorch
   ```

   ```
   conda install ipykernel
   ```

   ```
   python -m ipykernel install --user --name pytorch --display-name "PyTorch"
   ```

--> 잘 안됨ㅠ



#### 위의 방법보다는 아래의 방법으로 torchtext, sentencepiece, pytorch설치



1. **sentencepiece**

   ```
   conda install -c powerai sentencepiece
   ```

   

2. **pytorch**

   ```
   conda install -y -c peterjc123 pytorch
   ```



3. **git clone해서 torchtext를 깔기위해 git 설치**

   ```
   conda install -c conda-forge git
   ```

   ```
   git clone https://github.com/pytorch/text.git
   ```

   ```
   cd text
   ```

   ```
   python setup.py install
   ```



from torchtext import data, datasets --> 잘 된 다 ! ! !



---------------------------------------------------------------------------------------------

4. **ignite**

   ```
   conda install -c pytorch ignite
   ```

    [from ignite.engine import Engine, Events
     ModuleNotFoundError: No module named 'ignite'] --> 위의 명령어로 이 오류는 해결됨!





5. nltk

   ```
   conda install -c anaconda nltk
   ```

6. anaconda-jupyter

   `conda install -c conda-forge notebook`

   ```
   conda install -c conda-forge jupyter_core
   ```

7. anaconda-lab

   ```
   conda install -c conda-forge jupyterlab
   ```

   : 이거 안하면 jupyter notebook에서 ipynb파일을 만들었을때 kernel error가 뜬다.

