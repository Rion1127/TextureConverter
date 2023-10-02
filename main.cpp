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

	for (uint32_t i = 0; i < argc; i++) {
		printf(argv[i]);
		//改行
		printf("\n");
	}

	assert(argc >= NumArgument);

	//ライブラリの初期化
	HRESULT result = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(result));

	//テクスチャコンバータ
	TextureConverter converter;

	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COMライブラリの終了
	CoUninitialize();

	system("pause");
	return 0;
}