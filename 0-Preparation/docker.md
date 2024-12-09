
# Use of predefined docker images

If you want to run the notebooks locally on your workstation, the image to be used for most notebooks and examples is `chavid/devjupytercpp:2024.3` (available from the docker hub).

So to start a container with this image :
```
cd /path/to/your/workdir
docker run -it --rm -p 8888:8888 -v $PWD:/work -w /work chavid/devjupytercpp:2025.4 bash
```

Then you can start the usual notebook server:
```
jupyter notebook --no-browser --allow-root --ip=0.0.0.0
```

Or the lab:
```
jupyter-lab --no-browser --allow-root --ip=0.0.0.0
```





