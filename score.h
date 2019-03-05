//=============================================================================
//
// �X�R�A���� [score.h]
// Author : HAL�������ԕ� 2�N���Q�[���w�� GP11B341 24 �����a�P
//
//=============================================================================
#ifndef _SCORE_H_
#define _SCORE_H_


//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "main.h"


//*****************************************************************************
// �}�N���E�񋓌^��`
//*****************************************************************************
#define ADD_SCORE_VALUE			(100)


//*****************************************************************************
// �\���̒�`
//*****************************************************************************
// �X�R�A�\����
struct GAMESCORE {
	LPDIRECT3DTEXTURE9			pTexture;					// �e�N�X�`���ւ̃|�C���^
	VERTEX_2D					vertexWk[NUM_VERTEX];		// ���_���i�[���[�N
	D3DXVECTOR3					pos;						// ���W
	D3DXVECTOR3					rot;						// ��]

	int							value;						// �X�R�A�l
};


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
// �X�R�A�̏���������
HRESULT InitScore(int type);
// �X�R�A�̏I������
void UninitScore(void);
// �X�R�A�̍X�V����
void UpdateScore(void);
// �X�R�A�̕`�揈��
void DrawScore(void);
// �X�R�A�����Z
void AddScore(int addValue);



#endif