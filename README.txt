TODO:
- investigate \r
- check if the coords given in the script are within bound of the map
    (1920*1080) -> validate_script.c
- display the sprites
- toggalable hitbox
- set max frame rate and add a button to change it


STEPS:
✓ open the window and close event
✓ validate script
✓ assign values from script to struct
- create the sprites with their hitboxes, orientation etc display them
    quadtree:
    - move elements
    - classify elements in the quadtree and divide
    - check for collisions
    - remove collided elements
    - draw the screen
    - update display using CSFML
- make sure the program stops after all planes have landed/crashed
- user input
- bonus

MUST:
    ✓ The program must take exactly one parameter.
    ✓ The program must accept any filepath as argument. It corresponds to the file containing
        the script for the simulation containing characters and integers.
    ✓ The program must displayed an error message if the script is not found or incorrect.
    ✓ Your window must be 1920x1080 pixels.
    ✓ The window must be closed using events.
    ✕ The program must display aircrafts’ hitbox and control towers’ areas.
    ✕ The program must manage as many displayed entities as possible.
    ✕ Aircrafts must have 20x20 square shaped hitboxes.
    ✕ Aircrafts’ hitbox and sprite must be axis-aligned.
    ✕ Control towers must have circled shaped control areas.