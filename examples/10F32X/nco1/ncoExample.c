/*
 * File:   ncoExample.c
 * Author: Jamie
 *
 * Created on July 22, 2019, 4:25 PM

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

/* Purpose: Demo the NCO options for the PIC10F322 Device */



#include <xc.h>
#include <stdint.h>
#include "deviceconfig.h"
#include "NCO1.h"
#include "OSC.h"

int8_t pinDirection(int8_t pin, int8_t direction);

void main(void) {
    
    cpuFreqSelect(16);
    pinDirection(2,0);
    
    setNCO1ClockSource(2);    
    setNC01IncrementValue(0xFFFF);    
    enableNCO1Output();
    enableNCO1();
    
    
    while(1)
    {
        
    }
  }
