# MyDebug
This library configure the serial port and one led for debuging.  It also allow to control the led (off, on and toggle).

## Contents
- [Defines and structures](#defines-and-structures)  
- [Functions](#functions)
- [License and credits](#license-and-credits)

### Defines and structures
* DEFAULT_LED_PIN define is used to select the onboard led pin by default (2).

* DEFAULT_BAUDRATE is serial monitor speed by default (74880).  This speed specially allow to see bootloader informations.

### Functions
* mydebug(const int br, const int pin) instanciate class and set BAUDRATE and LED_PIN.
  * Init()		    Begin the serial connection and 0.6 second led blink.
  * led_OFF()		  Turn led off.
  * led_ON()		  Turn led on.
  * led_Toggle()	Toggle led state.
  * setBlynkRate(seconds) Blink the led for selected time.
  * handleWifiBlynk()     Called during loop() to blink led slowly (1 second) if wifi isn't connected and OFF when connected.

### License and credits
- [Arduino for ESP8266](https://github.com/esp8266/Arduino)
- [Ticker by Ivan Grokhtokov]
