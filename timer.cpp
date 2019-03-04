//=============================================================================
//
// �^�C�}�[���� [timer.cpp]
// Author : HAL�������ԕ� 2�N���Q�[���w�� GP11B341 24 �����a�P
//
//=============================================================================
#include "main.h"
#include "input.h"
#include "timer.h"
#include "font.h"


//*****************************************************************************
// �}�N����`
//*****************************************************************************
// �e�N�X�`���ꏊ
//#define TEXTURE_TIMER		_T("data/TEXTURE/timer.png")

// �^�C�}�[�̃T�C�Y
#define TIMER_SIZE_X		(SCREEN_WIDTH * 2)
#define TIMER_SIZE_Y		(SCREEN_HEIGHT / 5)	

// �^�C�}�[�̍��W
#define INIT_POS_X			(0.0f)
#define INIT_POS_Y			(SCREEN_HEIGHT * 0.8f)
#define MOVE_SPEED_X		(2.0f)

// �b
#define INIT_REMAIN_TIME	(60)				// �c�莞��
#define SECOND_TIME			(1000)				// �V�X�e��������̂P�b


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT MakeVertexTimer(void);					// ���_�̍쐬
void SetVertexTimer(void);						// ���_���W�̐ݒ�
void SetColorTimer(void);						// ���_�J���[�̐ݒ�
void SetTextureTimer(void);						// �e�N�X�`�����W�̐ݒ�


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
GAMETIMER timer;
LPSTR text;

//=============================================================================
// ����������
//=============================================================================
HRESULT InitTimer(int type)
{
	if (type == 0)
	{
		//// �e�N�X�`���̓ǂݍ���
		//LPDIRECT3DDEVICE9 pDevice = GetDevice();
		//D3DXCreateTextureFromFile(pDevice,
		//	TEXTURE_TIMER,
		//	&timer.pTexture);
	}

	timer.pos = D3DXVECTOR3(INIT_POS_X, INIT_POS_Y, 0.0f);
	timer.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	timer.currentTime = 0;
	timer.lastTime = 0;
	timer.displayTime = INIT_REMAIN_TIME;
	MakeVertexTimer();

	return S_OK;
}


//=============================================================================
// �I������
//=============================================================================
void UninitTimer(void)
{
	SAFE_RELEASE(timer.pTexture)
}


//=============================================================================
// �X�V����
//=============================================================================
void UpdateTimer(void)
{
	timer.currentTime = GetTime();

	//// �V�X�e��������1�b�o�߂��Ƃɕ\���^�C�����J�E���g�_�E��
	//if ((timer.currentTime - timer.lastTime) >= SECOND_TIME)
	//{
	//	timer.lastTime = timer.currentTime;
	//	timer.displayTime--;
	//}

	//wsprintf(text, TEXT("%d\n"), &timer.displayTime);

	//SetVertexTimer();
}


//=============================================================================
// �`�揈��
//=============================================================================
void DrawTimer(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	LPD3DXFONT font = GetFont(DEFAULT_FONT);
	RECT rect = { 0, 150, SCREEN_WIDTH, SCREEN_HEIGHT };
	font->DrawText(NULL, text, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0x00, 0x00, 0x00));

	//// ���_�t�H�[�}�b�g�̐ݒ�
	//pDevice->SetFVF(FVF_VERTEX_2D);

	//// �e�N�X�`���̐ݒ�
	//pDevice->SetTexture( 0, timer.pTexture );

	//// �|���S���̕`��
	//pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, NUM_POLYGON, timer.vertexWk, sizeof(VERTEX_2D));
}


//=============================================================================
// ���_�̍쐬
//=============================================================================
HRESULT MakeVertexTimer(void)
{
	// ���_���W�̐ݒ�	
	SetVertexTimer();

	// ���_�J���[�̐ݒ�
	SetColorTimer();

	// �e�N�X�`�����W�̐ݒ�
	SetTextureTimer();

	// rhw�̐ݒ�
	timer.vertexWk[0].rhw =
		timer.vertexWk[1].rhw =
		timer.vertexWk[2].rhw =
		timer.vertexWk[3].rhw = 1.0f;

	return S_OK;
}


//=============================================================================
// ���_���W�̐ݒ�
//=============================================================================
void SetVertexTimer(void)
{
	timer.vertexWk[0].vtx = D3DXVECTOR3(timer.pos.x, timer.pos.y, timer.pos.z);
	timer.vertexWk[1].vtx = D3DXVECTOR3(timer.pos.x + TIMER_SIZE_X, timer.pos.y, timer.pos.z);
	timer.vertexWk[2].vtx = D3DXVECTOR3(timer.pos.x, timer.pos.y + TIMER_SIZE_Y, timer.pos.z);
	timer.vertexWk[3].vtx = D3DXVECTOR3(timer.pos.x + TIMER_SIZE_X, timer.pos.y + TIMER_SIZE_Y, timer.pos.z);
}


//=============================================================================
// ���_�J���[�̐ݒ�
//=============================================================================
void SetColorTimer(void)
{
	timer.vertexWk[0].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
	timer.vertexWk[1].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
	timer.vertexWk[2].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
	timer.vertexWk[3].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
}


//=============================================================================
// �e�N�X�`�����W�̐ݒ�
//=============================================================================
void SetTextureTimer(void)
{
	timer.vertexWk[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	timer.vertexWk[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	timer.vertexWk[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	timer.vertexWk[3].tex = D3DXVECTOR2(1.0f, 1.0f);
}