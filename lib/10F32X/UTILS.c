/*
 * File:  utils.c
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  August 12, 2019, 11:23 AM
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
#include "UTILS.h"
#include "GPIO.h"



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