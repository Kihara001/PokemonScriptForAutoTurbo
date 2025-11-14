#include <NintendoSwitchControlLibrary.h>

/**
* ポケモンZA、レストラン・ド・フツー自動化
* モミジリサーチの最難関、バトル1000回を達成するためにお使いください
* レストランの戦闘1セット3試合を2分20秒程度で攻略。
* 戦闘ごとの賞金と全勝報酬のちいさなキノコ、参加料3000
* 2160×3+250×5-3000=4730円/1周
* 時給12万くらい。
*
* 手持ちにAボタンにしんそくを割り当てたカイリューを出せる状態にする（たぶん他のポケモンでもOK）
* レストラン受付に話しかけた状態でマイコンを挿してスタート
*
*/

// レストラン・ド・フツーで戦闘を繰り返し。しんそく連打で倒す
// ZL押しっぱなしだと2匹目以降がロックオンされないので、約1秒ごとにZLを押しなおす
void autobattleFutsu(){
    auto &sw = SwitchControlLibrary();

    // ZR 押しっぱなし開始
    sw.pressButton(Button::ZL);
    sw.sendReport();          // ← 状態を送る
    delay(500);               // 押したのを認識させるための少しの待ち

    // ZR を押したまま A を4回ゆっくり押す
    for (int i = 0; i < 4; i++) {
        sw.pressButton(Button::A);
        sw.sendReport();      // ← A+ZR 押下を送る
        delay(100);           // A を押している時間

        sw.releaseButton(Button::A);
        sw.sendReport();      // ← ZRだけ押している状態を送る
        delay(100);           // 次の A までの間隔
    }

    // 最後に ZR を離す
    sw.releaseButton(Button::ZL);
    sw.sendReport();          // ← 何も押していない状態を送る
    delay(100);
}


void setup(){
    // 最初の数回の入力はswitchが認識しない場合があるので、無駄打ちをしておく
    pushButton(Button::A, 500, 13);
}

void loop(){
    autobattleFutsu();
}

