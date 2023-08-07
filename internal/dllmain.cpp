

#include <Windows.h>
#include <string>
#include "Global.h"
#include "Memory.h"
#include <intrin.h> 


typedef unsigned char(*fnPaint) (ULONG64 Surface, ULONG64 a2, unsigned char mode);
fnPaint pfnPaint = 0;
PVOID  pSurfaceVmt[512] = { 0 };
int width, height;


void ShowConsoleWindow()
{
    if (!GetConsoleWindow())
    {
        AllocConsole();
        FILE* filePointer{};
        freopen_s(&filePointer, "CONOUT$", "w", stdout);
    }
}

unsigned char PaintHook(ULONG64 Surface, ULONG64 rdx, unsigned char mode)
{
    ULONG64 Address = (ULONG64)_ReturnAddress();
    if (Address == GameData::GameBase + 0x267D03)   
    {

        GameData::GSurface->GetSurfaceSize(width, height);
        GameData::GSurface->TextA(30, 1280,1280, 0xff48c9b0,"Internal Engine Base By bagchaser#5310");


    }
    return pfnPaint(Surface, rdx, mode);
}

void GetOffsetByApex()
{



    GameData::GameBase = (uint64_t)GetModuleHandle(L"r5apex.exe");
    printf("GameBase = %p\n", GameData::GameBase);
    GameData::GSurface = (ISurface*)(GameData::GameBase + 0xB433710);  
    printf("GSurface = %p\n", GameData::GSurface);
    uint64_t pSurface = GameData::GameBase + 0xB433710;
    PVOID* ESurfaceVmt = *(PVOID**)pSurface;
    for (uint32_t i = 0; i < 512; i++)
        pSurfaceVmt[i] = ESurfaceVmt[i];
    pfnPaint = (fnPaint)pSurfaceVmt[140];
    pSurfaceVmt[140] = PaintHook;          
    *(PVOID**)pSurface = pSurfaceVmt;
    







}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    ULONG EndTime
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {


        ShowConsoleWindow();
        GetOffsetByApex();
        break;
    }
    }
    return TRUE;
}




