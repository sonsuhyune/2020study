## GCP에서 이미 생성된 VM 인스턴스에  SSH로 접속하기

* Window환경이지만 어차피 putty를 이용하기 때문에 명령어에 있어서 OS환경 차이는 크게 없을 것 같다.



1. 생성된 VM 인스턴스의 외부 IP확인

​       : 해당 project의 GCP 콘솔에서 computer engine -> VM 인스턴스에서 확인가능

2. putty에서 인스턴스 접속

   : [블로그](https://medium.com/dream-youngs/google-cloud-console-ssh%EB%A1%9C-%EC%A0%91%EC%86%8D%ED%95%98%EA%B8%B0-for-windows-bf56104a9728) 순서대로 하면 된다.

3. 일단 anaconda와 jupyter를 설치해야 한다.

   : [블로그](https://shwksl101.github.io/gcp/2018/12/23/gcp_vm_custom_setting.html)를 참고했다.

   [여기](https://repo.continuum.io/archive/)서 자신의 리눅스버전에 맞는 링크를 복사한다. 

   (여기서 내 OS환경에 맞추어야 하는 줄 알고, window버전을 다운받았는데 결국 putty내에서 설치하고 사용하는 것이기 때문에 리눅스 버전을 다운받아주어야 한다)

   : 내가 사용한 링크=https://repo.continuum.io/archive/Anaconda3-2019.10-Linux-x86_64.sh

   ```bash
   wget https://repo.continuum.io/archive/Anaconda3-2019.10-Linux-x86_64.sh
   ```

   ```bash
   bash Anaconda3-2019.10-Linux-x86_64.sh
   ```

   : 위의 명령어를 치고 나서 계속 Enter를 눌러준다 (yes/no가 뜰 때까지)

   : yes를 치고 

​        [/home/**/anaconda3] >>>

​         이런 문구가 나오면 Enter를 눌러준다.

​        : VScode를 설치할거냐고 묻는 문구에는 no를 쳐준다.

​        : 마지막으로

```bash
source ~/.bashrc
```

4. Jupyter notebook 설치

   ```bash
   conda install notebook
   ```

   : 설치한 후에 jupyter notebook config가 있는지 확인

   ```bash
   ls ~/.jupyter/jupyter_notebook_config.py
   ```

   (없으면 아래의 명령어로 생성해줌 )

   ```
   jupyter notebook --generate-config
   ```

   : 이 config 파일을 수정해준다

   ```bash
   vi ~/.jupyter/jupyter_notebook_config.py
   ```

   ```
   c = get_config()
   c.NotebookApp.ip = '[1번에서 확인한 IP]'
   c.NotebookApp.open_browser = False
   c.NotebookApp.port = [Port Number]
   ```

   --> config 파일 내에 위의 코드를 써준다.



​		: 그리고 아래와 같은 명령어로 사용하면 된다고 하는데 난 안됐다. 

```
jupyter-notebook --no-browser --port=[PORT-NUMBER]
```

​        *그래서,

​          이 인스턴스를 처음 만든 사람의 디렉토리로 옮겨서 작업했다.

```bash
cd /home
```

```bash
ls
```

ls로 user를 확인하고, 내가 원하는 path로 옮겨서 작업하니 잘 되었다.!!