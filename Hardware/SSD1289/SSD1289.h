/*
 * SSD1289.h
 *
 *  Created on: 26.12.2018
 *      Author: Sven
 */

#ifndef HARDWARE_SSD1289_SSD1289_H_
#define HARDWARE_SSD1289_SSD1289_H_

/* DriverLib Includes */
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

#include <Hardware/Display.h>

typedef struct _SSD1289_Config
{
	volatile uint16_t * dataOut;
	volatile uint16_t * dataIn;
	volatile uint16_t * dataDir;
	volatile uint16_t * ctrlOut;
	uint16_t csPin;
	uint16_t rsPin;
	uint16_t rdPin;
	uint16_t wrPin;
} SSD1289_Config;

class SSD1289: public Display {
private:
	SSD1289_Config config;

public:
	SSD1289(DIO_PORT_Interruptable_Type * dataPort, DIO_PORT_Interruptable_Type * ctrlPort, uint16_t csPin, uint16_t rsPin, uint16_t rdPin, uint16_t wrPin);

	void Init(void);
	void Fill(uint16_t color, uint32_t count32);

public: // IDisplay
    void Rect(uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint16_t color);
    void Pixel(uint32_t x, uint32_t y, uint16_t color);
	void SetBounds(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
    void Blit16(const uint16_t* d, uint32_t count, bool cont);
};

#endif /* HARDWARE_SSD1289_SSD1289_H_ */