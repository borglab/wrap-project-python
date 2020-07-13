# wrap-project-python

Project template illustrating python wrapping with borglab/wrap, **no** GTSAM.

This file will be included as the python package description :)

## PREREQUISITES

- Python 3.6+ is required.

## INSTALL

- Clone this repository with all submodules by `git clone --recursive https://github.com/borglab/wrap-project-python.git`
- In the project directory, create a `build` directory and `cd` into it.
- Run `cmake ..` (with optional prefix of your choice)
- Run `make`, and the wrapped module will built into build/python.
- Run `make install`, which will install the C++ library (only) to the cmake prefix.
- Run `make python-install`, which will run `python build/setup.py install` in your current environment.

## DOCUMENTATION

For more detailed information, please refer to the [tutorial](TUTORIAL.md).
