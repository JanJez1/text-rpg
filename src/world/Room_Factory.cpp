#include "../world_helper/Room_Factory.h"

using namespace std;


void Room_Factory::generate_rooms() {

    //   *****  ROOM DESCRIPTIONS ******

    auto shore_01 = create_room(
        "a shore end",
        "The cliff protrudes to the sea making progress to the west impossible. The shore runs to the east."
    );
    shore_01->add_creature("an old goblin");
    shore_01->add_detail("cliff", "Steep mountain cliff towering along the northern side of the shore. It protrudes to the sea here.");
    shore_01->add_detail("shore", "Rocky shore about twenty feet wide. It runs to the east. It is lined by the cliff on the north and west and by the sea on the south.");
    shore_01->add_detail("sea", "Endless waves of the sea stretch far to the south.");

    auto shore_02 = create_room(
        "a shore",
        "The shore itself runs to the east and west while the path ends here in front of a dense bush growing at the foot of the cliff."
    );
    shore_02->add_detail("cliff", "Steep mountain cliff towering along the northern side of shore. There is a dense bush at the foot of the cliff.");
    shore_01->add_detail("shore", "Rocky shore about twenty feet wide. It runs to the east and west. It is lined by the cliff on the north and the sea on the south.");
    shore_02->add_detail("path", "The path seems to lead into the bush.");
    shore_02->add_detail("sea", "Endless waves of the sea stretch far to the south.");
    
    auto crossing = create_room(
        "a crossing",
        "there is an old mole to the south and the main road runs to the north. "
        "A narrow path runs along the shore to the west."
    );

    auto shore_03 = create_room(
        "a shore bend",
        "The shore bends here along the cliff to the south and west. To the north there is a cave entrance."
    );
    shore_03->add_detail("cliff", "Steep mountain cliff towering along the northern and eastern side of shore.");
    shore_03->add_detail("cave", "The cave entrance is on the north. It doesn't seem to be dangerous to enter the cave.");
    shore_03->add_detail("shore", "Rocky shore about twenty feet wide. It runs to the south and west.");
    shore_03->add_detail("sea", "Endless waves of the sea stretch far to the southwest.");

    auto shore_04 = create_room(
        "a shore end",
        "The shore ends here with only possible exit to the north. There is a tiny nest resting in the cliff wall."
    );
    shore_04->add_special_item("nest");
    shore_04->add_detail("cliff", "Steep mountain cliff surrounds the area.");
    shore_04->add_detail("sea", "Endless waves of the sea stretch far to the southwest.");

    auto mole = create_room(
        "an old mole",
        "The mole stretches to the sea. It is constructed from the wood, but seem to be unkept. There is a half sunken boat next to the mole."
    );
    mole->add_special_item("boat");
    mole->add_detail("sea", "Endless waves of the sea stretch far to the south.");
    mole->add_detail("mole", "The mole is about 20 feet long and 5 feet wide. It seems to be unkept for a long time.");

    auto goblin_cave_01 = create_room(
        "in the goblin cave",
        "Inhabitable part of the cave with simple bed."
    );
    goblin_cave_01->add_creature("a sturdy goblin");
    goblin_cave_01->add_detail("bed", "A simple bed made of wood.");

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

    auto road_01 = create_room(
        "narrow road",
        "Narrow road running through the mountain. There is a gate to the north."
    );
    road_01->add_detail("mountain", "High mountain tower along both sides of the road.");
    road_01->add_detail("road", "A narrow road covered by dirt.");

    auto escaped = create_room(
        "escaped",
        "You've escaped out of the abandoned harbour. Congratulations! Here the demo ends."
    );

   
    //   *****  CONNECTING ROOMS ******

    // SHORE + road
    connect_rooms(shore_01, Exit::east, shore_02);
    connect_rooms(shore_02, Exit::east, crossing);
    connect_rooms(crossing, Exit::east, shore_03);
    connect_rooms(shore_03, Exit::south, shore_04);
    connect_rooms(crossing, Exit::south, mole);
    connect_rooms(crossing, Exit::north, road_01);
    connect_rooms(road_01, Exit::north, escaped, "gate1"); // gate between rooms 'road_01' and 'escaped'

    // BAT CAVE
    connect_rooms(shore_03, Exit::north, bat_cave_03);
    connect_rooms(bat_cave_01, Exit::east, bat_cave_02);
    connect_rooms(bat_cave_01, Exit::south, bat_cave_03);
    connect_rooms(bat_cave_03, Exit::east, bat_cave_04);
    connect_rooms(bat_cave_02, Exit::south, bat_cave_04);

    // GOBLIN CAVE
    connect_rooms(shore_02, Exit::north, goblin_cave_01, "bush1"); // exit from shore_02 hidden in the bush
    connect_rooms(goblin_cave_01, Exit::west, goblin_cave_02);

    start_room = crossing;
}


