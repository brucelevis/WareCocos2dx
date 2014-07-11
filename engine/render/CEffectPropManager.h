//********************************************************************
//	�ļ�����:	CEffectPropManager.h
//	��������:	2014-6-5 9:49
//	��Ȩ��Ϣ: 	www.cocos2dres.com
//	�� �� ��:   Rare
//  ����˵��:   ��Ч������Դ������
//	�޸ļ�¼:	
//********************************************************************
#ifndef _CEFFECTPROPMANAGER_H_
#define _CEFFECTPROPMANAGER_H_

#include "cocos2dx_types.h"
#include "cocos2dx_macros.h"
#include <map>

NS_CC_ENGINE_BEGIN

struct IEffect;
struct IEffectProp;

class CEffectPropManager
{
private:
	CEffectPropManager(void);
	~CEffectPropManager(void);

	/**
	 @brief ��Ч������Ϣ
	 @param 
	*/
	struct SEffectPropInfo
	{
		IEffectProp*	pEffectProp;
		uint32			uLastUseTime;
		int32			nRecycleLevel;

		SEffectPropInfo() : pEffectProp(NULL), uLastUseTime(0),nRecycleLevel(0xffffffff) {}
	};

	typedef std::map< std::string, SEffectPropInfo >	EffectPropMap;

public:

	static CEffectPropManager& Instance()
	{
		static CEffectPropManager _inst;
		return _inst;
	}

	/// �˺���ֻ���ڹ��߿���
	/**
	 @brief ��������Ч����
	 @param[inout] ppEffectProp ��Ч���Զ���ָ��
	 @param[in] nRecycleLevel ���յȼ�
	*/
	int32			createEmptyEffectProp( IEffectProp** ppEffectProp, int32 nRecycleLevel = 0xffffffff );

	/**
	 @brief ������Ч
	 @param[in] szEffectName ��Ч����
	 @param[inout] ppEffectProp ��Ч���Զ���ָ��(���ڷ���)
	 @param[in] nRecycleLevel ���յȼ�
	*/
	int32			createEffectProp( const char* szEffectName, IEffectProp** ppEffectProp, int32 nRecycleLevel = 0xffffffff );

	/**
	 @brief �ͷ���Ч����
	 @param[in] pEffectProp ��Ч����
	*/
	void			releaseEffectProp( IEffectProp* pEffectProp );

	/**
	 @brief ������Ч����(����ʹ��)
	 @param[in] szEffectFileName ��Ч����
	 @param[in] pEffect ��Ч
	*/
	bool			saveEffect( const char* szEffectFileName, IEffect* pEffect );

	///**
	// @brief ����
	// @param dt ֡���ʱ��
	//*/
	//void			update( float32 dt );

protected:

	EffectPropMap	m_mapEffectProp;


	uint32			m_uIDSeed;
	///**
	// @brief �ͷ���Դ
	// @param 
	//*/
	//virtual void	DestroyRes( IResource* pResouce );

	///**
	// @brief Ӧ����Դ
	// @param 
	//*/
	//int32			applyEffect( IEffectProp* pEffectProp );
};

NS_CC_ENGINE_END

#endif // _CEFFECTPROPMANAGER_H_
