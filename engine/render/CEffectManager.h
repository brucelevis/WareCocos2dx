//********************************************************************
//	�ļ�����:	CEffectManager.h
//	��������:	2014-6-5 9:45
//	��Ȩ��Ϣ: 	www.cocos2dres.com
//	�� �� ��:   Rare
//  ����˵��:   ��Ч������
//	�޸ļ�¼:	
//********************************************************************
#ifndef _CEFFECTMANAGER_H_
#define _CEFFECTMANAGER_H_

#include "cocos2d.h"
#include "cocos2dx_types.h"
#include "cocos2dx_macros.h"

NS_CC_ENGINE_BEGIN

struct IEffect;
struct IEffectProp;

//class CEffectSprite;
//class IParticleAffector;
//class IResourceManager;

//#define MAX_PARTICLE_COUNT  30000

//struct SParticle
//{
//	SParticle() : pSprite(NULL), nLiftTime(0), pNext(NULL) {}
//
//	CEffectSprite*		pSprite;
//	int32				nLiftTime;
//	IParticleAffector*	pAffector;
//	SParticle*			pNext;
//};
//
///// ����Ӱ����
//class IParticleAffector
//{
//public:
//	virtual void update( SParticle* pParticle, uint32 uCurTime ) = 0;
//};

/// ����
class CEffectManager
{
private:
	CEffectManager(void);
	~CEffectManager(void);

public:
	
	static CEffectManager& getInstance()
	{
		static CEffectManager _instance;
		return _instance;
	}

	//SParticle* 		allocParticle();
	//void			freeParticle( SParticle* pParticel );

	/// ���·�����������ʹ��
	/**
	 @brief ��������Ч
	 @param 
	*/
	IEffect*		createEffect( IEffectProp* pEffectProp );

	/**
	 @brief ������Ч�ļ�����
	 @param 
	*/
	IEffect*		createEffectFromFile( const char* szEffectFileName );

	///**
	// @brief �ͷ���Ч
	// @param 
	//*/
	//void			releaseEffect( IEffect* pEffect );

	/**
	 @brief ������Ч
	 @param 
	*/
	void			saveEffect( const char* szFileName, IEffect* pEffect );

	bool			update( uint32 uCurTime );

private:

	uint32			m_uEffectIDSeed;
	//int32			m_nCurParticle;
	//SParticle		m_Particle[MAX_PARTICLE_COUNT];
	//SParticle*	m_ParticlePtr[MAX_PARTICLE_COUNT];
};

NS_CC_ENGINE_END

#endif // _CEFFECTMANAGER_H_
