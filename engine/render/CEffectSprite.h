//********************************************************************
//	�ļ�����:	CEffectSprite.h
//	��������:	2014-6-5 10:56
//	��Ȩ��Ϣ: 	www.cocos2dres.com
//	�� �� ��:   Rare
//  ����˵��:   ��Ч����
//	�޸ļ�¼:	
//********************************************************************
#ifndef _CEFFECTSPRITE_H_
#define _CEFFECTSPRITE_H_

#include "cocos2d.h"
#include "cocos2dx_macros.h"

NS_CC_ENGINE_BEGIN

class CEffectSprite : public CCSprite
{
public:
	CEffectSprite() {}

	//virtual void	GetWorldTransform( CMatrix4& matWorld );
	//virtual float32 GetCameraSpaceDepth();

	////void			SetZWrite( VBOOL bZWriteEnable );

	//void			SetWorldTrans( CTransform& Trans )	{ m_Transform = Trans; }

private:

	//CTransform		m_Transform;
};

NS_CC_ENGINE_END

#endif // _CEFFECTSPRITE_H_
