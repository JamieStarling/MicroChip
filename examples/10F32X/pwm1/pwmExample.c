/*
 * File:  pwmExample.c
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  July 28, 2019, 3:24 PM
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
#include "pwm1.h"
#include "OSC.h"



void main (void)
{
    cpuFreqSelect(16);
    pinDirection(0, 0);  //Set PORTA.0 as output
    resetPWM1();  //Reset PWM1 
    enablePWM1();
    setPWM1DutyCycle(512);
  
      while(1)
    {
        
    }
    
}