# Ubuntu 서버에 1)Ruby Rails 설치할때 2)node.js 설치할때 

## 1. ubuntu 서버에서 ruby rails 설치할때

- 오류가 나지 않는 다면 다른 부분들은 무시하고,  <1>, <2>... 이 순서대로 하면 된다.

- 서버에서 우리팀이 사용하는 가상환경에서 실행했다.

  **<1>  rvm 설치**

  `$ curl -L https://get.rvm.io | bash -s stable`

  - 원래는 이렇게 하면 rvm이 설치된다고 하는데 역시 나는 안됐다^^

  - curl 명령어를 못알아먹는 것 같아서 구글링을 해보니, 아래의 4단계로 하면 <1>의 명령어를 대체할 수 있다고 한다

    1)`sudo apt-get install curl`
  2)`curl -L https://get.rvm.io | bash -s stable`
    3)`source ~/.rvm/scripts/rvm`
    4)`rvm requirements`
  
  - 근데 나는 2)까지는 잘 했는데, 3)에서 그런 파일이 없다는 오류가 떴다. rvm이 자꾸 제대로 안깔리는 것 같았다..!

  - 그래서.. 

    2),3) 대신 --> `curl -sSL https://get.rvm.io | bash`  이 명령어를 사용했다.

    그리고, 4)를 수행하니까 설치가 잘 됐다고 떴다!

    
  
**<2> `rvm install 1.9.3`**
  
- 내가 뜯어보려는 코드의 버전에 맞추어 설치했다.
  
  **<3> `gem install rails`**
  
  - 근데 <3>을 하고 나니 <u>버전이 맞지 않아 설치할 수 없다</u>는 오류가 떴다.
  - cd로 디렉토리 옮겨서 직접 가보기도 하고
    sudo gem install rails --> sudo 를 써봐도 안됨
    gem install i18n -v 0.9.5
    gem install minitest -v 5.12.0
    gem install ruby -v 2.4.4
  - 이렇게 거의 3시간정도 진정한 삽질을 했다.
  - 결국,  <3> 대신 `gem install rails -v 4.2.2`이렇게 버전을 지정해서 해주면 되는 매우 간단한 것이었다!^^
  - 그런데 이걸 하고 나면 어떤 걸 설치하라고 오류와 함께 명령어를 알려준다.
  - 그 명령어를 따라 한 5-6번 치다보면 설치가 완료된다ㅎ



## 2. ubuntu 서버에서 node.js 설치할때

​            

- node.js 설치할때는 오류가 나지 않아서 ruby보다는 빠르게 할 수 있었다.

  <1> `rpm -qa | grep nodejs`
  <2> `node -v`

  - 이렇게 하면 node라는 command가 없다고 나온다.
  - 서버에 node가 없기 때문에 당연..(2번은 현재 내 서버에 node.js가 있는지 확인하는 거라고 생각하면 된다.)

  <3> `sudo apt install nodejs`

  - 설치 끝!

  <4> 버전 확인을 위해 `node -v`