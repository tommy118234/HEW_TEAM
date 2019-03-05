//=============================================================================
//
// ���U���g���� [result.h]
// Author : HAL�������ԕ� 2�N���Q�[���w�� GP11B341 24 �����a�P
//
//=============================================================================
#ifndef _RESULT_H_
#define _RESULT_H_


//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "main.h"


//*****************************************************************************
// �}�N���E�񋓌^��`
//*****************************************************************************
// ���U���g�^�C�v
enum RESULT_TYPE {
	GAME_CLEAR,		// �N���A
	GAME_OVER,		// �Q�[���I�[�o�[
	RESULT_MAX		// ���U���g�̐�
};

//*****************************************************************************
// �\���̒�`
//*****************************************************************************
// ���U���g�\����
struct GAMERESULT {
	LPDIRECT3DTEXTURE9				pTexture[RESULT_MAX];		// �e�N�X�`���ւ̃|�C���^
	VERTEX_2D						vertexWk[NUM_VERTEX];		// ���_���i�[���[�N
	D3DXVECTOR3						pos;						// ���W
	D3DXVECTOR3						rot;						// ��]
};


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
// ���U���g�̏���������
HRESULT InitResult(int type);
// ���U���g�̏I������
void UninitResult(void);
// ���U���g�̍X�V����
void UpdateResult(void);
// ���U���g�̕`�揈��
void DrawResult(void);


#endif