# About
This is my personal toolkit/toolset of C++ software development environment. It is a WIP, but the idea is to just link to the required lib for fast prototyping and having a structured skeleton project integrated with cmake and a testing framework like Catch2.

## Conan notes
If you are using GCC compiler >= 5.1, Conan will set the compiler.libcxx to the old ABI for backwards compatibility. You can change this with the following commands:

```bash
$ conan profile new default --detect  # Generates default profile detecting GCC and sets old ABI
$ conan profile update settings.compiler.libcxx=libstdc++11 default  # Sets libcxx to C++11 ABI
```

- [conan docs](https://docs.conan.io/en/latest/getting_started.html)

# Resources
## Assets
The assests folder contains spritelib from ari@widgetworx
- [widgetworx](https://widgetworx.com/)
