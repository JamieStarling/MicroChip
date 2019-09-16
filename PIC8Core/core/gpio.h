/*
 * File:  gpio.h
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  September 6, 2019, 4:45 PM
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

#ifndef GPIO_H
#define	GPIO_H

#include <xc.h>
#include <stdint.h>
#include "../PIC8Core.h"


void pinMode(uint8_t pin, uint8_t direction);
void digitalWrite (uint8_t pin, uint8_t value);
uint8_t digitalRead (uint8_t pin);
void digitalToggle (uint8_t pin);
#endif	/* GPIO_H */

