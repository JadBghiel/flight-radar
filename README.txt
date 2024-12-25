this version doesnt execute with the proper script it hangs for some reason,
    maybe due to my_fgets

TODO:
- investigate \r
- in my_fgets() 2 func have > 4 params so do a struct
- check if the coords given in the script are within bound of the map
    (1920*1080) -> validate_script.c
- assign the value from the script to the multiple struct (plane_t, tower_t)
- display the sprites
- toggalable hitbpx

STEPS:
✓ open the window and close event
- validate script
- assign values from script to struct
- create the sprites with their hitboxes, orientation etc display them
- check for collisions
- make sure the program stops after all planes have landed/crashed
- user input
- bonus


MUST:
    ✕ The program must take exactly one parameter.
    ✕ The program must accept any filepath as argument. It corresponds to the file containing
        the script for the simulation containing characters and integers.
    ✕ The program must displayed an error message if the script is not found or incorrect.
    ✓ Your window must be 1920x1080 pixels.
    ✓ The window must be closed using events.
    ✕ The program must display aircrafts’ hitbox and control towers’ areas.
    ✕ The program must manage as many displayed entities as possible.
    ✕ Aircrafts must have 20x20 square shaped hitboxes.
    ✕ Aircrafts’ hitbox and sprite must be axis-aligned.
    ✕ Control towers must have circled shaped control areas.