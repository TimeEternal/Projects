#include<windows.h> 
#include<tchar.h>
#include<fstream>
HDC hdc, mdc; 
HBITMAP  pic;
LONG bmpWidth, bmpHeight;
int i = 0;
bool readBmp(char *bmpName)
{
	FILE *fp = fopen(bmpName, "rb");//二进制读方式打开指定的图像文件
	if (fp == 0)
		return 0;
	fseek(fp, sizeof(BITMAPFILEHEADER), 0);//定义位图信息头结构变量，读取位图信息头进内存，存放在变量head中
	BITMAPINFOHEADER head;
	fread(&head, sizeof(BITMAPINFOHEADER), 1, fp); //获取图像宽、高、每像素所占位数等信息
	bmpWidth = head.biWidth;
	bmpHeight = head.biHeight;
	return true;
}
LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch(msg) {
	case WM_DESTROY: {
		PostQuitMessage(0); 
		break; 
	}
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == 2)
		{
			DestroyWindow(hwnd);
		}
		break;
	}
	
	/*case WM_SIZE: { 
		const int buttonWidth = 80; 
		const int buttonHeight = 25; 
		int buttonx, buttony; 
		RECT rctClient; 
		GetClientRect(hwnd, &rctClient);
		buttonx = rctClient.right / 2 - buttonWidth / 2; 
		buttony = rctClient.bottom / 2 - buttonHeight / 2;
		HWND hButton = GetDlgItem(hwnd, 2);
		MoveWindow(hButton, buttonx, buttony, buttonWidth, buttonHeight, TRUE); 
		break;
	} */
	case WM_PAINT:
	{
		//hdc = GetDC(hwnd);    //获得显示上下文设备的句柄
		const int buttonWidth = 80;
		const int buttonHeight = 25;
		const int textHeight = 25;
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		/*RECT rctClient, rctText;
		GetClientRect(hwnd, &rctClient);
		rctText.left = rctClient.left;
		rctText.right = rctClient.right;
		rctText.top = rctClient.bottom / 2 - buttonHeight - textHeight;
		rctText.bottom = rctClient.bottom / 2 - buttonHeight;
		DrawText(hdc, _T("Beyond code"), _tcslen(_T("Beyond code")), &rctText, DT_CENTER |DT_SINGLELINE | DT_VCENTER);*/
		mdc = CreateCompatibleDC(hdc);//创建一个与指定设备兼容的内存设备上下文环境
		i = (i + 1) % 3 + 1;
		switch (i) {
		case 1:
			readBmp("E:\\pic\\1.bmp");
			pic = (HBITMAP)LoadImage(NULL, _T("E:\\pic\\1.bmp"), IMAGE_BITMAP, bmpWidth, bmpHeight, LR_LOADFROMFILE);//加载一张指定了路径的bmp图片，此图片大小为63*128，用这个函数之前需要知道这张图的大小，分别填写在第4、5个参数里  
			SelectObject(mdc, pic);//选入设备环境
			BitBlt(hdc, 10, 10, bmpWidth, bmpHeight, mdc, 10, 10, SRCAND);//显示这张图   参数一：填HDC类型的变量,参数2、3：X、Y坐标，参数4、5：图片大小参数6：指向源设备环境的句柄。参数7、8：指定图片左上角的X、Y逻辑坐标，没有特殊情况一般都填0
			DeleteDC(mdc);
			ReleaseDC(hwnd, hdc);
			break;
		case 2:
			readBmp("E:\\pic\\2.bmp");
			pic = (HBITMAP)LoadImage(NULL, _T("E:\\pic\\2.bmp"), IMAGE_BITMAP, bmpWidth, bmpHeight, LR_LOADFROMFILE);//加载一张指定了路径的bmp图片，此图片大小为63*128，用这个函数之前需要知道这张图的大小，分别填写在第4、5个参数里  
			SelectObject(mdc, pic);//选入设备环境
			BitBlt(hdc, 10, 10, bmpWidth, bmpHeight, mdc, 10, 10, SRCAND);//显示这张图   参数一：填HDC类型的变量,参数2、3：X、Y坐标，参数4、5：图片大小参数6：指向源设备环境的句柄。参数7、8：指定图片左上角的X、Y逻辑坐标，没有特殊情况一般都填0
			DeleteDC(mdc);
			ReleaseDC(hwnd, hdc);
			break;
		case 3:
			readBmp("E:\\pic\\3.bmp");
			pic = (HBITMAP)LoadImage(NULL, _T("E:\\pic\\3.bmp"), IMAGE_BITMAP, bmpWidth, bmpHeight, LR_LOADFROMFILE);//加载一张指定了路径的bmp图片，此图片大小为63*128，用这个函数之前需要知道这张图的大小，分别填写在第4、5个参数里  
			SelectObject(mdc, pic);//选入设备环境
			BitBlt(hdc, 10, 10, bmpWidth, bmpHeight, mdc, 10, 10, SRCAND);//显示这张图   参数一：填HDC类型的变量,参数2、3：X、Y坐标，参数4、5：图片大小参数6：指向源设备环境的句柄。参数7、8：指定图片左上角的X、Y逻辑坐标，没有特殊情况一般都填0
			DeleteDC(mdc);
			ReleaseDC(hwnd, hdc);
			break;
		}
		EndPaint(hwnd, &ps);
		Sleep(3000);
		InvalidateRect(hwnd, NULL, true);
		break;
	}
	case WM_CREATE: { 
		RECT rctClient;//用来存放主窗口客户区大小信息
		const int buttonWidth=80;//按钮的宽
		const int buttonHeight=25;//按钮的高 
		GetClientRect(hwnd,&rctClient);//得到主窗口客户区的大小信息 
		HINSTANCE hInst=(HINSTANCE)GetWindowLongPtr(hwnd,GWLP_HINSTANCE); //创建button的句柄所对应的实例
		HWND hButton=CreateWindowEx(0L,_T("button"),_T("关闭"),WS_VISIBLE|WS_CHILD,rctClient.right/2-buttonWidth/2,rctClient.bottom/2-buttonHeight/2,buttonWidth,buttonHeight,hwnd,(HMENU)2,hInst,NULL);
		SetWindowText(hwnd,_T("Kevi's windows"));
		break;
	}
	default:return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd)
{
	WNDCLASSEX wc;
	wc.cbSize=sizeof(wc); 
	wc.style=CS_VREDRAW|CS_HREDRAW;
	wc.cbClsExtra=0;
	wc.cbWndExtra=0; 
	wc.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor=LoadCursor(NULL,IDC_ARROW); 
	wc.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	wc.hIconSm=LoadIcon(NULL,IDI_APPLICATION);
	wc.hInstance=hInstance; 
	wc.lpfnWndProc= WinProc;
	wc.lpszMenuName=NULL; 
	wc.lpszClassName=_T("MyWindowClass");
	if(!RegisterClassEx(&wc)){ 
		MessageBox(NULL,_T("注册窗口类出错"),_T("出错"),MB_OK);
		return 0;
	}
	HWND newWind = CreateWindowEx(0L, _T("MyWindowClass"), _T("beyond code"), WS_OVERLAPPEDWINDOW, 0, 0, 700, 700, NULL, NULL, hInstance, NULL); 
	if (NULL == newWind) {
		MessageBox(NULL, _T("创建窗口出错"), _T("出错"), MB_OK); 
		return 0; 
	} 
	ShowWindow(newWind, nShowCmd); 
	UpdateWindow(newWind);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg); 
		DispatchMessage(&msg);
	}
	return 0;
}
