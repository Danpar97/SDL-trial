# Dependencies

## List
* libsdl2-2.0-0/xenial,now 2.0.4+dfsg1-2ubuntu2 i386 [installed]
* libsdl2-dbg/xenial,now 2.0.4+dfsg1-2ubuntu2 i386 [installed]
* libsdl2-dev/xenial,now 2.0.4+dfsg1-2ubuntu2 i386 [installed]
* libsdl2-gfx-1.0-0/xenial,now 1.0.1+dfsg-3 i386 [installed]
* libsdl2-gfx-dbg/xenial,now 1.0.1+dfsg-3 i386 [installed]
* libsdl2-gfx-dev/xenial,now 1.0.1+dfsg-3 i386 [installed]
* libsdl2-image-2.0-0/xenial,now 2.0.1+dfsg-2 i386 [installed]
* libsdl2-image-dbg/xenial,now 2.0.1+dfsg-2 i386 [installed]
* libsdl2-image-dev/xenial,now 2.0.1+dfsg-2 i386 [installed]
* libsdl2-mixer-2.0-0/xenial,now 2.0.1+dfsg1-1 i386 [installed]
* libsdl2-mixer-dbg/xenial,now 2.0.1+dfsg1-1 i386 [installed]
* libsdl2-mixer-dev/xenial,now 2.0.1+dfsg1-1 i386 [installed]
* libsdl2-net-2.0-0/xenial,now 2.0.1+dfsg1-2 i386 [installed]
* libsdl2-net-dbg/xenial,now 2.0.1+dfsg1-2 i386 [installed]
* libsdl2-net-dev/xenial,now 2.0.1+dfsg1-2 i386 [installed]
* libsdl2-ttf-2.0-0/xenial,now 2.0.14+dfsg1-1 i386 [installed]
* libsdl2-ttf-dbg/xenial,now 2.0.14+dfsg1-1 i386 [installed]
* libsdl2-ttf-dev/xenial,now 2.0.14+dfsg1-1 i386 [installed]

##Install Method
Compile from source found [here](http://libsdl.org/) using the instructions provided on their wiki/docs
* **On Linux:**(Recommended Method)
'''sh
apt install libsdl2-2.0-0 libsdl2-dbg libsdl2-dev libsdl2-gfx-1.0-0 libsdl2-gfx-dbg libsdl2-gfx-dev libsdl2-image-2.0-0 libsdl2-image-dbg libsdl2-image-dev libsdl2-mixer-2.0-0 libsdl2-mixer-dbg libsdl2-mixer-dev libsdl2-net-2.0-0 libsdl2-net-dbg libsdl2-net-dev libsdl2-ttf-2.0-0 libsdl2-ttf-dbg libsdl2-ttf-dev
'''
* On Windows:
Just install the Development binaries (Runtime Binaries are included) for your compiler of choice either VC(Visual C/C++) or GCC(GNU C/C++), some features like SDL2_image and SDL2_mixer need additional DLL which need to be kept in the project directory for development.
