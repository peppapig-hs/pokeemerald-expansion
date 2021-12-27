Common_EventScript_SuperTrainer::
	lock
	faceplayer
	msgbox Common_Text_SuperTrainerWelcome, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_EventScript_SuperTrainerExit
	msgbox Common_Text_SuperTrainerChooseMon, MSGBOX_DEFAULT
	closemessage
Common_EventScript_SuperTrainerChooseMon:
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, Common_EventScript_SuperTrainerExit
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_ge VAR_RESULT, SPECIES_EGG, Common_EventScript_SuperTrainerInvalid
	goto Common_EventScript_SuperTrainerMainMenu

Common_EventScript_SuperTrainerExit::
	msgbox Common_Text_SuperTrainerExit, MSGBOX_DEFAULT
	release
	end

Common_EventScript_SuperTrainerInvalid::
	msgbox Common_Text_SuperTrainerChooseAgain, MSGBOX_DEFAULT
	closemessage
	goto Common_EventScript_SuperTrainerChooseMon

Common_EventScript_SuperTrainerMainMenu::
	msgbox Common_Text_SuperTrainerHowCanIHelp, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_SUPER_TRAINING_MENU, 0
	switch VAR_RESULT
	case 0, Common_EventScript_SuperTrainerTrainingEVs
	case 1, Common_EventScript_SuperTrainerResetEVs
	case 2, Common_EventScript_SuperTrainerTrainingIVs
	case 3, Common_EventScript_SuperTrainerChangeNature
	case 4, Common_EventScript_SuperTrainerChangeAbility
	case 5, Common_EventScript_SuperTrainerMoreInfo
	case MULTI_B_PRESSED, Common_EventScript_SuperTrainerExit

Common_EventScript_SuperTrainerTrainingEVs::
	msgbox Common_Text_SuperTrainerWhichStat, MSGBOX_DEFAULT
	special BufferChosenMonAllEVs
	multichoice 0, 0, MULTI_SUPER_TRAINING_MENU_STAT, 0
	goto_if_eq VAR_RESULT, MULTI_B_PRESSED, Common_EventScript_SuperTrainerMainMenu
	copyvar VAR_0x8005, VAR_RESULT
	specialvar VAR_RESULT, GetChosenMonLeftEVs
	goto_if_eq VAR_RESULT, 0, Common_EventScript_SuperTrainerReachingMaxEVs
	goto Common_EventScript_SuperTrainerChooseEVsValue

Common_EventScript_SuperTrainerReachingMaxEVs::
	msgbox Common_Text_SuperTrainerReachingMaxEVs, MSGBOX_DEFAULT
	goto Common_EventScript_SuperTrainerTrainingEVs

Common_EventScript_SuperTrainerChooseEVsValue::
	msgbox Common_Text_SuperTrainerChooseEVsValue, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_SUPER_TRAINING_MENU_EV_VALUE, 0
	switch VAR_RESULT
	case 0, Common_EventScript_SuperTrainerChooseEVsBy4
	case 1, Common_EventScript_SuperTrainerChooseEVsBy8
	case 2, Common_EventScript_SuperTrainerChooseEVsBy12
	case 3, Common_EventScript_SuperTrainerChooseEVsBy64
	case 4, Common_EventScript_SuperTrainerChooseEVsBy128
	case 5, Common_EventScript_SuperTrainerChooseEVsBy252
	case MULTI_B_PRESSED, Common_EventScript_SuperTrainerTrainingEVs

Common_EventScript_SuperTrainerChooseEVsBy4::
	setvar VAR_0x8006, 4
	setvar VAR_0x8009, 400
	goto Common_EventScript_SuperTrainerIncreaseEVs

Common_EventScript_SuperTrainerChooseEVsBy8::
	setvar VAR_0x8006, 8
	setvar VAR_0x8009, 800
	goto Common_EventScript_SuperTrainerIncreaseEVs

Common_EventScript_SuperTrainerChooseEVsBy12::
	setvar VAR_0x8006, 12
	setvar VAR_0x8009, 1200
	goto Common_EventScript_SuperTrainerIncreaseEVs

Common_EventScript_SuperTrainerChooseEVsBy64::
	setvar VAR_0x8006, 64
	setvar VAR_0x8009, 6400
	goto Common_EventScript_SuperTrainerIncreaseEVs

Common_EventScript_SuperTrainerChooseEVsBy128::
	setvar VAR_0x8006, 128
	setvar VAR_0x8009, 12800
	goto Common_EventScript_SuperTrainerIncreaseEVs
	
Common_EventScript_SuperTrainerChooseEVsBy252::
	setvar VAR_0x8006, 252
	setvar VAR_0x8009, 25200
	goto Common_EventScript_SuperTrainerIncreaseEVs

Common_EventScript_SuperTrainerIncreaseEVs::
	showmoneybox 0, 0, 0
	buffernumberstring 2, VAR_0x8009
	msgbox Common_Text_SuperTrainerDisplayCost, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_EventScript_SuperTrainerIncreaseEVsRefused
	checkmoney VAR_0x8009, 0
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_SuperTrainerNotEnoughMoneyIncreaseEVs
	removemoney VAR_0x8009, 0
	updatemoneybox
	playse SE_SHOP
	special IncreaseChosenMonEV
	msgbox Common_Text_SuperTrainerDoneTraining, MSGBOX_DEFAULT
	hidemoneybox
	goto Common_EventScript_SuperTrainerTrainingEVs

Common_EventScript_SuperTrainerIncreaseEVsRefused::
	hidemoneybox
	goto Common_EventScript_SuperTrainerTrainingEVs

Common_EventScript_SuperTrainerNotEnoughMoneyIncreaseEVs::
	hidemoneybox
	msgbox Common_Text_SuperTrainerNotEnoughMoney, MSGBOX_DEFAULT
	goto Common_EventScript_SuperTrainerTrainingEVs

Common_EventScript_SuperTrainerResetEVs::
	msgbox Common_Text_SuperTrainerWantToResetEVs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_EventScript_SuperTrainerMainMenu
	playse SE_SHOP
	special ResetChosenMonEVs
	msgbox Common_Text_SuperTrainerDoneTraining, MSGBOX_DEFAULT
	goto Common_EventScript_SuperTrainerMainMenu

Common_EventScript_SuperTrainerTrainingIVs::
	msgbox Common_Text_SuperTrainerTrainingIVs, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_SUPER_TRAINING_MENU_IV_MENU, 0
	switch VAR_RESULT
	case 0, Common_EventScript_SuperTrainerChangeIVs
	case 1, Common_EventScript_SuperTrainerChangeHiddenPowerType
	case MULTI_B_PRESSED, Common_EventScript_SuperTrainerMainMenu

Common_EventScript_SuperTrainerChangeIVs::
	msgbox Common_Text_SuperTrainerWhichStat, MSGBOX_DEFAULT
	special BufferChosenMonAllIVs
	multichoice 0, 0, MULTI_SUPER_TRAINING_MENU_STAT, 0
	goto_if_eq VAR_RESULT, MULTI_B_PRESSED, Common_EventScript_SuperTrainerTrainingIVs
	copyvar VAR_0x8005, VAR_RESULT
	goto Common_EventScript_SuperTrainerChooseIVsValue

Common_EventScript_SuperTrainerChooseIVsValue::
	msgbox Common_Text_SuperTrainerChooseIVsValue, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_SUPER_TRAINING_MENU_IV_VALUE, 0
	switch VAR_RESULT
	case 0, Common_EventScript_SuperTrainerChooseIVsBy0
	case 1, Common_EventScript_SuperTrainerChooseIVsBy1
	case 2, Common_EventScript_SuperTrainerChooseIVsBy14
	case 3, Common_EventScript_SuperTrainerChooseIVsBy15
	case 4, Common_EventScript_SuperTrainerChooseIVsBy30
	case 5, Common_EventScript_SuperTrainerChooseIVsBy31
	case MULTI_B_PRESSED, Common_EventScript_SuperTrainerChangeIVs

Common_EventScript_SuperTrainerChooseIVsBy0::
	setvar VAR_0x8006, 0
	setvar VAR_0x8009, 0
	goto Common_EventScript_SuperTrainerSetIVs

Common_EventScript_SuperTrainerChooseIVsBy1::
	setvar VAR_0x8006, 1
	setvar VAR_0x8009, 100
	goto Common_EventScript_SuperTrainerSetIVs

Common_EventScript_SuperTrainerChooseIVsBy14::
	setvar VAR_0x8006, 14
	setvar VAR_0x8009, 1400
	goto Common_EventScript_SuperTrainerSetIVs

Common_EventScript_SuperTrainerChooseIVsBy15::
	setvar VAR_0x8006, 15
	setvar VAR_0x8009, 1500
	goto Common_EventScript_SuperTrainerSetIVs

Common_EventScript_SuperTrainerChooseIVsBy30::
	setvar VAR_0x8006, 30
	setvar VAR_0x8009, 3000
	goto Common_EventScript_SuperTrainerSetIVs

Common_EventScript_SuperTrainerChooseIVsBy31::
	setvar VAR_0x8006, 31
	setvar VAR_0x8009, 3100
	goto Common_EventScript_SuperTrainerSetIVs

Common_EventScript_SuperTrainerSetIVs::
	showmoneybox 0, 0, 0
	buffernumberstring 2, VAR_0x8009
	msgbox Common_Text_SuperTrainerDisplayCost, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_EventScript_SuperTrainerSetIVsRefused
	checkmoney VAR_0x8009, 0
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_SuperTrainerNotEnoughMoneySetIVs
	removemoney VAR_0x8009, 0
	updatemoneybox
	playse SE_SHOP
	special SetChosenMonIV
	msgbox Common_Text_SuperTrainerDoneTraining, MSGBOX_DEFAULT
	hidemoneybox
	goto Common_EventScript_SuperTrainerChangeIVs

Common_EventScript_SuperTrainerSetIVsRefused::
	hidemoneybox
	goto Common_EventScript_SuperTrainerChangeIVs

Common_EventScript_SuperTrainerNotEnoughMoneySetIVs::
	hidemoneybox
	msgbox Common_Text_SuperTrainerNotEnoughMoney, MSGBOX_DEFAULT
	goto Common_EventScript_SuperTrainerChangeIVs

Common_EventScript_SuperTrainerChangeHiddenPowerType::
	msgbox Common_Text_SuperTrainerChooseHiddenPowerType, MSGBOX_DEFAULT
	copyvar VAR_0x800A, VAR_0x8004
	setvar VAR_0x8004, SCROLL_MULTI_SUPER_TRAINING_HIDDEN_POWER_TYPE
	special ShowScrollableMultichoice
	waitstate
	goto_if_eq VAR_RESULT, MULTI_B_PRESSED, Common_EventScript_SuperTrainerRebufferChosenMon
	copyvar VAR_0x8005, VAR_RESULT
	copyvar VAR_0x8004, VAR_0x800A
	special CalculateIVSpreadPrice
	goto Common_EventScript_SuperTrainerSetHiddenPowerType

Common_EventScript_SuperTrainerRebufferChosenMon::
	copyvar VAR_0x8004, VAR_0x800A
	goto Common_EventScript_SuperTrainerTrainingIVs

Common_EventScript_SuperTrainerSetHiddenPowerType::
	showmoneybox 0, 0, 0
	buffernumberstring 2, VAR_0x8009
	msgbox Common_Text_SuperTrainerDisplayCost, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_EventScript_SuperTrainerSetHiddenPowerTypeRefused
	checkmoney VAR_0x8009, 0
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_SuperTrainerNotEnoughMoneySetHiddenPowerType
	removemoney VAR_0x8009, 0
	updatemoneybox
	playse SE_SHOP
	special SetChosenMonIVSpread
	msgbox Common_Text_SuperTrainerDoneTraining, MSGBOX_DEFAULT
	hidemoneybox
	goto Common_EventScript_SuperTrainerTrainingIVs

Common_EventScript_SuperTrainerSetHiddenPowerTypeRefused::
	hidemoneybox
	goto Common_EventScript_SuperTrainerChangeHiddenPowerType

Common_EventScript_SuperTrainerNotEnoughMoneySetHiddenPowerType::
	hidemoneybox
	msgbox Common_Text_SuperTrainerNotEnoughMoney, MSGBOX_DEFAULT
	goto Common_EventScript_SuperTrainerChangeHiddenPowerType

Common_EventScript_SuperTrainerChangeNature::
	msgbox Common_Text_SuperTrainerChangeNatureStatUp, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_SUPER_TRAINING_MENU_STAT_UP, 0
	goto_if_eq VAR_RESULT, MULTI_B_PRESSED, Common_EventScript_SuperTrainerMainMenu
	copyvar VAR_0x8005, VAR_RESULT
	goto Common_EventScript_SuperTrainerChangeNatureStatDown

Common_EventScript_SuperTrainerChangeNatureStatDown::
	msgbox Common_Text_SuperTrainerChangeNatureStatDown, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_SUPER_TRAINING_MENU_STAT_DOWN, 0
	goto_if_eq VAR_RESULT, MULTI_B_PRESSED, Common_EventScript_SuperTrainerChangeNature
	copyvar VAR_0x8006, VAR_RESULT
	setvar VAR_0x8009, 2000
	goto Common_EventScript_SuperTrainerSetNature

Common_EventScript_SuperTrainerSetNature::
	showmoneybox 0, 0, 0
	buffernumberstring 2, VAR_0x8009
	msgbox Common_Text_SuperTrainerDisplayCost, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_EventScript_SuperTrainerSetNatureRefused
	checkmoney VAR_0x8009, 0
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_SuperTrainerNotEnoughMoneySetNature
	removemoney VAR_0x8009, 0
	updatemoneybox
	playse SE_SHOP
	special SetChosenMonNature
	msgbox Common_Text_SuperTrainerDoneTraining, MSGBOX_DEFAULT
	hidemoneybox
	goto Common_EventScript_SuperTrainerMainMenu

Common_EventScript_SuperTrainerSetNatureRefused::
	hidemoneybox
	goto Common_EventScript_SuperTrainerMainMenu

Common_EventScript_SuperTrainerNotEnoughMoneySetNature::
	hidemoneybox
	msgbox Common_Text_SuperTrainerNotEnoughMoney, MSGBOX_DEFAULT
	goto Common_EventScript_SuperTrainerMainMenu

Common_EventScript_SuperTrainerChangeAbility::
	msgbox Common_Text_SuperTrainerWantToChangeAbility, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_EventScript_SuperTrainerMainMenu
	playse SE_SHOP
	special ChangeChosenMonAbility
	msgbox Common_Text_SuperTrainerDoneTraining, MSGBOX_DEFAULT
	goto Common_EventScript_SuperTrainerMainMenu

Common_EventScript_SuperTrainerMoreInfo::
	msgbox Common_Text_SuperTrainerMoreInfo, MSGBOX_DEFAULT
	goto Common_EventScript_SuperTrainerMainMenu

Common_Text_SuperTrainerWelcome:
	.string "Hi! Have you heard about\n"
	.string "{COLOR BLUE}Super Training{COLOR DARK_GRAY}?\p"
	.string "I can train your POKéMON for\n"
	.string "a fraction of price.\p"
	.string "Would you like to give it a try?$"

Common_Text_SuperTrainerExit:
	.string "Alright, please come back again!$"

Common_Text_SuperTrainerChooseMon:
	.string "Please choose your POKéMON.$"

Common_Text_SuperTrainerChooseAgain:
	.string "I cannot train the chosen POKéMON.\p"
	.string "Please choose again.$"

Common_Text_SuperTrainerHowCanIHelp:
	.string "How can I help your POKéMON?$"

Common_Text_SuperTrainerWhichStat:
	.string "Which stat would you like to train?$"

Common_Text_SuperTrainerReachingMaxEVs:
	.string "It seems your POKéMON can no longer\n"
	.string "train this stat.\p"
	.string "Please choose again.$"

Common_Text_SuperTrainerChooseEVsValue:
	.string "How many EVs would you like to increase?$"

Common_Text_SuperTrainerDisplayCost:
	.string "That'll cost ¥{STR_VAR_3}. Is that OK?$"

Common_Text_SuperTrainerNotEnoughMoney:
	.string "You don't have the money.$"

Common_Text_SuperTrainerDoneTraining:
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "All good!$"

Common_Text_SuperTrainerWantToResetEVs:
	.string "I can reset your POKéMON's EVs\n"
	.string "for free!\p"
	.string "Would you like to continue?$"

Common_Text_SuperTrainerTrainingIVs:
	.string "How can I train your POKéMON's IVs?$"

Common_Text_SuperTrainerChooseIVsValue:
	.string "What IV value would you like to train?$"

Common_Text_SuperTrainerChooseHiddenPowerType:
	.string "Which Hidden Power type would you like?$"

Common_Text_SuperTrainerChangeNatureStatUp:
	.string "Which stat should your POKéMON likes?$"

Common_Text_SuperTrainerChangeNatureStatDown:
	.string "Which stat should your POKéMON\n"
	.string "dislikes?$"

Common_Text_SuperTrainerWantToChangeAbility:
	.string "I can reset your POKéMON's ability\n"
	.string "for free!\p"
	.string "Would you like to continue?$"

Common_Text_SuperTrainerMoreInfo:
	.string "{COLOR BLUE}EVs{COLOR DARK_GRAY} are values that contribute to an\n"
	.string "individual POKéMON's stats.\p"
	.string "Your POKéMONs will gain EVs when they\n"
	.string "defeat another POKéMON but what which\l"
	.string "stat they will gain depends on the\l"
	.string "species of the defeated POKéMON.\p"
	.string "Each EV ranges from 0 to 255 and the\n"
	.string "total EVs cannot be more than 510.\p"
	.string "{COLOR BLUE}IVs{COLOR DARK_GRAY} are the same.\n"
	.string "However, the values are unique to each\l"
	.string "POKéMON.\p"
	.string "They cannot be changed without using\n"
	.string "Super Training.\p"
	.string "Each IV ranges from 0 to 31 and they\n"
	.string "are used to determine your POKéMON's\l"
	.string "Hidden Power type.\p"
	.string "{COLOR BLUE}Nature{COLOR DARK_GRAY} can make one of your POKéMON's\n"
	.string "stats goes up or down, which is crucial\l"
	.string "in a competitive battle.\p"
	.string "{COLOR BLUE}Ability{COLOR DARK_GRAY} is unique to each species.\p"
	.string "A POKéMON species can have up to\n"
	.string "3 abilities where one of them is\l"
	.string "hidden.\p"
	.string "Hidden Ability can only be obtained\n"
	.string "through Super Training or rare events.$"
