#ifndef MENU_CMDS_H
#define MENU_CMDS_H

#include <string>
#include <vector>
#include "../objects/Player.h"
#include "../cmds/Cmd_Base.h"
#include "../cmds/Raise.h"
#include "Player_Factory.h"
#include "Main_Menu.h"

class Menu_Profile : public Raise {
public:
    virtual ~Menu_Profile() {};
    std::string action(std::vector<std::string>, Player&) override;
};

class Menu_Help : public Cmd_Base {
public:
    virtual ~Menu_Help() {};
    std::string action(std::vector<std::string>, Player&) override;
};

class Menu_Reset : public Cmd_Base {
public:
    virtual ~Menu_Reset() {};
    std::string action(std::vector<std::string>, Player&) override;
};

class Menu_Quit : public Cmd_Base {
public:
    virtual ~Menu_Quit() {};
    std::string action(std::vector<std::string>, Player&) override;
};

class Menu_Play : public Cmd_Base {
public:
    virtual ~Menu_Play() {};
    std::string action(std::vector<std::string>, Player&) override;
};

#endif // MENU_CMDS_H