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
    static const std::map<std::string, std::unique_ptr<Cmd_Base>> commands;
    static const std::map<std::string, std::unique_ptr<Cmd_Base>> menu_commands;
    static void apply_go_aliases(std::vector<std::string>& tokens);
    static const std::map<std::string, std::unique_ptr<Cmd_Base>> init_commands();
    static const std::map<std::string, std::unique_ptr<Cmd_Base>> init_menu_commands();

public:
    static std::string execute_command(std::vector<std::string>, Player&);
    static std::string execute_menu_command(std::vector<std::string>, Player&);
};

#endif // COMMANDS_H
