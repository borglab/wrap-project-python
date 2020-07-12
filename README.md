# wrap-project-python

Project template illustrating python wrapping with borglab/wrap, **no** GTSAM.

## PREREQUISITES

- Python 3.6+ is required, since we support these versions.

## INSTALL

- In the `example` directory, create the `build` directory and `cd` into it.
- Run `cmake ..`.
- Run `make`, and the wrapped module will built into build/python.
- Run `make install`, which will install the C++ library (only) to the cmake prefix.
- Run `make python-install`, which will run `python build/python/setup.py install` in your current environment.

## DOCUMENTATION

For more detailed information, please refer to the [tutorial](TUTORIAL.md).
