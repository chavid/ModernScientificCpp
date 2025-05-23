
# Prepare yourself for the lessons

## Knowledge prerequisites

The knowledge prerequisites for this lessons are given in [`prerequisites.md`](prerequisites.md), together with links to courses and online tutorials which may help to fill the gaps.

## Access to the teaching material

The material is available, or will be progressively, on the current repository. Most of the education materials is given as jupyter notebooks. You can read them on the web, and copy/paste the C++ extracts.

At any time, one can also clone the repository, pull the last revision of it, or download a `zip` file with anything included : lessons, notebooks, exercises.

This is especially needed if you may want to *play* the notebooks, using one of the infrastructure described below. Our notebooks mostly use a C++ kernel, which is rather unusual. You can get additional information in the file [`notebooks.md`](notebooks.md), and practice shortly this [demo](demo-notebook.ipynb).

## Practice infrastructure : pure C++

#### Pre-installed computers ?

IDRIS computers : check with the teachers.

If the course takes place in a real classroom, with dedicated computers, those computers may be pre-installed with the necessary software. If you are following the course from a distance, or you have been asked to bring your own portable computers, and/or you want to be able to work on your own outside the classroom: please read the following.

#### Web online compilers
You will be able copy the C++ examples from the material, and paste it in your favorite C++ tools. As long as the examples are short enough, you can simply use the web service [CoLiRu](http://coliru.stacked-crooked.com/). The [Compiler Explorer](https://godbolt.org/) is a more elaborated tool which can handle multiple files.

#### On your own machine, with docker

If you have docker installed, there are turnkey images, as described in [`docker.md`](docker.md).

#### Baremetal installation

If you want/need to compile yourself on your own machine, you may need to install a recent compiler, such as described at the beginning of [`installation.md`](installation.md).


## Practice infrastructure : use of notebooks

#### IDRIS computers : check with the teachers.

#### Binder (***CURRENTLY NOT WORKING***)

If you want to interact directly with the notebooks, there is also a web service available, called [binder](https://mybinder.org/). So to start such a service : browse the main `README.md` file at the top of the repository, and click on the "launch binder" button. The first time, the launch time may be VERY VERY long, because it is building a docker image on the fly.

#### JupyterHub@Paris-Saclay (OBSOLETE)

If you have an account in the RENATER federation, you may use [JupyterHub@Paris-Saclay](https://jupyterhub.ijclab.in2p3.fr/shibboleth) (see [`jupyterhub-ijclab.md`](jupyterhub-ijclab.md)). Once your server is started, you will need to clone there the training material.

#### MyDocker@Paris-Saclay (SOON...)

#### On your own machine, with docker

If you want to play the notebooks through docker, instructions are found in [`docker.md`](docker.md).


#### Baremetal installation

At last, if you want to play the notebooks directly on your machine, the file [`installation.md`](installation.md) try to sum up what to install.

