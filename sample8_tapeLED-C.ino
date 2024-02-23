#include <SpresenseNeoPixel.h>

const uint16_t PIN = 6;            // データを送信するピン番号
const uint16_t NUM_PIXELS = 40;    // 制御するLEDの数

SpresenseNeoPixel<PIN, NUM_PIXELS> neopixel;

//セットアップ
void setup(){
  neopixel.clear();　//すべてのLEDを消す
}

//メインループ
void loop(){　//サンプル関数の実行
  round_trip(); 
  round_trip_doubleight();
  switch_odd_even();
}

//往復点灯
void round_trip(){ //0からNUMPIXELS-1までroop
  for( int i = 0; i < NUM_PIXELS; i++ ){
    neopixel.set( i, 150, 80, 30 );   
    neopixel.show();                
    delay( 50 );                    
    neopixel.clear();              
  }
  for( int i = 0; i < NUM_PIXELS; i++ ){
    neopixel.set( NUM_PIXELS - i , 125, 70, 10 );   // LEDをオレンジに設定
    neopixel.show();                // LEDに反映
    delay( 50 );                    // 0.05秒(50ミリ秒)待つ
    neopixel.clear();               // LED消灯
  }
}

void round_trip_doubleight(){ //往復点灯(2回転灯)
  for( int i = 0; i < NUM_PIXELS; i++ ){　//0からNUM_PIXELS-1までループ
    for( int j = 0; j < 2; j++ ){
      neopixel.set( i, 20, 100, 50 );   // ピンク色に設定
      neopixel.show();                // LEDに設定を反映
      delay( 50 );                    // 0.05(50ミリ)秒待つ
      neopixel.clear();               // LEDを消灯
      neopixel.show();                // LEDに反映
      delay( 50 );                    // 0.05(50ミリ)秒待つ
    }
  }
  for( int i = 0; i < NUM_PIXELS; i++ ){
    for( int j = 0; j < 2; j++ ){
      neopixel.set( NUM_PIXELS - i, 0, 100, 30 );   // 紫色に設定
      neopixel.show();                // LEDに反映
      delay( 50 );                    // 0.05(50ミリ)秒待つ
      neopixel.clear();               // 光を消す設定
      neopixel.show();                // LEDに設定を反映
      delay( 50 );                    // 0.05(50ミリ)秒待つ
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
  delay( 200 );                   // 0.2(200ミリ)秒待つ
  for( int i = 1; i < NUM_PIXELS - 1; i = i + 2 ){
    neopixel.set( i, 0, 20, 0 );  
  }
  neopixel.show();                // 設定を反映
  delay( 200 );                   // 0.2(200ミリ)秒待つ
  neopixel.clear();               // 光を消す設定
  neopixel.show();                // 設定を反映
  delay( 200 );                   // 0.2(200ミリ)秒待つ
}
