# gr-navtex: GNU Radio OOT module for NAVTEX

This OOT GNU Radio module supports the decoding of NAVTEX traffic (https://en.wikipedia.org/wiki/NAVTEX)

## Dependencies

This module requires libnavtex (https://github.com/fventuri/navtex).

Please build and install the libnavtex library before building this module.


## Build and installation

```
cd gr-navtex
mkdir build
cd build
cmake ..
make
sudo make install
```

# Examples

A couple of examples of decoding a raw file and a WAV file are provided in the [examples](examples) directory.


## Credits

- Franco Spinelli, IW2DHW for his patience and perseverance and for providing some NAVTEX examples
- Rik van Riel, AB1KW for the NAVTEX decoder from fldigi, which libnavtex is based on


## Copyright

(C) 2021 Franco Venturi - Licensed under the GNU GPL V3 (see [LICENSE](LICENSE))
