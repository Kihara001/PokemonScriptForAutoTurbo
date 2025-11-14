#include <auto_command_util.h>

int loadingTime = 15000;

void autoBench() {
  SwitchController().setStickTiltRatio(0, 100, 0, 0);
  delay(500);
  pushButton(Button::A, 100, 50);
  SwitchController().setStickTiltRatio(0, 0, 0, 0);
  delay(loadingTime);
}


void setup() {
  // put your setup code here, to run once:
  // ベンチにAボタンで「時間をつぶす」項目がでたところからマイコンを挿してスタート
  // 最初の数回の入力はswitchが認識しない場合があるので、無駄打ちをしておく
  pushButton(Button::A, 500, 13);

}

void loop() {
  // put your main code here, to run repeatedly:
  autoBench();
}
