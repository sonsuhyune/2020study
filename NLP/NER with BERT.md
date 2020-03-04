# NER with BERT



<img src="https://user-images.githubusercontent.com/1250095/50369600-a2ded500-05db-11e9-8edf-e3126941d58b.png" alt="img" style="zoom:50%;" />

: Bert Model에서 맨마지막에 **sequence tagging을 위한  layer**를 쌓아서 구현

 NER Task의 경우 마지막 4개 Layer를 Concatenate 했을 때,

 Fine-tuned Model과 거의 차이가 없었다.

 이를 도식화 하면

![img](https://jalammar.github.io/images/bert-feature-extraction-contextualized-embeddings.png)

​          [그림1- http://docs.likejazz.com/bert/]

 NER에서도 SOTA 달성





## NER with BERT-BioBERT

BioBert - https://github.com/dmis-lab/biobert

BioBert는 BERT의 run_classifier.py를 변경하여 **NER - Bio tagging**



run_ner.py에서 **def create_model** 

```python
def create_model(bert_config, is_training, input_ids, input_mask,
                 segment_ids, labels, num_labels, use_one_hot_embeddings):
    model = modeling.BertModel(
        config=bert_config,
        is_training=is_training,
        input_ids=input_ids,
        input_mask=input_mask,
        token_type_ids=segment_ids,
        use_one_hot_embeddings=use_one_hot_embeddings
    )
    output_layer = model.get_sequence_output()

    hidden_size = output_layer.shape[-1].value

    output_weight = tf.get_variable(
        "output_weights", [num_labels, hidden_size],
        initializer=tf.truncated_normal_initializer(stddev=0.02)
    )
    output_bias = tf.get_variable(
        "output_bias", [num_labels], initializer=tf.zeros_initializer()
    )
    with tf.variable_scope("loss"):
        if is_training:
            output_layer = tf.nn.dropout(output_layer, keep_prob=0.9)
        output_layer = tf.reshape(output_layer, [-1, hidden_size])
        logits = tf.matmul(output_layer, output_weight, transpose_b=True)
        logits = tf.nn.bias_add(logits, output_bias)
        logits = tf.reshape(logits, [-1, FLAGS.max_seq_length, 7])
        # mask = tf.cast(input_mask,tf.float32)
        # loss = tf.contrib.seq2seq.sequence_loss(logits,labels,mask)
        # return (loss, logits, predict)
        ##########################################################################
        log_probs = tf.nn.log_softmax(logits, axis=-1)
        one_hot_labels = tf.one_hot(labels, depth=num_labels, dtype=tf.float32)
        per_example_loss = -tf.reduce_sum(one_hot_labels * log_probs, axis=-1)
        loss = tf.reduce_sum(per_example_loss)
        probabilities = tf.nn.softmax(logits, axis=-1)
        predict = tf.argmax(probabilities,axis=-1)
        return (loss, per_example_loss, logits, log_probs, predict)
        ##########################################################################
```



### 아래: 위 코드의 line별 설명

```
 model = modeling.BertModel(
        config=bert_config,
        is_training=is_training,
        input_ids=input_ids,
        input_mask=input_mask,
        token_type_ids=segment_ids,
        use_one_hot_embeddings=use_one_hot_embeddings
    )
```

**▶ modeling.py 의 class BertModel**

- **is_training** 

  : bool

  : True면 training, False면 eval

  : dropout을 할지 말지 --> Training이면 dropout과정을 하기 위해

- **input_ids**

  : vocab에서 해당 token이 어디에 위치하는지

  : 크기 [batch_size, seq_length]

- **input_mask**

​       : padding [PAD] 인지 아닌지 구분하는

​       : 크기 [batch_size, seq_length]

- **token_type_ids**

​       : Token A인지 Token B인지 구분하는

​       : 크기 [batch_size, seq_length]

- **use_one_hot_embedding**

  : bool

  : one-hot word embedding을 사용할 건지, `tf.embedding_lookup()`을 사용할지

​    **[tf.embedding_lookup()]**

​        : 큰 사이즈의 list형태의 data가 있을 때, 입력받은 index에 따라 lookup해서 사용

.

```python
 output_layer = model.get_sequence_output()
```

▶ **Encoder(BERT)의 final hidden layer**

​     : 크기 [batch_size, seq_length, hidden_size]

​     : 여기서 나온 layer는 BERT를 거치고 나온 layer

.

```
hidden_size = output_layer.shape[-1].value
```

▶ **Encoder(BERT)의 final hidden layer의 size**

​     : 크기 [batch_size, seq_length, hidden_size]

.

```
output_weight = tf.get_variable(
        "output_weights", [num_labels, hidden_size],
        initializer=tf.truncated_normal_initializer(stddev=0.02)
    )
```

▶ **output_weight 행렬 만들기**

​     : 크기 [num_labels, hidden_size]

​     : initializer-표준편차로 정규분포에서 초기화

.

```
output_bias = tf.get_variable(
        "output_bias", [num_labels], initializer=tf.zeros_initializer()
    )
```

▶ **output_bias 행렬 만들기**

​       : 크기 [num_labels]

​       : initializer-zero로 초기화

.

```python
with tf.variable_scope("loss"):
        if is_training:
            output_layer = tf.nn.dropout(output_layer, keep_prob=0.9)
```

▶ **training이면 output layer에 dropout을 해준다**

.

```
output_layer = tf.reshape(output_layer, [-1, hidden_size])
```

▶ **(dropout을 한/하지 않은) output_layer를 reshape**

​      : 크기 [batch_size X seq_length, hidden_size]

​      : 3차원이던 크기를 2차원으로 reshape

​      : 밑에서 **W와 곱하기 위해** 차원 변경을 목적으로

.

```
logits = tf.matmul(output_layer, output_weight, transpose_b=True)
```

▶ **output weight의 Transpose X output layer** 

​      : 여기서 weight - fine tuning과정의 Task 별 weight인데 여기서 Task=NER

​      : W의 크기 [num_labels, hidden_size]

.

```
logits = tf.nn.bias_add(logits, output_bias)
```

▶ **weight를 곱한 결과에 bias를 더해준다**

.

```python
logits = tf.reshape(logits, [-1, FLAGS.max_seq_length, 7])
```

▶ **다시 reshape를 해준다**

​    : 크기 [batch_size, max_seq_length, 7]

​    : 결국 W를 곱하기 전에 reshape을 해줬던 과정 직전의 차원과 같아 진다

.

```
log_probs = tf.nn.log_softmax(logits, axis=-1)
```

▶ **log_probs를 구한다**

​     : 구하기 위해 위의 logits에 log_softmax

.

```
one_hot_labels = tf.one_hot(labels, depth=num_labels, dtype=tf.float32)
```

▶ **labels를 one-hot vector로 만들어 준다**

​      : 여기서  labels = ['B','I','O','CLS','SEP','X']

.

```
per_example_loss = -tf.reduce_sum(one_hot_labels * log_probs, axis=-1)
```

▶ **각 example 별 loss를 구한다**

​     : 여기서 example = 각 Token

.

```
loss = tf.reduce_sum(per_example_loss)
probabilities = tf.nn.softmax(logits, axis=-1)
predict = tf.argmax(probabilities,axis=-1)
```

▶ **loss, prob, pedict을 구한다**

​     : softmax값을 취한 것에서 max값이 예측값! 

.

#### output_layer가 변경되는 과정

.

![image-20200131184216377](C:\Users\SAMSUNG\AppData\Roaming\Typora\typora-user-images\image-20200131184216377.png)



.

### 참고자료

 BERT 톺아보기 http://docs.likejazz.com/bert/