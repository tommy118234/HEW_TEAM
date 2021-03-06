//=============================================================================
//
// 背景処理 [bg.h]
// Author : HAL東京昼間部 2年制ゲーム学科 GP11B341 24 中込和輝
//
//=============================================================================
#ifndef _BG_H_
#define _BG_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "main.h"


//*****************************************************************************
// マクロ・列挙型定義
//*****************************************************************************


//*****************************************************************************
// 構造体定義
//*****************************************************************************
// 背景構造体
struct GAMEBG 
{
	LPDIRECT3DTEXTURE9				pTexture;					// テクスチャへのポインタ
	VERTEX_2D						vertexWk[NUM_VERTEX];		// 頂点情報格納ワーク
	D3DXVECTOR3						pos;						// 座標
	D3DXVECTOR3						rot;						// 回転
};


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
// 背景の初期化処理
HRESULT InitBg(int type);
// 背景の終了処理
void UninitBg(void);
// 背景の更新処理
void UpdateBg(void);
// 背景の描画処理
void DrawBg(void);
// BGの取得
GAMEBG *GetBg(void);
// 頂点カラーの設定
void SetColorBg(GAMEBG *bg, D3DCOLOR setCol);	// 頂点カラーの設定

#endif