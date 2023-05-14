/*!
 * Params/Tenshi.h - Library for Moe-PCB (Moe Kiban)
 *
 * Copyright (c) 2022-2023 Mizuhasi Yukkie, Onozawa Hiro
 * Released under the MIT license.
 * see https://opensource.org/licenses/MIT
 */

#ifndef Params_Tenshi_h
#define Params_Tenshi_h

#include <stdint.h>
#include <Arduino.h>

// 天子の萌基板パラメータ
class MoePCB_Params_Tenshi
{
public:
  class LED {
  public:
    typedef uint8_t led_index_t;

  public:
    class Placement
    {
    public:
      static constexpr led_index_t Heart       = 0; // LED1 : 胸 (背面)
      static constexpr led_index_t OuterLeft   = 1; // LED2 : 最左
      static constexpr led_index_t Left        = 2; // LED3 : 中左
      static constexpr led_index_t Center      = 3; // LED4 : 中
      static constexpr led_index_t Right       = 4; // LED5 : 中右
      static constexpr led_index_t OuterRight  = 5; // LED6 : 最右
      static constexpr led_index_t SwordBottom = 6; // LED7 : 剣の最下

      static constexpr led_index_t SwordLEDNum = 10; // 剣に配置されたLED個数
    };

  public:
    static constexpr led_index_t Length = 16;
    static constexpr int16_t Port = 6;
  };

  class SubLED {
  public:
    typedef uint8_t pin_t;

  public:
    static constexpr pin_t Pin = 13;
  };

  class Thermometer {

  };

  class TouchSensor {
  public:
    typedef uint8_t touch_sensor_port_t;
    typedef uint8_t touch_sensor_index_t;

  public:
    // 配置場所 -> インデックス
    class Placement
    {
    public:
      static constexpr touch_sensor_index_t Hair  = 0; // タッチセンサ1 : 髪
      static constexpr touch_sensor_index_t Chest = 1; // タッチセンサ2 : 胸
      static constexpr touch_sensor_index_t Skirt = 2; // タッチセンサ3 : スカート
      static constexpr touch_sensor_index_t Sword = 3; // タッチセンサ4 : 剣
    };

    // インデックス -> 接続先ポート
    class Port
    {
    public:
      static constexpr touch_sensor_port_t Hair  = A1; // タッチセンサ1 : 髪
      static constexpr touch_sensor_port_t Chest = A0; // タッチセンサ2 : 胸
      static constexpr touch_sensor_port_t Skirt = A2; // タッチセンサ3 : スカート
      static constexpr touch_sensor_port_t Sword = A3; // タッチセンサ4 : 剣

    public:
      static constexpr touch_sensor_port_t Get(touch_sensor_index_t idx) {
        return idx == 0 ? Hair : (idx == 1 ? Chest : (idx == 2 ? Skirt : 0));
      }
    };

  public:
    static constexpr touch_sensor_index_t Length = 3;
  };
};

#endif
