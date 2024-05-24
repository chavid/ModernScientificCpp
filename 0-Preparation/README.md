
# Prepare yourself for the lessons

## Knowledge prerequisites

The knowledge prerequisites for this lessons are given in `prerequisites.md`, together with links to courses and online tutorials which may help to fill the gaps.

## Access to the teaching material

As better described in `teaching-material.md`, the material will be made available, progressively, on [this public project](https://github.com/chavid/ModernScientificCpp.git).

Most of the education materials is given as jupyter notebooks. You can read them on the [public project](https://github.com/chavid/ModernScientificCpp.git), and copy/paste the C++ extracts.

Yet, you may want to *play* the notebooks, using one of the infrastructure described below. Our notebooks mostly use a C++ kernel, which is rather unusual. You can get additional information in the file [`notebooks.md`](`notebooks.md`), and practly shortly this [demo](demo-notebook.ipynb).

## Practice infrastructure

If the course takes place in a real classroom, with dedicated computers (such as at IDRIS), those computers will be pre-installed with the necessary software. If you are following the course from a distance, or you have been asked to bring your own portable computers, and/or you want to be able to work on your own outside the classroom: please read the following.

You will be able copy the C++ examples from the material, and paste it in your favorite C++ tools. As long as the examples are short enough, you can simply use the web service [CoLiRu](http://coliru.stacked-crooked.com/). If you want/need to compile yourself on your own machine, you may need to install a recent compiler, such as described at the beginning of [`installation.md`](installation.md).

If you want to interact directly with the notebooks, there is also a web service available, called [binder](https://mybinder.org/). So to start such a service : browse the main `README.md` file at the top of the [repository](https://github.com/chavid/ModernScientificCpp.git), and click on the "launch binder" button. The first time, because it is building a docker image on the fly, the launch time may be VERY long.

If you have an account in the RENATER federation, you may use [JupyterHub@Paris-Saclay](`https://jupyterhub.ijclab.in2p3.fr/`) (see `jupyterhub-ijclab.md`). This is supposedly faster. Yet you will need to clone yourself the material.

At last, if you want to play the notebooks directly on your machine, the file [`installation.md`](installation.md) try to sum up what to install. If you want to play them through docker, additional instructions are found in [`docker.md`](docker.md).

