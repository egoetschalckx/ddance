/****************************************************************************
 *  Original Diku Mud copyright (C) 1990, 1991 by Sebastian Hammer,			*
 *  Michael Seifert, Hans Henrik St{rfeldt, Tom Madsen, and Katja Nyboe.	*
 *																			*
 *  Merc Diku Mud improvments copyright (C) 1992, 1993 by Michael			*
 *  Chastain, Michael Quan, and Mitchell Tse.								*
 *																			*
 ***************************************************************************/
 
/****************************************************************************
*	ROM 2.4 is copyright 1993-1998 Russ Taylor								*
*	ROM has been brought to you by the ROM consortium						*
*	    Russ Taylor (rtaylor@hypercube.org)									*
*	    Gabrielle Taylor (gtaylor@hypercube.org)							*
*	    Brian Moore (zump@rom.org)											*
*	By using this code, you have agreed to follow the terms of the			*
*	ROM license, in the file Rom24/doc/rom.license							*
***************************************************************************/
#if defined(macintosh)
#include <types.h>
#else
#include <sys/types.h>
#endif
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include "merc.h"
#include "arena.h"
#include "interp.h"
#include "tables.h"
#include "olc.h"
#include "recycle.h"
#include "lookup.h"
#include "skill_tree.h"

struct	tree_skill_type	tree_skill_table	[MAX_TREE_SKILLS]	=
{
	{"combat"},
	{"combat.offense"},				
	{"combat.offense.slashing"},					
	{"combat.offense.slashing.swords"},						
	{"combat.offense.slashing.axes"},						
	{"combat.offense.slashing.polearms"},						
	{"combat.offense.bashing"},					
	{"combat.offense.bashing.maces"},						
	{"combat.offense.bashing.flails"},						
	{"combat.offense.bashing.staves"},						
	{"combat.offense.piercing"},					
	{"combat.offense.piercing.daggers"},						
	{"combat.offense.piercing.spears"},						
	{"combat.offense.piercing.missiles"},
	{"combat.offense.unarmed"},
	{"combat.defense"},				
	{"combat.defense.parrying"},					
	{"combat.defense.dodging"},					
	{"combat.defense.countering"},	
	{"combat.defense.shield"},
	{"combat.special"},					
	{"combat.special.multihit"},					
	{"combat.special.berserk"},					
	{"combat.special.mastery"}, 
	{"covert"},			 
	{"covert.stealth"},			 
	{"covert.stealth.stalking"},			 
	{"covert.stealth.hiding"},			 
	{"covert.stealth.sneaking"},			 
	{"covert.stealth.agility"},			 
	{"covert.manipulation"},			 
	{"covert.manipulation.stealing"},			 
	{"covert.manipulation.stealing.currency"},			 
	{"covert.manipulation.stealing.inventory"},			 
	{"covert.manipulation.stealing.equipped"},			 
	{"covert.manipulation.lockpicking"},			 
	{"covert.manipulation.poisons"},			 
	{"arcane"},			 
	{"arcane.necromancy"},			 
	{"arcane.necromancy.summoning"},			 
	{"arcane.necromancy.reanimation"},			 
	{"arcane.greater_elemental"},			 
	{"arcane.greater_elemental.fire"},			 
	{"arcane.greater_elemental.wind"},			 
	{"arcane.greater_elemental.water"},			 
	{"arcane.greater_elemental.earth"},			 
	{"arcane.greater_elemental.ether"},			 
	{"arcane.alteration"},			 
	{"arcane.alteration.object"},			 
	{"arcane.alteration.person"},			 
	{"arcane.alteration.immaterial"},			 
	{"arcane.protection"},			 
	{"arcane.protection.magical"},			 
	{"arcane.protection.physical"},			 
	{"worship"},			 
	{"worship.benediction"},			 
	{"worship.benediction.protection"},			 
	{"worship.benediction.protection.physical"},
	{"worship.benediction.protection.magical"},		 
	{"worship.benediction.protection.spiritual"},		 
	{"worship.benediction.healing"},			 
	{"worship.benediction.healing.restoration"},			 
	{"worship.benediction.healing.curative"},			 
	{"worship.benediction.enhancement"},			 
	{"worship.benediction.enhancement.mind"},
	{"worship.benediction.enhancement.body"},			 
	{"worship.maladiction"},			 
	{"worship.maladiction.affliction"},			 
	{"worship.maladiction.offensive"},			 
	{"sorcery"},			 
	{"sorcery.heraldic"},			 
	{"sorcery.heraldic.detection"},			 
	{"sorcery.heraldic.illusion"},			 
	{"sorcery.heraldic.conjuration"},			 
	{"sorcery.heraldic.transportation"},			 
	{"sorcery.heraldic.enchantment"},			 
	{"sorcery.heraldic.enchantment.person"},			 
	{"sorcery.heraldic.enchantment.object"},		 
	{"sorcery.wizardry"},			 
	{"sorcery.wizardry.elemental"},			 
	{"sorcery.wizardry.weather"},	 
	{"sorcery.wizardry.psionic"}
};

const struct skill_stat_table		check_skill_group	[SKILL_GROUPS]	=
{
	{"combat",	SKILL_COMBAT,	STAT_STR},
	{"covert",	SKILL_COVERT,	STAT_DEX},
	{"sorcery",	SKILL_SORCERY,	STAT_INT},
	{"arcane",	SKILL_ARCANE,	STAT_INT},
	{"worship",	SKILL_WORSHIP,	STAT_WIS}
};