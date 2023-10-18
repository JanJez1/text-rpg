# text-rpg

Role Playing Game (RPG) running in the console.

Under development.

You are in control of a hero in a medieval/fantasy world. The world consists of separate locations (so called rooms). While exploring the world you move between rooms, fight monsters, collect items, look for hidden treasures and gain experience. Description of locations, monsters and items are in text only. You control your hero by giving text commands.

Currently implemented:
- rooms connected via exits
- hero movement
- items, armours, weapons, creatures
- item manipulation
- worn/held items alter player (and monster) characteristics (ac, damage, strength, ...)
- simple combat based on AD&D
- some creatures reappear over time when killed
- general support for interaction with objects (finding hidden exits or items, ...)

Commands:
- go ('go north', or simply 'n')
- look (at), inventory, status
- get, drop
- wear, hold, remove
- quit
- hit (attack)