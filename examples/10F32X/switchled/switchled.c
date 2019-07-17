/*
 * File:   switchled.c
 * Author: Jamie
 *
 * Created on July 17, 2019, 8:38 AM
 * 
 *  * Copyright 2018 - 2019 Jamie Starling

Free for Personal Use.  
Restricted Commercial Use  : Please Contact Jamie at jamie@jamiestarling.com for Terms.

THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED,INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/
/* 
 * Purpose : Turns on off a LED on  PORTA.0 based on input value on PORTA.1
 * 
 */


#include <xc.h>
#include <stdint.h>
#include "deviceconfig.h"


//Should put this in a header file.. but feeling lazy.
int8_t pinDirection(int8_t pin, int8_t direction);
int8_t digitalWrite (int8_t pin, int8_t value);
int8_t digitalRead (int8_t pin);



void setup()
{
    pinDirection(0, 0); //Set A.0 as output
    pinDirection(1,1); //Set A.1 as input
    digitalWrite (0,0); //Set A.0 to Low
}


void main(void) {
    
    setup();
    
    while(1)
    {
        while (digitalRead(1))
        {
          digitalWrite (0,1);  //Set A.0 High
        }
        
        digitalWrite (0,0);  //Set A.0 Low       
        
    }
    
    
   
}
