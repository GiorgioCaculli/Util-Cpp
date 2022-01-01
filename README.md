# Personal Utilities Libraries
## Used throughout various (personal) projects

## Dependencies
- [Boost](https://www.boost.org/)

## Build Tools:
- [CMake](https://cmake.org/)
- [Autotools](https://www.gnu.org/software/software.html)

## Building Instructions:

### Autotools
1. mkdir build
2. cd build
3. autoreconf -fiv ../
4. ../configure
5. make
6. sudo (or doas) make install

### CMake
1. mkdir build
2. cmake ../
3. make
4. sudo (or doas) make install
