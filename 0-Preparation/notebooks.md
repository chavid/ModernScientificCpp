
# About this course notebooks

The use of notebooks is not completely mandatory : you can read them on the [public project](https://gitlab.in2p3.fr/chamont/modernscientificcpp), and copy/paste the C++ extracts to your prefered editor. Else, if you want to play with the notebooks, please look at the notebook section in file `installation.md`.


## Two kind of notebooks

Most of the notebooks are relying on the **xeus-cling** C++17 kernel, which will directly "interpret" the code.

For few features which are not supported by the xeus-cling kernel (user defined literals, execution strategies, C++20 features), we use the magic command `%%file` and `!` so that the code is written to a temporary file, and the code compiled and executed by the underlying shell. In such a case, a python kernel is enough.

## Notebooks vs git versioning

One issue when working with notebooks : when using a notebook, you generally modifies it (at least the output of the code cells). If the teacher ask you to `git pull` a new version of it, you may face tedious merging conflicts.

The usual dirty workarounds applies : before pulling, either move globally your modified notebooks to a private git branch, or move/copy them to a backup directory.

If you prefer to solve the conflicts, `git diff`  will not help much. The right command is rather `nbdiff` , which is not available by default (till now) in the linux distributions. You will need to install the `nbdime` package first, for example with the command `conda install -y -c conda-forge nbdime`.

TO BE INVESTIGATED:
- https://jupytext.readthedocs.io/en/latest/
- https://mybinder.org/
