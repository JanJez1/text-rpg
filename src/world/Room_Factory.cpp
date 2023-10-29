#include "../world_helper/Room_Factory.h"

using namespace std;


void Room_Factory::generate_rooms() {

    auto shore_01 = create_room(
        "a shore end",
        "The cliff protrudes to the sea making progress to the west impossible. The shore runs to the east."
    );
    shore_01->add_creature("an old goblin");
    shore_01->add_detail("cliff", "Steep mountain cliff towering along the shore. It protrudes to the sea here.");

    auto shore_02 = create_room(
        "a shore",
        "The shore itself runs to the east and west while the path ends here in front of a dense bush growing at the foot of the cliff."
    );
    shore_01->add_detail("cliff", "Steep mountain cliff towering along northern side of shore.");
    
    auto crossing = create_room(
        "a crossing",
        "there is an old mole to the south and the main road runs to the north. "
        "A narrow path runs along the shore to the west."
    );

    auto shore_03 = create_room(
        "a shore bend",
        "The shore bends here along the cliff to the south and west. To the north there is a cave entrance."
    );

    auto shore_04 = create_room(
        "a shore end",
        "The shore ends here with only possible exit to the north. There is a tiny nest resting in the cliff wall."
    );
    shore_04->add_special_item("nest");

    auto goblin_cave_01 = create_room(
        "in the goblin cave",
        "Inhabitable part of the cave with simple bed."
    );
    goblin_cave_01->add_creature("a sturdy goblin");

    auto goblin_cave_02 = create_room(
        "a narrow niche",
        "This is a narrow but rather long part of the cave. There is a chest placed at its end."
    );
    goblin_cave_02->add_special_item("chest1");

    auto bat_cave_01 = create_room(
        "in the cave",
        "Northwestern corner of the cave.",
        true // resetable
    );
    bat_cave_01->add_creature("a grey bat");

    auto bat_cave_02 = create_room(
        "in the cave",
        "Northeastern corner of the cave.",
        true
    );
    bat_cave_02->add_creature("a grey bat");

    auto bat_cave_03 = create_room(
        "in the cave",
        "Southwestern corner of the cave. The exit from the cave is to the south.",
        true
    );
    bat_cave_03->add_creature("a grey bat");

    auto bat_cave_04 = create_room(
        "in the cave",
        "Southeastern corner of the cave.",
        true
    );
    bat_cave_04->add_creature("a grey bat");
    bat_cave_04->add_item("a wooden stick");

    auto mole = create_room(
        "an old mole",
        "The mole stretches to the sea. It is constructed from the wood, but seem to be unkept. There is a half sunken boat next to the mole."
    );
    mole->add_special_item("boat");

    auto road_01 = create_room(
        "narrow road",
        "Narrow road running through the mountain. There is a gate to the north."
    );

    auto escaped = create_room(
        "escaped",
        "You've escaped out of the abandoned harbour. Congratulations! Here the demo ends."
    );



    start_room = crossing;
    
    // SHORE + road
    connect_rooms(shore_01, Exit::east, shore_02);
    connect_rooms(shore_02, Exit::east, crossing);
    connect_rooms(crossing, Exit::east, shore_03);
    connect_rooms(shore_03, Exit::south, shore_04);
    connect_rooms(crossing, Exit::south, mole);
    connect_rooms(crossing, Exit::north, road_01);
    connect_rooms(road_01, Exit::north, escaped, "gate1");

    // BAT CAVE
    connect_rooms(shore_03, Exit::north, bat_cave_03);
    connect_rooms(bat_cave_01, Exit::east, bat_cave_02);
    connect_rooms(bat_cave_01, Exit::south, bat_cave_03);
    connect_rooms(bat_cave_03, Exit::east, bat_cave_04);
    connect_rooms(bat_cave_02, Exit::south, bat_cave_04);

    // GOBLIN CAVE
    // shore_02->add_special_item("bush1", goblin_cave_01); // hidden exit
    // goblin_cave_01->add_exit(Exit::south, shore_02); // opposite exit must be done explicitly
    connect_rooms(shore_02, Exit::north, goblin_cave_01, "bush1"); // hidden exit
    connect_rooms(goblin_cave_01, Exit::west, goblin_cave_02);
}


