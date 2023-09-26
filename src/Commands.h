#ifndef COMMANDS_H
#define COMMANDS_H

#include <map>
#include <vector>
#include <string>
#include <memory>

#include "World.h"

#include "cmds/Cmd_Base.h"

#include "cmds/Drop.h"
#include "cmds/Get.h"
#include "cmds/Go.h"
#include "cmds/Look.h"


class Commands
{
private:
    std::map<std::string, std::unique_ptr<Cmd_Base>> commands;
public:
    Commands();
    std::string execute_command(std::vector<std::string>, Player&);
    void apply_go_aliases(std::vector<std::string>&);
};

#endif // COMMANDS_H
