# Ubuntu에서 "**JRE not installed/Java is disabled.**" Error

### 1. 일단 java가 깔려 있지 않아서 java를 설치했다.

: 이 [블로그](https://opentutorials.org/module/516/5558)를 참고하여 작성하였다.

1. **운영체제 종류 파악**

   : 아래 두가지 command중 하나로 확인하면 된다.

   ```
   file /lib/systemd/systemd
   ```

   ```bash
   file /sbin/init
   ```

2. **자바가 이미 철치 되어 있는지 확인**

   ```bash
   java -version
   ```

3. **자바를 설치 할 디렉토리 생성**

​       : 이때 생성이 잘 되었는지 직접 cd로 가서 확인했다

```bash
    sudo mkdir -p /usr/local/java
```

4. **자바 다운로드**

   : 1번에서 확인한 종류에 맞게 설치하면 된다

   : 가장 최신 버전을 다운받으니, 다운로드 된 폴더 내의 파일들이 블로그와 다른 부분이 많아서

     "**1.8.0_241**" 이 버전으로 다운 받았다

   ```bash
   sudo mkdir -p /usr/local/java
   ```

5. **3번에서 생성한 디렉토리로 다운로드 파일 옮기기**

   ```bash
   sudo mv jdk-7u45-linux-x64.tar.gz /usr/local/java/
   ```

6. **그 디렉토리로 이동한 후, 압축을 풀어준다.**

   ```bash
   cd /usr/local/java;
   ```

   ```bash
   sudo tar xvfz /usr/local/java/jdk-7u45-linux-x64.tar.gz
   ```

7. **환경변수 설정**

   : profile 파일을 변경하여 설정한다.

   ```bash
   sudo nano /etc/profile
   ```

   ```bash
   export JAVA_HOME=$(readlink -f /usr/bin/java | sed "s:bin/java::")
   ```

    : "export JAVA_HOME=$(readlink -f /usr/bin/java | sed "s:bin/java::")"

   ​    --> 이 명령어를 profile 파일 아래부분에 추가해주면 된다.

8.  **java를 기본 명령어로 등록**

   : 여기서 jdk폴더 이름은 다운받은 버전에 따라 다르므로 고쳐줘야 한다.

   ```bash
   sudo update-alternatives --install "/usr/bin/java" "java" "/usr/local/java/jdk1.8.0_241/bin/java" 1;
   ```

   ```bash
   sudo update-alternatives --install "/usr/bin/javac" "javac" "/usr/local/java/jdk1.8.0_241/bin/javac" 1;
   ```

   ```bash
   sudo update-alternatives --install "/usr/bin/javaws" "javaws" "/usr/local/java/jdk1.8.0_241/bin/javaws" 1;
   ```

   ```bash
   sudo update-alternatives --set java /usr/local/java/jdk1.8.0_241/bin/java;
   ```

   ```bash
   sudo update-alternatives --set javac /usr/local/java/jdk1.8.0_241/bin/javac;
   ```

   ```bash
   sudo update-alternatives --set javaws /usr/local/java/jdk1.8.0_241/bin/javaws;
   ```

9. **변경사항을 반영**

   ```bash
   . /etc/profile
   ```

10. **설치된 자바 버전확인**

    ```bash
    java -version
    ```

    



### 2. java를 설치하고 다시 해봐도 Error가 계속 떴다. 구글링 해보니, icedtea를 설치해서 chrome에 설정을 해줘야 한다고 한다.

--> 해도 안됨. 

​      프로그램 특성상 explorer에 맞춰어져 있어서 안된다고 함.

​      포기..

