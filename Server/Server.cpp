// Server.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "resource.h"
#include <Windows.h>

HINSTANCE hInstance; HINSTANCE hPrevInst;
LPSTR lpszArgs; int nWinMode;
//����������� ��������� ��� ���������
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE
	hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int ret = DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1),
		NULL, (DLGPROC)DlgProc);
	if (ret == 0)
	{
		//���� ���� ������ ������ ������ ��� �������
		MessageBox(NULL, (LPCTSTR)L"������", (LPCTSTR)L"Inform",
			MB_OK | MB_ICONINFORMATION);
	}
	else if (ret == 1)
	{
		
		//���� ���� ������ ������ ��
		MessageBox(NULL, (LPCTSTR)L"��", (LPCTSTR)L"Inform",
			MB_OK | MB_ICONINFORMATION);
	}

	return ret;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT msg, WPARAM wParam,
	LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
	{
		return FALSE;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDOK:
			EndDialog(hwnd, 1);
			return TRUE;
		case IDCANCEL:
			EndDialog(hwnd, 0);
			return TRUE;
		}
	}
	case WM_CLOSE:
	{
		EndDialog(hwnd, 0);
		return FALSE;
	}
	}
	return FALSE;//����� ��� �� ������� ������� ��� ���������� ����
				 //return TRUE;//�� ����� ��������� ������� ���������� ����
}

void ForWin()
{
	int a = WinMain(hInstance, hPrevInst, lpszArgs, nWinMode);
}
/////////////////////////////





/////////////////////////////
int main()
{
	setlocale(LC_ALL, "Russian_Russia.1251");//��������� ��������� ��� ������ �������� ����� 
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ForWin, NULL, NULL, NULL);
	//int a = WinMain(hInstance, hPrevInst, lpszArgs, nWinMode);
	
	
	
	system("pause");
    return 0;
}

