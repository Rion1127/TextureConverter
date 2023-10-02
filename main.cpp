#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <comdef.h>
#include <cstdint>

#include "TextureConverter.h"

enum Argument {
	kApplicationPath,	//�A�v���P�[�V�����̃p�X
	kFilePath,			//�n���ꂽ�t�@�C���̃p�X

	NumArgument
};

int main(int argc,char* argv[]) {

	for (uint32_t i = 0; i < argc; i++) {
		printf(argv[i]);
		//���s
		printf("\n");
	}

	assert(argc >= NumArgument);

	//���C�u�����̏�����
	HRESULT result = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(result));

	//�e�N�X�`���R���o�[�^
	TextureConverter converter;

	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COM���C�u�����̏I��
	CoUninitialize();

	system("pause");
	return 0;
}