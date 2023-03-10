/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "Conversation.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "DBCEnums.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "World.h"
#include "WorldSession.h"
#include "SpellAuras.h"
#include "PhasingHandler.h"
#include "GameEventMgr.h"

class PlayerScript_Weekly_Quests : public PlayerScript
{
public:
    PlayerScript_Weekly_Quests() : PlayerScript("PlayerScript_Weekly_Quests") {}

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {
        if (!player)
            return;

        if (!sGameEventMgr->IsActiveEvent(110))
        {
            player->RemoveActiveQuest(sObjectMgr->GetQuestTemplate(44175), false);
            player->RemoveAura(225788);
        }
        else
            player->CastSpell(player, 225788, false);

        if (!sGameEventMgr->IsActiveEvent(111))
        {
            player->RemoveActiveQuest(sObjectMgr->GetQuestTemplate(44173), false);
            player->RemoveAura(186403);
        }
        else
            player->CastSpell(player, 186403, false);

        if (!sGameEventMgr->IsActiveEvent(112))
        {
            player->RemoveActiveQuest(sObjectMgr->GetQuestTemplate(44174), false);
            player->RemoveAura(186406);
        }
        else
            player->CastSpell(player, 186406, false);

        if (!sGameEventMgr->IsActiveEvent(113))
        {
            player->RemoveActiveQuest(sObjectMgr->GetQuestTemplate(44172), false);
            player->RemoveAura(186401);
        }
        else
            player->CastSpell(player, 186401, false);

        if (!sGameEventMgr->IsActiveEvent(114))
        {
            player->RemoveActiveQuest(sObjectMgr->GetQuestTemplate(44171), false);
            player->RemoveAura(225787);
        }
        else
            player->CastSpell(player, 225787, false);
    }

    void OnMapChanged(Player* player) override
    {
        if (!player)
            return;

        if (!sGameEventMgr->IsActiveEvent(110))
            player->RemoveAura(225788);
        if (!sGameEventMgr->IsActiveEvent(111))
            player->RemoveAura(186403);
        if (!sGameEventMgr->IsActiveEvent(112))
            player->RemoveAura(186406);
        if (!sGameEventMgr->IsActiveEvent(113))
            player->RemoveAura(186401);
        if (!sGameEventMgr->IsActiveEvent(114))
            player->RemoveAura(225787);

    }
};

void AddSC_custom_player_script()
{
    new PlayerScript_Weekly_Quests();
}
