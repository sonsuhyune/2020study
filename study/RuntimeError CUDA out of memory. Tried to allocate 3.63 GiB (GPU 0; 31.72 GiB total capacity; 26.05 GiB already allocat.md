## RuntimeError: CUDA out of memory. Tried to allocate 3.63 GiB (GPU 0; 31.72 GiB total capacity; 26.05 GiB already allocated; 2.66 GiB free; 1.98 GiB cached)



**Out of Memory 문제**



1. 일단 Batch_size를 절반으로 줄여서 돌린다.

2. 16까지 batch_size를 줄였는데도 에러가 나서, 결국 데이터 양을 줄였다.

   training data의 비율을 이전보다 적게

3. 한 Epoch을 돌때 이 오류가 안뜨면 그 뒤 Epoch에서도 안뜨는 것 같다.