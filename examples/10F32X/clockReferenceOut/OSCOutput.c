/*
 * File:   OSCOutput.c
 * Author: Jamie
 *
 * Created on July 22, 2019, 1:46 PM

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
/*
 *Purpose : Configures the device to output a clock signal
 *The clock signal is equal to FSOC/4 
 *A device configure for 8Mhz will output a 2Mhz Clock
 *A device configure for 16Mhz will ourput a 4Mhz Clock
 * 
  
 */






#include <xc.h>
#include <stdint.h>
#include "deviceconfig.h"
#include "OSC.h"






void main(void) {

cpuFreqSelect(16); //Configure Internal OSC to 16Mhz
clockReferenceOut(1); //Enable clock Reference on PortA.2

while(1) //We just hang here
{
    
}

}
