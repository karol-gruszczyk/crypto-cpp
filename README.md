# Crypto CPP
A set of cryptography related utilities packaged as static library

## Prerequisites

### Testing
#### Install Catch2
```shell script
git clone https://github.com/catchorg/Catch2.git
cd Catch2
cmake -Bbuild -H. -DBUILD_TESTING=OFF
sudo cmake --build build/ --target install
```
