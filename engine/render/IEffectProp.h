//*************************************************************************
//	��������:	2014-5-11   13:42
//	�ļ�����:	IEffectProp.h
//	�� �� ��:	Rare
//  �汾����:   www.cocos2dres.com
//	˵    ��:	��Ч��������
//*************************************************************************
#ifndef _IEFFECTPROP_H_
#define _IEFFECTPROP_H_

#include "cocos2d.h"
#include "cocos2dx_types.h"
#include "cocos2dx_macros.h"
#include <string>

NS_CC_ENGINE_BEGIN

struct IEffectUnitProp;

/// EffectTrack
struct SEffectUnitPropTrack
{
	SEffectUnitPropTrack() : fStartPos(0.0f), fEndPos(1.0f), pEffectUnitProp(NULL) {}

	float32				fStartPos;
	float32				fEndPos;
	IEffectUnitProp*	pEffectUnitProp; 
};

typedef std::vector< SEffectUnitPropTrack* >	EffectUnitTrack;

struct IEffectProp : public CCObject
{
	//////////////////////////////////////////////////////////////////////////
	/// ΪTool׼���ĺ���
	/**
	 @brief �����Ч��Ԫ����
	 @param 
	*/
	virtual int32					addEffectUnitProp( int32 nEffectUnitType ) = 0;
	/**
	 @brief ������Ч��Ԫ����
	 @param 
	*/
	virtual void					insertEffectUnitProp( int32 nIndex, int32 nEffectUnitType ) = 0;

	/// �����еĹ������EffectUnitProp, ���֮ǰ�Ѿ�����һ��EffectUnitProp,���滻����ǰ��
	virtual void					setEffectUnitProp( int32 nIndex, int32 nEffectUnitType ) = 0;
	virtual SEffectUnitPropTrack*	getEffectTrack( int32 nIndex ) = 0;
	virtual void					removeEffectUnitProp( int32 nIndex ) = 0;
	virtual const EffectUnitTrack&	getEffectUnitTracks() = 0;

	/**
	 @brief ��ȡID
	 @param 
	*/
	virtual int32					getID() = 0;
	/**
	 @brief ��Ч��
	 @param 
	*/
	virtual bool					isValid() = 0;

	/// ��������
	virtual const std::string&		getCustomName() = 0;
	virtual void					setCustomName( const std::string& strName ) = 0;
	virtual uint32					getEffectTime() = 0;
	virtual void					setEffectTime( uint32 uTime ) = 0;
	//////////////////////////////////////////////////////////////////////////
};

NS_CC_ENGINE_END

#endif // _IEFFECTPROP_H_