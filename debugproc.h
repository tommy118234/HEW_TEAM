//=============================================================================
//
// �f�o�b�O�\������ [debugproc.h]
//
//=============================================================================
#ifndef _DEBUGPROC_H_
#define _DEBUGPROC_H_


//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "main.h"


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitDebugProc(void);
void UninitDebugProc(void);
void UpdateDebugProc(void);
void DrawDebugProc(void);
void PrintDebugProc(int no, const char *fmt,...);
#endif