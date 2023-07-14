#include <Novice.h>
#include <math.h>

const char kWindowTitle[] = "LE2D_02_カガミ_ケイイチロウ";
struct Vector3 {
	float x;
	float y;
	float z;
};

static const int kRowHeight = 20;
static const int kColumnWidth = 60;

//加算
Vector3 Add(Vector3 v1, Vector3 v2) {
	Vector3 r = { 0,0,0 };
	r.x = v1.x + v2.x;
	r.y = v1.y + v2.y;
	r.z = v1.z + v2.z;
	return r;
}

//減算
Vector3 Subtract(Vector3 v1, Vector3 v2) {
	Vector3 r = { 0,0,0 };
	r.x = v1.x - v2.x;
	r.y = v1.y - v2.y;
	r.z = v1.z - v2.z;
	return r;
}

//スカラー倍
Vector3 Multiply(float k, Vector3 v1) {
	Vector3 r = { 0,0,0 };
	r.x = k * v1.x;
	r.y = k * v1.y;
	r.z = k * v1.z;
	return r;
}

//内積
float Dot(Vector3 v1, Vector3 v2) {
	Vector3 r = { 0,0,0 };
	r.x = v1.x * v2.x;
	r.y = v1.y * v2.y;
	r.z = v1.z * v2.z;
	return r.x + r.y + r.z;
}

//長さ
float Length(Vector3 v1) {
	float result;
	result = sqrtf(Dot(v1, v1));
	return result;
}

//正規化
Vector3 Normalize(const Vector3& v) {
	Vector3 reslut = { 0,0,0 };
	reslut.x = v.x / Length(v);
	reslut.y = v.y / Length(v);
	reslut.z = v.z / Length(v);
	return reslut;
}

void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);

}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Vector3 v1{ 1.0f,3.0f,-5.0f };
	Vector3 v2{ 4.0f,-1.0f,2.0f };
	float k = 4.0f;
	Vector3 resultAdd = Add(v1, v2);
	Vector3 resultSubtract = Subtract(v1, v2);
	Vector3 resultMultiply = Multiply(k, v1);
	float resultDot = Dot(v1, v2);
	float resultLength = Length(v1);
	Vector3 resultNormalize = Normalize(v2);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		
		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		VectorScreenPrintf(0, 0, resultAdd, ":Add");
		VectorScreenPrintf(0, kRowHeight, resultSubtract, ":Subtract");
		VectorScreenPrintf(0, kRowHeight * 2, resultMultiply, ":Multiply");
		Novice::ScreenPrintf(0, kRowHeight * 3, "%.02f:Dot", resultDot);
		Novice::ScreenPrintf(0, kRowHeight * 4, "%.02f:Length", resultLength);
		VectorScreenPrintf(0, kRowHeight * 5, resultNormalize, ":Normalize");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
