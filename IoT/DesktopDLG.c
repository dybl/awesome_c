
//-------------------------------- 包含的头文件 --------------------------
#include "DIALOG.h"
#include "includes.h"
WIN_PARA WinPara;
uint8_t UserApp_Running=0;

#define ID_WINDOW_0    (GUI_ID_USER + 0x00)
#define ID_TEXT_0    	 (GUI_ID_USER + 0x01)
#define ID_TEXT_1    	 (GUI_ID_USER + 0x02)
#define ID_BUTTON_0    (GUI_ID_USER + 0x03)
#define ID_BUTTON_1    (GUI_ID_USER + 0x04)
#define ID_BUTTON_2    (GUI_ID_USER + 0x05)
#define ID_BUTTON_3    (GUI_ID_USER + 0x06)
#define ID_BUTTON_4    (GUI_ID_USER + 0x07)
//------------------------------ 窗口的图标 -----------------------
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 	0, 	240, 320,0, 0x0, 0 },
  { TEXT_CreateIndirect, 	 "Text", 	 ID_TEXT_0, 	0, 	10, 240, 20, 0, 0x64,0 },
  { TEXT_CreateIndirect, 	 "Text", 	 ID_TEXT_1, 	0, 	60, 240, 20, 0, 0x64,0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 20, 136,90,  36, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_1, 130,138,90,  36, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_2, 20, 200,90,  36, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_3, 130,200,90,  36, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_4, 75, 250,90,  36, 0, 0x0, 0 },
};
//------------------------------ 创建函数的回调函数 -----------------------
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);		
		TEXT_SetFont(hItem, &FONT_XINSONGTI_16);
		TEXT_SetTextColor(hItem,GUI_BLUE);
		TEXT_SetText(hItem,UTF8_WIN_TEXT);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
		TEXT_SetFont(hItem, &FONT_XINSONGTI_16);
		TEXT_SetTextColor(hItem,GUI_RED);
		TEXT_SetText(hItem,UTF8_TASK_TEXT);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetFont(hItem, &FONT_XINSONGTI_16);
    BUTTON_SetText(hItem, UTF8_BTN0_TEXT);
    
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
    BUTTON_SetFont(hItem, &FONT_XINSONGTI_16);
    BUTTON_SetText(hItem, UTF8_BTN1_TEXT);
    
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
    BUTTON_SetFont(hItem, &FONT_XINSONGTI_16);
    BUTTON_SetText(hItem, UTF8_BTN2_TEXT);
    
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
    BUTTON_SetFont(hItem, &FONT_XINSONGTI_16);
    BUTTON_SetText(hItem, UTF8_BTN3_TEXT);
		
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);
    BUTTON_SetFont(hItem, &FONT_XINSONGTI_16);
    BUTTON_SetText(hItem, UTF8_BTN4_TEXT);
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: 
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
				CreateFramewin();
        break;
      }
      break;
    case ID_BUTTON_1: 
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
				resumostask1();
				resumostask2();
        break;
      }
      break;
    case ID_BUTTON_2: 
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
				deltask();
        break;
      }
      break;
    case ID_BUTTON_3: 
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
				suspendostask1();
				suspendostask2();
        break;
      }
    break;
	 case ID_BUTTON_4: 
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
				suspendostask1();
				suspendostask2();
        break;
      }
      break;
    }
    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}
//------------------------------ 创建函数 -----------------------
WM_HWIN CreateWindow(void);
WM_HWIN CreateWindow(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	
  return hWin;
}
//----------------- 创建桌面的任务函数 ----------------------
void  AppTaskDesktop (void  )
{
	GUI_SetColor(GUI_WHITE);				            					//--设置字体颜色
	GUI_SetFont(GUI_FONT_20B_ASCII);				            	//--设置字体大小
  GUI_DispStringHCenterAt("Start OS....\nWaiting a mounte",120,50);
  GUI_Delay(100);	
	//------------------ 准备建立2个窗口，以下是使用到的用户定义参数，方便在回调函数中使用
	WinPara.xSizeLCD = LCD_GetXSize();				            //--LCD屏幕尺寸
	WinPara.ySizeLCD = LCD_GetYSize();				            //--LCD屏幕尺寸
	WinPara.xPosWin	 = 0;							          					//--窗口的起始位置
	WinPara.yPosWin  = 0;							          					//--窗口的起始位置
	WinPara.xSizeWin = WinPara.xSizeLCD;						      //--窗口尺寸
	WinPara.ySizeWin = WinPara.ySizeLCD;									//--窗口尺寸
	suspendostask1();
	suspendostask2();
	CreateWindow();
	while(1)
  {			
    GUI_Delay(10);
  }
}
//------------------------------ 创建函数的回调函数 -----------------------
