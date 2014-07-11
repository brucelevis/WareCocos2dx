//********************************************************************
//	�ļ�����:	DragonBoneSpriteObj.h
//	��������:	2014-4-26 13:41
//	��Ȩ��Ϣ: 	www.cocos2dres.com
//	�� �� ��:   Rare
//  ����˵��:   DragonBone����ʵ��
//	�޸ļ�¼:	
//********************************************************************
#ifndef _DRAGONBONESPRITEOBJ_H_
#define _DRAGONBONESPRITEOBJ_H_

#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocos2dx_types.h"
#include "cocos2dx_macros.h"
#include "DragonBoneAnimation.h"
#include "IRenderable.h"

NS_CC_ENGINE_BEGIN

/**
@brief DragonBone������������
*/
class CDragonBoneSpriteObj : public IDragonBoneSprite
{
public:

	CDragonBoneSpriteObj(uint32 uID);
	~CDragonBoneSpriteObj(void);

	/**
	@brief ����
	@param szPicFileName ��Դ�ļ���
	@param ptOffset ƫ��ֵ
	@return ���ش����ɹ�����ʶ
	*/
	virtual bool		create( const char* szAniFileName, CCPoint ptOffset = ccp(0,0) );

	/**
	@brief ����
	@param
	*/
	virtual void		update( float dt );

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
	virtual const std::string getFileName() { return m_strPicFileName; }

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
	@brief 
	@param
	*/
	virtual CCSprite*	getSprite() { return (CCSprite*)NULL; }

	/**
	@brief ��ȡ�����Χ��
	@param
	*/
	virtual bool		getBoundingBox( CCRect& boundBox );

	/**
	@brief ��ȡ�������ſ���
	@param
	*/
	virtual IAnimation*	getAnimation() { return (IAnimation*)&m_Animate; }

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

private:

	std::string				m_strPicFileName;	/// ��ͼ�ļ���
	CDragonBoneAnimation	m_Animate;			/// ����ʵ��

	extension::CCArmature*	m_pArmature;		/// ������������

};

NS_CC_ENGINE_END

#endif // _DRAGONBONESPRITEOBJ_H_
