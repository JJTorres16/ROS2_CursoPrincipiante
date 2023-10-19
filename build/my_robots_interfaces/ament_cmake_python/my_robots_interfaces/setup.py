from setuptools import find_packages
from setuptools import setup

setup(
    name='my_robots_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('my_robots_interfaces', 'my_robots_interfaces.*')),
)
