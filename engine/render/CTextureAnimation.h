//********************************************************************
//	�ļ�����:	CTextureAnimation.h
//	��������:	2014-6-5 11:07
//	��Ȩ��Ϣ: 	www.cocos2dres.com
//	�� �� ��:   Rare
//  ����˵��:   ��ͼ����
//	�޸ļ�¼:	
//********************************************************************
#ifndef _CTEXTUREANIMATION_H_
#define _CTEXTUREANIMATION_H_

#include "cocos2d.h"
#include "CEffectUnit.h"

NS_CC_ENGINE_BEGIN

class CTextureAnimation : public CEffectUnit
{
public:
	CTextureAnimation( IEffectUnitProp* pEffectUnitProp,uint32 uID );
	~CTextureAnimation(void);

	/**
	 @brief ����
	 @param 
	*/
	virtual bool		create();

	/**
	@brief ����
	@param dt ֡���ʱ��
	*/
	virtual void		update( float32 dt );

	/**
	 @brief ������Ч��Ԫ����(����ʹ��)
	 @param 
	*/
	virtual	void		setEffectUnitProp( IEffectUnitProp* pProp );

private:

	CCSprite*			m_pSprite;
};

NS_CC_ENGINE_END

#endif // _CTEXTUREANIMATION_H_
