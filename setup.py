#!/usr/bin/env python

"""
setup.py file for SWIG example
"""

from distutils.core import setup, Extension
import re
import requests
import numpy

np_version = re.compile(r'(?P<MAJOR>[0-9]+)\.'
                        '(?P<MINOR>[0-9]+)') \
                        .search(numpy.__version__)
np_version_string = np_version.group()
np_version_info = {key: int(value)
                   for key, value in np_version.groupdict().items()}

np_file_name = 'numpy.i'
np_file_url = 'https://raw.githubusercontent.com/numpy/numpy/maintenance/' + \
              np_version_string + '.x/tools/swig/' + np_file_name
if(np_version_info['MAJOR'] == 1 and np_version_info['MINOR'] < 9):
    np_file_url = np_file_url.replace('tools', 'doc')

chunk_size = 8196
with open(np_file_name, 'wb') as file:
    for chunk in requests.get(np_file_url,
                              stream=True).iter_content(chunk_size):
        file.write(chunk)

#! /usr/bin/env python

# System imports
from distutils.core import *
from distutils      import sysconfig

# Third-party modules - we depend on numpy for everything
import numpy

# Obtain the numpy include directory.  This logic works across numpy versions.
try:
    numpy_include = numpy.get_include()
except AttributeError:
    numpy_include = numpy.get_numpy_include()

_felzenszwalb = Extension('_felzenszwalb',
                           sources=['felzenszwalb_wrap.cxx', 'pysegment.cpp'],
                           include_dirs = [numpy_include],
                           )

setup (name = 'felzenszwalb',
       version = '0.1',
       author      = "Nadav Arbel",
       description = """Python port of Pedro Felzenszwalb's Segmentation algorithm""",
       ext_modules = [_felzenszwalb],
       py_modules = ["felzenszwalb"],
       )


