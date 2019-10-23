/*
 * File:  16F15313_deviceconfig.h
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  September 6, 2019, 9:45 PM
 * 
 * Copyright 2018 - 2019 Jamie Starling

Free for Personal Use.  
Restricted Commercial Use  : Please Contact Jamie at jamie@jamiestarling.com for Terms.

THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED,INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

 * 
 * Purpose : Provides Standard Configuration for 10F32X devices
 * 
 */


#include <xc.h>
#include <stdint.h>

#ifndef DEVICECONFIG_H
#define	DEVICECONFIG_H

// Configuration bits: 

// CONFIG1
#pragma config FEXTOSC = OFF    // External Oscillator mode selection bits->Oscillator not enabled
#pragma config RSTOSC = HFINTPLL    // Power-up default value for COSC bits->HFINTOSC with 2x PLL, with OSCFRQ = 16 MHz and CDIV = 1:1 (FOSC = 32 MHz)
#pragma config CLKOUTEN = OFF    // Clock Out Enable bit->CLKOUT function is disabled; i/o or oscillator function on OSC2
#pragma config CSWEN = ON    // Clock Switch Enable bit->Writing to NOSC and NDIV is allowed
#pragma config FCMEN = ON    // Fail-Safe Clock Monitor Enable bit->FSCM timer enabled

// CONFIG2
#pragma config MCLRE = OFF    // Master Clear Enable bit->MCLR pin function is port defined function
#pragma config PWRTE = ON    // Power-up Timer Enable bit->PWRT enabled
#pragma config LPBOREN = OFF    // Low-Power BOR enable bit->ULPBOR disabled
#pragma config BOREN = ON    // Brown-out reset enable bits->Brown-out Reset Enabled, SBOREN bit is ignored
#pragma config BORV = LO    // Brown-out Reset Voltage Selection->Brown-out Reset Voltage (VBOR) set to 1.9V on LF, and 2.45V on F Devices
#pragma config ZCD = OFF    // Zero-cross detect disable->Zero-cross detect circuit is disabled at POR.
#pragma config PPS1WAY = ON    // Peripheral Pin Select one-way control->The PPSLOCK bit can be cleared and set only once in software
#pragma config STVREN = ON    // Stack Overflow/Underflow Reset Enable bit->Stack Overflow or Underflow will cause a reset

// CONFIG3
#pragma config WDTCPS = WDTCPS_31    // WDT Period Select bits->Divider ratio 1:65536; software control of WDTPS
#pragma config WDTE = OFF    // WDT operating mode->WDT Disabled, SWDTEN is ignored
#pragma config WDTCWS = WDTCWS_7    // WDT Window Select bits->window always open (100%); software control; keyed access not required
#pragma config WDTCCS = SC    // WDT input clock selector->Software Control

// CONFIG4
#pragma config BBSIZE = BB512    // Boot Block Size Selection bits->512 words boot block size
#pragma config BBEN = OFF    // Boot Block Enable bit->Boot Block disabled
#pragma config SAFEN = OFF    // SAF Enable bit->SAF disabled
#pragma config WRTAPP = OFF    // Application Block Write Protection bit->Application Block not write protected
#pragma config WRTB = OFF    // Boot Block Write Protection bit->Boot Block not write protected
#pragma config WRTC = OFF    // Configuration Register Write Protection bit->Configuration Register not write protected
#pragma config WRTSAF = OFF    // Storage Area Flash Write Protection bit->SAF not write protected
#pragma config LVP = OFF    // Low Voltage Programming Enable bit->High Voltage on MCLR/Vpp must be used for programming

// CONFIG5
#pragma config CP = OFF    // UserNVM Program memory code protection bit->UserNVM code protection disabled



//Used to calculate the delay time - Change depending on processor Speed
#define _XTAL_FREQ 32000000

/*Standard Defines*/

/*EQU 0*/
#define OFF 0x00
#define FALSE 0x00
#define LOW 0x00
#define OUTPUT 0x00


/*EQU 1*/
#define ON  0x01
#define TRUE 0x01
#define HIGH 0x01
#define INPUT 0x01

#define MAXIOPINS 6

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3  
#define PIN4 4
#define PIN5 5


/******************GPIO Defines - Used with gpio.c*/


const uint8_t PIN_BIT_MASK_PGM[] = 
{
    0b00000001,
    0b00000010,
    0b00000100,
    0b00001000,    //Input Only
    0b00010000,
    0b00100000,
};

const uint16_t PIN_TO_DIRECTION_REGISTER_PGM[] =
{
	 (uint16_t) &TRISA,
	 (uint16_t) &TRISA,
	 (uint16_t) &TRISA,
     (uint16_t) &TRISA,
     (uint16_t) &TRISA,
     (uint16_t) &TRISA,
     
};

const uint16_t PIN_TO_ANALOG_REGISTER_PGM[] =
{
	 (uint16_t) &ANSELA,
	 (uint16_t) &ANSELA,
	 (uint16_t) &ANSELA,
     (uint16_t) &ANSELA,
     (uint16_t) &ANSELA,
     (uint16_t) &ANSELA,
};


const uint16_t PIN_TO_PORT_WRITE_REGISTER_PGM[] =
{
	 (uint16_t) &LATA,
	 (uint16_t) &LATA,
	 (uint16_t) &LATA,
     (uint16_t) &LATA,
     (uint16_t) &LATA,
     (uint16_t) &LATA,
     
};

const uint16_t PIN_TO_PORT_READ_REGISTER_PGM[] =
{
	 (uint16_t) &PORTA,
	 (uint16_t) &PORTA,
	 (uint16_t) &PORTA,
     (uint16_t) &PORTA,
     (uint16_t) &PORTA,
     (uint16_t) &PORTA,
};




#endif	/* DEVICECONFIG_H */