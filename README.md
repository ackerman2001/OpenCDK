# OpenCDK
OpenCDK (Open Caitlyn Development Kit) is a free and open-source implementation of the Caitlyn Platform. This includes Caitlyn compiler and Caitlyn virtual machine (CVM).
## Contributing
The best way to interact with us is to test tools and make bug reports through GitHub.
* [Issues](https://github.com/ackerman2001/OpenCDK/issues)

If you are a developer. See:
* [Coding Style](https://github.com/ackerman2001/OpenCDK/wiki/Coding-Style)
## Building
Caitlyn language is supported for Linux but other platforms should be able to buid Open Caitlyn Development Kit.
First of all you will need to install gcc-10
```
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install gcc-10
```
Next we have to clone the repository
```
git clone https://github.com/ackerman2001/OpenCDK.git
cd OpenCDK
```
To install Caitlyn virtual machine
```
cd tools/cvm/src
gcc cvm.c -o cvm
```

