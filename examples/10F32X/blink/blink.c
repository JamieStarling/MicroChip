/*
 * File:  blink.c
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  June 7, 2019, 9:45 PM
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

 * 
 * Purpose : Blinks an LED Connected to PORTA.0 every 1 second
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

//Used to calculate the delay time 
#define _XTAL_FREQ 8000000  //8 MHz (default after Reset)


int8_t pinDirection(int8_t pin, int8_t direction);
int8_t digitalWrite (int8_t pin, int8_t value);

void main ()
{
    //Set Pin 0 PortA.0 as output
     pinDirection(0,0);
    
    //The Forever Loop
    while (1)
    {
        
        //Set PortA.0 High (turn on LED)
        digitalWrite(0,1);        
        
        //Wait 1 second
        __delay_ms(1000);
        
        //Set PortA.0 Low  (turn off LED)
        digitalWrite(0,0);
        
        //Wait 1 second
        __delay_ms(1000);
        
        //End of Loop
        
    }
}


int8_t digitalWrite (int8_t pin, int8_t value)
/*
 * Turns off or on a specific pin.  
 * Usage digitalWrite( pin to control , 1 for on / 0 for off)
 * Returns 0 if success, 1 if failure.   
 * Valid pins for 10F32x are 0 - 2 - pin 3 is always input only.
 * 
 
 */
{ 
    switch (pin)  
    {
        case 0 : //Port RA0
            if (value)  //Turn on if value is 1
            {
                LATAbits.LATA0 = 1;
            }
            else       //Other wise turn off
            {
                LATAbits.LATA0 = 0;
            }
            return 0;
            
        case 1 : //Port RA1
            if (value)  //Turn on if value is 1
            {
                LATAbits.LATA1 = 1;
            }
            else       //Other wise turn off
            {
                LATAbits.LATA1 = 0;
            }
            return 0;  
            
         case 2 : //Port RA2
            if (value)  //Turn on if value is 1
            {
                LATAbits.LATA2 = 1;
            }
            else       //Other wise turn off
            {
                LATAbits.LATA2 = 0;
            }
            return 0;
            
            default : //Value out of range - return 1 includes pin 3 since it is output only
            return 1;            
            
    }
    
}

int8_t pinDirection(int8_t pin, int8_t direction)
/*
 * Sets a pin direction input or output
 * Usage pinDirection (Pin Value , 1 for input or 0 for output)
 * Valid pins for the 10F32X is 0 - 2 - pin 3 is always input
 * The routine also clears the Analog bit for the port
 * Returns 0 if success 1 if failure. 
 
 
 */
{
    switch (pin)
    {
        case 0 : //Port RA0
           ANSELAbits.ANSA0 = 0; //Disable Analog
           if (direction)  //Set Pin as Input
           {
               TRISAbits.TRISA0 = 1;                       
           }
           else
           {
               TRISAbits.TRISA0 = 0;
           }
           return 0;
        
        case 1 : //Port RA1
           ANSELAbits.ANSA1 = 0; //Disable Analog
           if (direction)  //Set Pin as Input
           {
               TRISAbits.TRISA1 = 1;                       
           }
           else
           {
               TRISAbits.TRISA1 = 0;
           }
           return 0;
           
        case 2 : //Port RA2
           ANSELAbits.ANSA2 = 0; //Disable Analog
           if (direction)  //Set Pin as Input
           {
               TRISAbits.TRISA2 = 1;                       
           }
           else
           {
               TRISAbits.TRISA2 = 0;
           }  
           return 0;
           
        case 3 : //Port RA3 - Input only we do nothing
            return 0;
            
        default : //Value out of range - return 1
        return 1;
           
    }
}