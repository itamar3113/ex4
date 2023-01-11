GPP=g++
OBJS=main.o utilities.o Mtmchkin.o Players/Player.o Cards/Card.o $(CARDS_OBJS) $(PLAYERS_OBJS) 
CARDS_OBJS=Cards/Barfight.o Cards/BattleCard.o Cards/Dragon.o Cards/Gremlin.o Cards/Mana.o Cards/Merchant.o Cards/Treasure.o Cards/Well.o Cards/Witch.o 
PLAYERS_OBJS=Players/Healer.o Players/Ninja.o Players/Warrior.o
EXEC=main
DEBUG_FLAG= -g# can add -g
COMP_FLAG=--std=c++11 -Wall -Werror -pedantic-errors

$(EXEC) : $(OBJS)
	$(GPP) $(COMP_FLAG) $(OBJS) -o $@
main.o : main.cpp Mtmchkin.o
	$(GPP) -c $(COMP_FLAG) $*.cpp -o $@
utilities.o : utilities.cpp utilities.h
	$(GPP) -c $(COMP_FLAG) $*.cpp -o $@
Cards/Barfight.o : Cards/Barfight.cpp Cards/Barfight.h
	$(GPP) -c $(COMP_FLAG) $*.cpp -o $@
Cards/BattleCard.o : Cards/BattleCard.cpp Cards/BattleCard.h
	$(GPP) -c $(COMP_FLAG) $*.cpp -o $@
Cards/Dragon.o : Cards/Dragon.cpp Cards/Dragon.h Cards/BattleCard.cpp Cards/BattleCard.h
	$(GPP) -c $(COMP_FLAG) $*.cpp -o $@
Cards/Gremlin.o : Cards/Gremlin.cpp Cards/Gremlin.h Cards/BattleCard.cpp Cards/BattleCard.h
	$(GPP) -c $(COMP_FLAG) $*.cpp -o $@
Cards/Witch.o : Cards/Witch.cpp Cards/Witch.h Cards/BattleCard.cpp Cards/BattleCard.h
	$(GPP) -c $(COMP_FLAG) $*.cpp -o $@
Cards/Mana.o : Cards/Mana.cpp Cards/Mana.h
	$(GPP) -c $(COMP_FLAG) $*.cpp -o $@
Cards/Merchant.o : Cards/Merchant.cpp Cards/Merchant.h
	$(GPP) -c $(COMP_FLAG) $*.cpp -o $@
Cards/Treasure.o : Cards/Treasure.cpp Cards/Treasure.h
	$(GPP) -c $(COMP_FLAG) $*.cpp -o $@
Cards/Well.o : Cards/Well.cpp Cards/Well.h
	$(GPP) -c $(COMP_FLAG) $*.cpp -o $@
Players/Warrior.o : Players/Warrior.cpp Players/Warrior.h
	$(GPP) -c $(COMP_FLAG) $*.cpp -o $@
Players/Ninja.o : Players/Ninja.cpp Players/Ninja.h
	$(GPP) -c $(COMP_FLAG) $*.cpp -o $@
Players/Healer.o : Players/Healer.cpp Players/Healer.h
	$(GPP) -c $(COMP_FLAG) $*.cpp -o $@
Players/Player.o : Players/Player.cpp Players/Player.h $(PLAYERS_OBJS)
	$(GPP) -c $(COMP_FLAG) $*.cpp -o $@
Cards/Card.o : Cards/Card.cpp Cards/Card.h Players/Player.h utilities.h $(CARDS_OBJS)
	$(GPP) -c $(COMP_FLAG) $*.cpp -o $@
Mtmchkin.o : Mtmchkin.cpp Mtmchkin.h Players/Player.h Cards/Card.h utilities.h
	$(GPP) -c $(COMP_FLAG) $*.cpp -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(EXEC)
