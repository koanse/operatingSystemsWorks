#include <windows.h>

int __stdcall WinMain
				(
					HINSTANCE hi, HINSTANCE pre,
					LPSTR cl, int show
				)
{
	STARTUPINFO si;
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);

	PROCESS_INFORMATION pi;
	ZeroMemory( &pi, sizeof(pi) );

	BOOL Res = CreateProcess
				(
					0,
					"notepad.exe 1.txt",
					0,
					0,
					FALSE,
					0,
					0,
					0,
					&si,
					&pi
				);

	if( Res != TRUE )
	{
		MessageBox( 0, "Error creating process!", "Life's not easy!", MB_OK );
	}

	CloseHandle( pi.hThread );
	CloseHandle( pi.hProcess );
	
	return 0;
}