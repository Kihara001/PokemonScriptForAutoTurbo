

// --------------------↓以下、設定項目↓--------------------
// 片道を走る時間を設定。ミリ秒。
// 時間を長くするほど湧き範囲が増える（面積当たりの効率は微悪）。長すぎると野生ポケモンからの攻撃が増えて主人公が倒れる可能性があるので注意
// 実際はBダッシュしていない時間があるので設定時間+1秒くらい片道移動する。実際に動かして微調整してください
// Zone20の場合8000~9000程度を推奨
int runningTime = 800;

// ロード時間調整用。休憩中のA連打をしていない時間。
// Switch1or2、2エディションでベンチ休憩時のロード時間が異なる場合はここを調整してください。ミリ秒
// Switch2エディションでは8000程度を推奨
int loadingTime = 7500;


#include <auto_command_util.h>

void autoFrog() {
  SwitchController().setStickTiltRatio(0, -100, 0, 0);
  pushButton(Button::Y, 100);
  delay(700);
  SwitchController().setStickTiltRatio(100, 0, 0, 0);
  pushButton(Button::Y, 100);
    // 走るためB入力
  delay(700);
  SwitchController().setStickTiltRatio(0, 0, 0, 0);
  pushButton(Button::PLUS, 100);
  delay(100);
  SwitchController().setStickTiltRatio(80, -100, 0, 0);
  delay(100);
  SwitchController().setStickTiltRatio(0, 0, 0, 0);
  delay(100);
  // pushButton(Button::Y, 100);
  // delay(100);
  // pushButton(Button::MINUS, 100);

  // for (int i = 0; i < 2; i++) {
  //   pushHatButton(Hat::UP, 10);
  //   delay(10);
  // }

  // pushButton(Button::A, 100);
  // delay(100);

  // for (int i = 0; i < 15; i++) {
  //   pushHatButton(Hat::DOWN, 10);
  //   delay(10);
  // }


  pushButton(Button::A, 100);
  delay(500);
  pushButton(Button::A, 100);

  delay(loadingTime);
}


void setup() {
  // put your setup code here, to run once:
  pushButton(Button::A, 500, 13);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  autoFrog();
}
