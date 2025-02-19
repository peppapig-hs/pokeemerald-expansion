	.align 2
voicegroup191:: @ DPPt main
	voice_directsound 60, 0, DirectSoundWaveData_dp_reverscyn_16, 255, 0, 255, 0
	voice_keysplit_all voicegroup192				 @ drums 1
	voice_keysplit voicegroup195, KeySplitTable6     @ piano
	voice_keysplit voicegroup196, KeySplitTable7     @ piano low
	voice_keysplit voicegroup197, KeySplitTable8     @ ep 1
	voice_keysplit voicegroup198, KeySplitTable9     @ ep 2
	voice_keysplit_all voicegroup193				 @ drums 2
	voice_keysplit voicegroup199, KeySplitTable10    @ clavi
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, DirectSoundWaveData_dp_glocken_c6_16, 255, 247, 0, 208
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit voicegroup200, KeySplitTable11    @ vibraphone
	voice_keysplit voicegroup201, KeySplitTable12    @ marimba
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit voicegroup203, KeySplitTable14    @ tubular bell
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit_all voicegroup194				 @ synth kick + snare
	voice_keysplit voicegroup205, KeySplitTable16    @ rotary organ
	voice_keysplit voicegroup206, KeySplitTable17    @ straight organ
	voice_directsound 60, 0, DirectSoundWaveData_dp_org5_c3_16, 255, 175, 235, 171
	voice_directsound 60, 0, DirectSoundWaveData_dp_sawtoothlead60, 255, 200, 255, 171
	voice_keysplit voicegroup207, KeySplitTable18    @ accordion
	voice_directsound 60, 0, DirectSoundWaveData_dp_harmonica_c3_16, 67, 247, 191, 171
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit voicegroup210, KeySplitTable21    @ distortion guitar 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2_alt 60, 0, 2, 0, 7, 2, 0
	voice_keysplit voicegroup212, KeySplitTable23    @ upright bass 1
	voice_directsound 60, 0, DirectSoundWaveData_dp_sting_bass_e1_16, 255, 251, 0, 208
	voice_directsound 60, 0, DirectSoundWaveData_dp_pickbass_e1_16, 255, 251, 0, 208
	voice_directsound 60, 0, DirectSoundWaveData_dp_fretlessbass_d1_16, 255, 0, 255, 196
	voice_directsound 60, 0, DirectSoundWaveData_dp_slapbass_g1_16, 255, 0, 255, 222
	voice_directsound 60, 0, DirectSoundWaveData_dp_slapbass_c1_16, 255, 0, 255, 216
	voice_directsound 60, 0, DirectSoundWaveData_dp_synbass1_c2_16, 255, 1, 255, 196
	voice_directsound 60, 0, DirectSoundWaveData_dp_synbass2_c1_16, 255, 0, 255, 222
	voice_keysplit voicegroup213, KeySplitTable24    @ violin
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2_alt 60, 0, 2, 0, 7, 10, 0
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_wind, 37, 244, 155, 226
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit voicegroup214, KeySplitTable25    @ pizzicato
	voice_keysplit voicegroup215, KeySplitTable26    @ harp
	voice_keysplit voicegroup216, KeySplitTable27    @ timpani 1
	voice_keysplit voicegroup217, KeySplitTable28    @ strings
	voice_directsound 60, 0, DirectSoundWaveData_dp_octlow_cs2_16, 255, 200, 255, 196
	voice_directsound 60, 0, DirectSoundWaveData_dp_octlowbra_b2_16, 255, 200, 255, 226
	voice_keysplit voicegroup218, KeySplitTable27    @ timpani 2
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_bubbles, 254, 0, 255, 0
	voice_directsound 60, 0, DirectSoundWaveData_dp_octhit_c2_16, 255, 200, 255, 222
	voice_keysplit voicegroup219, KeySplitTable29    @ trumpets 1
	voice_keysplit voicegroup220, KeySplitTable30    @ trombone
	voice_keysplit voicegroup221, KeySplitTable31    @ tuba
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit voicegroup223, KeySplitTable9     @ french horns
	voice_keysplit voicegroup224, KeySplitTable32    @ distortion guitar 2
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2_alt 60, 0, 0, 0, 6, 6, 2
	voice_directsound 60, 0, DirectSoundWaveData_dp_synbass_c1_16, 255, 1, 255, 216
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_2_alt 60, 0, 2, 0, 6, 6, 2
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, DirectSoundWaveData_dp_sy_clarinet_c3_16, 255, 243, 159, 216
	voice_square_2_alt 60, 0, 2, 0, 3, 6, 0
	voice_keysplit voicegroup226, KeySplitTable33    @ flute
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, DirectSoundWaveData_dp_tenorchoir48, 255, 200, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_dp_sopranochoir60, 255, 200, 255, 171

