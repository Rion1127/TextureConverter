#pragma once
#include <string>
#include "DirectXTex/DirectXTex.h"
class TextureConverter
{
private:
	//�摜�̏��
	DirectX::TexMetadata metadata_;
	//�摜�C���[�W�̃R���e�i
	DirectX::ScratchImage scratchImage_;

	//�f�B���N�g���p�X
	std::wstring directoryPath_;
	//�t�@�C����
	std::wstring fileName_;
	//�t�@�C���g���q
	std::wstring fileExt_;
	//�~�b�v���x��
	size_t mipLevel_ = 0;
public:
	/// <summary>
	/// �e�N�X�`����WIC����DDS�ɕϊ�����
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	/// <param name="numOptions">���Ԃ����̐�</param>
	/// <param name="filePath">�I�v�V�����z��</param>
	void ConvertTextureWICToDDS(const std::string& filePath,
		int numOptions = 0,char* options[] = nullptr);

	static void OutputUsage();
private:
	/// <summary>
	/// �e�N�X�`���t�@�C���ǂݍ���
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void LoadWICTextureFromFile(const std::string& filePath);
	/// <summary>
	/// �t�H���_�p�X�ƃt�@�C�����𕪗�����
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void SeparateFilePath(const std::wstring& filePath);
	/// <summary>
	/// DDS�e�N�X�`���Ƃ��ăt�@�C�������o��
	/// </summary>
	void SaveDDSTextureToFile(int numOptions, char* options[]);

	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);
};

