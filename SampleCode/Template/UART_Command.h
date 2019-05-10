
#include <stdio.h>
#include <string.h>

#include "NuMicro.h"

#if 1	// from Function_Define.h
//16 --> 8 x 2
#define HIBYTE(v1)              		((unsigned char)((v1)>>8))                      //v1 is UINT16
#define LOBYTE(v1)              		((unsigned char)((v1)&0xFF))
//8 x 2 --> 16
#define MAKEWORD(v1,v2)         	((((unsigned short)(v1))<<8)+(unsigned short)(v2))      //v1,v2 is UINT8
//8 x 4 --> 32
#define MAKELONG(v1,v2,v3,v4)   	(unsigned long)((v1<<32)+(v2<<16)+(v3<<8)+v4)  //v1,v2,v3,v4 is UINT8
//32 --> 16 x 2
#define YBYTE1(v1)              		((unsigned short)((v1)>>16))                    //v1 is UINT32
#define YBYTE0(v1)              		((unsigned short)((v1)&0xFFFF))
//32 --> 8 x 4
#define TBYTE3(v1)              		((unsigned char)((v1)>>24))                     //v1 is UINT32
#define TBYTE2(v1)              		((unsigned char)((v1)>>16))
#define TBYTE1(v1)              		((unsigned char)((v1)>>8)) 
#define TBYTE0(v1)              		((unsigned char)((v1)&0xFF))
#endif


#define UARTCMD_HEADER							(0x34)	//customize
#define UARTCMD_TAILER							(0x81)	//customize
#define UARTCMD_DATA_LEN						(4)		//customize

typedef enum
{
	UARTCMD_1_BYTE_DATA = 1,
	UARTCMD_2_BYTE_DATA = 2,	
	UARTCMD_3_BYTE_DATA = 3,
	UARTCMD_4_BYTE_DATA = 4,
	
	UARTCMD_BYTE_MAX,
}UARTCMD_BYTE_DATA;	//customize , because UARTCMD_DATA_LEN define 4


//extern UART CMD variable
extern uint8_t u8UartRxCnt;
extern uint8_t u8SetProcessPkt;

void UartCmd_Rx_Receive(uint8_t tmp);
void UartCmd_Send(uint8_t *pui1_data ,uint8_t z_len );
void UART0_Process(void);

