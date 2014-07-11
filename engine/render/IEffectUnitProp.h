//*************************************************************************
//	��������:	2014-5-11   13:55
//	�ļ�����:	IEffectUnitProp.h
//	�� �� ��:	Rare
//  �汾����:   www.cocos2dres.com
//	˵    ��:	��Ч��Ԫ����
//*************************************************************************
#ifndef _IEFFECTUNITPROP_H_
#define _IEFFECTUNITPROP_H_

#include "cocos2d.h"
#include "cocos2dx_types.h"
#include "cocos2dx_macros.h"
#include "WareFileRead.h"
#include "WareFileWrite.h"
#include "EffectProp.h"

NS_CC_ENGINE_BEGIN

enum EEffectUnitType
{
	EFFECTUNIT_TYPE_UNKOWN = 0,
	EFFECTUNIT_TYPE_TEXTUREANI,
	EFFECTUNIT_TYPE_PARTICLESYS,

	EFFECTUNIT_TYPE_COUNT,
};

struct IEffectUnitProp : public CCObject
{
	/**
	@brief ��ȡ��Ч��Ԫ����
	@param
	*/
	virtual int32				getType() = 0;
	/**
	@brief ������Ч��Ԫ
	@param
	*/
	virtual bool				loadProp( CWareFileRead& File ) = 0;
	/**
	@brief ������Ч��Ԫ����
	@param
	*/
	virtual void				saveProp( CWareFileWrite& File ) = 0;

	/// ���·��� �ǿ��Ÿ�����ʹ��
	/**
	@brief ��ȡ��Ч��Ԫ����
	@param
	*/
	virtual const std::string&	getEffectUnitName() = 0;
	/**
	@brief ��ȡ��Ч��Ԫ����
	@param
	*/
	virtual void				getProp( std::vector< EffectProp* >& PropList ) = 0;
	/**
	@brief ��ȡ��Ч��Ԫ����
	@param PropList �����б�
	@return �����˶��ٸ�����
	*/
	virtual int32				setProp( std::vector< EffectProp* >& PropList ) = 0;
	/**
	@brief ��ȡ�߼�����
	@param
	*/
	virtual uint32				getAdvanceProp( OffsetMap& Offset, NameMap& Texture,SizeMap& Size, ColorMap& Color, AlphaMap& Alpha ) = 0;
	/**
	@brief ���ø߼�����
	@param
	*/
	virtual void				setAdvanceProp( OffsetMap& Offset, NameMap& Texture,SizeMap& Size, ColorMap& Color, AlphaMap& Alpha ) = 0;
};

NS_CC_ENGINE_END

#endif // _IEFFECTUNITPROP_H_