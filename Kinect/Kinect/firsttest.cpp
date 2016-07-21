#include<windows.h> 
#include<tchar.h>
#include<fstream>
HDC hdc, mdc; 
HBITMAP  pic;
LONG bmpWidth, bmpHeight;
int i = 0;
bool readBmp(char *bmpName)
{
	FILE *fp = fopen(bmpName, "rb");//�����ƶ���ʽ��ָ����ͼ���ļ�
	if (fp == 0)
		return 0;
	fseek(fp, sizeof(BITMAPFILEHEADER), 0);//����λͼ��Ϣͷ�ṹ��������ȡλͼ��Ϣͷ���ڴ棬����ڱ���head��
	BITMAPINFOHEADER head;
	fread(&head, sizeof(BITMAPINFOHEADER), 1, fp); //��ȡͼ����ߡ�ÿ������ռλ������Ϣ
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
		//hdc = GetDC(hwnd);    //�����ʾ�������豸�ľ��
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
		mdc = CreateCompatibleDC(hdc);//����һ����ָ���豸���ݵ��ڴ��豸�����Ļ���
		i = (i + 1) % 3 + 1;
		switch (i) {
		case 1:
			readBmp("E:\\pic\\1.bmp");
			pic = (HBITMAP)LoadImage(NULL, _T("E:\\pic\\1.bmp"), IMAGE_BITMAP, bmpWidth, bmpHeight, LR_LOADFROMFILE);//����һ��ָ����·����bmpͼƬ����ͼƬ��СΪ63*128�����������֮ǰ��Ҫ֪������ͼ�Ĵ�С���ֱ���д�ڵ�4��5��������  
			SelectObject(mdc, pic);//ѡ���豸����
			BitBlt(hdc, 10, 10, bmpWidth, bmpHeight, mdc, 10, 10, SRCAND);//��ʾ����ͼ   ����һ����HDC���͵ı���,����2��3��X��Y���꣬����4��5��ͼƬ��С����6��ָ��Դ�豸�����ľ��������7��8��ָ��ͼƬ���Ͻǵ�X��Y�߼����꣬û���������һ�㶼��0
			DeleteDC(mdc);
			ReleaseDC(hwnd, hdc);
			break;
		case 2:
			readBmp("E:\\pic\\2.bmp");
			pic = (HBITMAP)LoadImage(NULL, _T("E:\\pic\\2.bmp"), IMAGE_BITMAP, bmpWidth, bmpHeight, LR_LOADFROMFILE);//����һ��ָ����·����bmpͼƬ����ͼƬ��СΪ63*128�����������֮ǰ��Ҫ֪������ͼ�Ĵ�С���ֱ���д�ڵ�4��5��������  
			SelectObject(mdc, pic);//ѡ���豸����
			BitBlt(hdc, 10, 10, bmpWidth, bmpHeight, mdc, 10, 10, SRCAND);//��ʾ����ͼ   ����һ����HDC���͵ı���,����2��3��X��Y���꣬����4��5��ͼƬ��С����6��ָ��Դ�豸�����ľ��������7��8��ָ��ͼƬ���Ͻǵ�X��Y�߼����꣬û���������һ�㶼��0
			DeleteDC(mdc);
			ReleaseDC(hwnd, hdc);
			break;
		case 3:
			readBmp("E:\\pic\\3.bmp");
			pic = (HBITMAP)LoadImage(NULL, _T("E:\\pic\\3.bmp"), IMAGE_BITMAP, bmpWidth, bmpHeight, LR_LOADFROMFILE);//����һ��ָ����·����bmpͼƬ����ͼƬ��СΪ63*128�����������֮ǰ��Ҫ֪������ͼ�Ĵ�С���ֱ���д�ڵ�4��5��������  
			SelectObject(mdc, pic);//ѡ���豸����
			BitBlt(hdc, 10, 10, bmpWidth, bmpHeight, mdc, 10, 10, SRCAND);//��ʾ����ͼ   ����һ����HDC���͵ı���,����2��3��X��Y���꣬����4��5��ͼƬ��С����6��ָ��Դ�豸�����ľ��������7��8��ָ��ͼƬ���Ͻǵ�X��Y�߼����꣬û���������һ�㶼��0
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
		RECT rctClient;//������������ڿͻ�����С��Ϣ
		const int buttonWidth=80;//��ť�Ŀ�
		const int buttonHeight=25;//��ť�ĸ� 
		GetClientRect(hwnd,&rctClient);//�õ������ڿͻ����Ĵ�С��Ϣ 
		HINSTANCE hInst=(HINSTANCE)GetWindowLongPtr(hwnd,GWLP_HINSTANCE); //����button�ľ������Ӧ��ʵ��
		HWND hButton=CreateWindowEx(0L,_T("button"),_T("�ر�"),WS_VISIBLE|WS_CHILD,rctClient.right/2-buttonWidth/2,rctClient.bottom/2-buttonHeight/2,buttonWidth,buttonHeight,hwnd,(HMENU)2,hInst,NULL);
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
		MessageBox(NULL,_T("ע�ᴰ�������"),_T("����"),MB_OK);
		return 0;
	}
	HWND newWind = CreateWindowEx(0L, _T("MyWindowClass"), _T("beyond code"), WS_OVERLAPPEDWINDOW, 0, 0, 700, 700, NULL, NULL, hInstance, NULL); 
	if (NULL == newWind) {
		MessageBox(NULL, _T("�������ڳ���"), _T("����"), MB_OK); 
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
