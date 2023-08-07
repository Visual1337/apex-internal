#include "Surface.h"
#include <Windows.h>
#include <string>

void ISurface::SetColorPrimitive(ULONG Color) {
	if (!this) return;
	VirtualCall<void>(this, 14, (Color & 0xFF000000) >> 24, (Color & 0x00FF0000) >> 16, (Color & 0x0000FF00) >> 8, (Color & 0x000000FF));
}

void ISurface::GetSurfaceSize(int& wide, int& tall) {
	if (!this) return;
	VirtualCall<void>(this, 54, &wide, &tall);
}

void ISurface::Line(const FVector2D& Start, const FVector2D& End, ULONG Color) {
	if (!this) return;
	SetColorPrimitive(Color);
	VirtualCall<void>(this, 20, (int)Start.X, (int)Start.Y, (int)End.X, (int)End.Y);
}

void ISurface::Box(const FVector2D& Start, const FVector2D& Size, ULONG Color) {
	if (!this) return;
	SetColorPrimitive(Color);
	VirtualCall<void>(this, 19, (int)Start.X, (int)Start.Y, (int)Start.X + (int)Size.X, (int)Start.Y + (int)Size.Y);
}

void ISurface::Box(const FVector2D& Start, const FVector2D& Size, ULONG Color, int thickness) 
{
	if (!this) return;

	FilledRect(Start, FVector2D(Size.X, (float)thickness), Color);
	FilledRect(Start, FVector2D((float)thickness, Size.Y), Color);
	FilledRect(FVector2D(Start.X, Start.Y + Size.Y - thickness), FVector2D(Size.X, (float)thickness), Color);
	FilledRect(FVector2D(Start.X + Size.X - thickness, Start.Y), FVector2D((float)thickness, Size.Y), Color);
}

void ISurface::FilledRect(const FVector2D& Start, const FVector2D& Size, ULONG Color) {
	if (!this) return;
	SetColorPrimitive(Color);
	VirtualCall<void>(this, 16, (int)Start.X, (int)Start.Y, (int)Start.X + (int)Size.X, (int)Start.Y + (int)Size.Y);
}

void ISurface::TextA(int Size, int X, int Y, ULONG Color, const char* text, ...) {
	va_list va_alist;
	char buf[256] = { 0 };
	va_start(va_alist, text);
	_vsnprintf_s(buf, 255, text, va_alist);
	va_end(va_alist);
	int underlineStyle = VirtualCall<int>(this, 161);
	VirtualCall<void>(this, 197, underlineStyle, Size, X, Y, (Color & 0xFF000000) >> 24, (Color & 0x00FF0000) >> 16, (Color & 0x0000FF00) >> 8, (Color & 0x000000FF), u8"%s", buf);
}

void ISurface::DrawCircle(float x, float y, float radius, ULONG color)
{
	float PI = 3.1415927f;
	float Step = PI * 2.0f / 50;
	int Count = 0;
	FVector2D V[128];
	for (float a = 0; a < PI * 2.0; a += Step) {
		float X1 = radius * (float)cos(a) + x;
		float Y1 = radius * (float)sin(a) + y;
		float X2 = radius * (float)cos(a + Step) + x;
		float Y2 = radius * (float)sin(a + Step) + y;
		V[Count].X = X1;
		V[Count].Y = Y1;
		V[Count + 1].X = X2;

		Line(FVector2D(V[Count].X, V[Count].Y), FVector2D(X2, Y2), color);
	}
}
