// CubeWorldXMLLanguageFix.cpp : Defines the entry point for the application.
//

#include "CubeWorldXMLLanguageFix.h"


DWORD WINAPI MainLoop() {
    cube::InitAPI();
    SetupOnLanguageWStringCopy();
    return 0;
}

extern "C" BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MainLoop, 0, 0, NULL);
        break;
    }
    return TRUE;
}