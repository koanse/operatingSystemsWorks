#include <windows.h>

int _stdcall WinMain (HINSTANCE hi, HINSTANCE pr, LPSTR cl, int show)
{
	STARTUPINFO si;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);

	PROCESS_INFORMATION pi;
	ZeroMemory(&pi, sizeof(pi));
	
	BOOL res = CreateProcess(
							0,
							"notepad.t",
							0,
							0,
							FALSE,
							0,
							0,
							0,
							&si,
							&pi
							);

	if(!res)
	{
		MessageBox(0, "Хреново!", "Гвоздец", MB_OK);
	}

	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);

	return 0;
}
									
