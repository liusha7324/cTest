#ifndef WIRELESS_H
#define WIRELESS_H

//#define	SWITCH_RELAY_DIRECT          pd3_4
//#define	SWITCH_RELAY                 p3_4	//SWITCH_TOGGLE Relay Control Signal
//#define	ALARM_RELAY_DIRECT           pd3_5 
//#define	ALARM_RELAY                  p3_5	/*"±¨¾¯Êä³ö"*/ 
//
//#define	SWITCH_OPEN_DIRECT           pd3_4
//#define	SWITCH_OPEN                  p3_4	//SWITCH_TOGGLE Relay open Signal
//#define	SWITCH_CLOSE_DIRECT        	 pd0_5
//#define	SWITCH_CLOSE                 p0_5	//SWITCH_TOGGLE Relay close Signal

extern void GPRS_Signal_Stength_Lcd_show(void);
extern void Reset_Wireless_State(void);
//extern int Read_event_GPRS(void);	
extern int Set_GPRS_State_Allow(void);
extern int Set_GPRS_State(void);
extern int Get_GPRS_State(void);

//extern unsigned char  uartxcomm;
#endif