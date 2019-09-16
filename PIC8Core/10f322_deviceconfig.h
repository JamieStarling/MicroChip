/*
 * File:  10F322_deviceconfig.h
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


#pragma config FOSC = INTOSC  // Oscillator Selection 
#pragma config BOREN = ON    // Brown-out Reset
#pragma config WDTE = OFF    // Watchdog Timer
#pragma config PWRTE = ON    // Power-up Timer
#pragma config MCLRE = OFF   // MCLR Pin Function Select bit->MCLR pin function is digital input, MCLR internally tied to VDD
#pragma config CP = OFF      // Code Protection 
#pragma config LVP = OFF     // Low-Voltage Programming 
#pragma config LPBOR = ON    // Brown-out Reset Selection bits
#pragma config BORV = LO    // Brown-out Reset Voltage Selection
#pragma config WRT = OFF    // Flash Memory Self-Write Protection



//Used to calculate the delay time - Change depending on processor Speed
#define _XTAL_FREQ 8000000  //8 MHz (default after Reset)



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

#define MAXIOPINS 4

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3  //10F32x PIN 3 is always input only



/******************GPIO Defines - Used with gpio.c*/


const uint8_t PIN_BIT_MASK_PGM[] = 
{
    0b00000001,
    0b00000010,
    0b00000100,
    0b00001000,     
};

const uint16_t PIN_TO_DIRECTION_REGISTER_PGM[] =
{
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
};


const uint16_t PIN_TO_PORT_WRITE_REGISTER_PGM[] =
{
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
};


/******************CPU OSCILATOR used with osc.c*/

#define MHZ16  0b00000111
#define MHZ8   0b00000110
#define MHZ4   0b00000101
#define MHZ2   0b00000100
#define MHZ1   0b00000011
#define KHZ500 0b00000010
#define KHZ250 0b00000001
#define KHZ31  0b00000000

#define OSCILATOR_SPEEDCONTROL_REGISTER OSCCONbits.IRCF
#define CLOCK_REFERENCE_OUT_ENABLE CLKRCONbits.CLKROE = 1
#define CLOCK_REFERENCE_OUT_DISABLE CLKRCONbits.CLKROE = 0


/******************PWM Defines used with pwm.c*/
#if _XTAL_FREQ == 8000000 /** 8MHz = PWM Frequency 19.61 kHz 8bits Duty*/
#define PWM1_ENABLE  PR2 = 0x65;T2CONbits.T2CKPS = 0b00;T2CONbits.TMR2ON = 0x01;PWM1CONbits.PWM1OE = 0x01;PWM1CONbits.PWM1EN = 0x01;
#endif

#if _XTAL_FREQ == 16000000  /**16Mhz = PWM Frequency  15.7 kHz 10bits  Duty*/
#define PWM1_ENABLE PR2 = 0xFF;T2CONbits.T2CKPS = 0b00;T2CONbits.TMR2ON = 0x01;PWM1CONbits.PWM1OE = 0x01;PWM1CONbits.PWM1EN = 0x01;
#endif