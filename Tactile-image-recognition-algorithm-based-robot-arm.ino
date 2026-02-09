/**************************************************
 * 홀센서 DC 모터 관절 제어 코드
 * - 홀센서 A/B를 이용한 위치(엔코더) 카운트
 * - 목표 위치로 모터를 자동 이동
 * - Arduino UNO 기준
 **************************************************/

/* ================= 핀 정의 ================= */

// 모터 드라이버 제어 핀
#define MOTOR_PWM  9     // 모터 속도 제어 (PWM)
#define MOTOR_DIR  8     // 모터 방향 제어

// 홀 센서 입력 핀 (인터럽트 가능 핀 사용)
#define HALL_A     2     // 홀센서 A
#define HALL_B     3     // 홀센서 B

/* ================= 전역 변수 ================= */

// 엔코더 카운트 값 (인터럽트에서 변경되므로 volatile 필수)
volatile long encoderCount = 0;

// 목표 위치 (엔코더 카운트 기준)
long targetPosition = 1000;

// 모터 기본 속도 (0~255)
int motorSpeed = 120;

/* ================= 인터럽트 함수 ================= */

/*
 * 홀센서 A가 HIGH로 변할 때 실행됨
 * B의 상태를 보고 회전 방향 판단
 */
void hallA_ISR() {
  if (digitalRead(HALL_B) == HIGH) {
    encoderCount++;   // 정방향 회전
  } else {
    encoderCount--;   // 역방향 회전
  }
}

/* ================= 초기 설정 ================= */

void setup() {
  // 모터 제어 핀 설정
  pinMode(MOTOR_PWM, OUTPUT);
  pinMode(MOTOR_DIR, OUTPUT);

  // 홀센서 입력 핀 설정 (내부 풀업 저항 사용)
  pinMode(HALL_A, INPUT_PULLUP);
  pinMode(HALL_B, INPUT_PULLUP);

  // 홀센서 A 상승엣지에서 인터럽트 발생
  attachInterrupt(digitalPinToInterrupt(HALL_A), hallA_ISR, RISING);

  // 시리얼 통신 시작 (디버깅용)
  Serial.begin(9600);

  Serial.println("Hall Sensor Motor Control Start");
}

/* ================= 메인 루프 ================= */

void loop() {
  // 현재 위치와 목표 위치 차이 계산
  long error = targetPosition - encoderCount;

  // 오차가 작으면 정지 (관절 위치 도달)
  if (abs(error) < 10) {
    analogWrite(MOTOR_PWM, 0);   // 모터 정지
  }
  // 목표 위치보다 현재 위치가 작을 때 (정방향 회전)
  else if (error > 0) {
    digitalWrite(MOTOR_DIR, HIGH);   // 방향 설정
    analogWrite(MOTOR_PWM, motorSpeed);
  }
  // 목표 위치보다 현재 위치가 클 때 (역방향 회전)
  else {
    digitalWrite(MOTOR_DIR, LOW);    // 방향 설정
    analogWrite(MOTOR_PWM, motorSpeed);
  }

  // 현재 엔코더 값 출력 (디버깅용)
  Serial.print("Encoder Count: ");
  Serial.println(encoderCount);

  delay(10);   // 너무 빠른 반복 방지
}
