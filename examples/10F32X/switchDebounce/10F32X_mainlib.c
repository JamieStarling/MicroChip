/*
 * File:  10F32X_mainlib.c
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  August 2, 2019, 7:43 AM
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


#include <xc.h>
#include <stdint.h>
#include "deviceconfig.h"
#include "GPIO.h"


uint8_t deBounce(uint8_t pin, uint8_t value);


void main (void)
{
    pinDirection(3,1); //Set PORTA.3 as input
    enableWPUA (3); //Enable Internal Pullup
    
    pinDirection(0,0); //Set PORTA.0 as output - connect LED here
    digitalWrite(0,0);  //Set PORTA.0 Low   
    
    while(1)
    {
        if (!digitalRead (3))   //If PORTA.3 is low
        {
           if (deBounce(3,0))   //Debounce it for true signal 
           {
                digitalWrite(0,1);  //Set LED High
                __delay_ms(1000);   //wait 1000ms
                digitalWrite(0,0);  //Set LED Low
                while (!digitalRead (3));  //hang here if PORTA.3 is still low
           }
        }        
    }       
}
    
    


uint8_t deBounce(uint8_t pin, uint8_t value)
/*Purpose debounces an input pin
 * Requires pin number, and test value
 * returns 1 if signal is true
 * returns 0 if signal was false
 */
{
    if (value == 1)
    {
        __delay_ms (20);  //Wait 20ms to test again
        if (digitalRead (pin))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        __delay_ms (20);   //Wait 20ms to test again
        if (!digitalRead (pin))
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
    }
    
    
    
    
    
    
}