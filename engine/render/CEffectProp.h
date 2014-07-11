//*************************************************************************
//	��������:	2014-5-11   13:59
//	�ļ�����:	CEffectProp.h
//	�� �� ��:	Rare
//  �汾����:   www.cocos2dres.com
//	˵    ��:	��Ч����
//*************************************************************************
#ifndef _CEFFECTPROP_H_
#define _CEFFECTPROP_H_

#include "cocos2d.h"
#include "cocos2dx_types.h"
#include "cocos2dx_macros.h"
#include "IEffectProp.h"

NS_CC_ENGINE_BEGIN

class CEffectUnitProp;

//////////////////////////////////////////////////////////////////////////
/// ����˵���¼�������: CEffectProp ->  CEffect
///						CEffectUnitProp -> CEffectUnit
/// һ��CEffect���ɶ��CEffectUnit����ɵģ������ڸ��Բ�ͬ�Ĺ����
/// CEffectProp����ľ��Ǹ���EffectUnit�Ĺ�ϵ����Ϣ
/// CEffectUnitProp�����CEffectUnit����Ϣ
//////////////////////////////////////////////////////////////////////////
class CEffectProp : public IEffectProp
{
	friend class CEffect;
public:
	CEffectProp( uint32 uID );
	~CEffectProp();

	/**
	 @brief �ͷ�
	 @param 
	*/
	virtual void					release();

	/// ������һ��CEffectProp�����ܶ಻ͬ��CEffect,��CEffectProp������ü���������CEffectUnitProp
	/// �ǲ��ᱻ���õģ���ֻ������һ��CEffectProp�У���������ʹ��CEffectUnitProp��������key
	//typedef map< IEffectUnitProp*, SEffectUnitPropTrack* > EffectUnitTrack;
	//////////////////////////////////////////////////////////////////////////
	/// IResource
	virtual int32					getID()									{ return m_uID; }

	///// ������Դ������Ϣ
	//virtual int32					LoadDesc();
	/// ������Դ���ݲ���(ֻ����һ�����ǿ��Էŵ���һ���߳�ȥ����)
	virtual int32					loadRes();	
	///// ж����Դ���ݲ���
	//virtual int32					UnloadRes();
	///// ��Դ���ݲ���������Ϻ�Ļص�
	//virtual bool					OnResLoaded();

	virtual bool					saveRes( const char* szFileName );

	//virtual int32					Grab();
	//virtual int32					Drop();

	/**
	 @brief ��Ч��
	 @param 
	*/
	virtual bool					isValid()								{ return m_bValid; }

	//////////////////////////////////////////////////////////////////////////
	/// IEffectProp for tool
	virtual int32					addEffectUnitProp( int32 nEffectUnitType );
	virtual void					insertEffectUnitProp( int32 nIndex, int32 nEffectUnitType );
	virtual void					setEffectUnitProp( int32 nIndex, int32 nEffectUnitType );
	virtual SEffectUnitPropTrack*	getEffectTrack( int32 nIndex );
	virtual void					removeEffectUnitProp( int32 nIndex );
	virtual const EffectUnitTrack&	getEffectUnitTracks()					{ return m_vecEffectUnitProp; }

	/// ��������
	virtual const std::string&		getCustomName()							{ return m_strCustomName; }
	virtual void					setCustomName( const std::string& strName )	{ m_strCustomName = strName; }
	virtual uint32					getEffectTime()							{ return m_uTotalTime; }
	virtual void					setEffectTime( uint32 uTime )			{ m_uTotalTime = uTime; }
	//////////////////////////////////////////////////////////////////////////

	/**
	 @brief ��������
	 @param 
	*/
	bool							create( const char* szFileName );

	void							setID( uint32 uID )						{ m_uID = uID; }

	void							setResourceName( const char* szFileName )	{ m_strFileName = szFileName; }
	const std::string&				getResourceName() { return m_strFileName; }

	void							getTrackCount();

	CEffectUnitProp*				createEffectUnitProp( int32 nType );
	void							releaseEffectUnitProp( IEffectUnitProp* pEffectUnitProp );
	
protected:

	uint32							m_uID;
	std::string						m_strFileName;
	bool							m_bValid;

	std::string						m_strCustomName;
	uint32							m_uTotalTime;
	EffectUnitTrack					m_vecEffectUnitProp;
};

NS_CC_ENGINE_END

#endif // _CEFFECTPROP_H_