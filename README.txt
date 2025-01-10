NEXT:
- user input: S and L key to toggle
- set max frame rate and add a button to change it
- when planes arrived at their destination they dissapear
- timer 
- radius is not centered with the towers
- check vf valgrind


TODO:
- check if the coords given in the script are within bound of the map
    (1920*1080) -> validate_script.c

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
    ✓ The program must display aircrafts’ hitbox and control towers’ areas.
    ✕ The program must manage as many displayed entities as possible.
    ✓ Aircrafts must have 20x20 square shaped hitboxes.
    ✓ Aircrafts’ hitbox and sprite must be axis-aligned.
    ✓ Control towers must have circled shaped control areas.

SHOULD:
    ✕ The program should display and update a timer in seconds at the top-right corner of the
        window.
    ✕ The program should stop once all aircrafts have landed on or have been destroyed.
    ✓ Aircrafts should be able to take off after a given delay.
    ✓ Aircrafts and control towers should be displayed using sprites.
    ✓ The program should accept the “-h” option, then display the usage.
    ✕ The program should be able to switch visibility of hitboxes and areas by pressing the key
        ‘L’.
    ✕ The program should be able to switch visibility of entities’ sprites by pressing the key ‘S’.
    ✓ Possible user interactions should be explicitly displayed in the usage.

COULD:
    ✕ Aircrafts’ hitbox and size could be in a 3D space.
    ✕ Aircrafts could cross any side of a screen and appear on the opposite one.
    ✕ Aircrafts’ hitbox and sprite could rotate depending on the aircrafts’ direction.
    ✓ Aircrafts’ hitbox could follow the sprite boundary.
    ✕ Aircrafts’ hitbox could have different sizes.
    ✕ Control towers’ areas could cross any side of the screen and affect the opposite one.
    ✕ The program could manage floating numbers coming from the script.