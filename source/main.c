/*
 * Copyright 2016-2018 NXP Semiconductor, Inc.
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
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
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
 
/**
 * @file    main.c
 * @brief   Application entry point.
 */

#include "stdint.h"
#include "FlexTimer.h"
#include "GPIO.h"
#include "Delay.h"
#define MAX_COUNT_OUTPUT_TOGGL 0x04
#define CHANNEL_VALUE 0x03


int main()
{



	const FTM_config_t g_ftm_toggle_conf = {
								FTM_0,
								WP_DIS,
								Canal_0,
								MAX_COUNT_OUTPUT_TOGGL,  //count
								CHANNEL_VALUE,    //CnV
								FLEX_TIMER_MSA | FLEX_TIMER_ELSA,
								FLEX_TIMER_CLKS_1,
								FLEX_TIMER_PS_2
	};


	const FTM_config_t g_ftm_compSet_conf = {
									FTM_0,
									WP_DIS,
									Canal_0,
									41015u,  //count
									CHANNEL_VALUE,    //CnV
									FLEX_TIMER_MSA | FLEX_TIMER_ELSA | FLEX_TIMER_ELSB,
									FLEX_TIMER_CLKS_1,
									FLEX_TIMER_PS_128
		};



	const FTM_config_t g_ftm_compClear_conf = {
										FTM_0,
										WP_DIS,
										Canal_0,
										41015u,  //count
										CHANNEL_VALUE,    //CnV
										(FLEX_TIMER_MSA | FLEX_TIMER_ELSB) & ~FLEX_TIMER_ELSA,
										FLEX_TIMER_CLKS_1,
										FLEX_TIMER_PS_128
			};
		FlexTimer_Init(&g_ftm_toggle_conf);
		delay(20000);
		FlexTimer_Init(&g_ftm_compSet_conf);




while(1){


}

}
