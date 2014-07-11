//*************************************************************************
//	��������:	2014-5-11   13:45
//	�ļ�����:	IEffectUnit.h
//	�� �� ��:	Rare
//  �汾����:   www.cocos2dres.com
//	˵    ��:	��Ч��Ԫ
//*************************************************************************
#ifndef _IEFFECTUNIT_H_
#define _IEFFECTUNIT_H_

#include "cocos2d.h"
#include "cocos2dx_types.h"
#include "cocos2dx_macros.h"

NS_CC_ENGINE_BEGIN

struct IEffectUnitProp;

struct IEffectUnit : public CCNode
{
	/**
	 @brief ��ȡ��Ч��ԪID
	 @param 
	*/
	virtual uint32				getID() = 0;

	/**
	 @brief ����
	 @param 
	*/
	virtual bool				create() = 0;

	/**
	@brief ��ȡ��Ч��Ԫ����
	@param
	*/
	virtual IEffectUnitProp*	getEffectUnitProp() = 0;

	/**
	@brief ��ȡ��Ч��Ԫ����
	@param
	*/
	virtual	void				setEffectUnitProp( IEffectUnitProp* pProp ) = 0;
};

NS_CC_ENGINE_END

#endif // _IEFFECTUNIT_H_