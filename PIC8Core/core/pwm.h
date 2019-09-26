/*
 * File:  pwm.h
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  September 11, 2019, 3:13 PM
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

#ifndef PWM_H
#define	PWM_H

#include <xc.h>
#include <stdint.h>
#include "../PIC8Core.h"


void pwmOut(uint8_t pin, uint16_t dutyCycle);
void setPWMDutyCycle (uint8_t pin, uint8_t duty);



#endif	/* PWM_H */

