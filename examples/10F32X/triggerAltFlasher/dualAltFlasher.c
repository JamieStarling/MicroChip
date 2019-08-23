/*
 * File:  dualAltFlasher.
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  August 23, 2019, 7:44 AM
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

#define ALTERNATINGTIME 500  //Adjust this value to set the time the LEDs alternate. 

void main (void);
void deviceInit(void);
void altFlash(void); 


void main(void)
{
    deviceInit();    
    
    while(1)
    {
        if (!digitalRead(2))
        {
          altFlash();  
        }       
    }       
}


void deviceInit(void)
{
    pinDirection(0,0); //PORTA.0 Output LED1
    pinDirection(1,0); //PORTA.1 Output LED2
    pinDirection(2,1); //PORTA.2 Input Trigger Active Low
    
    enableWPUA (2);  //Enable WPU on PORTA.2
    
    digitalWrite(0,0);  //Go Ahead make sure PORTA.0 is LOW
    digitalWrite(1,0);  //Go Ahead make sure PORTA.1 is LOW    
}


void altFlash(void)
{
    digitalWrite(0,1);  //PORTA.0 is HIGH
    __delay_ms(ALTERNATINGTIME);
    digitalWrite(0,0);  //PORTA.0 is LOW
    digitalWrite(1,1);  //PORTA.1 is HIGH
    __delay_ms(ALTERNATINGTIME);
    digitalWrite(1,0);  //PORTA.1 is LOW   
}