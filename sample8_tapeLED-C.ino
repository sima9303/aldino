#include <SpresenseNeoPixel.h>

const uint16_t PIN = 6;            // データを送信するピン番号
const uint16_t NUM_PIXELS = 40;    // 制御するLEDの数

SpresenseNeoPixel<PIN, NUM_PIXELS> neopixel;
//SpresenseNeoPixelライブラリの機能を使う
//｢PIN｣と｢NUM_PIXELS｣の値を使って、LEDを制御する準備をする
//制御用の関数は、上記で用意した｢neopixel｣という名前を活用して用いる

// LEDがテープ上を1つ往復するサンプル

void setup(){
  neopixel.clear();
}

void loop(){
  // ｢⌘+/｣ でコメント状態を切り替えながら動かしてみよう
  round_trip(); 
  round_trip_doubleight();
  switch_odd_even();
}

void round_trip(){ //左右を1つの光が往復するサンプル
  for( int i = 0; i < NUM_PIXELS; i++ ){
    neopixel.set( i, 150, 80, 30 );   // 赤色に設定
    neopixel.show();                // LEDに反映
    delay( 50 );                    // 0.05秒待つ
    neopixel.clear();               // 光を消す
  }
  for( int i = 0; i < NUM_PIXELS; i++ ){
    neopixel.set( NUM_PIXELS - i , 125, 70, 10 );   // 赤色に設定
    neopixel.show();                // LEDに反映
    delay( 50 );                    // 0.05秒待つ
    neopixel.clear();               // 光を消す
  }
}

void round_trip_doubleight(){ //左右を1つの光が2回ずつ点滅して往復するサンプル
  for( int i = 0; i < NUM_PIXELS; i++ ){
    for( int j = 0; j < 2; j++ ){
      neopixel.set( i, 20, 100, 50 );   // 赤色に設定
      neopixel.show();                // LEDに反映
      delay( 50 );                    // 0.05秒待つ
      neopixel.clear();               // 光を消す設定
      neopixel.show();                // LEDに反映
      delay( 50 );                    // 0.05秒待つ
    }
  }
  for( int i = 0; i < NUM_PIXELS; i++ ){
    for( int j = 0; j < 2; j++ ){
      neopixel.set( NUM_PIXELS - i, 0, 100, 30 );   // 赤色に設定
      neopixel.show();                // LEDに反映
      delay( 50 );                    // 0.05秒待つ
      neopixel.clear();               // 光を消す設定
      neopixel.show();                // LEDに反映
      delay( 50 );                    // 0.05秒待つ
    }
  }
}

void switch_odd_even(){ //奇数番目と偶数番目が別々の色で交互に点灯するサンプル
  for( int i = 0; i < NUM_PIXELS; i = i + 2 ){
    neopixel.set( i, 20, 60, 100 ); // 赤色に設定
  }
  neopixel.show();                // 設定を反映
  delay( 200 );                   // 0.2秒待つ
  neopixel.clear();               // 光を消す設定
  neopixel.show();                // 設定を反映
  delay( 200 );                   // 0.2秒待つ
  for( int i = 1; i < NUM_PIXELS - 1; i = i + 2 ){
    neopixel.set( i, 0, 20, 0 );  // 赤色に設定
  }
  neopixel.show();                // 設定を反映
  delay( 200 );                   // 0.2秒待つ
  neopixel.clear();               // 光を消す設定
  neopixel.show();                // 設定を反映
  delay( 200 );                   // 0.2秒待つ
}
