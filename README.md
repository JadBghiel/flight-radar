# FLIGHT RADAR SIMULATOR

Takes file as input and simulate planes and towers.

Project for Epitech first year (2024)

### Description

1. Rule:

- If two planes collide with each other outside of a control tower radius, they crash, otherwise they keep on going to their destination

## Getting Started

### Dependencies

- [Linux](https://linux.org/)
- [Make](https://www.gnu.org/software/make/)
- [GCC](https://gcc.gnu.org/)
- [CSFML](https://26.customprotocol.com/csfml/index.htm)
- [Python](https://www.python.org/)

### Installation

* Download/Clone the repository and enter its directory
* Compile the code typing `make`

* If you want to use generate a script, install python3 and run `python3 generator.py -h for more details

## Usage

**Execution:**

The program takes one file as input (the script):

```
./my_radar <generated_python_script>
```

## Innerworkings

### Proyect structure

#### Approach

Firstly, the script given as parameter is parsed to make sure it is the correct format and contain valid data, next the data is extracted from the script and assigned to a struct which will later be used to create and initialize the sprites (towers and planes),

Finally, it updates the plane position to make it move from it's departure coordinate to it's arrival coordinate and handling the crashing if two planes's hitboxes collide.

#### Tools

The only allowed functions of this project were the CSFML and math library ones as well as some standard C functions : malloc, free, stat, memset, rand, srand, time (only with srand), (f)open ,(f)read, (f)write, (f)close, getline.

The rest were all custom made functions.

## Acknowledgments

* [Epitech](https://www.epitech.eu/)

## Authors

* **Jad BGHIEL** ([GitHub](https://github.com/JadBghiel) / [LinkedIn](https://www.linkedin.com/in/jadbghiel/))

## License

This project is licensed under the GNU Public License version 3.0 - see the [LICENSE](https://www.gnu.org/licenses/gpl-3.0.html) file for details.