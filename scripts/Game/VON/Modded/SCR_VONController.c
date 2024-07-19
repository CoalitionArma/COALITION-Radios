modded class SCR_VONController
{
	[Attribute(defvalue: "Sounds/VON/beepstart.wav", params: "wav")]
	protected ResourceName m_sRadioSound;
	
	[Attribute(defvalue: "Sounds/VON/beepend.wav", params: "wav")]
	protected ResourceName m_sRadioSoundEnd;
	
	protected AudioHandle m_AudioHandleRadioSqawk;
	protected AudioHandle m_AudioHandleRadioSqawkRadioSqawkOff;
	
	//------------------------------------------------------------------------------------------------
	//! VON channel speech listener callback
 	override protected void OnVONChannel(float value, EActionTrigger reason)
	{
		if (reason == EActionTrigger.DOWN)
		{
			m_bIsActiveModeLong = false;
			if (!AudioSystem.IsSoundPlayed(m_AudioHandleRadioSqawk))
					AudioSystem.TerminateSound(m_AudioHandleRadioSqawk);
				
			m_AudioHandleRadioSqawk = AudioSystem.PlaySound(m_sRadioSound);			
			
			VONChannel(true);
		}
		else {
				AudioSystem.TerminateSound(m_AudioHandleRadioSqawk);
				
				if (!AudioSystem.IsSoundPlayed(m_AudioHandleRadioSqawkRadioSqawkOff))
						AudioSystem.TerminateSound(m_AudioHandleRadioSqawkRadioSqawkOff);
				
				m_AudioHandleRadioSqawkRadioSqawkOff = AudioSystem.PlaySound(m_sRadioSoundEnd);
			
				VONChannel(false);
		}
	}
};
