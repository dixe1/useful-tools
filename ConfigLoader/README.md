# ConfigLoader

A simple C++ configuration file loader in `key=value` format.  
The `ConfigLoader` class reads a file and returns an `std::unordered_map` of key-value pairs.

## Info

- ConfigLoader returns: unordered_map<string, string>

## Config format
- key=value
- key = value
* Warning: Only leading and trailing spaces are removed. Multiple spaces inside key or value are kept.

## Usage
```cpp
#include "ConfigLoader.h"
#include <iostream>

int main() {
    auto config = ConfigLoader::load("exampleConfig.txt");
    
    std::cout << config.at("width") << std::endl;
}
