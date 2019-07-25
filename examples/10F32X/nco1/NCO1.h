/*
 * File:  NCO1.h
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

#ifndef NCO1_H
#define	NCO1_H

void enableNCO1(void);
void disableNCO1(void);
void enableNCO1Output(void);
void disableNCO1Output(void);

void setNCO1ClockSource(int8_t clockSelect);
void setNC01IncrementValue (uint16_t incrementValue);
void setNC01FrequencyMode (int8_t freqMode);
void setNCO1Polarity (int8_t polarity);
void setNCO1PulseWidth (uint8_t width);

#endif	/* NCO1_H */

