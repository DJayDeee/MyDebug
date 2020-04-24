/****************************************************************************************
* File :		MyDebug.cpp
* Date :		2018-Oct-10
* By :			Jean-Daniel Lavoie
* Description :	This library configure the serial port and one led for debuging.
*				It also allow to control the led (off, on and toggle).
****************************************************************************************/

#include	"MyDebug.h"

int	mydebug::led_pin = DEFAULT_LED_PIN;
void Toggle(void) { digitalWrite(mydebug::led_pin, !digitalRead(mydebug::led_pin));	}

// Constructor : 
mydebug::mydebug(const int br, const int pin) {
	led_pin = pin;
	baudrate = br;
}

void mydebug::Init(void) {
 	pinMode(led_pin, OUTPUT);
	blynker.attach(0.6, Toggle);
	
	Serial.begin(baudrate);
	Serial.println(" ");
}

void mydebug::led_OFF(void) {
	digitalWrite(led_pin, HIGH);
}

void mydebug::led_ON(void) {
	digitalWrite(led_pin, LOW);
}

void mydebug::led_Toggle(void) {
	digitalWrite(led_pin, !digitalRead(led_pin));
}
	
void mydebug::setBlynkRate(const float seconds) {
	if(seconds)								// If blynk rate is 0 stop the blynker and let the led on.
		blynker.attach(seconds, Toggle);
	else {
		blynker.detach();
		led_OFF();
	}
}
	
void mydebug::handleWifiBlynk(void)	{
	if ( WiFi.isConnected() != last_wifistate){	// Change led blynk state only if WiFi status change.
		last_wifistate = WiFi.isConnected();
		if (!last_wifistate) {				// Led blynk slowly if WiFi is disconnected.
		  setBlynkRate(1);
		  WiFi.begin();
		} else								// Led on solid if WiFi is connected.
		  setBlynkRate(0);
	}
}