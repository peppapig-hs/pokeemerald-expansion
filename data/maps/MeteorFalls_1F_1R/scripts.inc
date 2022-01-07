.set LOCALID_MAGMA_GRUNT_1, 5
.set LOCALID_MAGMA_GRUNT_2, 6
.set LOCALID_ARCHIE, 7
.set LOCALID_AQUA_GRUNT_1, 8
.set LOCALID_AQUA_GRUNT_2, 9

MeteorFalls_1F_1R_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	.byte 0

MeteorFalls_1F_1R_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
	end

MeteorFalls_1F_1R_EventScript_OpenStevensCave::
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
	return

MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_Delay48
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	addobject LOCALID_ARCHIE
	addobject LOCALID_AQUA_GRUNT_1
	addobject LOCALID_AQUA_GRUNT_2
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
	applymovement LOCALID_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
	waitmovement 0
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_MAGMA_GRUNT_2
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieExit
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_AQUA_GRUNT_1
	removeobject LOCALID_AQUA_GRUNT_2
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	setvar VAR_METEOR_FALLS_STATE, 1
	releaseall
	end

MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieArrive:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Exit:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Exit:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay:
	walk_in_place_faster_down
	delay_4
	walk_in_place_faster_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	face_right
	step_end

MeteorFalls_1F_1R_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
	setflag FLAG_MET_PROF_COZMO
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_MetCozmo::
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_ZinniasGrandmother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SALAMENCITE, MeteorFalls_1F_1R_EventScript_CheckDragonAscent
	msgbox MeteorFalls_1F_1R_Text_GiveSalamencite, MSGBOX_DEFAULT
	giveitem ITEM_SALAMENCITE
	setflag FLAG_RECEIVED_SALAMENCITE
MeteorFalls_1F_1R_EventScript_ZinniaFuture:
	msgbox MeteorFalls_1F_1R_Text_ZinniaFuture, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_CheckDragonAscent::
	specialvar VAR_RESULT, ShouldTeachDragonAscent
	goto_if_eq VAR_RESULT, FALSE, MeteorFalls_1F_1R_EventScript_ZinniaFuture
	msgbox MeteorFalls_1F_1R_Text_CanTeachDragonAscent, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MeteorFalls_1F_1R_EventScript_DragonAscentExplained
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, MAX_MON_MOVES, MeteorFalls_1F_1R_EventScript_ForgetMove
	goto MeteorFalls_1F_1R_EventScript_TeachDragonAscent

MeteorFalls_1F_1R_EventScript_ForgetMove::
	bufferpartymonnick 0, VAR_0x8004
	buffermovename 1, MOVE_DRAGON_ASCENT
	msgbox MeteorFalls_1F_1R_Text_TryLearnMove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MeteorFalls_1F_1R_EventScript_DragonAscentExplained
	msgbox MeteorFalls_1F_1R_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, MeteorFalls_1F_1R_EventScript_DragonAscentExplained
	special BufferMoveDeleterNicknameAndMove
	msgbox MeteorFalls_1F_1R_Text_ForgotMove, MSGBOX_DEFAULT
	special MoveDeleterForgetMove
	goto MeteorFalls_1F_1R_EventScript_TeachDragonAscent

MeteorFalls_1F_1R_EventScript_TeachDragonAscent::
	special TeachDragonAscent
	bufferpartymonnick 0, VAR_0x8004
	buffermovename 1, MOVE_DRAGON_ASCENT
	playfanfare MUS_LEVEL_UP
	msgbox MeteorFalls_1F_1R_Text_LearnedMove, MSGBOX_DEFAULT
	goto MeteorFalls_1F_1R_EventScript_DragonAscentExplained

MeteorFalls_1F_1R_EventScript_DragonAscentExplained::
	msgbox MeteorFalls_1F_1R_Text_DragonAscentExplained, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Text_WithThisMeteorite:
	.string "Hehehe!\p"
	.string "With this METEORITE, that thing in\n"
	.string "MT. CHIMNEY will…$"

MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma:
	.string "Heh?\p"
	.string "I don't know who you are, but if you get\n"
	.string "in the way of TEAM MAGMA, don't\l"
	.string "expect any mercy!$"

MeteorFalls_1F_1R_Text_HoldItRightThereMagma:
	.string "Hold it right there, TEAM MAGMA!\p"
	.string "You're badly mistaken if you think you\n"
	.string "can have your way with the world!$"

MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua:
	.string "Hehehe!\n"
	.string "Even TEAM AQUA joins us!\p"
	.string "But it's too much trouble to deal with\n"
	.string "you all…\p"
	.string "Heh, it doesn't matter!\p"
	.string "We've got the METEORITE, so off to\n"
	.string "MT. CHIMNEY we go!\p"
	.string "Hehehe! Be seeing you, you TEAM\n"
	.string "AQUA dingbats!$"

MeteorFalls_1F_1R_Text_ArchieSeenYouBefore:
	.string "ARCHIE: Didn't I see you before?\n"
	.string "At SLATEPORT's MUSEUM?\p"
	.string "Ah, so your name is {PLAYER}.\p"
	.string "At the time, I thought you were one\n"
	.string "of TEAM MAGMA's goons.\p"
	.string "Humph…\n"
	.string "You're one odd kid.\p"
	.string "TEAM MAGMA is a dangerous group of\n"
	.string "total fanatics.\p"
	.string "They engage in destruction, claiming\n"
	.string "to expand the land mass.\p"
	.string "They are the rivals to us,\n"
	.string "the sea-loving TEAM AQUA!$"

MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma:
	.string "BOSS, we should give chase to\n"
	.string "TEAM MAGMA…$"

MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo:
	.string "ARCHIE: Yes, yes, we must!\n"
	.string "We've got to hurry.\p"
	.string "There's no telling what TEAM MAGMA\n"
	.string "will do at MT. CHIMNEY!$"

MeteorFalls_1F_1R_Text_ArchieFarewell:
	.string "ARCHIE: {PLAYER}, you should keep\n"
	.string "an eye out for TEAM MAGMA, too.\p"
	.string "Farewell!$"

MeteorFalls_1F_1R_Text_MeetProfCozmo:
	.string "I… I'm COZMO…\n"
	.string "I'm a PROFESSOR…\p"
	.string "TEAM MAGMA asked me to guide them\n"
	.string "to METEOR FALLS…\p"
	.string "But they tricked me.\n"
	.string "They even took my METEORITE away…\p"
	.string "And then another similar bunch,\n"
	.string "TEAM AQUA showed up.\p"
	.string "After that…\n"
	.string "I don't understand any of it.\p"
	.string "But that TEAM MAGMA…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE at MT. CHIMNEY?$"

MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney:
	.string "PROF. COZMO: But that TEAM MAGMA…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE at MT. CHIMNEY?$"

MeteorFalls_1F_1R_Text_GiveSalamencite:
	.string "Zinnia has gone on a journey.\n"
	.string "A journey to find herself this time.\p"
	.string "Ah, yes...\n"
	.string "She did leave this for you, though.\l"
	.string "I hope you will accept it.$"

MeteorFalls_1F_1R_Text_ZinniaFuture:
	.string "I wonder what kind of future\n"
	.string "Zinnia might find for herself,\l"
	.string "now that she is free from the\l"
	.string "fate of the Draconids.\p"
	.string "Though I don't think that I\n"
	.string "need to worry about it.\p"
	.string "Ah, yes.\n"
	.string "If ever your Rayquaza forgets how to\l"
	.string "use Dragon Ascent, come call upon me.$"

MeteorFalls_1F_1R_Text_CanTeachDragonAscent:
	.string "Hmm... Do you want me to teach\n"
	.string "Dragon Ascent to your POKéMON?$"

MeteorFalls_1F_1R_Text_TryLearnMove:
	.string "{STR_VAR_1} is trying to learn\n{STR_VAR_2}.\p"
	.string "But {STR_VAR_1} can't learn more\n"
	.string "than four moves.\p"
	.string "Delete an older move to make\n"
	.string "room for {STR_VAR_2}?$"

MeteorFalls_1F_1R_Text_WhichMoveShouldBeForgotten:
	.string "Which move should be forgotten?$"

MeteorFalls_1F_1R_Text_ForgotMove:
	.string "{PAUSE 32}1, {PAUSE 15}2, and {PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Poof!\p"
	.string "{STR_VAR_1} forgot how to use\n"
	.string "{STR_VAR_2}.\p"
	.string "And…$"

MeteorFalls_1F_1R_Text_LearnedMove:
	.string "{STR_VAR_1} learned {STR_VAR_2}!{WAIT_SE}$"

MeteorFalls_1F_1R_Text_DragonAscentExplained:
	.string "Dragon Ascent is a powerful move\n"
	.string "that only Rayquaza can use.\p"
	.string "They say its power is so strong that\n"
	.string "even a huge meteoroid can be broken\l"
	.string "into pieces with one attack.\p"
	.string "Well, you must know best\n"
	.string "about how fierce it is, though.$"
