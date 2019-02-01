
//-------------------------------- 包含的头文件 --------------------------
#include "DIALOG.h"
#include "includes.h"
//------------------------------ 窗口的图标 -----------------------
#define UTF8_KEY_CONTROL     "\xe6\x8c\x89\xe9\x94\xae\xe6\x8e\xa7\xe5\x88\xb6LED\xe4\xba\xae\xe7\x81\xad"  //按键控制LED亮灭
#define UTF8_LED      					"\xe6\xb5\x81\xe6\xb0\xb4\xe7\x81\xaf"   //流水灯
#define UTF8_TOUCH_CAL      	"\xe8\xa7\xa6\xe6\x91\xb8\xe5\x81\x8f\xe5\xb7\xae\xe5\xa4\xa7\xe6\x89\x8d\xe9\x9c\x80\xe8\xa6\x81\xe8\xa7\xa6\xe6\x91\xb8\xe6\xa0\xa1\xe5\x87\x86"     //触摸偏差大才需要触摸校准
#define UTF8_CAL_BUTTON       "\xe8\xa7\xa6\xe6\x91\xb8\xe6\xa0\xa1\xe5\x87\x86"//触摸校准
//
#define ID_FRAMEWIN_0      	(GUI_ID_USER + 0x00)
#define ID_TEXT_0      		(GUI_ID_USER + 0x01)
#define ID_TEXT_1      		(GUI_ID_USER + 0x02)
#define ID_TEXT_2      		(GUI_ID_USER + 0x03)
#define ID_TEXT_3      		(GUI_ID_USER + 0x04)
#define ID_TEXT_4      		(GUI_ID_USER + 0x05)
//

char text1[30]={0};
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, 	"Framewin", ID_FRAMEWIN_0, 	0, 0, 	240, 320,   0, 0x64, 	0 },
  { TEXT_CreateIndirect, 		"Text", ID_TEXT_0, 			0, 40, 	230, 20, 	0, 0x0, 	0 },
  { TEXT_CreateIndirect,  		"Text", ID_TEXT_1, 			0, 100, 230, 20, 	0, 0x0, 	0 },
  { TEXT_CreateIndirect, 		"Text", ID_TEXT_2, 			0, 160, 230, 20, 	0, 0x0, 	0 },
  { TEXT_CreateIndirect, 		"Text", ID_TEXT_3, 			0, 220, 230, 20, 	0, 0x0, 	0 },
  { TEXT_CreateIndirect, 		"Text", ID_TEXT_4, 			0, 280, 230, 20, 	0, 0x0, 	0 },
};
//
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
	OS_ERR         err;
	CPU_INT16U     version;
	CPU_INT32U     cpu_clk_freq;
	
	version = OSVersion(&err);
	cpu_clk_freq = BSP_CPU_ClkFreq();
  switch (pMsg->MsgId) {
	case WM_DELETE:
			tpad_flag=0;
			UserApp_Running = 0;	
		break;
  case WM_INIT_DIALOG:
   hItem = pMsg->hWin;
		FRAMEWIN_SetFont(hItem,&FONT_XINSONGTI_16);
    FRAMEWIN_SetText(hItem,UTF8_BTN0_TEXT);
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
		FRAMEWIN_AddCloseButton(hItem,FRAMEWIN_BUTTON_RIGHT,0);	
		//--------------------------------------
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);		
		TEXT_SetFont(hItem, &FONT_XINSONGTI_16);
		TEXT_SetTextColor(hItem,GUI_BLUE);
		sprintf(text1,"uC/OS\xe7\x89\x88\xe6\x9c\xac\xe5\x8f\xb7\xef\xbc\x9a V%d.%02d.%02d",version/10000, version%10000/100, version%100);
		TEXT_SetText(hItem,text1);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);		
		TEXT_SetFont(hItem, &FONT_XINSONGTI_16);
		TEXT_SetTextColor(hItem,GUI_BLUE);
		sprintf(text1,"CPU\xe4\xbd\xbf\xe7\x94\xa8\xe7\xbb\x9f\xe8\xae\xa1\xef\xbc\x9a%02d.%02d",OSStatTaskCPUUsage/100, OSStatTaskCPUUsage%100);
		TEXT_SetText(hItem,text1);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);		
		TEXT_SetFont(hItem, &FONT_XINSONGTI_16);
		TEXT_SetTextColor(hItem,GUI_BLUE);
		sprintf(text1,"CPU\xe4\xb8\xbb\xe9\xa2\x91\xef\xbc\x9a%dMHz",cpu_clk_freq/1000000);
		TEXT_SetText(hItem,text1);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);		
		TEXT_SetFont(hItem, &FONT_XINSONGTI_16);
		TEXT_SetTextColor(hItem,GUI_BLUE);
		sprintf(text1,"\xe4\xbb\xbb\xe5\x8a\xa1\xe5\x88\x87\xe6\x8d\xa2\xe6\x80\xbb\xe6\xac\xa1\xe6\x95\xb0\xef\xbc\x9a%d",OSTaskCtxSwCtr);
		TEXT_SetText(hItem,text1);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);		
		TEXT_SetFont(hItem, &FONT_XINSONGTI_16);
		TEXT_SetTextColor(hItem,GUI_BLUE);
		sprintf(text1,"\xe7\x9b\xae\xe5\x89\x8d\xe6\x80\xbb\xe5\x85\xb1\xe6\x9c\x89\xef\xbc\x9a%d\xe4\xb8\xaa\xe4\xbb\xbb\xe5\x8a\xa1", OSTaskQty);
		TEXT_SetText(hItem,text1);
    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}
//----------------------------------------------
void CreateFramewin(void) {
 WM_HWIN hWin;
	OS_ERR  os_err;	
	hWin=GUI_CreateDialogBox(   _aDialogCreate, 
						GUI_COUNTOF(_aDialogCreate),
						_cbDialog,
						WM_HBKWIN, 
						0, 
						0);
	while(UserApp_Running)
	{	
			//等待按键
		 if(OSFlagPend ((OS_FLAG_GRP *)&key_flag_grp,                  
						(OS_FLAGS     )( EVEN_KEY1_DOWN ),
						(OS_TICK      )0,
						(OS_OPT       )OS_OPT_PEND_FLAG_SET_ALL |
									 OS_OPT_PEND_NON_BLOCKING,
						(CPU_TS      *)0,
						(OS_ERR      *)&os_err) == EVEN_KEY1_DOWN)
		 {
		 		//等待到后清除标志
			OSFlagPost ((OS_FLAG_GRP  *)&key_flag_grp,                             
						(OS_FLAGS      )EVEN_KEY1_DOWN,
						(OS_OPT        )OS_OPT_POST_FLAG_CLR,
						(OS_ERR       *)&os_err);
			 //LED1_TOGGLE;
		 }		 
		 			//等待按键
		 if(OSFlagPend ((OS_FLAG_GRP *)&key_flag_grp,                  
						(OS_FLAGS     )( EVEN_KEY2_DOWN ),
						(OS_TICK      )0,
						(OS_OPT       )OS_OPT_PEND_FLAG_SET_ALL |
									 OS_OPT_PEND_NON_BLOCKING,
						(CPU_TS      *)0,
						(OS_ERR      *)&os_err) == EVEN_KEY2_DOWN)
		 {
		 		//等待到后清除标志
			OSFlagPost ((OS_FLAG_GRP  *)&key_flag_grp,                             
						(OS_FLAGS      )EVEN_KEY2_DOWN,
						(OS_OPT        )OS_OPT_POST_FLAG_CLR,
						(OS_ERR       *)&os_err);
			 //LED2_TOGGLE;
		 }				
		//检查电容按键标志
		if(tpad_flag)WM_DeleteWindow(hWin);
		GUI_Delay(10); 				
	}
}


