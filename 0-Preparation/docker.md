
# Use of predefined docker images

If you want to run the notebooks locally on your workstation, the image to be used for most notebooks and examples is `gitlab-registry.in2p3.fr/chamont/modernscientificcpp/default:v4`.

In case you need a more advanced compiler features, which cannot be handled by the xeus-cling notebook kernel, you should rather rely on `gitlab-registry.in2p3.fr/chamont/modernscientificcpp/advanced:v4`. This image should be used for the advanced notebooks where the kernel is a Python one, and the extracts execution is delegated to the underlying system, through %%file and ! magic instructions.

So to start a container with any of those images :
```
docker run -it --rm -p 8888:8888 -v $PWD:/work -w /work <THE-IMAGE-PATH> bash
```

Then you can start the usual notebook server:
```
jupyter notebook --no-browser --allow-root --ip=0.0.0.0
```

Or the lab:
```
jupyter-lab --no-browser --allow-root --ip=0.0.0.0
```