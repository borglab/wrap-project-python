"""
GTSAM Copyright 2010-2019, Georgia Tech Research Corporation,
Atlanta, Georgia 30332-0415
All Rights Reserved

See LICENSE for the license information

Cal3Unified unit tests.
Author: Frank Dellaert & Duy Nguyen Ta (Python)
"""
import unittest

import numpy as np

import gtsam_example
from gtsam.utils.test_case import GtsamTestCase


class TestCal3Unified(GtsamTestCase):

    def test_Hello(self):
        g = gtsam_example.Greeting()
        g.sayHello()

    def test_Goodbye(self):
        g = gtsam_example.Greeting()
        g.sayGoodbye()


if __name__ == "__main__":
    unittest.main()