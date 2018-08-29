# Simple Pac-Man

Project use SFML C++ library and need to install this library!!! And project tested on Ubuntu 16.04 LTE!

## Prepare installation
For SFML installation
'''
./SFML_autoInstall.sh
'''
OR
'''
> ./SFML_install.sh
'''
First argument of program is the path to the map.
If program haven\`t the first argument, program include standart map

Map is a text file with digits delimited by spaces and be new lines

Every digit symbolize a thing:
0 - wall
1 - space
2 - position of pac-man
3 - position of ghosts
4 - position of exit
5 - points

Map must be without new lines at the end of file! Must be only one position of pac-man at the map!

And ghosts can go on walls (it not a bug)!
