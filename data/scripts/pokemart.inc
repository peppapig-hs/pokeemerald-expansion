Common_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_BADGE06_GET, Common_EventScript_Clerk8
	goto_if_set FLAG_BADGE05_GET, Common_EventScript_Clerk7
	goto_if_set FLAG_BADGE04_GET, Common_EventScript_Clerk6
	goto_if_set FLAG_BADGE03_GET, Common_EventScript_Clerk5
	goto_if_set FLAG_BADGE02_GET, Common_EventScript_Clerk4
	goto_if_set FLAG_BADGE01_GET, Common_EventScript_Clerk3
	goto_if_set FLAG_VISITED_RUSTBORO_CITY, Common_EventScript_Clerk2
	goto_if_set FLAG_SYS_POKEDEX_GET, Common_EventScript_Clerk1
	goto Common_EventScript_Clerk0
	end

Common_EventScript_Clerk0::
	pokemart Common_Pokemart_Inventory0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Common_EventScript_Clerk1::
	pokemart Common_Pokemart_Inventory1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Common_EventScript_Clerk2::
	pokemart Common_Pokemart_Inventory2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Common_EventScript_Clerk3::
	pokemart Common_Pokemart_Inventory3
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end
Common_EventScript_Clerk4::
	pokemart Common_Pokemart_Inventory4
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Common_EventScript_Clerk5::
	pokemart Common_Pokemart_Inventory5
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Common_EventScript_Clerk6::
	pokemart Common_Pokemart_Inventory6
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Common_EventScript_Clerk7::
	pokemart Common_Pokemart_Inventory7
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Common_EventScript_Clerk8::
	pokemart Common_Pokemart_Inventory8
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

.align 2
Common_Pokemart_Inventory0:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

.align 2
Common_Pokemart_Inventory1:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

.align 2
Common_Pokemart_Inventory2:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

.align 2
Common_Pokemart_Inventory3:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

.align 2
Common_Pokemart_Inventory4:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE
	release
	end

.align 2
Common_Pokemart_Inventory5:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

.align 2
Common_Pokemart_Inventory6:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ETHER
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

.align 2
Common_Pokemart_Inventory7:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ETHER
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

.align 2
Common_Pokemart_Inventory8:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ETHER
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end
