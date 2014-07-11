//********************************************************************
//	�ļ�����:	CTextureAnimationProp.h
//	��������:	2014-6-5 11:29
//	��Ȩ��Ϣ: 	www.cocos2dres.com
//	�� �� ��:   Rare
//  ����˵��:   ��ͼ��������
//	�޸ļ�¼:	
//********************************************************************
#ifndef _CTEXTUREANIMATIONPROP_H_
#define _CTEXTUREANIMATIONPROP_H_

#include "CEffectUnitProp.h"

NS_CC_ENGINE_BEGIN

class CTextureAnimationProp : public CEffectUnitProp
{
	friend class CTextureAnimation;
public:
	CTextureAnimationProp();   /// ���캯���е����麯�����������
	~CTextureAnimationProp(void);

	virtual int32			getType()			{ return EFFECTUNIT_TYPE_TEXTUREANI; }

	virtual bool			loadProp( CWareFileRead& File );
	virtual void			saveProp( CWareFileWrite& File );

	virtual int32			setProp( std::vector< EffectProp* >& PropList );
	virtual void			getProp( std::vector< EffectProp* >& PropList );

	virtual const std::string&	getEffectUnitName()	{ return m_strEffectUnitName; }

	virtual uint32			getAdvanceProp( OffsetMap& Offset, NameMap& Texture,SizeMap& Size, ColorMap& Color, AlphaMap& Alpha );

	virtual void			registerProp();

protected:

	std::vector< EffectProp* >	m_vecProp;
	std::string				m_strEffectUnitName;

	int32					m_nWidth;		/// ���
	int32					m_nHeight;		/// �߶�
	int32					m_nTotalTime;	/// �������е���ʱ��
	int32					m_nRenderMode;
	CCPoint					m_Pos;			/// λ��
};

NS_CC_ENGINE_END

#endif // _CTEXTUREANIMATIONPROP_H_