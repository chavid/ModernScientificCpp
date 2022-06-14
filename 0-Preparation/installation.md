
# What should I install ?

## For raw compilation : a C++17 compiler

The more we progress in the lessons, the more advanced C++ features we will use: mostly C++17, and C++20 for few demonstrations. It is therefore adviced to have a recent enough compiler, such as **gcc 9**, or even **gcc 11.2** which we use for the preparation of this course. You will find [here](https://en.cppreference.com/w/cpp/compiler_support) the table of which C++ feature is supported by which compiler version. You should be aware that there is often a distinction between language syntax and standard library : a compiler version which supports C++17 language features does not necessarily supports the C++17 standard library. Generally, the support for syntax is implemented first, and the library novelties comes with a later version.

## GNU time

For some of the exercices, you will need to have **GNU time** installed where you want to execute the scripts. Try the command `\time -f "%U" echo toto` to check if it works fine. The `\` is there to avoid that bash use its own internal time command. If it does not work properly, try `conda install -c conda-forge time` (for example). 

## If you want to intereact with the notebooks

Most of the education materials is given as notebooks. You can read them on the [public project](https://gitlab.in2p3.fr/chamont/modernscientificcpp), and copy/paste the C++ extracts. Yet, if you want to play the notebooks directly on your machine, you will need to install:
1. `git` and `git-lfs` so to download the files (see en.teaching-material.md) ;
2. [jupyter](https://jupyter.org/) ecosystem ;
3. [xeus-cling](https://xeus-cling.readthedocs.io/en/latest/) C++ kernels for notebooks.

The jupyter notebooks tools are part of the [anaconda3 distribution](https://www.anaconda.com/). One can also use `miniconda` for a more focused installation (see below).

### Basic installation and setup with miniconda

[Miniconda](https://docs.conda.io/en/latest/miniconda.html) may be installed this way:
```
MINICONDA_ROOT=/opt/miniconda3
wget https://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh
bash Miniconda3-latest-Linux-x86_64.sh -b -p ${MINICONDA_ROOT}
rm Miniconda3-latest-Linux-x86_64.sh
${MINICONDA_ROOT}/bin/conda init bash
```

Thus, the following installation should bring you anything listed before:
```
conda update -y conda
conda install -y -c conda-forge mamba
mamba install -y -c conda-forge jupyter
mamba install -y -c conda-forge notebook
mamba install -y -c conda-forge jupyterlab
mamba install -y -c conda-forge xeus-cling
mamba install -y -c conda-forge nbdime
mamba install -y -c conda-forge time
mamba install -y -c conda-forge gxx
```

## With docker

We have also prepared some docker images with anything pre-installed, if you have docker on your machine. See `docker.md` .



