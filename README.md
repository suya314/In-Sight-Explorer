# In-Sight-Explorer
깃허브 사용 미숙으로 제대로 프로젝트 폴더를 업로드하지 못함. 추후 수정 필요!
## 프로젝트 개요
2021-1 컴퓨터영상신호처리 교과목에서 진행한 개인 프로젝트. OpenCV를 이용한 In-Sight Explorer 기능 구현


* In-Sight Explorer란?
  * Cognex 사에서 제공하는 광학 검사 응용 프로그램
  * Cognex는 기존 육안 검사에 의존하던 제조업의 외관 검사를 딥러닝 기술을 적용해 자동화하는 솔루션을 제공하는 회사
  * In-Sight Explorer는 함수를 입력하고 검사 영역을 지정한 후, 정상 범위 값을 지정하면 함수 값에 따라 이 부품이 불량인지 아닌지 판별하는 프로그램 


In-Sight Explorer에서 사용되는 함수들을 OpenCV로 구현하고, Bracket 샘플 사진을 검사하여 불량품을 검출하는 프로그램을 만듦.
* ExtractHistogram : 영역에서 GrayScale 값을 계산하는 함수
* ExtractBlob : 영역에서 Blob을 찾는 함수

![0004](https://user-images.githubusercontent.com/69028945/138356471-9388d4d4-7114-48c2-a690-b3397d858ccd.jpg)

## 구현

![0005](https://user-images.githubusercontent.com/69028945/138356539-6a4d4728-f39e-46f7-903d-3095345c52c3.jpg)

[시연 영상](https://youtu.be/ml4Wm9xp0uI)


## 개선점

![0014](https://user-images.githubusercontent.com/69028945/138357507-adce69dd-e34b-470b-aa97-44e013a1eab2.jpg)

