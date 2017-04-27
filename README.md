# Cold-Engine
Engine made in SDL2.0 with C++

## About:


## Dependencies:
	Cold Engine uses the following libraries:
* C++ STL
* CMake 3.2.2
* SDL 2
* SDL_image 2
* SDL_ttf 2
* SDL_mixer 2


## Intalling Dependencies:
  	In Debian-based Linux distributions, these libraries can be installed by the following commands:
### Cmake 3.2.2
   	
	Currently, the latest version is 3.2.2, the following instructions based on this version. You should therefore check this URL and adjust the file name accordingly.

    	$ sudo apt-get install build-essential
    	$ wget http://www.cmake.org/files/v3.2/cmake-3.2.2.tar.gz
    	$ tar xf cmake-3.2.2.tar.gz
    	$ cd cmake-3.2.2
    	$ ./configure
   	$ make
	
	Now you can have to choose an installation type to decide, I recommend installing with checkinstall, as this creates a DEB package.
	
	- With checkinstall

        $ sudo apt-get install checkinstall
        $ sudo checkinstall

        - With make install

        $ sudo make install
	
### SDL 2
	$ sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev


## Author:
    Developer: Arthur Barbosa Diniz (15/0118457)
   	Contact: arthurbdiniz@gmail.com

## BUILD/RUN INSTRUCTIONS:
	First of all, it's necessary to download and install the required libraries.
	]
   

	



	Cold Engine uses GNU Cmake for building the project. Simply run the following 
	command in your command prompt:
	
	$ mkdir build
	$ cd build	
	$ cmake ..
	$ make
	$ ./wild_west


## License
GNU Public License Version 3 (GPLv3)
