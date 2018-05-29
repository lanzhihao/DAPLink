#include "string.h"
#include "stdio.h"
#include "stdint.h"

#include "gd32f10x_gpio.h"
//#include "board.h"
//#include "gpio.h"
#include "uart.h"
//#include "serial.h"
#include "TesterCommandTypes.h"
#include "DAP.h"
#include "stdbool.h"
#include "uart.h"
#include "read_uid.h"

/*
#include "tasks.h"
#include "target_reset.h"
#include "swd_host.h"
#include "info.h"
#include "vfs_manager.h"
#include "settings.h"
#include "daplink.h"
#include "util.h"
#include "DAP.h"
*/

uint8_t cmdRec[10][11] = {"SET_PIN,1;","SET_PIN,2;", "SET_PIN,3;", "SET_PIN,4;", "BUTTON;", "LED;"};
static uint8_t cmd_index = 0;
static char command[CMD_LENGTH];

//d0 pb13 clk, d1 pb14 swdio, d2 pa1 rts, d3 pa0 cts 

void cmdSwclk(void)
{
	GPIO_InitPara  GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin   = GPIO_PIN_13;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUT_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOB, GPIO_PIN_13);	
	
    GPIO_InitStructure.GPIO_Pin   = GPIO_PIN_14;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUT_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_SetBits(GPIOB, GPIO_PIN_14);	
	
    GPIO_InitStructure.GPIO_Pin   = GPIO_PIN_1;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUT_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_SetBits(GPIOA, GPIO_PIN_1);

    GPIO_InitStructure.GPIO_Pin   = GPIO_PIN_0;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUT_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_SetBits(GPIOA, GPIO_PIN_0);		
}

void cmdSwdio(void)
{
    GPIO_InitPara  GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin   = GPIO_PIN_13;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUT_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_SetBits(GPIOB, GPIO_PIN_13);	
	
    GPIO_InitStructure.GPIO_Pin   = GPIO_PIN_14;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUT_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOB, GPIO_PIN_14);	
	
    GPIO_InitStructure.GPIO_Pin   = GPIO_PIN_1;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUT_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_SetBits(GPIOA, GPIO_PIN_1);

    GPIO_InitStructure.GPIO_Pin   = GPIO_PIN_0;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUT_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_SetBits(GPIOA, GPIO_PIN_0);		
}

void cmdRts(void)
{
    GPIO_InitPara  GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin   = GPIO_PIN_13;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUT_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_SetBits(GPIOB, GPIO_PIN_13);	
	
    GPIO_InitStructure.GPIO_Pin   = GPIO_PIN_14;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUT_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_SetBits(GPIOB, GPIO_PIN_14);	
	
    GPIO_InitStructure.GPIO_Pin   = GPIO_PIN_1;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUT_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOA, GPIO_PIN_1);

    GPIO_InitStructure.GPIO_Pin   = GPIO_PIN_0;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUT_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_SetBits(GPIOA, GPIO_PIN_0);		
}

void cmdCts(void)
{
    GPIO_InitPara  GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin   = GPIO_PIN_13;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUT_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_SetBits(GPIOB, GPIO_PIN_13);	
	
    GPIO_InitStructure.GPIO_Pin   = GPIO_PIN_14;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUT_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_SetBits(GPIOB, GPIO_PIN_14);	
	
    GPIO_InitStructure.GPIO_Pin   = GPIO_PIN_1;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUT_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_SetBits(GPIOA, GPIO_PIN_1);

    GPIO_InitStructure.GPIO_Pin   = GPIO_PIN_0;
    GPIO_InitStructure.GPIO_Speed = GPIO_SPEED_50MHZ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUT_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOA, GPIO_PIN_0);		
}

void serialPrint(const char *str)
{
    uart_write_data(str, strlen(str));
}

void serialPrintln(const char *str)
{
	uart_write_data(str, strlen(str));
}

void buttonTest()
{
    static uint16_t cnt_20ms = 0;
    bool buttonState = true;
    while(cnt_20ms++ < 500)
    {
        buttonState = GPIO_ReadInputBit(GPIOB, GPIO_PIN_7);
        Delayms(20);

        if(buttonState == 0)
        {
            GPIO_ResetBits(GPIOB, GPIO_PIN_6);
            serialPrintln(cmdRec[5]);
            break;
        }
    }
    cnt_20ms = 0;
}

void ledTest()
{
    GPIO_ResetBits(GPIOB, GPIO_PIN_6);
}

typedef struct _TesterCommand
{
    const char *name;
    int type;
} TesterCommand;

const TesterCommand commands[] =
{

         {"INFO",               INFO},
         {"",                   END}

};

void printItem(const char *name, const char *value)
{
    serialPrint(name);
    serialPrint(": ");
    serialPrintln(value);
}

void serialPrintIID(const char *str)
{
	uart_write_data(str, strlen(str));	
}

void printID(const char *name, const char *value)
{
    serialPrint(name);
    serialPrint(": ");
    serialPrintIID(value);
}


void printInfo()
{
	uint32_t id[4];
	char strId[24];

	read_unique_id(id);

	sprintf(strId, "%08X%08X%08X", id[0], id[1], id[2]);
    serialPrintln(strId);

}

void cmd_info()
{
    printInfo();
}

void cmd_swdio()
{
    cmdSwdio();
}

void ledFlash()
{
    GPIO_SetBits(GPIOB, GPIO_PIN_6);
    //Delayms(500);
    //GPIO_ResetBits(GPIOB, GPIO_PIN_6);
    //Delayms(500);
}

void checkSerial(char c)
{	
	if(cmd_index == 0)
	{
		memset(command, 0, CMD_LENGTH);
	}
	if(cmd_index < CMD_LENGTH)
	{
		command[cmd_index++] = c;
	}
	else
	{
		cmd_index = 0;
		//memset(command, 0, 10);
	}

	
	if (c != ';') {
		//cmd_index = 0;
        return;
    }
	cmd_index = 0;

	int type = 0;
	if(strcmp(command, "INFO;") == 0)
	{
		type = INFO;
	}
	else if(strcmp(command, cmdRec[0]) == 0)
	{
		type = SET_SWCLK;
	}
	else if(strcmp(command, cmdRec[1]) == 0)
	{
		type = SET_SWDIO;
	}   
	else if(strcmp(command, cmdRec[2]) == 0)
	{
		type = SET_RTS;
	}  
	else if(strcmp(command, cmdRec[3]) == 0)
	{
		type = SET_CTS;
	}            
    else if(strcmp(command, cmdRec[4]) == 0)
    {
        type = BUTTON;
    }
    else if(strcmp(command, cmdRec[5]) == 0)
    {
        type = LED;
    }
    else if(strcmp(command, "RUN;") == 0)
    {
        type = RUN;
    }
    
    switch (type) {
        
        case INFO:
            ledFlash();
            cmd_info();
            break;
        case SET_SWCLK:
            cmdSwclk();
            serialPrintln(cmdRec[0]);
            break;
         case SET_SWDIO:
            cmdSwdio();
            serialPrintln(cmdRec[1]);
            break;  
         case SET_RTS:
            cmdRts();
            serialPrintln(cmdRec[2]);
            break;     
         case SET_CTS:
            cmdCts();
            serialPrintln(cmdRec[3]);
            break;        
         case BUTTON:
            serialPrintln(cmdRec[4]);
            buttonTest();
            break;
         case LED:
            ledTest();
            break;
         case RUN:
             cmd_info();
             break;
        default:
            break;

    }
}

int serialAvailable()
{
	return uart_available();	
}

int serialRead()
{
	uint8_t data;
    uart_read_data(&data, 1);
    return data;
} 

void loop()
{
    //buttonTest();
#if 1
    int c = -1;
    if (serialAvailable()) {
        c = serialRead();
        //char s[2];
        //s[0] = c;
        //s[1] = 0;
        //serialPrint(s);
    }

    if (c != -1) {
        checkSerial((char) c);
    }
#endif
}