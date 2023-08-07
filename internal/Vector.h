#pragma once
#include <windows.h>
#include <cmath>
#define CHECK_VALID( _v ) 0
#define M_PI       3.14159265358979323846f   // pi
#define M_RADPI	57.295779513082f
#define M_WC       0.62325931f   // pi

struct FVector2D {
	float                                              X;                                                        // 0x0000(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
	float                                              Y;                                                        // 0x0004(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
	inline FVector2D()
		: X(0), Y(0) {
	}

	inline FVector2D(float x, float y)
		: X(x),
		Y(y) {
	}

	__forceinline FVector2D& operator*=(float v) {
		X *= v; Y *= v; return *this;
	}

	__forceinline FVector2D operator-(const FVector2D& V) const {
		return FVector2D(X - V.X, Y - V.Y);
	}

	__forceinline FVector2D operator+(const FVector2D& V) const {
		return FVector2D(X + V.X, Y + V.Y);
	}

	__forceinline FVector2D operator*(float Scale) const {
		return FVector2D(X * Scale, Y * Scale);
	}

	__forceinline FVector2D operator/(float Scale) const {
		const float RScale = 1.f / Scale;
		return FVector2D(X * RScale, Y * RScale);
	}

	__forceinline FVector2D operator+(float A) const {
		return FVector2D(X + A, Y + A);
	}

	__forceinline FVector2D operator-(float A) const {
		return FVector2D(X - A, Y - A);
	}

	__forceinline FVector2D operator*(const FVector2D& V) const {
		return FVector2D(X * V.X, Y * V.Y);
	}

	__forceinline FVector2D operator/(const FVector2D& V) const {
		return FVector2D(X / V.X, Y / V.Y);
	}

	__forceinline float operator|(const FVector2D& V) const {
		return X * V.X + Y * V.Y;
	}

	__forceinline float operator^(const FVector2D& V) const {
		return X * V.Y - Y * V.X;
	}

	__forceinline FVector2D& operator+=(const FVector2D& v) {
		CHECK_VALID(*this);
		CHECK_VALID(v);
		X += v.X;
		Y += v.Y;
		return *this;
	}

	__forceinline FVector2D& operator-=(const FVector2D& v) {
		CHECK_VALID(*this);
		CHECK_VALID(v);
		X -= v.X;
		Y -= v.Y;
		return *this;
	}

	__forceinline FVector2D& operator*=(const FVector2D& v) {
		CHECK_VALID(*this);
		CHECK_VALID(v);
		X *= v.X;
		Y *= v.Y;
		return *this;
	}

	__forceinline FVector2D& operator/=(const FVector2D& v) {
		CHECK_VALID(*this);
		CHECK_VALID(v);
		X /= v.X;
		Y /= v.Y;
		return *this;
	}

	__forceinline bool operator==(const FVector2D& src) const {
		CHECK_VALID(src);
		CHECK_VALID(*this);
		return (src.X == X) && (src.Y == Y);
	}

	__forceinline bool operator!=(const FVector2D& src) const {
		CHECK_VALID(src);
		CHECK_VALID(*this);
		return (src.X != X) || (src.Y != Y);
	}

	__forceinline float Size() const {
		return sqrt(X * X + Y * Y);
	}

	__forceinline float SizeSquared() const {
		return X * X + Y * Y;
	}

	__forceinline float Dot(const FVector2D& vOther) const {
		const FVector2D& a = *this;

		return (a.X * vOther.X + a.Y * vOther.Y);
	}

	__forceinline float GetDistance(const FVector2D& vOther) const {
		return (float)sqrt(((X - vOther.X) * (X - vOther.X) + (Y - vOther.Y) * (Y - vOther.Y)));;
	}

	__forceinline FVector2D Normalize() {
		FVector2D vector;
		float length = this->Size();

		if (length != 0) {
			vector.X = X / length;
			vector.Y = Y / length;
		}
		else
			vector.X = vector.Y = 0.0f;

		return vector;
	}
};

struct FRotator {
	float                                              Pitch;                                                    // 0x0000(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
	float                                              Yaw;                                                      // 0x0004(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
	float                                              Roll;                                                     // 0x0008(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)

	inline FRotator()
		: Pitch(0), Yaw(0), Roll(0) {
	}

	inline FRotator(float x, float y, float z)
		: Pitch(x),
		Yaw(y),
		Roll(z) {
	}

	__forceinline FRotator operator+(const FRotator& V) {
		return FRotator(Pitch + V.Pitch, Yaw + V.Yaw, Roll + V.Roll);
	}

	__forceinline FRotator operator-(const FRotator& V) {
		return FRotator(Pitch - V.Pitch, Yaw - V.Yaw, Roll - V.Roll);
	}

	__forceinline FRotator operator*(float Scale) const {
		return FRotator(Pitch * Scale, Yaw * Scale, Roll * Scale);
	}

	__forceinline FRotator operator/(float Scale) const {
		const float RScale = 1.f / Scale;
		return FRotator(Pitch * RScale, Yaw * RScale, Roll * RScale);
	}

	__forceinline FRotator operator+(float A) const {
		return FRotator(Pitch + A, Yaw + A, Roll + A);
	}

	__forceinline FRotator operator-(float A) const {
		return FRotator(Pitch - A, Yaw - A, Roll - A);
	}

	__forceinline FRotator operator*(const FRotator& V) const {
		return FRotator(Pitch * V.Pitch, Yaw * V.Yaw, Roll * V.Roll);
	}

	__forceinline FRotator operator/(const FRotator& V) const {
		return FRotator(Pitch / V.Pitch, Yaw / V.Yaw, Roll / V.Roll);
	}

	__forceinline float operator|(const FRotator& V) const {
		return Pitch * V.Pitch + Yaw * V.Yaw + Roll * V.Roll;
	}

	__forceinline FRotator& operator+=(const FRotator& v) {
		CHECK_VALID(*this);
		CHECK_VALID(v);
		Pitch += v.Pitch;
		Yaw += v.Yaw;
		Roll += v.Roll;
		return *this;
	}

	__forceinline FRotator& operator-=(const FRotator& v) {
		CHECK_VALID(*this);
		CHECK_VALID(v);
		Pitch -= v.Pitch;
		Yaw -= v.Yaw;
		Roll -= v.Roll;
		return *this;
	}

	__forceinline FRotator& operator*=(const FRotator& v) {
		CHECK_VALID(*this);
		CHECK_VALID(v);
		Pitch *= v.Pitch;
		Yaw *= v.Yaw;
		Roll *= v.Roll;
		return *this;
	}

	__forceinline FRotator& operator/=(const FRotator& v) {
		CHECK_VALID(*this);
		CHECK_VALID(v);
		Pitch /= v.Pitch;
		Yaw /= v.Yaw;
		Roll /= v.Roll;
		return *this;
	}

	__forceinline float operator^(const FRotator& V) const {
		return Pitch * V.Yaw - Yaw * V.Pitch - Roll * V.Roll;
	}

	__forceinline bool operator==(const FRotator& src) const {
		CHECK_VALID(src);
		CHECK_VALID(*this);
		return (src.Pitch == Pitch) && (src.Yaw == Yaw) && (src.Roll == Roll);
	}

	__forceinline bool operator!=(const FRotator& src) const {
		CHECK_VALID(src);
		CHECK_VALID(*this);
		return (src.Pitch != Pitch) || (src.Yaw != Yaw) || (src.Roll != Roll);
	}

	__forceinline float Size() const {
		return sqrt(Pitch * Pitch + Yaw * Yaw + Roll * Roll);
	}

	__forceinline float SizeSquared() const {
		return Pitch * Pitch + Yaw * Yaw + Roll * Roll;
	}

	__forceinline float Dot(const FRotator& vOther) const {
		const FRotator& a = *this;

		return (a.Pitch * vOther.Pitch + a.Yaw * vOther.Yaw + a.Roll * vOther.Roll);
	}

	__forceinline FRotator Clamp() const
	{
		FRotator result(Pitch, Yaw, Roll);

		if (result.Pitch > 180)
			result.Pitch -= 360;

		else if (result.Pitch < -180)
			result.Pitch += 360;

		if (result.Yaw > 180)
			result.Yaw -= 360;

		else if (result.Yaw < -180)
			result.Yaw += 360;

		if (result.Pitch < -89)
			result.Pitch = -89;

		if (result.Pitch > 89)
			result.Pitch = 89;

		while (result.Yaw < -180.0f)
			result.Yaw += 360.0f;

		while (result.Yaw > 180.0f)
			result.Yaw -= 360.0f;

		result.Roll = 0;

		return result;
	}
	__forceinline FRotator ClampCp() const
	{
		FRotator result(Pitch, Yaw, Roll);

		if (result.Pitch < 0.f)
			result.Pitch += 360.f;

		while (result.Yaw < 0.0f)
			result.Yaw += 360.0f;

		result.Roll = 0;

		return result;
	}

	__forceinline float ClampAxis(float Angle) {
		// returns Angle in the range (-360,360)
		Angle = fmod(Angle, 360.f);

		if (Angle < 0.f) {
			// shift to [0,360) range
			Angle += 360.f;
		}

		return Angle;
	}

	__forceinline float NormalizeAxis(float Angle) {
		// returns Angle in the range [0,360)
		Angle = ClampAxis(Angle);

		if (Angle > 180.f) {
			// shift to (-180,180]
			Angle -= 360.f;
		}

		return Angle;
	}

	__forceinline void Normalize() {
		Pitch = NormalizeAxis(Pitch);
		Yaw = NormalizeAxis(Yaw);
		Roll = NormalizeAxis(Roll);
	}

	__forceinline FRotator GetNormalized() const {
		FRotator Rot = *this;
		Rot.Normalize();
		return Rot;
	}
};

struct FVector {
	float                                              X;                                                        // 0x0000(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
	float                                              Y;                                                        // 0x0004(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
	float                                              Z;                                                        // 0x0008(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)

	inline FVector()
		: X(0), Y(0), Z(0) {
	}

	inline FVector(float x, float y, float z)
		: X(x),
		Y(y),
		Z(z) {
	}

	__forceinline float& operator[](int i)
	{
		return ((float*)this)[i];
	}
	__forceinline float operator[](int i) const
	{
		return ((float*)this)[i];
	}
	__forceinline FVector operator-(const FVector& V) const {
		return FVector(X - V.X, Y - V.Y, Z - V.Z);
	}

	__forceinline FVector operator+(const FVector& V) const {
		return FVector(X + V.X, Y + V.Y, Z + V.Z);
	}

	__forceinline FVector operator*(float Scale) const {
		return FVector(X * Scale, Y * Scale, Z * Scale);
	}

	__forceinline FVector operator/(float Scale) const {
		const float RScale = 1.f / Scale;
		return FVector(X * RScale, Y * RScale, Z * RScale);
	}

	__forceinline FVector operator+(float A) const {
		return FVector(X + A, Y + A, Z + A);
	}

	__forceinline FVector operator-(float A) const {
		return FVector(X - A, Y - A, Z - A);
	}

	__forceinline FVector operator*(const FVector& V) const {
		return FVector(X * V.X, Y * V.Y, Z * V.Z);
	}

	__forceinline FVector operator/(const FVector& V) const {
		return FVector(X / V.X, Y / V.Y, Z / V.Z);
	}

	__forceinline float operator|(const FVector& V) const {
		return X * V.X + Y * V.Y + Z * V.Z;
	}

	__forceinline float operator^(const FVector& V) const {
		return X * V.Y - Y * V.X - Z * V.Z;
	}

	__forceinline FVector& operator+=(const FVector& v) {
		CHECK_VALID(*this);
		CHECK_VALID(v);
		X += v.X;
		Y += v.Y;
		Z += v.Z;
		return *this;
	}

	__forceinline FVector& operator-=(const FVector& v) {
		CHECK_VALID(*this);
		CHECK_VALID(v);
		X -= v.X;
		Y -= v.Y;
		Z -= v.Z;
		return *this;
	}

	__forceinline FVector& operator*=(const FVector& v) {
		CHECK_VALID(*this);
		CHECK_VALID(v);
		X *= v.X;
		Y *= v.Y;
		Z *= v.Z;
		return *this;
	}

	__forceinline FVector& operator/=(const FVector& v) {
		CHECK_VALID(*this);
		CHECK_VALID(v);
		X /= v.X;
		Y /= v.Y;
		Z /= v.Z;
		return *this;
	}

	__forceinline bool operator==(const FVector& src) const {
		CHECK_VALID(src);
		CHECK_VALID(*this);
		return (src.X == X) && (src.Y == Y) && (src.Z == Z);
	}

	__forceinline bool operator!=(const FVector& src) const {
		CHECK_VALID(src);
		CHECK_VALID(*this);
		return (src.X != X) || (src.Y != Y) || (src.Z != Z);
	}

	__forceinline float Size() const {
		return sqrt(X * X + Y * Y + Z * Z);
	}

	__forceinline float Size2D() const {
		return sqrt(X * X + Y * Y);
	}

	__forceinline float SizeSquared() const {
		return X * X + Y * Y + Z * Z;
	}

	__forceinline float SizeSquared2D() const {
		return X * X + Y * Y;
	}

	__forceinline float Dot(const FVector& vOther) const {
		const FVector& a = *this;

		return (a.X * vOther.X + a.Y * vOther.Y + a.Z * vOther.Z);
	}
	__forceinline float Distance(const FVector& v)
	{
		return float(sqrt(powf(v.X - X, 2.0) + powf(v.Y - Y, 2.0) + powf(v.Z - Z, 2.0)));
	}
	__forceinline FVector Clamp()
	{
		if (this->X < -89.0f)
			this->X = -89.0f;

		if (this->X > 89.0f)
			this->X = 89.0f;

		while (this->Y < -180.0f)
			this->Y += 360.0f;

		while (this->Y > 180.0f)
			this->Y -= 360.0f;

		this->Z = 0.0f;
		return *this;
	}
	__forceinline FRotator ToFRotator()
	{
		FRotator rot = FRotator(0, 0, 0);
		float RADPI = (float)(180.f / M_PI);
		rot.Yaw = (float)atan2(Y, X) * RADPI;
		rot.Pitch = (float)atan2(Z, sqrt((X * X) + (Y * Y))) * RADPI;
		return rot;
	}

	__forceinline FVector Normalize() {
		FVector vector;
		float length = this->Size();

		if (length != 0) {
			vector.X = X / length;
			vector.Y = Y / length;
			vector.Z = Z / length;
		}
		else
			vector.X = vector.Y = 0.0f;
		vector.Z = 1.0f;

		return vector;
	}
};

struct FVector4D {
	float                                              X;                                                        // 0x0000(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
	float                                              Y;                                                        // 0x0004(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
	float                                              Z;                                                        // 0x0000(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
	float                                              W;                                                        // 0x0004(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)

	__forceinline FVector4D()
		: X(0), Y(0), Z(0), W(0) {
	}

	__forceinline FVector4D(FVector Pos)
		: X(Pos.X),
		Y(Pos.Y),
		Z(Pos.Z),
		W(0.f) {
	}

	__forceinline FVector4D(float x, float y, float z, float w)
		: X(x),
		Y(y),
		Z(z),
		W(w) {
	}

	__forceinline float LengthSqr() const {
		return (X * X + Y * Y + Z * Z);
	}
};

struct alignas(16) FQuat {
	float                                              X;                                                        // 0x0000(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
	float                                              Y;                                                        // 0x0004(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
	float                                              Z;                                                        // 0x0008(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
	float                                              W;                                                        // 0x000C(0x0004) (CPF_Edit, CPF_BlueprintVisible, CPF_ZeroConstructor, CPF_SaveGame, CPF_IsPlainOldData)
};

typedef struct _MATRIX4X4 {
	union {
		struct
		{
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;
		};

		float m[4][4];
	};
} MATRIX4X4;

typedef struct _MATRIX3X4 {
	union {
		struct
		{
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
		};

		float m[3][4];
	};
} MATRIX3X4;

typedef struct
{
	float R;
	float G;
	float B;
	float A;
}RGBA;

class Color
{
public:
	RGBA red = { 255,0,0,255 };
	RGBA Magenta = { 255,0,255,255 };
	RGBA yellow = { 255,255,0,255 };
	RGBA grayblue = { 128,128,255,255 };
	RGBA green = { 128,224,0,255 };
	RGBA darkgreen = { 0,224,128,255 };
	RGBA brown = { 192,96,0,255 };
	RGBA pink = { 255,168,255,255 };
	RGBA DarkYellow = { 216,216,0,255 };
	RGBA SilverWhite = { 236,236,236,255 };
	RGBA purple = { 144,0,255,255 };
	RGBA Navy = { 88,48,224,255 };
	RGBA skyblue = { 0,136,255,255 };
	RGBA graygreen = { 128,160,128,255 };
	RGBA blue = { 0,96,192,255 };
	RGBA orange = { 255,128,0,255 };
	RGBA peachred = { 255,80,128,255 };
	RGBA reds = { 255,128,192,255 };
	RGBA darkgray = { 96,96,96,255 };
	RGBA Navys = { 0,0,128,255 };
	RGBA darkgreens = { 0,128,0,255 };
	RGBA darkblue = { 0,128,128,255 };
	RGBA redbrown = { 128,0,0,255 };
	RGBA purplered = { 175,0,128,255 };
	RGBA greens = { 0,180,0,255 };
	RGBA envy = { 0,255,255,255 };
	RGBA black = { 0,0,0,255 };
	RGBA gray = { 128,128,128,255 };
	RGBA white = { 255,255,255,255 };
	RGBA blues = { 30,144,255,255 };
	RGBA lightblue = { 135,206,250,160 };
	RGBA Scarlet = { 220, 20, 60, 160 };
	RGBA white_ = { 255,255,255,200 };
	RGBA gray_ = { 128,128,128,200 };
	RGBA black_ = { 0,0,0,200 };
	RGBA red_ = { 255,0,0,200 };
	RGBA Magenta_ = { 255,0,255,200 };
	RGBA yellow_ = { 255,255,0,200 };
	RGBA grayblue_ = { 128,128,255,200 };
	RGBA green_ = { 128,224,0,200 };
	RGBA darkgreen_ = { 0,224,128,200 };
	RGBA brown_ = { 192,96,0,200 };
	RGBA pink_ = { 255,168,255,200 };
	RGBA darkyellow_ = { 216,216,0,200 };
	RGBA silverwhite_ = { 236,236,236,200 };
	RGBA purple_ = { 144,0,255,200 };
	RGBA Blue_ = { 88,48,224,200 };
	RGBA skyblue_ = { 0,136,255,200 };
	RGBA graygreen_ = { 128,160,128,200 };
	RGBA blue_ = { 0,96,192,200 };
	RGBA orange_ = { 255,128,0,200 };
	RGBA pinks_ = { 255,80,128,200 };
	RGBA Fuhong_ = { 255,128,192,200 };
	RGBA darkgray_ = { 96,96,96,200 };
	RGBA Navy_ = { 0,0,128,200 };
	RGBA darkgreens_ = { 0,128,0,200 };
	RGBA darkblue_ = { 0,128,128,200 };
	RGBA redbrown_ = { 128,0,0,200 };
	RGBA purplered_ = { 128,0,128,200 };
	RGBA greens_ = { 0,255,0,200 };
	RGBA envy_ = { 0,255,255,200 };
	RGBA filled = { 0, 0, 0, 150 };

	RGBA glassblack = { 0, 0, 0, 160 };
	RGBA GlassBlue = { 65,105,225,80 };
	RGBA glassyellow = { 255,255,0,160 };
	RGBA glass = { 200,200,200,60 };

	RGBA Plum = { 221,160,221,160 };
};
extern Color Col;