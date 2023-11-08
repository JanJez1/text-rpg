#ifndef COMMANDS_H
#define COMMANDS_H

#include <map>
#include <vector>
#include <string>
#include <memory>

#include "cmds/Cmd_Base.h"
#include "cmds/Drink.h"
#include "cmds/Drop.h"
#include "cmds/Get.h"
#include "cmds/Go.h"
#include "cmds/Hit.h"
#include "cmds/Hold.h"
#include "cmds/Inventory.h"
#include "cmds/Look.h"
#include "cmds/Profile.h"
#include "cmds/Quit.h"
#include "cmds/Raise.h"
#include "cmds/Remove.h"
#include "cmds/Unlock.h"
#include "cmds/Wear.h"

#include "main_menu/Menu_Cmds.h"


class Commands
{
private:
    std::map<std::string, std::unique_ptr<Cmd_Base>> commands;
    std::map<std::string, std::unique_ptr<Cmd_Base>> menu_commands;
public:
    Commands();
    std::string execute_command(std::vector<std::string>, Player&);
    void apply_go_aliases(std::vector<std::string>&);
};

#endif // COMMANDS_H
