


extern volatile unsigned long TimeCount5ms;
extern volatile unsigned char FirstInterPowerDown;
extern unsigned char pdmode1,pdmode2;
extern unsigned char pdmode3;//ganjp 20090325
extern volatile  unsigned int PowerdownDisplayCyleAdd;
extern volatile unsigned int  PowerdownDisplayOverAdd;  //mw modified 2010-04-30
extern volatile unsigned int  PowerdownStopCommAdd;     //mw modified 2010-04-30
extern volatile unsigned char IntoPowerDownFlag;
extern volatile unsigned char Valid_IntoPowerdown_Flag[8]; 
//extern volatile unsigned char Valid_PD_Curr_Flag[8]; //ganjp 20091104
//mw added 2010-04-30
extern unsigned char keykick;   //mw modified 2010-04-30

//mw added 2010-04-30 
extern void PowerDownDisplayInit(void);
extern void ClearDatePoerDown(void);               //LDH20051225
extern void TimerA2_Int_Interrupt(void);
extern volatile union BYTE_BIT TimeChontrolBeginFlag;  /*"时间点到中间单元"*/
extern void Ad_Converter_Int(void);///king chen add 121214
extern volatile unsigned  char pdmodekeyflag; 
extern volatile unsigned  char PowerdownStopKeyAdd; 
extern volatile unsigned int Powerdown_TempTimeAdd;
extern volatile unsigned char pdopencoverintflag[2];
extern volatile unsigned char farwakeupreadyflag;
extern volatile unsigned char farwakeupreadycnt; 

