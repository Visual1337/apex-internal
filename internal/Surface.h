#pragma once
#include <Windows.h>
#include "Vector.h"
#include <stdint.h>

template< typename ReturnType = void, typename... Args>
ReturnType VirtualCall(PVOID Ctx, uint32_t number, Args... Arguments)
{
	return reinterpret_cast<ReturnType(*)(PVOID, Args...)>((*(PVOID**)Ctx)[number])(Ctx, Arguments...);
}



class ISurface 
{
public:
	void SetColorPrimitive(ULONG Color);
	void GetSurfaceSize(int& wide, int& tall);
	void Line(const FVector2D& Start, const FVector2D& End, ULONG Color);
	void Box(const FVector2D& Start, const FVector2D& Size, ULONG Color);
	void Box(const FVector2D& Start, const FVector2D& Size, ULONG Color, int thickness);
	void FilledRect(const FVector2D& Start, const FVector2D& Size, ULONG Color);
	void TextA(int Size, int X, int Y, ULONG Color, const char* text, ...);
	void DrawCircle(float x, float y, float radius, ULONG color);
};
