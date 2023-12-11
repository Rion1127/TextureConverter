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

	if (argc < NumArgument) {
		TextureConverter::OutputUsage();
		return 0;
	}

	//���C�u�����̏�����
	HRESULT result = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(result));

	//�e�N�X�`���R���o�[�^
	TextureConverter converter;
	//�I�v�V�����̐�
	int numOptions = argc - NumArgument;
	//�I�v�V�����z��i�_�u���|�C���^�j
	char** options = argv + NumArgument;

	converter.ConvertTextureWICToDDS(argv[kFilePath],numOptions,options);

	//COM���C�u�����̏I��
	CoUninitialize();

	//system("pause");
	return 0;
}