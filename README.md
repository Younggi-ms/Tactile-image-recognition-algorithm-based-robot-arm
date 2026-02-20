# Tactile-image-recognition-algorithm-based-robot-arm
## 프로젝트 개요
본 프로젝트는 인간 손의 복잡한 동작을 모방하는 로봇 손 개발 및 촉각 이미지 센서를 통한 섬세한 작업기능 구현을 목표로 하였습니다. 

기존의 로봇 손 기술은 손가락 폄근을 제어하는 능력이 부족하며, 이는 실제 손의 섬세한 움직을 구현하는데 한계를 드러내고 있었습니다.
이에 따라 유연한 관절을 기반으로 섬세한 동작을 구현하는 로봇손 및 물건의 촉감을 감지하는 촉감 이미지 센서 개발을 진행하였습니다.

## 개발 목표
- 센서 H/W 제작
- 학습 데이터 수집 및 전처리
- 실시간 힘 추론 알고리즘
- Teensy 4.1 통신 규격 고안
- 로봇 손 S/W 제작

## 시스템 구성
### 하드웨어 주요 구성
- BLDC 모터 * 8개
- Tendon 제작용 Wire
- 카메라 모듈 * 4개
- 실리콘 젤
### 소프트웨어 주요 구성
- 모터 제어 시스템
- 자세 제어 시스템

## 손 관절 구성
![Image](https://github.com/user-attachments/assets/f636a0df-8aa6-47b6-93c9-30374d603871)
- 실제 손과 크기 비교
## 핀 맵 및 3D 모델
<img width="3508" height="2480" alt="Image" src="https://github.com/user-attachments/assets/5fdc5987-e028-4c2c-b5dd-37bf7040376b" />
- 마스터 모델 핀맵

<img width="2352" height="1560" alt="Image" src="https://github.com/user-attachments/assets/1dcf9d3c-4ea1-434c-bf27-8e67c96ad2a5" />
- 슬레이브 모델 핀맵

<img width="1724" height="938" alt="Image" src="https://github.com/user-attachments/assets/b33e6b99-3463-4612-ae73-cb7e81c34e63" />
- 마스터 모델 3D 모델
  

## 관절 구동을 위한 모터 플랫폼 구현
![Image](https://github.com/user-attachments/assets/91d342aa-11f9-43c9-b8cb-103e028a1d29)
- 마스터 모델과 BLDC 모터 연결.


![Image](https://github.com/user-attachments/assets/951c3bad-1cb0-4d06-87db-22eef46e52ed)
- 관절 구동 BLDC 모터를 3D프린터로 뽑은 기어를 통해 구동하고자, 기어 플랫폼 제작.

## 주요 관절 제작 및 힘줄 구현
<img width="452" height="481" alt="Image" src="https://github.com/user-attachments/assets/969e25e7-a70e-4926-8a75-3358317789b6" />
<img width="452" height="481" alt="Image" src="https://github.com/user-attachments/assets/00627a68-7e18-4b27-a3ea-912c5ecd0545" />

- <좌| 주요관절 3D프린터 제작>
- <우| 관절에 근육처럼 움직일 수 있도록, 의료테이프 부착>

## 동작 로직
