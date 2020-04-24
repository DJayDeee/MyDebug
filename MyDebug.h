/****************************************************************************************
* File :		MyDebug.h
* Date :		2018-Oct-10
* By :			Jean-Daniel Lavoie
* Description :	This library configure the serial port and one led for debuging.
*				It also allow to control the led (off, on and toggle).
****************************************************************************************/

#ifndef		_MYDEBUG_H_
#define		_MYDEBUG_H_

#include	<ESP8266WiFi.h>					//https://github.com/esp8266/Arduino
#include	<Ticker.h>						// Timer manager

#define	DEFAULT_LED_PIN		2
#define	DEFAULT_BAUDRATE	74880

class mydebug {
  public:
	mydebug(const int br = DEFAULT_BAUDRATE, const int pin = DEFAULT_LED_PIN);
	void	Init(void);

	void	led_OFF(void);
	void	led_ON(void);
	void	led_Toggle(void);
		
	void	setBlynkRate(const float seconds);
	void	handleWifiBlynk(void);
	
	static int		led_pin;
  private:
	Ticker	blynker;
	int		baudrate;
	int 	last_wifistate;
};

#endif // _MYDEBUG_H_
