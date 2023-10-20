#include "../world_helper/Room_Factory.h"

using namespace std;


void Room_Factory::generate_rooms() {

    auto main_square = create_room(
        "main square",
        "a quite large square covered with cobblestones. Currently only one narrow street leads to the south and bush is to the north."
    );
    main_square->add_detail("cobblestones", "About half foot large square pieces of stone.");
    main_square->add_detail("cobblestone", "About half foot large square pieces of stone.");
    main_square->add_item("a leather helmet");
    main_square->add_item("a leather cap");
    main_square->add_item("a tiny iron key");
    main_square->add_item( "leather boots of dexterity");
    main_square->add_item("a wooden stick");
    main_square->add_item("a rusty dagger");
    main_square->add_item("a heater shield");
    main_square->add_item("a tiny buckler");
    
    auto dark_lane1 = create_room(
        "a dark lane",
        "This is a narrow dark street running among tiny houses. "
        "It opens to a square to the north while getting even darker to the south."
    );
    dark_lane1->add_creature("a green orc");
    main_square->add_special_item("bush1", dark_lane1);

    auto dark_lane2 = create_room(
        "a dark lane bending",
        "This is a narrow street running among tiny houses. It turns here abruptly.",
        true //room is resetable
    );
    dark_lane2->add_creature("a small rat");
    dark_lane2->add_creature("a grey bat");

    auto dark_lane3 = create_room(
         "a dark lane dead end",
        "The dark lane ends here. The only exit is to the west. There is a bird nest."
    );
    dark_lane3->add_item("a leather helmet");
    dark_lane3->add_special_item("nest", "a tiny iron key");
    
    start_room = main_square;
    
    connect_rooms(main_square, Exit::south, dark_lane1);
    connect_rooms(dark_lane1, Exit::south, dark_lane2);
    connect_rooms(dark_lane2, Exit::east, dark_lane3);
}


