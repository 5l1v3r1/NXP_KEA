/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdint.h>
#include "derivative.h"
#include "gpio.h"

static int i = 0;

#define LED_PIN 	PTH1
#define LED_PORT	PTH

#define POWER_AC_EXTERNAL_PORT	LED_PORT
#define POWER_AC_EXTERNAL_BIT	LED_PIN

#define BUTTON_PIN	PTD0
#define BUTTON_PORT PTD

int main(void)
{
	/* Write your code here */
	CONFIG_PIN_AS_GPIO( LED_PORT, LED_PIN, OUTPUT );			// Led pin as output as there is a LED
	CONFIG_PIN_AS_GPIO( BUTTON_PORT, BUTTON_PIN, INPUT );	// Button pin as input as it shall provide a digital value

	ENABLE_INPUT( BUTTON_PORT, BUTTON_PIN );					// Enable input on button

	/* This for loop should be replaced. By default this loop allows a single stepping. */

	int powerState = 0;
	for ( ;; )
	{
		// Read button value
//		bool input = READ_INPUT(BUTTON_PORT, BUTTON_PIN);
//
//		if(input == 1)
//			OUTPUT_SET(LED_PORT, LED_PIN);
//		else
//			OUTPUT_CLEAR(LED_PORT, LED_PIN);

		if ( powerState == 0 )
		{
			OUTPUT_SET( POWER_AC_EXTERNAL_PORT, POWER_AC_EXTERNAL_BIT );
			//setEnableExternalPowerSupply(POWER_ON);
			powerState = 1;
		}
		else
		{
			OUTPUT_CLEAR( POWER_AC_EXTERNAL_PORT, POWER_AC_EXTERNAL_BIT );
			//setEnableExternalPowerSupply(POWER_OFF);
			powerState = 0;
		}

		/* Read pin state */
		//power_state_t externalPowerState = getExternalPowerState();
		CONFIG_PIN_AS_GPIO( POWER_AC_EXTERNAL_PORT, POWER_AC_EXTERNAL_BIT, INPUT );
		ENABLE_INPUT( POWER_AC_EXTERNAL_PORT, POWER_AC_EXTERNAL_BIT );
		int result = READ_INPUT( POWER_AC_EXTERNAL_PORT, POWER_AC_EXTERNAL_BIT );
		CONFIG_PIN_AS_GPIO(  POWER_AC_EXTERNAL_PORT, POWER_AC_EXTERNAL_BIT, OUTPUT );

		int breakpoint = 0;

	}
	/* Never leave main */
	return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
