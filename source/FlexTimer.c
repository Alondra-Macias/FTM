/**
	\file
	\brief
		This is the starter file of FlexTimer.
		In this file the FlexTimer is configured in overflow mode.
	\author J. Luis Pizano Escalante, luispizano@iteso.mx
	\date	7/09/2014
	\todo
	    Add configuration structures.
 */



#include "FlexTimer.h"
#include "MK64F12.h"
uint16_t edge=0;
uint32_t periodo;


void FTM0_IRQHandler(void){
	periodo=FTM0->CONTROLS[0].CnV-edge;
	edge=FTM0->CONTROLS[0].CnV;

}





void FTM_clk(FTM_channel_t channel){
	switch(channel)
					{
						case (FTM_0):
						/** Clock gating for the FlexTimer 0*/
							SIM->SCGC6 |= FLEX_TIMER_0_CLOCK_GATING;
							break;

						case (FTM_1):
						/** Clock gating for the FlexTimer 1*/
							SIM->SCGC6 |= FLEX_TIMER_1_CLOCK_GATING;
							break;

						case (FTM_2):
						/** Clock gating for the FlexTimer 2*/
							SIM->SCGC6 |= FLEX_TIMER_2_CLOCK_GATING;
							break;

						default:
							break;
					}
}


void FTM_write_protection_disable(FTM_channel_t channel, FTM_WP_DIS_t writeprot){
	switch(channel)
			{
				case (FTM_0):
						if (writeprot)
						{
							/* When write protection is disabled (WPDIS = 1), write protected bits can be written.*/
									FTM0->MODE |= FLEX_TIMER_WPDIS;
									/**Enables the writing over all registers*/
									FTM0->MODE &= ~FLEX_TIMER_FTMEN;
						}
						else
									FTM0->MODE |= ~FLEX_TIMER_WPDIS;
									/**Enables the writing over all registers*/
									FTM0->MODE &= FLEX_TIMER_FTMEN;;
						break;

				case (FTM_1):
								if (writeprot)
								{
									/* When write protection is disabled (WPDIS = 1), write protected bits can be written.*/
											FTM1->MODE |= FLEX_TIMER_WPDIS;
											/**Enables the writing over all registers*/
											FTM1->MODE &= ~FLEX_TIMER_FTMEN;
								}
								else
											FTM1->MODE |= ~FLEX_TIMER_WPDIS;
											/**Enables the writing over all registers*/
											FTM1->MODE &= FLEX_TIMER_FTMEN;;
								break;
					break;

				case (FTM_2):
								if (writeprot)
								{
									/* When write protection is disabled (WPDIS = 1), write protected bits can be written.*/
											FTM2->MODE |= FLEX_TIMER_WPDIS;
											/**Enables the writing over all registers*/
											FTM2->MODE &= ~FLEX_TIMER_FTMEN;
								}
								else
											FTM2->MODE |= ~FLEX_TIMER_WPDIS;
											/**Enables the writing over all registers*/
											FTM2->MODE &= FLEX_TIMER_FTMEN;;
								break;
					break;

				default:
					break;
			}
}
void FTM_counter(FTM_channel_t channel, uint16_t count){
	switch(channel)
				{
					case (FTM_0):
						FTM0->MOD = count;
						break;

					case (FTM_1):
						FTM1->MOD = count;
						break;

					case (FTM_2):
						FTM2->MOD = count;
						break;

					default:
						break;
				}

	}
void FTM_duty_cycle_value(FTM_channel_t channel, FTM_canal_t canal, uint16_t channelValue)
{	switch(channel) {
	case (FTM_0):
			FTM0->CONTROLS[canal].CnV = channelValue;
		break;

	case (FTM_1):
			FTM1->CONTROLS[canal].CnV = channelValue;
		break;

	case (FTM_2):
			FTM2->CONTROLS[canal].CnV = channelValue;
		break;

	default:
		break;
}
}
uint16_t FTM_get_value(){
	return periodo;
}


void FMT_mode_edge_level_selection(FTM_channel_t channel,FTM_canal_t canal, uint8_t mels){
	switch(channel)
				{
					case (FTM_0):
				FTM0->CONTROLS[canal].CnSC = mels;
						break;

					case (FTM_1):
				FTM1->CONTROLS[canal].CnSC = mels;
						break;

					case (FTM_2):
				FTM2->CONTROLS[canal].CnSC = mels;
						break;

					default:
						break;
				}

}
void FTM_timer(FTM_channel_t channel, uint8_t PS, uint8_t clock){
	switch(channel)
{
	case (FTM_0):
		/**Configure the times*/
		FTM0->SC = clock | PS;
		break;

	case (FTM_1):
		FTM1->SC = clock | PS;
		break;

	case (FTM_2):
		FTM2->SC = clock | PS;
		break;

	default:
		break;
}

															}

void FlexTimer_updateCHValue(sint16 channelValue)
{
	/**Assigns a new value for the duty cycle*/
	FTM0->CONTROLS[0].CnV = channelValue;
}
void FlexTimer_Init(const FTM_config_t* FTM_Config)
{	 	PORTC->PCR[1]   = PORT_PCR_MUX(0x4);
//2 salidas por asignar
		FTM_clk(FTM_Config->FTM_channel);
		FTM_write_protection_disable(FTM_Config->FTM_channel, FTM_Config->FTM_WP_DIS);
		FTM_counter(FTM_Config->FTM_channel, FTM_Config->count);
		FMT_mode_edge_level_selection(FTM_Config->FTM_channel,FTM_Config->FTM_canal, FTM_Config->mels);
		FTM_duty_cycle_value(FTM_Config->FTM_channel,FTM_Config->FTM_canal, FTM_Config->channelValue);
		FTM_timer(FTM_Config->FTM_channel, FTM_Config->PS, FTM_Config->clock);

}



