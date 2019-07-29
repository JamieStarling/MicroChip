/*
 * File:  pwm1.c
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  July 28, 2019, 3:25 PM
 * 
 * Copyright 2018 - 2019 Jamie Starling

Free for Personal Use.  
Restricted Commercial Use  : Please Contact Jamie at jamie@jamiestarling.com for Terms.

THE SOFTWARE IS PROVIDED ?AS IS?, WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED,INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

 */
/*
 *  PWM setup and routines for PIC - 10F322
 *  PWM1 is on PORTA.0
 */


#include <xc.h>
#include <stdint.h>
#include "deviceconfig.h"
#include "pwm1.h"



void setPWM1DutyCycle (uint16_t duty)
/*
 * Sets the duty cycle of the PWM Output
 * At 8Mhz the valid range is 0 - 408 with 204 being 50% duty cycle
 * At 16Mhz the valid range is 0 -  1024 with 512 being 50% duty cycle
 * Dutyvalue = (desired% / 100) * 4(PR2 Value + 1)
 * PR2 at 8Mhz is 101(dec)
 * PR2 at 16Mhz is 255(dec)
 */
{
    PWM1DCL =  ((duty & 0b11) << 0x06);  //Get the LSB
    PWM1DCH = (duty >> 0x02);    //Get the MSB
}


void resetPWM1 (void)
/*
 *Performs a rest of PWM1 - 
 */
{
    PWM1CON = 0x00;
    PR2 = 0x00;
    PWM1DCL = 0x00;
    PWM1DCH = 0x00;
    T2CONbits.TMR2ON = 0x00;  
    PIR1bits.TMR2IF = 0x00;    
}

void enablePWM1 (void)
/*
 * Will enable the PWM1 - based on _XTAL_FREQ for max bit depth max frequency
 * 8MHz = PWM Frequency 19.61 kHz 8bits Duty
 * 16Mhz = PWM Frequency  15.7 kHz 10bits  Duty 
 */
{
    if (_XTAL_FREQ == 16000000)
    {
        PR2 = 0xFF; 
        T2CONbits.T2CKPS = 0b00;  //Set Prescale Select to 1
        T2CONbits.TMR2ON = 0x01;  //Timer 2 on
        PWM1CONbits.PWM1OE = 0x01;  //Enable PWM output
        PWM1CONbits.PWM1EN = 0x01;  //Enable PWM        
    }
    else
    {
        PR2 = 0x65; 
        T2CONbits.T2CKPS = 0b00;  //Set Prescale Select to 1
        T2CONbits.TMR2ON = 0x01;  //Timer 2 on
        PWM1CONbits.PWM1OE = 0x01;  //Enable PWM output
        PWM1CONbits.PWM1EN = 0x01;  //Enable PWM        
        
    }       
}

void disablePWM1Output(void)
/*
 *Disables PWM output 
 */
{
    PWM1CONbits.PWM1OE = 0x00;
}

void enablePWM1Output(void)
/*
 *Enables PWM output
 */
{
    PWM1CONbits.PWM1OE = 0x01;
}