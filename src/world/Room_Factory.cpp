#include "../world_helper/Room_Factory.h"

using namespace std;


void Room_Factory::generate_rooms() {

    auto main_square = create_room(
        "main_square",
        "main square",
        "a quite large square covered with cobblestones. Currently only one narrow street leads to the south."
    );
    main_square->add_item("leather_helmet");
    main_square->add_item("leather_cap");
    main_square->add_item("key");
    main_square->add_item( "leather_boots_dex");
    main_square->add_item("stick");
    main_square->add_item("rusty_dagger");
    main_square->add_item("heater_shield");
    main_square->add_item("buckler");
    main_square->add_detail("cobblestones", "About half foot large square pieces of stone.");
    main_square->add_detail("cobblestone", "About half foot large square pieces of stone.");
    
    auto dark_lane1 = create_room(
        "dark_lane1",
        "a dark lane",
        "This is a narrow dark street running among tiny houses. "
        "It opens to a square to the north while getting even darker to the south."
    );
    dark_lane1->add_creature("green_orc");

    auto dark_lane2 = create_room(
        "dark_lane2",
        "a dark lane bending",
        "This is a narrow street running among tiny houses. It turns here abruptly.",
        true //room is resetable
    );
    dark_lane2->add_creature("rat");

    auto dark_lane3 = create_room(
        "dark_lane3",
        "a dark lane dead end",
        "The dark lane ends here. The only exit is to the west."
    );
    dark_lane3->add_item("leather_helmet");
    
    start_room = (rooms["main_square"].get());
    
    connect_rooms(main_square, Exit::south, dark_lane1);
    connect_rooms(dark_lane1, Exit::south, dark_lane2);
    connect_rooms(dark_lane2, Exit::east, dark_lane3);
}


