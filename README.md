pyQCD
=====
pyQCD provides a Python package for running coarse lattice QCD simulations on desktop and workstation computers.

pyQCD may not be as powerful or as fully-featured as the like of Chroma or UKHADRON, but through simplicity it
is more transparent and perfect for basic desktop simulations. By interfacing with Python and numpy, it
facilitates the analysis of the results of the simulation.

***Please note that this software is very much still in alpha stage and is not yet mature, so backwards
compatability is not yet guaranteed for newer versions. If something's broken, have a look at the function
reference below, or check the python source code.***

Installation
------------
To build and install the module, the following packages are required:

* boost::python and boost::random, both version 1.49.0 or greater;
* Eigen C++ matrix library, version 3.1.3 or greater;
* numpy version 1.7 or greater;
* scipy version 0.12 or greater;
* OpenMP (version 3), required for parallel updates, but not essential.

Once these are installed, the package can be built using cmake. On Unix-like OSes, this is straightforward:

> cmake .
> make lattice
> make

The package can then be installed:

> sudo make install

Or, alternatively...

> python setup.py install

I haven't investigated how to do this on Windows, but if anyone has any success with this I'd be interested to
know.

It's possible that one or more of the required packages is not in a standard location, so cmake won't be able
to find these files automatically. In this case, the following flags can be used to point cmake to the relevant
paths:

> -DEIGEN3_INCLUDE_DIR=...
> -DBoost_INCLUDE_DIR=...
> -DBoost_LIBRARY_DIR=...
> -DPYTHON_LIBRARY=...

To build the documentation on linux, enter the doc directory and run

> make html

On Windows:

> make.bat html

This will build html documentation in the _build/html dubdirectory. At the moment this provides a brief function
reference. In the future this will hopefully be more detailed.

Quick Start
-----------

The library contains two high-level functions: one to run lattice simulations and one to process the results.
Both functions accept an input xml that specifies the settings for the simulation or processing. Examples of
these may be found in the examples directory, with each file containing a description of what the file encodes. A
list of the default values for the xml input files may be found in the simulation_default.xml file. These values
are automatically inserted when they are missing in the main xml file.

To run a very basic simulation, without measurements, from the project root directory, do

> from pyQCD.bin import simulate
> simulate.main("examples/basic.xml")

Postprocessing can be executed in a similar way:

> form pyQCD.bin import postprocess
> postprocess.main("examples/plaquette_autocorrelation.xml")

Once installed, the simulate.py and postprocess.py files may be run from the command line, with the input file
specified using the -i or --input=... flags.

> python -m pyQCD.bin.simulate -i examples/basic.xml
> python -m pyQCD.bin.postprocess -i examples/plaquette_autocorrelation.xml