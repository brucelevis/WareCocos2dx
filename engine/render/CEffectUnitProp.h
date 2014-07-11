//********************************************************************
//	�ļ�����:	CEffectUnitProp.h
//	��������:	2014-6-4 17:02
//	��Ȩ��Ϣ: 	www.cocos2dres.com
//	�� �� ��:   Rare
//  ����˵��:   ��Ч��Ԫ����ʵ��
//	�޸ļ�¼:	
//********************************************************************
#ifndef _CEFFECTUNITPROP_H_
#define _CEFFECTUNITPROP_H_

#include "IEffectUnitProp.h"
#include "EffectProp.h"

NS_CC_ENGINE_BEGIN

class CEffectUnitProp : public IEffectUnitProp
{
	friend class CEffectUnit;
public:
	/// IEffectUnitProp
	virtual bool			loadProp( CWareFileRead& File );
	virtual void			saveProp( CWareFileWrite& File );

	virtual int32			setProp( std::vector< EffectProp* >& PropList ) { return 0; }
	virtual void			getProp( std::vector< EffectProp* >& PropList ) {}

	virtual uint32			getAdvanceProp( OffsetMap& Offset, NameMap& Texture,SizeMap& Size, ColorMap& Color, AlphaMap& Alpha );
	virtual void			setAdvanceProp( OffsetMap& Offset, NameMap& Texture,SizeMap& Size, ColorMap& Color, AlphaMap& Alpha );

	virtual void			registerProp() {}

	const NameMap&			getTextureList()	{ return m_mapTextureFileName; }

protected:

	OffsetMap					m_mapOffset;
	NameMap						m_mapTextureFileName;
	SizeMap						m_mapSize;
	ColorMap					m_mapColor;
	AlphaMap					m_mapAlpha;

	uint32						m_uAdvancePropFlag;
	std::vector< EffectProp* >	m_vecProps;
};

NS_CC_ENGINE_END

#endif // _CEFFECTUNITPROP_H_