### Sketch-BERT: Learning Sketch Bidirectional Encoder Representation from Transformers by Self-supervised Learning of Sketch Gestalt

---------------------------------------

* Abstract

  - Sketch는 pixel 단위인 photo-realistic image와는 달리 **data points의 sequence, vector format의 representation**으로 저장된다.

  - skatchBERT

    - proposed components and pretraining algorithm 

      (including the newly designed **sketch embedding networks** and the **self-supervised learning** of sketch gestalt)

    - In pretraining task, proposed novel Sketch Gestalt Model(SGM) 

    - downstream task: sketch recognition, sketch retrieval, and sketch gestalt

      (sketch gestalt task는 이 paper에서 처음으로 제안한 task이다)



* Introduction
  - iPad와 같은 touch-screen device로 인해 사람들은 쉽게 sketch를 할 수 있게 되었고, 자동으로 그 sketch를 인식하는 것에 대한 중요성 증가
  - 