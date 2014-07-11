//********************************************************************
//	�ļ�����:	CEffect.h
//	��������:	2014-6-4 14:14
//	��Ȩ��Ϣ: 	www.cocos2dres.com
//	�� �� ��:   Rare
//  ����˵��:   ��Чʵ��
//	�޸ļ�¼:	
//********************************************************************
#ifndef _CEFFECT_H_
#define _CEFFECT_H_

#include "IRenderable.h"
#include "cocos2dx_types.h"
#include "cocos2dx_macros.h"

NS_CC_ENGINE_BEGIN

struct IEffectProp;
struct IEffectUnitProp;
struct IEffectUnit;
class CEffectUnit;

struct SEffectTrack
{
	SEffectTrack() : pEffectUnit(NULL), fStartPos(0.0f), fEndPos(1.0f), bActive(false) {}

	IEffectUnit*	pEffectUnit;
	float32			fStartPos;
	float32			fEndPos;
	bool			bActive;
};

class CEffect : public IEffect
{
public:
	CEffect( uint32 uID );
	~CEffect(void);

	typedef std::vector< SEffectTrack* > EffectUnitVec;

	/**
	@brief ����
	@param szPicFileName ��Դ�ļ���
	@param ptOffset ƫ��ֵ
	@return ���ش����ɹ�����ʶ
	*/
	virtual bool		create( const char* szEffectFileName, CCPoint ptOffset = ccp(0,0) );

	/**
	 @brief �ͷ�
	 @param 
	*/
	virtual void		release();

	/**
	 @brief ����
	 @param 
	*/
	virtual void		update(float dt);

	/**
	 @brief ��ȡ��Ч����
	 @param 
	*/
	virtual IEffectProp* getEffectProp();


		/**
	@brief 
	@param
	*/
	virtual void		onExit();

	/**
	@brief �������ɫ
	@param
	*/
	virtual void		setColor( const ccColor3B& color );

	/**
	@brief ����ID
	@param
	*/
	virtual void		setID( uint32 uID ) { m_uID = uID; }

	/**
	@brief ��ȡID
	@param
	*/
	virtual uint32		getID() { return m_uID; }

	/**
	@brief ����͸����
	@param byAlpha ͸����
	*/
	virtual void		setOpacity( BYTE byAlpha );

	/**
	@brief ��ȡ�ö����������(ȫ��Ψһ)
	@param strFeature ������
	*/
	virtual void		getFeatureString( std::string& strFeature );

	/**
	@brief ��ȡ��ͼ�ļ���
	@param
	*/
	virtual const std::string getFileName() { return m_strEffectName; }

	/**
	@brief ��ײ���
	@param
	*/
	virtual bool		hitTest( const CCPoint& pt );

	/**
	@brief ��ײ���
	@param
	*/
	virtual bool		hitTest( const CCRect& rect );

	/**
	@brief ��ȡ�����Χ��
	@param
	*/
	virtual bool		getBoundingBox( CCRect& boundBox );

	/**
	@brief ��ȡƫ��
	@param
	*/
	virtual void		setOffset( CCPoint& ptOffet );

	/**
	@brief ��ȡƫ��
	@param
	*/
	virtual void		getOffset( CCPoint& ptOffet );

	/**
	 @brief ������Ч
	 @param pEffectProp ��Ч����
	*/
	bool				createEffect( IEffectProp* pEffectProp );

	/**
	 @brief ������Ч��Ԫ
	 @param[in] pEffectUnitProp ��Ч��Ԫ����
	*/
	CEffectUnit*		createEffectUnit( IEffectUnitProp* pEffectUnitProp );

	/**
	 @brief �ͷ���Ч��Ԫ
	 @param[in] pEffectUnit ��Ч��Ԫ
	*/
	void				releaseEffectUnit( IEffectUnit* pEffectUnit );

private:

	std::string			m_strEffectName;
	uint32				m_uID;						/// ��ЧID
	uint32				m_uEffectUnitID;			/// ��Ч��ԪID

	IEffectProp*		m_pEffectProp;				/// ��Ч����

	EffectUnitVec		m_vecEffectUnitTrack;		/// ��Ч�������

	uint32				m_uStartTime;				/// ��Чʱ��
};

NS_CC_ENGINE_END

#endif // _CEFFECT_H_