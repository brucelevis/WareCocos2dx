//********************************************************************
//	�ļ�����:	CDragonBoneAnimation.h
//	��������:	2014-4-26 14:09
//	��Ȩ��Ϣ: 	www.cocos2dres.com
//	�� �� ��:   Rare
//  ����˵��:   DragonBone��������ʵ��
//	�޸ļ�¼:	
//********************************************************************
#ifndef _IDRAGONBONEANIMATION_H_
#define _IDRAGONBONEANIMATION_H_

#include "IAnimation.h"
#include "cocos-ext.h"

NS_CC_ENGINE_BEGIN

class CDragonBoneAnimation : public CCObject, public IAnimation
{
public:
	CDragonBoneAnimation(void);
	~CDragonBoneAnimation(void);

	/**
	 @brief ���ö�����Դ
	 @param pAnimation ��������
	*/
	void			setAnimationRes( extension::CCArmatureAnimation* pAnimation );

	/**
	@brief ���ö������Żص�
	@param
	*/
	virtual void	setAniCallback( IAnimationCallback* pAniCallBack, void* pContext );

	/**
	@brief ���Ŷ��� ����ö�������ֹͣ״̬�����������
	@param[in] szAniName ��������
	@param[in] fSpeed �����ٶ�
	@param[in] nLoops ѭ������
	@param[in] bForceUpdate �Ƿ�ǿ�Ƹ��¶�������(�������²���)
	*/
	virtual void	play( const std::string& strAniName, float fSpeed = 1.0f, int nLoops = -1, bool bForceUpdate = false );

	/**
	@brief ��ת��ָ��֡
	@param
	*/
	virtual void	gotoFrame( int nFrame ) {}

	/**
	@brief ��ȡ��ǰ֡
	@param
	*/
	virtual int		getCurFrame() { return 0; }

	/**
	@brief ���ò����ٶ�
	@param fSpeed �����ٶ�
	*/
	virtual void	speed( float fSpeed );

	/**
	@brief ��ȡ�����ٶ�
	@param fSpeed �����ٶ�
	*/
	virtual float	getSpeed();
	
	/**
	@brief ֹͣ����
	@param
	*/
	virtual void	stop(void);

	/**
	@brief ֹͣ����
	@param
	*/
	virtual void	pause(void);

	/**
	@brief �Ƿ��ڲ���
	@param
	*/
	virtual bool	isPlaying() { return m_nState == 0; }

	/**
	@brief �Ƿ���ͣ״̬
	@param
	*/
	virtual bool	isPause() { return m_nState == 1; }

	/**
	 @brief �Ƿ����ָ�����ƵĶ���
	 @param strAniName ��������
	 @return ����ָ�������������
	*/
	virtual bool	isExistClip( const std::string& strAniName );

	/**
	@brief ��ȡ�����б�
	@param[inout] animations �����б�
	*/
	virtual void	getAnimationList( std::list< std::string >& animations );

	/**
	 @brief �����ص�
	 @param pArmature ����
	 @param eMovementEventType ��������
	 @param szEventName �ص��¼�����
	*/
	void			onMovementEventCallFunc(extension::CCArmature* pArmature, extension::MovementEventType eMovementEventType, const char * szEventName );

	/**
	 @brief ֡�¼��ص�
	 @param pBone ����
	 @param pFrameEventName ֡�¼�����
	 @param nFrameID ֡ID
	 @param nTime �ص�ʱ��
	*/
	void			onFrameEventCallFunc(extension::CCBone* pBone, const char* pFrameEventName, int nFrameID, int nTime );

private:

	int								m_nState;			/// 0 �������� 1 ��ͣ 2 ֹͣ
	float							m_fSpeed;			/// ���������ٶ�
	std::string						m_strCurActionName;	/// ��ǰ��������

	extension::CCArmatureAnimation*	m_pArmatureAni;		/// ������������

	IAnimationCallback*				m_pAniCallBack;		/// �������Żص�
	void*							m_pCallBackContext;	/// �����ص�����
};

NS_CC_ENGINE_END
	
#endif // _IDRAGONBONEANIMATION_H_

