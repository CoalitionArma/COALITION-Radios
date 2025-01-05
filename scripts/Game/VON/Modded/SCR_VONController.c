modded class SCR_VONController
{
	[Attribute(defvalue: "Sounds/VON/beepstart.wav", params: "wav")]
	protected ResourceName m_sRadioSound;
	
	[Attribute(defvalue: "Sounds/VON/beepend.wav", params: "wav")]
	protected ResourceName m_sRadioSoundEnd;
	
	override void ActivateVON(EVONTransmitType transmitType)
	{
		super.ActivateVON(transmitType);
		
		if (transmitType != EVONTransmitType.DIRECT && transmitType != EVONTransmitType.NONE)
			AudioSystem.PlaySound(m_sRadioSound);
	}
	
	override void DeactivateVON(EVONTransmitType transmitType = EVONTransmitType.NONE)
	{
		super.DeactivateVON(transmitType);
		
		if (transmitType != EVONTransmitType.DIRECT && transmitType != EVONTransmitType.NONE)
			AudioSystem.PlaySound(m_sRadioSoundEnd);	
	}
};
