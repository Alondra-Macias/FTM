/**
	\file
	\brief
		This is the header file for the FlexTimer divice driver.
	\author J. Luis Pizano Escalante, luispizano@iteso.mx
	\date	7/09/2014
	\todo
	    Add configuration structures.
 */

#ifndef FLEXTIMER_H_
#define FLEXTIMER_H_


#include "MK64F12.h"
#include "DataTypeDefinitions.h"


#define FLEX_TIMER_0_CLOCK_GATING 0x01000000
#define FLEX_TIMER_1_CLOCK_GATING 0x02000000
#define FLEX_TIMER_2_CLOCK_GATING 0x04000000

#define FLEX_TIMER_FAULTIE  0x80
#define FLEX_TIMER_FAULTM_0   0x00
#define FLEX_TIMER_FAULTM_1   0x20
#define FLEX_TIMER_FAULTM_2   0x40
#define FLEX_TIMER_FAULTM_3   0x60
#define FLEX_TIMER_CAPTEST  0x10
#define FLEX_TIMER_PWMSYNC  0x08
#define FLEX_TIMER_WPDIS    0x04
#define FLEX_TIMER_INIT     0x02
#define FLEX_TIMER_FTMEN    0x01

#define FLEX_TIMER_TOF     0x80
#define FLEX_TIMER_TOIE    0x40
#define FLEX_TIMER_CPWMS   0x20
#define FLEX_TIMER_CLKS_0  0x00
#define FLEX_TIMER_CLKS_1  0x08
#define FLEX_TIMER_CLKS_2  0x10
#define FLEX_TIMER_CLKS_3  0x18
#define FLEX_TIMER_PS_1    0x00
#define FLEX_TIMER_PS_2    0x01
#define FLEX_TIMER_PS_4    0x02
#define FLEX_TIMER_PS_8    0x03
#define FLEX_TIMER_PS_16    0x04
#define FLEX_TIMER_PS_32    0x05
#define FLEX_TIMER_PS_64    0x06
#define FLEX_TIMER_PS_128    0x07

#define FLEX_TIMER_PWMLOAD_CH0 0x01
#define FLEX_TIMER_PWMLOAD_CH1 0x02
#define FLEX_TIMER_PWMLOAD_CH2 0x04
#define FLEX_TIMER_PWMLOAD_CH3 0x08
#define FLEX_TIMER_PWMLOAD_CH4 0x10
#define FLEX_TIMER_PWMLOAD_CH5 0x20
#define FLEX_TIMER_PWMLOAD_CH6 0x40
#define FLEX_TIMER_PWMLOAD_CH7 0x80
#define FLEX_TIMER_LDOK        0x200


#define  FLEX_TIMER_DMA   0x01
#define  FLEX_TIMER_ELSA  0x04
#define  FLEX_TIMER_ELSB  0x08
#define  FLEX_TIMER_MSA   0x10
#define  FLEX_TIMER_MSB   0x20
#define  FLEX_TIMER_CHIE  0x40
#define  FLEX_TIMER_CHF   0x80

typedef enum {FTM_0,
			  FTM_1,
			  FTM_2
			  } FTM_channel_t;
 typedef enum {
 Canal_0,
 Canal_1,
 Canal_2,
 Canal_3,
 Canal_4,
 Canal_5
 } FTM_canal_t;

typedef enum{WP_ENE, WP_DIS} FTM_WP_DIS_t;
 typedef struct
 {				FTM_channel_t FTM_channel;
 	 	 	 	FTM_WP_DIS_t FTM_WP_DIS;
 	 	 	 	FTM_canal_t FTM_canal;
 	 	 	 	uint16_t count;
 	 	 	 	uint16_t channelValue;
 	 	 	 	uint8_t mels;
 	 	 	 	uint8_t PS;
 	 	 	 	uint8_t clock;
			  } FTM_config_t;

void FTM_clk(FTM_channel_t channel);
void FTM_write_protection_disable(FTM_channel_t channel, FTM_WP_DIS_t writeprot);
void FTM_counter(FTM_channel_t channel, uint16_t count);
void FTM_duty_cycle_value(FTM_channel_t channel, FTM_canal_t canal, uint16_t channelValue);
uint16_t FTM_get_value();
void FMT_mode_edge_level_selection(FTM_channel_t channel,FTM_canal_t canal, uint8_t mels);
void FTM_timer(FTM_channel_t channel, uint8_t PS, uint8_t clock);
void FlexTimer_Init(const FTM_config_t* FTM_Config);
void FlexTimer_updateCHValue(sint16 channelValue);



#endif /* FLEXTIMER_H_ */
