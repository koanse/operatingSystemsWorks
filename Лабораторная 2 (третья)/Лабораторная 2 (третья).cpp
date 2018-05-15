#include <windows.h>

int main( void )
{
	SECURITY_ATTRIBUTES sa;
	ZeroMemory( &sa, sizeof(sa) );
	sa.nLength = sizeof(sa);
	sa.bInheritHandle = TRUE;

	HANDLE file = CreateFile
					( 
						L"1.txt", 
						GENERIC_WRITE,
						FILE_SHARE_READ,
						&sa,
						CREATE_ALWAYS,
						FILE_ATTRIBUTE_NORMAL,
						NULL
					);

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory( &si, sizeof(si) );
	ZeroMemory( &pi, sizeof(pi) );

	si.cb = sizeof(si);

	si.dwFlags = STARTF_USESTDHANDLES;
	si.hStdOutput = file;

	wchar_t buf[100];
	CopyMemory
		( 
			buf, 
			L"testAS05.exe", 
			(wcslen(L"testAS05.exe") + 1)*sizeof(wchar_t) 
		);

	BOOL res = CreateProcess
				(
					0,
					buf,
					0,
					0,
					TRUE,
					0,
					0,
					0,
					&si,
					&pi
				);

	if( !res )
	{
		MessageBox( 0, L"Error creating process!", L"Life's not easy.", MB_OK );
	}
	else
	{
		WaitForSingleObject( pi.hProcess, INFINITE );
		CloseHandle( pi.hThread );
		CloseHandle( pi.hProcess );
	}

	CloseHandle(file);

	return 0;
}