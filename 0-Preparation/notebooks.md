
# About this course notebooks

The direct use of notebooks is not completely mandatory : you can view them on the web, and copy/paste the C++ extracts to your prefered editor. Else, if you want to play with the notebooks on your machine, please look at the notebook section in file [`installation.md`](installation.md).


## Two kind of notebooks

Most of the notebooks here are relying on the **xeus-cling** C++17 kernel, which will directly "interpret" the code.

For few features which are not supported by the xeus-cling kernel (user defined literals, execution strategies, C++20 features), we rather use notebooks with the classical python kernel, and we
use the magic commands `%%file` and `!` so that the code is written to a temporary file, and the code compiled and executed by the underlying shell.


## Notebooks vs git versioning

One issue when working with notebooks : when using a notebook, you generally modifies it (at least the output of the code cells). If the teacher ask you to `git pull` a new version of the notebook you modified, you may face tedious merging conflicts.

The usual dirty workarounds apply : before pulling, either move globally your modified notebooks to a private git branch, or move/copy them to a backup directory, or even simply rename it.

If you prefer to solve the conflicts, `git diff`  will not help much. The right command is rather `nbdiff -s`, which is not available by default (till now) in the linux distributions. You will need to install the `nbdime` package first, for example with the command `conda install -y -c conda-forge nbdime`. Actually, I do not recommend.

The simpler and safer way is probably to **make a copy of any notebook you want to play with**, and work with the copy. This way, if the teacher ask you to pull a modified version of the notebook, no conflict !

