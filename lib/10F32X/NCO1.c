/*
 * File:  NCO1.c
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  July 22, 2019, 4:27 PM
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
 * Controls NUMERICALLY CONTROLLED OSCILLATOR (NCO) MODULE
 * Output on PortA.2 
 * 
 * To use 
 *   setNCO1ClockSource(2); - Set Clock Source
 *   setNC01IncrementValue(0xFFFF);    -Set Incremental Value
 *   enableNCO1Output();  -Enable Output
 *   enableNCO1(); -Enable NCO
 * 
 * 
 * 
 */


#include <xc.h>
#include <stdint.h>


void setNCO1ClockSource(int8_t clockSelect)
/* Selects the NCO Clock Source
* 11 = LC1OUT            3 - Low Freq CLock
* 10 = HFINTOSC (16 MHz) 2 - HFINTOC 16MHZ Clock
* 01 = FOSC         - 1 FOSC
* 00 = NCO1CLK pin  - 0 NCO1CLK Pin Input
*/
{

switch (clockSelect)
{
    
    case 0:
        NCO1CLKbits.N1CKS = 0b00;
        return;
    case 1:
        NCO1CLKbits.N1CKS = 0b01;
        return;
    case 2:
        NCO1CLKbits.N1CKS = 0b10;
        return;
    case 3:
         NCO1CLKbits.N1CKS = 0b11;
        return;
        
    default:
        return;      
}    
}


void setNC01IncrementValue (uint16_t incrementValue)
/* Sets the NCO Incremental Value using a 16bit number
 * 
 */
{   
    NCO1INC  = incrementValue;
}

void setNC01FrequencyMode (int8_t freqMode)
/* 1 operates in Pulse Frequency mode
 * 0 operates in Fixed Duty Cycle mode */

{
    if (freqMode == 1)
    {
        NCO1CONbits.N1PFM = 1;
    }
    else
    {
         NCO1CONbits.N1PFM = 0;
    }
}

void setNCO1Polarity (int8_t polarity)
{
    if (polarity == 1)
    {
        NCO1CONbits.N1POL = 1;
    }
    else
    {
         NCO1CONbits.N1POL = 0;
    }
    
}

void setNCO1PulseWidth (uint8_t width)
/* Sets the pulse width if used in Pulse Mode*/
{
    
    switch (width)
    {
        case 1:
           NCO1CLKbits.N1PWS = 0b000; 
           return;
        case 2:
           NCO1CLKbits.N1PWS = 0b001; 
           return;
        case 4:
           NCO1CLKbits.N1PWS = 0b010; 
           return;
        case 8:
           NCO1CLKbits.N1PWS = 0b011; 
           return;
        case 16:
           NCO1CLKbits.N1PWS = 0b100; 
           return;
        case 32:
           NCO1CLKbits.N1PWS = 0b101; 
           return;
        case 64:
            NCO1CLKbits.N1PWS = 0b110; 
           return;
        case 128:
            NCO1CLKbits.N1PWS = 0b111; 
           return;
            
        default :
            return;
        
        
    }
}    
    
    
    
    




void enableNCO1(void)
/*
 Enables NCO1  
 */
{
    NCO1CONbits.N1EN = 1;   
}

void disableNCO1(void)
/*
 Disables NCO1  
 */
{
    NCO1CONbits.N1EN = 0;
}

void enableNCO1Output(void)
/* Enables Output on RA.2 */
{
     NCO1CONbits.N1OE = 1;
}

void disableNCO1Output(void)
/* Disables Output on RA.2 */
{
     NCO1CONbits.N1OE = 0;
}