#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <comdef.h>
#include <cstdint>

#include "TextureConverter.h"

enum Argument {
	kApplicationPath,	//アプリケーションのパス
	kFilePath,			//渡されたファイルのパス

	NumArgument
};

int main(int argc,char* argv[]) {

	if (argc < NumArgument) {
		TextureConverter::OutputUsage();
		return 0;
	}

	//ライブラリの初期化
	HRESULT result = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(result));

	//テクスチャコンバータ
	TextureConverter converter;
	//オプションの数
	int numOptions = argc - NumArgument;
	//オプション配列（ダブルポインタ）
	char** options = argv + NumArgument;

	converter.ConvertTextureWICToDDS(argv[kFilePath],numOptions,options);

	//COMライブラリの終了
	CoUninitialize();

	//system("pause");
	return 0;
}