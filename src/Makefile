CC      = gcc
PROF    = -O -g
NOCRYPT =
C_FLAGS =  -Wall $(PROF) $(NOCRYPT)
L_FLAGS =  $(PROF)
LIBS	= -lcrypt

O_FILES =	act_channel.o act_comm.o act_enter.o act_info.o act_move.o act_obj.o act_wiz.o \
			alias.o arena.o auction.o ban.o bank2.o bit.o check.o classes.o comm.o const.o \
			copyover.o dagashi.o db2.o db.o delete.o draconian.o effects.o esper.o execute.o \
			fight.o flags.o forms.o golem.o guild.o handler.o healer.o heroexp.o honor.o \
			interp.o keyring.o legionare.o locker.o lookup.o magic2.o magic.o mem.o mob_cmds.o \
			mobdeaths.o mob_prog.o music.o note.o olc_act.o olc.o olc_load_mobs.o lc_load_new.o \
			olc_load_rooms.o olc_mpcode.o olc_save.o olc_save_new.o oldsave.o pload.o pwipe.o \
			qsort.o quest.o race.o raiding.o recycle.o reload.o remort.o restring.o save.o sensei.o \
			sheath.o skill_arcane.o skill_combat.o  skill_covert.o skills.o skill_sorcery.o \
			skill_table.o skilltable.o skill_tree.o skill_worship.o slay.o smithing.o special.o \
			stat.o string.o tables.o taomaster.o teach.o  trophy.o update.o weapon_spells.o \
			zealot.o


rom: $(O_FILES)
	rm -f rom
	$(CC) $(L_FLAGS) -o rom $(O_FILES) $(LIBS)

.c.o: merc.h
	$(CC) -c $(C_FLAGS) $<
